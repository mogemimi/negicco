# Help text

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
cd negicco/04-help-text

# Compiling for any platforms
make build CLANG_DIR=/path/to/your/dir/clang+llvm-3.9.0

# Compiling under Mac OS X
make build CLANG_DIR=/path/to/your/dir/clang+llvm-3.9.0-x86_64-apple-darwin
```

## Running the application

#### Show help text

```shell
.negicco -help
```

Result:

```shell
OVERVIEW: negicco <source file>
USAGE: negicco [options] <source0> [... <sourceN>]

OPTIONS:

Generic Options:

  -help                      - Display available options (-help-hidden for more)
  -help-list                 - Display list of available options (-help-list-hidden for more)
  -version                   - Display the version of this program

My Tool Options:

  -extra-arg=<string>        - Additional argument to append to the compiler command line
  -extra-arg-before=<string> - Additional argument to prepend to the compiler command line
  -p=<string>                - Build path

-p <build-path> is used to read a compile command database.

	For example, it can be a CMake build directory in which a file named
	compile_commands.json exists (use -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
	CMake option to get this output). When no build path is specified,
	a search for compile_commands.json will be attempted through all
	parent paths of the first input file . See:
	http://clang.llvm.org/docs/HowToSetupToolingForLLVM.html for an
	example of setting up Clang Tooling on a source tree.

<source0> ... specify the paths of source files. These paths are
	looked up in the compile command database. If the path of a file is
	absolute, it needs to point into CMake's source tree. If the path is
	relative, the current working directory needs to be in the CMake
	source tree and the file must be in a subdirectory of the current
	working directory. "./" prefixes in the relative files will be
	automatically removed, but the rest of a relative path must be a
	suffix of a path in the compile command database.

More help text...
```
