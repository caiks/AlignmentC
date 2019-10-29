# AlignmentC
C++ implementation of aspects of the theory of Aligned Induction 

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
Ubuntu release -
```sh
cd /home/cliff/Documents/projects/CAIKS4
git clone https://github.com/Tencent/rapidjson.git

cd AlignmentC

g++ -I../rapidjson/include -std=gnu++17 -O3 -o main main.cpp AlignmentUtil.cpp Alignment.cpp AlignmentApprox.cpp AlignmentAeson.cpp 

./main

```
