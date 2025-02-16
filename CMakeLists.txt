cmake_minimum_required(VERSION 3.22.1)
project(tcards)

include(CTest)

enable_testing()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)
add_subdirectory(tests)

add_test(NAME cards_card COMMAND cards_card_test)
add_test(NAME cards_deck COMMAND cards_deck_test)
