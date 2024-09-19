cmake_minimum_required(VERSION 3.10)
project(lab01)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавление опций компиляции
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=maybe-uninitialized")

# Установка Google Test
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.15.2
        TLS_VERIFY false
)

FetchContent_MakeAvailable(googletest)

# Добавляем библиотеку для решения (src/solution.cpp)
add_library(${CMAKE_PROJECT_NAME}_lib src/solution.cpp)

# Включаем директорию с заголовочными файлами
target_include_directories(${CMAKE_PROJECT_NAME}_lib PUBLIC include)

# Создание основного исполняемого файла (main.cpp)
add_executable(${CMAKE_PROJECT_NAME}_exe main.cpp)

# Линковка библиотеки с исполняемым файлом
target_link_libraries(${CMAKE_PROJECT_NAME}_exe PRIVATE ${CMAKE_PROJECT_NAME}_lib)

# Включаем поддержку тестов
enable_testing()

# Создание тестов (test/tests01.cpp)
add_executable(tests test/tests01.cpp)

# Линковка тестов с библиотекой и Google Test
target_link_libraries(tests ${CMAKE_PROJECT_NAME}_lib gtest_main)

# Добавление тестов в набор тестирования
add_test(NAME TestLab1 COMMAND tests)
