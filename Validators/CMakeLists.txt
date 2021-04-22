cmake_minimum_required (VERSION 3.15)

project (Validators)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)
if (MSVC)
	add_compile_options (/W3 /permissive- /Zc:externConstexpr /Zc:inline)
endif ()

add_executable (Validators)

add_subdirectory (include)
add_subdirectory (src)