cmake_minimum_required(VERSION 3.22.1)

project(tarea_gpu)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(extern)
add_subdirectory(test)

enable_testing()

add_executable(tarea_1 main.cpp)

target_include_directories(tarea_1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# cmake_minimum_required(VERSION 3.16.3)
# project(playCircle)
# set(CMAKE_CXX_STANDARD 17)

# link_directories(${CMAKE_LIBRARY_PATH})

# add_executable(${PROJECT_NAME} main.cpp)

# #add_subdirectory(extern)
# add_subdirectory(src)
# #add_subdirectory(test)

# #quitar para evitar test
# enable_testing()

# target_link_libraries(${PROJECT_NAME} Point)

# cmake_minimum_required(VERSION 3.16.3)
# project(tarea1)
# set(CMAKE_CXX_STANDARD 17)

# link_directories(${CMAKE_LIBRARY_PATH})

# add_executable(${PROJECT_NAME} main.cpp)

# # Agregar el subdirectorio include a la lista de inclusión de encabezados
# add_subdirectory(src)


# target_link_libraries(${PROJECT_NAME} Point)