# Dump enum classes from AST

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
cd negicco/05-enum-classes

# Compiling for any platforms
make build CLANG_DIR=/path/to/your/dir/clang+llvm-3.9.0

# Compiling under Mac OS X
make build CLANG_DIR=/path/to/your/dir/clang+llvm-3.9.0-x86_64-apple-darwin
```

## Running the application

#### Dump enum classes and comments to yaml

```shell
.negicco tests/enum_class.cpp -- -std=c++14
```

or

```shell
.negicco <sources ...> -- <compilation-options-of-clang ...>
```

Result:

```yaml
- DeclName: Color
  Style: Scoped (C++11)
  IntegerType: int
  QualifiedName: negicco::Color
  Location: "/path/to/negicco/05-enum-classes/test/enum_class.cpp:3:1"
  Members:
    - Name: Red
      Value: 0
    - Name: Yellow
      Value: 1
    - Name: Blue
      Value: 2

- DeclName: Animal
  Style: Scoped (C++11)
  IntegerType: int
  QualifiedName: negicco::Animal
  Location: "/path/to/negicco/05-enum-classes/test/enum_class.cpp:10:1"
  Comments:
    - @brief Hello, this is enum
  Members:
    - Name: Dog
      Value: 42
    - Name: Cat
      Value: 100
    - Name: Fish
      Value: 3

- DeclName: CStyleEnum
  Style: C-Style
  IntegerType: unsigned int
  QualifiedName: negicco::CStyleEnum
  Location: "/path/to/negicco/05-enum-classes/test/enum_class.cpp:20:1"
  Comments:
    - @brief C-style enum definition
    - @details This is detail comment
  Members:
    - Name: One
      Value: 0
    - Name: Two
      Value: 1
    - Name: Three
      Value: 2

- DeclName: UnsignedCharEnum
  Style: Scoped (C++11)
  IntegerType: unsigned char
  QualifiedName: negicco::UnsignedCharEnum
  Location: "/path/to/negicco/05-enum-classes/test/enum_class.cpp:26:1"
  Members:
    - Name: One
      Value: 1
      Comments:
        - @brief Hello one
    - Name: Two
      Value: 2
      Comments:
        - @brief Good morning two!
    - Name: Three
      Value: 3
      Comments:
        - @brief Hi three!!

- DeclName: Buki
  Style: Scoped (C++11)
  IntegerType: int
  QualifiedName: negicco::Fire::Ninja::Buki
  Location: "/path/to/negicco/05-enum-classes/test/enum_class.cpp:37:9"
  Members:
    - Name: Shuriken
      Value: 0
    - Name: Katana
      Value: 1
    - Name: Makibishi
      Value: 2
```
