# Dump all named declarations from AST

## Prerequisite - Downloading LLVM Clang

- http://releases.llvm.org/download.html

#### Mac OS X

```shell
cd path/to/your/dir
wget http://releases.llvm.org/3.9.0/clang+llvm-3.9.0-x86_64-apple-darwin.tar.xz
tar xaf clang+llvm-3.9.0-x86_64-apple-darwin
```

## Compiling the application

```shell
git clone https://github.com/mogemimi/negicco.git
cd negicco/02-named-declarations

# Compiling for any platforms
make build CLANG_DIR=/path/to/your/dir/clang+llvm-3.9.0

# Compiling under Mac OS X
make build CLANG_DIR=/path/to/your/dir/clang+llvm-3.9.0-x86_64-apple-darwin
```

## Running the application

#### Get enum definitions and comments from source code

```shell
.negicco main.cpp -- -std=c++14
```

or

```shell
.negicco <sources ...> -- <compilation-options-of-clang ...>
```

Result:

```yaml
- DeclName: CommonOptionsParser
  QualifiedName: CommonOptionsParser
  Kind: Using
  At: "/path/to/negicco/02-named-declarations/main.cpp:34:1"

- DeclName: ClangTool
  QualifiedName: ClangTool
  Kind: Using
  At: "/path/to/negicco/02-named-declarations/main.cpp:35:1"

- DeclName: 
  QualifiedName: (anonymous)
  Kind: Namespace
  At: "/path/to/negicco/02-named-declarations/main.cpp:37:1"

- DeclName: MyToolCategory
  QualifiedName: (anonymous namespace)::MyToolCategory
  Kind: Var
  At: "/path/to/negicco/02-named-declarations/main.cpp:39:1"

- DeclName: MyPrinter
  QualifiedName: (anonymous namespace)::MyPrinter
  Kind: CXXRecord
  At: "/path/to/negicco/02-named-declarations/main.cpp:41:1"

- DeclName: Print
  QualifiedName: (anonymous namespace)::MyPrinter::Print
  Kind: CXXMethod
  At: "/path/to/negicco/02-named-declarations/main.cpp:43:5"

- DeclName: s
  QualifiedName: s
  Kind: ParmVar
  At: "/path/to/negicco/02-named-declarations/main.cpp:43:16"

- DeclName: GetLocation
  QualifiedName: (anonymous namespace)::GetLocation
  Kind: Function
  At: "/path/to/negicco/02-named-declarations/main.cpp:46:1"

- DeclName: ss
  QualifiedName: ss
  Kind: Var
  At: "/path/to/negicco/02-named-declarations/main.cpp:49:5"

- DeclName: NamedDeclVisitor
  QualifiedName: (anonymous namespace)::NamedDeclVisitor
  Kind: CXXRecord
  At: "/path/to/negicco/02-named-declarations/main.cpp:56:1"

- DeclName: sourceManager
  QualifiedName: (anonymous namespace)::NamedDeclVisitor::sourceManager
  Kind: Field
  At: "/path/to/negicco/02-named-declarations/main.cpp:58:5"

- DeclName: NamedDeclVisitor
  QualifiedName: (anonymous namespace)::NamedDeclVisitor::NamedDeclVisitor
  Kind: CXXConstructor
  At: "/path/to/negicco/02-named-declarations/main.cpp:61:5"

- DeclName: sourceManagerIn
  QualifiedName: sourceManagerIn
  Kind: ParmVar
  At: "/path/to/negicco/02-named-declarations/main.cpp:61:31"

- DeclName: VisitNamedDecl
  QualifiedName: (anonymous namespace)::NamedDeclVisitor::VisitNamedDecl
  Kind: CXXMethod
  At: "/path/to/negicco/02-named-declarations/main.cpp:66:5"

- DeclName: namedDecl
  QualifiedName: namedDecl
  Kind: ParmVar
  At: "/path/to/negicco/02-named-declarations/main.cpp:66:25"

- DeclName: MyASTConsumer
  QualifiedName: (anonymous namespace)::MyASTConsumer
  Kind: CXXRecord
  At: "/path/to/negicco/02-named-declarations/main.cpp:77:1"

- DeclName: printer
  QualifiedName: (anonymous namespace)::MyASTConsumer::printer
  Kind: Field
  At: "/path/to/negicco/02-named-declarations/main.cpp:79:5"

- DeclName: sourceManager
  QualifiedName: (anonymous namespace)::MyASTConsumer::sourceManager
  Kind: Field
  At: "/path/to/negicco/02-named-declarations/main.cpp:80:5"

- DeclName: pp
  QualifiedName: (anonymous namespace)::MyASTConsumer::pp
  Kind: Field
  At: "/path/to/negicco/02-named-declarations/main.cpp:81:5"

- DeclName: MyASTConsumer
  QualifiedName: (anonymous namespace)::MyASTConsumer::MyASTConsumer
  Kind: CXXConstructor
  At: "/path/to/negicco/02-named-declarations/main.cpp:84:5"

- DeclName: printerIn
  QualifiedName: printerIn
  Kind: ParmVar
  At: "/path/to/negicco/02-named-declarations/main.cpp:84:19"

- DeclName: sourceManagerIn
  QualifiedName: sourceManagerIn
  Kind: ParmVar
  At: "/path/to/negicco/02-named-declarations/main.cpp:84:41"

- DeclName: ppIn
  QualifiedName: ppIn
  Kind: ParmVar
  At: "/path/to/negicco/02-named-declarations/main.cpp:85:19"

- DeclName: HandleTranslationUnit
  QualifiedName: (anonymous namespace)::MyASTConsumer::HandleTranslationUnit
  Kind: CXXMethod
  At: "/path/to/negicco/02-named-declarations/main.cpp:92:5"

- DeclName: context
  QualifiedName: context
  Kind: ParmVar
  At: "/path/to/negicco/02-named-declarations/main.cpp:92:32"

- DeclName: visitor
  QualifiedName: visitor
  Kind: Var
  At: "/path/to/negicco/02-named-declarations/main.cpp:94:9"

- DeclName: decls
  QualifiedName: decls
  Kind: Var
  At: "/path/to/negicco/02-named-declarations/main.cpp:96:9"

- DeclName: MyFrontendAction
  QualifiedName: (anonymous namespace)::MyFrontendAction
  Kind: CXXRecord
  At: "/path/to/negicco/02-named-declarations/main.cpp:108:1"

- DeclName: MyFrontendAction
  QualifiedName: (anonymous namespace)::MyFrontendAction::MyFrontendAction
  Kind: CXXConstructor
  At: "/path/to/negicco/02-named-declarations/main.cpp:110:5"

- DeclName: printerIn
  QualifiedName: printerIn
  Kind: ParmVar
  At: "/path/to/negicco/02-named-declarations/main.cpp:110:31"

- DeclName: MyFrontendActionFactory
  QualifiedName: (anonymous namespace)::MyFrontendActionFactory
  Kind: CXXRecord
  At: "/path/to/negicco/02-named-declarations/main.cpp:126:1"

- DeclName: MyFrontendActionFactory
  QualifiedName: (anonymous namespace)::MyFrontendActionFactory::MyFrontendActionFactory
  Kind: CXXConstructor
  At: "/path/to/negicco/02-named-declarations/main.cpp:128:5"

- DeclName: printerIn
  QualifiedName: printerIn
  Kind: ParmVar
  At: "/path/to/negicco/02-named-declarations/main.cpp:128:38"

- DeclName: create
  QualifiedName: (anonymous namespace)::MyFrontendActionFactory::create
  Kind: CXXMethod
  At: "/path/to/negicco/02-named-declarations/main.cpp:133:5"

- DeclName: printer
  QualifiedName: (anonymous namespace)::MyFrontendActionFactory::printer
  Kind: Field
  At: "/path/to/negicco/02-named-declarations/main.cpp:139:5"

- DeclName: main
  QualifiedName: main
  Kind: Function
  At: "/path/to/negicco/02-named-declarations/main.cpp:144:1"

- DeclName: argc
  QualifiedName: argc
  Kind: ParmVar
  At: "/path/to/negicco/02-named-declarations/main.cpp:144:10"

- DeclName: argv
  QualifiedName: argv
  Kind: ParmVar
  At: "/path/to/negicco/02-named-declarations/main.cpp:144:20"

- DeclName: options
  QualifiedName: options
  Kind: Var
  At: "/path/to/negicco/02-named-declarations/main.cpp:146:5"

- DeclName: tool
  QualifiedName: tool
  Kind: Var
  At: "/path/to/negicco/02-named-declarations/main.cpp:147:5"

- DeclName: printer
  QualifiedName: printer
  Kind: Var
  At: "/path/to/negicco/02-named-declarations/main.cpp:149:5"
```
