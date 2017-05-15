// Copyright (c) 2017 mogemimi. Distributed under the MIT license.

#ifdef _MSC_VER
#pragma warning(disable : 4146 4127 4244 4702 4996)
#else
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wconversion"
#endif

#include "clang/Frontend/FrontendActions.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
#include "llvm/Support/CommandLine.h"

#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif

namespace {

llvm::cl::OptionCategory MyToolCategory("My Tool Options");

} // end anonymous namespace

int main(int argc, const char** argv)
{
    using clang::tooling::CommonOptionsParser;
    using clang::tooling::ClangTool;
    using clang::tooling::newFrontendActionFactory;

    CommonOptionsParser options(argc, argv, MyToolCategory);
    ClangTool tool(options.getCompilations(), options.getSourcePathList());
    return tool.run(newFrontendActionFactory<clang::SyntaxOnlyAction>().get());
}
