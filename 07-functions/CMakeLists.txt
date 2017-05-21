
cmake_minimum_required (VERSION 3.8)

set (TARGET_NAME negicco-07)
add_executable (${TARGET_NAME} main.cpp)
target_compile_features (${TARGET_NAME} PRIVATE cxx_std_14)
target_compile_definitions (${TARGET_NAME} PRIVATE ${LLVM_DEFINITIONS})
target_include_directories (${TARGET_NAME} PRIVATE ${LLVM_INCLUDE_DIRS})

target_link_libraries (${TARGET_NAME} PRIVATE clangTooling)
