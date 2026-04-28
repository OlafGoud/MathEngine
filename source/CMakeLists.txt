cmake_minimum_required(VERSION 3.25)
project(Mathengine VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE 
  src/main.cpp
  src/tokenizer.cpp
  src/userinput.cpp  
)

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)
