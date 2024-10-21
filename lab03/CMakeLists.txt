cmake_minimum_required(VERSION 3.25)
project(lab03)

# Установка стандарта C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Поиск и подключение GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Опциональные флаги компиляции (можно раскомментировать при необходимости)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra")

# Исходные файлы проекта
set(SOURCE_FILES
    src/main.cpp
    src/figure.cpp
    src/octagon.cpp
    src/square.cpp      # Добавляем файл для квадрата
    src/triangle.cpp    # Добавляем файл для треугольника
    src/FigureValidator.cpp
    src/OctagonValidator.cpp
    src/SquareValidator.cpp  # Добавляем валидатор для квадрата
    src/TriangleValidator.cpp # Добавляем валидатор для треугольника
    src/IFigureValidator.cpp
    src/point.cpp
)

# Создание исполняемого файла для основной программы
add_executable(task03 ${SOURCE_FILES})

# Настройка тестов
enable_testing()

# Исходные файлы для тестов
set(TEST_FILES
    src/tests.cpp
    src/figure.cpp
    src/octagon.cpp
    src/square.cpp      # Добавляем файл для квадрата
    src/triangle.cpp    # Добавляем файл для треугольника
    src/FigureValidator.cpp
    src/OctagonValidator.cpp
    src/SquareValidator.cpp  # Добавляем валидатор для квадрата
    src/TriangleValidator.cpp # Добавляем валидатор для треугольника
    src/IFigureValidator.cpp
    src/point.cpp
)

# Создание исполняемого файла для тестов
add_executable(tests03 ${TEST_FILES})

# Линковка с GTest
target_link_libraries(tests03 ${GTEST_LIBRARIES})

# Добавление тестов
add_test(NAME BASIC COMMAND tests03)
