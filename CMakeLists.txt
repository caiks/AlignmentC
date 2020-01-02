cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(AlignmentC)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(../rapidjson/include)

add_library(AlignmentC AlignmentUtil.cpp Alignment.cpp AlignmentApprox.cpp AlignmentAeson.cpp)

add_executable(AlignmentC_test main.cpp)

target_link_libraries(AlignmentC_test PUBLIC AlignmentC)

target_include_directories(AlignmentC_test PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          )

install(TARGETS AlignmentC DESTINATION lib)
install(FILES AlignmentUtil.h Alignment.h AlignmentApprox.h AlignmentAeson.h
  DESTINATION include
  )
