cmake_minimum_required(
  VERSION 3.11
)


project(prog)
add_executable(prog main.cxx)

set_property(TARGET prog PROPERTY CXX_STANDARD 20)

find_package(Python3 COMPONENTS Development NumPy)
find_package(Eigen3 REQUIRED NO_MODULE)
find_package(fmt REQUIRED)

target_include_directories(prog 
  PRIVATE ${Python3_INCLUDE_DIRS} ${Python3_Numpy_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/includes
)
target_link_libraries(prog Python3::Python Python3::NumPy Eigen3::Eigen fmt pthread)
