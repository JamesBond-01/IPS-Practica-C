cmake_minimum_required(VERSION 3.22)
project(Algorithms_Tests C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Algorithms_Tests
        binarySearch.c
        bubbleSort.c
        insertionSort.c
        mergeSort.c
        quickSort.c)
