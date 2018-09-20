# C++/CMake modern boilerplate
[![Travis build Status](https://travis-ci.org/Lectem/cpp-boilerplate.svg?branch=master)](https://travis-ci.org/Lectem/cpp-boilerplate)
[![Appveyor build status](https://ci.appveyor.com/api/projects/status/63mnrl1am9plfc4f/branch/master?svg=true)](https://ci.appveyor.com/project/Lectem/boilerplate/branch/master)
[![Coverage](https://codecov.io/gh/Lectem/cpp-boilerplate/branch/master/graph/badge.svg)](https://codecov.io/gh/Lectem/cpp-boilerplate)
[![CDash dashboard](https://img.shields.io/badge/CDash-Access-blue.svg)](http://my.cdash.org/index.php?project=cpp-boilerplate)
[![Pull requests](https://img.shields.io/github/issues-pr-raw/Lectem/cpp-boilerplate.svg)](https://github.com/Lectem/cpp-boilerplate/pulls)
[![Opened issues](https://img.shields.io/github/issues-raw/Lectem/cpp-boilerplate.svg)](https://github.com/Lectem/cpp-boilerplate/issues)

This is a template for new c++ projects for new projects. It demonstrates how to use modern CMake to set up a library properly, as well as how to define proper tests using catch. It also set ups some basic CI builds.
It uses "modern" CMake, ie 3.x paradigms, and should be a good starting point for both people willing to learn it and those that want to update/upgrade their CMakeLists.txt !
If you disagree with some pieces of advice given here, please discuss it with me by opening a Github Issue ! Enhancements are always welcome.

## Usage

If you want to bootstrap a new project you only need to :

 * If you don't already have your git repository setup
   - Simply copy/paste the folder (without the .git folder) and run the .bat file (renaming to .sh should work for linux). This will create an initial git commit and add the *required* submodules.
 * Hack CMakeLists.txt and CTestConfig.cmake to change the project name
 * Ready to go !

The CI providers used and that might need some setup :

 * Travis CI, for GCC / Clang on Linux/MacOS
 * AppVeyor, for MSVC on Windows
 * Codecov.io, for the codecoverage reports
 * CDash, for test and coverage reports using CTest. Can also be used to build nightlies.

## Requirements :

 * CMake 3.8.2 (Not needed for all scripts)
 * Git (for the submodules)
 * Any of the CI providers listed above if needed.

## Some features/notes :

 * Scripts lying in the cmake/ folder can be copy/pasted for use in any CMake project
 * Uses c++14
 * CopyDllsForDebug.cmake script : A small wrapper around fixup_bundle to copy DLLs to the output directory on windows
 * LTO.cmake script : Easier link time optimization configuration (should work on all CMake 3.x versions) as it used to be painful to setup.
 * Warnings.cmake script : A wrapper around common warning settings
 * Coverage.cmake : Test coverage script to add a 'Coverage' build type to CMake

## FAQ

__Q__: Why can't I link some new libraries I put inside the external folder ?

__A__: By default targets are not at the GLOBAL scope, which means your CMakelists.txt might not see it.
In this case you can either add an alias/imported library or use find_package/library as you would if the library was not in your buildtree.


__Q__: Should I always put my dependencies in the folder external

__A__: Absolutely not ! It is a great place for small libraries, but you probably don't want to have to rebuild big libs every time.
For those, you can use a package manager such as [Hunter](https://github.com/ruslo/hunter) or simply rely on find_package/library.



__Q__: Why are there so many subdirectories to all your code? Everything is so scattered!

__A__: While for this small project size it might indeed be an overkill, this approach scales well to larger
Projects with many modules/libraries. Separating sources and headers into separate directories tends to clear up the
code better, and make it easier to deploy all headers of a library. Adding another subdirectory for the include bundles the
headers even if they are deployed, i.e. after installation, headers will end up in "install/include/cool-lib" and "install/include/cool-header-lib" respectively.
