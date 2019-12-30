cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(AlignmentC)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(../rapidjson/include)

add_library(libAlignmentC AlignmentUtil.cpp Alignment.cpp AlignmentApprox.cpp AlignmentAeson.cpp)

add_executable(AlignmentC main.cpp)

target_link_libraries(AlignmentC PUBLIC libAlignmentC)

target_include_directories(AlignmentC PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          )

install(TARGETS AlignmentC DESTINATION bin)
install(TARGETS libAlignmentC DESTINATION lib)
install(FILES AlignmentUtil.h Alignment.h AlignmentApprox.h AlignmentAeson.h
  DESTINATION include
  )
