cmake_minimum_required(VERSION 3.12)
project(AVLDictionary)

set(CMAKE_CXX_STANDARD 14)

add_executable(AVLDictionary main.cpp Data_Dictionary.h AVL_ADT.h Interface.h Dictionary_Node.h Search.h)