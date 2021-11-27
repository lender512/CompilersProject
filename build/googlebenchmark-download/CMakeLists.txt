cmake_minimum_required(VERSION 2.8.2)

project(googlebenchmark-download NONE)

include(ExternalProject)
ExternalProject_Add(googlebenchmark-download
                    GIT_REPOSITORY;https://github.com/google/benchmark.git;GIT_TAG;main;UPDATE_DISCONNECTED 1
                    SOURCE_DIR          "/home/luis/Repos/Compilers/CompilersProject/build/googlebenchmark-src"
                    BINARY_DIR          "/home/luis/Repos/Compilers/CompilersProject/build/googlebenchmark-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
)
