# Example CMAKE file for CXX project

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(ParallelPi)

enable_testing()

set(PARALLEL_PI_LIB parallelpi)
set(PARALLEL_PI_INCLUDE ${PROJECT_SOURCE_DIR}/include)
set(PARALLEL_PI_SOURCE ${PROJECT_SOURCE_DIR}/src)
set(PARALLEL_PI_TEST ${PROJECT_SOURCE_DIR}/test)

#Uncomment to make makefiles verbose
#set(CMAKE_VERBOSE_MAKEFILE ON)

option(BUILD_CILK "Build cilk code" ON)
option(BUILD_OPENMP "Build OpenMP code" ON)

set(CILK_INCLUDE_DIR "" CACHE FILEPATH "Directory where the cilk forlder is located")
set(CILK_LIBRARY_DIR "" CACHE FILEPATH "Directory where the cilk library is located")

if(BUILD_CILK)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DPARALLEL_PI_USE_CILK -I${CILK_INCLUDE_DIR} -L${CILK_LIBRARY_DIR} -fcilkplus -lcilkrts")
endif()

if(BUILD_OPENMP)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DPARALLEL_PI_USE_OMP -fopenmp")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DNDEBUG -O3")

#Source Code
add_subdirectory(${PARALLEL_PI_SOURCE})
include_directories(${PARALLEL_PI_INCLUDE})

# Exe
add_library(${PARALLEL_PI_LIB} ${SOURCE_FILES})

add_subdirectory(${PARALLEL_PI_TEST})
