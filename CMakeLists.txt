cmake_minimum_required(VERSION 3.14)
project(bookExperiment C)

set(CMAKE_C_STANDARD 99)

add_executable(bookExperiment main.c LinerList/orderStore.h LinerList/OrderStore/OrderStore.c LinerList/UnOrderStore/UnOrderStore.c LinerList/UnOrderstore.h Stack/StackSq.h Stack/StackSq.c Stack/StackLink.c)