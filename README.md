# AlignmentC

The AlignmentC repository is a literal C++ implementation of some of the set-theoretic functions and structures described in the paper *The Theory and Practice of Induction by Alignment* at https://greenlake.co.uk/. 

The AlignmentC repository is designed to be used with the fast implementation of *practicable inducers* in the [AlignmentRepaC repository](https://github.com/caiks/AlignmentRepaC).

## Installation

The `AlignmentC` module requires [modern C++](https://en.cppreference.com/w/) version 17 or later to be installed.

For example in Ubuntu,
```
sudo apt-get update -y
sudo apt install -y g++
```
Then download the zip file or use git to get the rapidjson and AlignmentC repositories -
```
git clone https://github.com/caiks/AlignmentC.git
```

## Build

Ubuntu release -
```sh
cd /home/cliff/Documents/projects/CAIKS4
git clone https://github.com/Tencent/rapidjson.git

cd AlignmentC

g++ -I../rapidjson/include -std=gnu++17 -O3 -o main main.cpp AlignmentUtil.cpp Alignment.cpp AlignmentApprox.cpp AlignmentAeson.cpp 

./main

```
Windows debug -
```sh
cd /d C:\zzz\caiks\AlignmentC-master

cl -IC:../rapidjson-master\include /EHsc /DEBUG /Zi main.cpp AlignmentUtil.cpp Alignment.cpp AlignmentApprox.cpp AlignmentAeson.cpp 

main
```
Windows release -
```sh
cd /d C:\zzz\caiks\AlignmentC-master

cl -IC:../rapidjson-master\include /EHsc /O2 main.cpp AlignmentUtil.cpp Alignment.cpp AlignmentApprox.cpp AlignmentAeson.cpp 

main
```

