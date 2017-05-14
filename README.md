# Negicco

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
git clone https://github.com/mogemimi/negicco.git && cd negicco

# Compiling for any platforms
make build CLANG_DIR=/path/to/your/dir/clang+llvm-3.9.0

# Compiling under Mac OS X
make build CLANG_DIR=/path/to/your/dir//clang+llvm-3.9.0-x86_64-apple-darwin
```

## Running the application

#### Get variables and comments from source code

```shell
.negicco tests/enum_class.cpp -- -std=c++14
```

Result:

```shell
42
/path/to/negicco/main.cpp:10:10: fatal error: 'clang/AST/AST.h' file
      not found
#include "clang/AST/AST.h"
         ^
1 error generated.
Error while processing /path/to/negicco/main.cpp.
```
