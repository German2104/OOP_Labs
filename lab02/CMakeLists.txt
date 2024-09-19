cmake_minimum_required(VERSION 3.10)
project(lab02)

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

# Добавляем библиотеку для решения
add_library(lab02_lib src/solution.cpp)

# Включаем директорию с заголовочными файлами
target_include_directories(lab02_lib PUBLIC include)

# Создание основного исполняемого файла
add_executable(lab02_exe main.cpp)

# Линковка библиотеки с исполняемым файлом
target_link_libraries(lab02_exe PRIVATE lab02_lib)

# Включаем поддержку тестов
enable_testing()

# Создание тестов
add_executable(lab02_tests test/tests01.cpp)

# Линковка тестов с библиотекой и Google Test
target_link_libraries(lab02_tests lab02_lib gtest_main)

# Добавление тестов в набор тестирования
add_test(NAME TestLab2 COMMAND lab02_tests)
