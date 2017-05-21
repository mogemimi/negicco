# Negicco

Practicing and learning Clang LibTooling (still work in progress).

- [01. Getting started](01-getting-started)
  - keywords: `CommonOptionsParser` `ClangTool`
- [02. Named declarations](02-named-declarations)
  - keywords: `NamedDecl`, `RecursiveASTVisitor`
- [03. Comments](03-comments)
  - keywords: `Preprocessor`, `CommentHandler`, `SourceRange`
- [04. Help text](04-help-text)
  - keywords: `OptionCategory`, `extrahelp`
- [05. Enum classes](05-enum-classes)
  - keywords: `ASTContext`, `EnumDecl`
- [06. Variables](06-variables)
  - keywords: WIP
- [07. Functions](07-functions)
  - keywords: WIP
- [08. Namespaces](#)
- [09. Classes](#)
- [10. Preprocessor Definitions](#)

## How to build
Use `CMake` to configure & build executables.

ex:
```shell
mkdir BUILD
cd BUILD
cmake -G Ninja  \
    -DLLVM_DIR=<directory contains LLVMConfig.cmake> \
    -DClang_DIR=<directory contains ClangConfig.cmake>
cmake --build BUILD
```
