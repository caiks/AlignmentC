# AlignmentC

The AlignmentC repository is a literal C++ implementation of some of the set-theoretic functions and structures described in the paper *The Theory and Practice of Induction by Alignment* at https://greenlake.co.uk/. 

The AlignmentC repository is designed to be used with the fast implementation of *practicable inducers* in the [AlignmentRepaC repository](https://github.com/caiks/AlignmentRepaC).

## Download

The `AlignmentC` module requires [modern C++](https://en.cppreference.com/w/) version 17 or later to be installed.

For example, in Ubuntu bionic (18.04),
```
sudo apt-get update -y && sudo apt install -y git g++ cmake

```
Then download the zip file or use git to get the rapidjson and AlignmentC repositories -
```
git clone https://github.com/Tencent/rapidjson.git
git clone https://github.com/caiks/AlignmentC.git

```

## Build

Ubuntu debug -
```sh
mkdir AlignmentC_build
cd AlignmentC_build
cmake -DCMAKE_BUILD_TYPE=DEBUG ../AlignmentC
make

```
Ubuntu release -
```sh
mkdir AlignmentC_build
cd AlignmentC_build
cmake -DCMAKE_BUILD_TYPE=RELEASE ../AlignmentC
make

```
Windows debug -
```sh
mkdir AlignmentC_build
cd /d AlignmentC_build
"C:\Program Files\CMake\bin\cmake" -G "Visual Studio 14 2015" -A x64 ../AlignmentC
"C:\Program Files\CMake\bin\cmake" --build . --config Debug

```
Windows release -
```sh
mkdir AlignmentC_build
cd /d AlignmentC_build
"C:\Program Files\CMake\bin\cmake" -G "Visual Studio 14 2015" -A x64 ../AlignmentC
"C:\Program Files\CMake\bin\cmake" --build . --config Release

```

## Usage

Ubuntu -
```sh
cd ..
mkdir AlignmentC_ws
cd AlignmentC_ws
../AlignmentC_build/AlignmentC_test 

```
Windows debug -
```sh
cd ..
mkdir AlignmentC_ws
cd AlignmentC_ws
..\AlignmentC_build\Debug\AlignmentC_test.exe

```
Windows release -
```sh
cd ..
mkdir AlignmentC_ws
cd AlignmentC_ws
..\AlignmentC_build\Release\AlignmentC_test.exe 

```

