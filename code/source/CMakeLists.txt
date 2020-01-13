cmake_minimum_required(VERSION 3.10)
project(MyProject CXX)
add_library(
	KDTree
	Kd_tree.h
	Kd_tree.cpp
)
add_executable(out main.cpp)
set_target_properties(KDTree PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(out PRIVATE KDTree)



