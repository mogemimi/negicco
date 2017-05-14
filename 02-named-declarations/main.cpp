// Copyright (c) 2017 mogemimi. Distributed under the MIT license.

#ifdef _MSC_VER
#pragma warning(disable : 4146 4127 4244 4702 4996)
#else
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wconversion"
#endif

#include "clang/AST/AST.h"
#include "clang/AST/ASTConsumer.h"
#include "clang/AST/Comment.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/Basic/FileManager.h"
#include "clang/Basic/SourceLocation.h"
#include "clang/Basic/SourceManager.h"
#include "clang/Basic/Version.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/FrontendActions.h"
#include "clang/Parse/Parser.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
#include "llvm/ADT/StringMap.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/Signals.h"

#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif

#include <sstream>

using namespace clang;
using namespace clang::ast_matchers;
using namespace clang::driver;
using namespace clang::tooling;
using namespace llvm;

namespace {

cl::OptionCategory MyToolCategory("negicco options");
cl::extrahelp CommonHelp(CommonOptionsParser::HelpMessage);
cl::extrahelp MoreHelp("\nMore help text...");

constexpr auto MyToolUsage = "negicco <source file>";

} // end anonymous namespace

namespace {

class MyPrinter final {
public:
    void Print(const std::string& s) { llvm::outs() << s << "\n"; }
};

std::string GetLocation(clang::SourceLocation location,
                        clang::SourceManager& sourceManager)
{
    std::ostringstream ss;
    ss << sourceManager.getFilename(location).str() << ":"
       << sourceManager.getSpellingLineNumber(location) << ":"
       << sourceManager.getSpellingColumnNumber(location);
    return ss.str();
}

class NamedDeclVisitor final : public clang::RecursiveASTVisitor<NamedDeclVisitor> {
private:
    clang::SourceManager& sourceManager;

public:
    NamedDeclVisitor(clang::SourceManager& sourceManagerIn)
        : sourceManager(sourceManagerIn)
    {
    }

    bool VisitNamedDecl(clang::NamedDecl* namedDecl)
    {
        llvm::outs() << namedDecl->getQualifiedNameAsString() << "\n"
                     << " at " << GetLocation(namedDecl->getLocStart(), sourceManager)
                     << "\n";
        return true;
    }
};

class MyASTConsumer final : public ASTConsumer {
private:
    MyPrinter& printer;
    clang::SourceManager& sourceManager;
    clang::Preprocessor& pp;

public:
    MyASTConsumer(MyPrinter& printerIn, clang::SourceManager& sourceManagerIn,
                  clang::Preprocessor& ppIn)
        : printer(printerIn)
        , sourceManager(sourceManagerIn)
        , pp(ppIn)
    {
    }

    void HandleTranslationUnit(ASTContext& context) override
    {
        NamedDeclVisitor visitor(sourceManager, context, pp);

        auto decls = context.getTranslationUnitDecl()->decls();
        for (auto& decl : decls) {
            const auto& fileID = sourceManager.getFileID(decl->getLocation());
            if (fileID != sourceManager.getMainFileID()) {
                continue;
            }

            visitor.TraverseDecl(decl);
        }
    }
};

class MyFrontendAction final : public ASTFrontendAction {
public:
    explicit MyFrontendAction(MyPrinter& printerIn)
        : printer(printerIn)
    {
    }

    std::unique_ptr<ASTConsumer> CreateASTConsumer(CompilerInstance& ci,
                                                   StringRef file) override
    {
        return std::make_unique<MyASTConsumer>(printer, ci.getSourceManager(),
                                               ci.getPreprocessor());
    }

private:
    MyPrinter& printer;
};

class MyFrontendActionFactory final : public FrontendActionFactory {
public:
    explicit MyFrontendActionFactory(MyPrinter& printerIn)
        : printer(printerIn)
    {
    }

    clang::FrontendAction* create() override
    {
        return new MyFrontendAction(printer);
    }

private:
    MyPrinter& printer;
};

} // end anonymous namespace

int main(int argc, const char** argv)
{
    using clang::tooling::CommonOptionsParser;
    using clang::tooling::ClangTool;

    CommonOptionsParser options(argc, argv, MyToolCategory, MyToolUsage);
    options.getCompilations();
    ClangTool tool(options.getCompilations(), options.getSourcePathList());

    MyPrinter printer;
    return tool.run(std::make_unique<MyFrontendActionFactory>(printer).get());
}
