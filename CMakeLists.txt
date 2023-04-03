
cmake_minimum_required(VERSION 3.0)
project (KittyLogs VERSION 1.0 LANGUAGES CXX)

find_package(Boost COMPONENTS system thread log REQUIRED)


add_definitions(-std=c++14)
add_definitions(-DBOOST_LOG_DYN_LINK)

add_library(kittyLogs INTERFACE)

target_include_directories(kittyLogs INTERFACE
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_include_directories(kittyLogs SYSTEM INTERFACE ${Boost_INCLUDE_DIRS})
target_compile_definitions(kittyLogs INTERFACE -DBOOST_LOG_DYN_LINK)
target_link_libraries(kittyLogs INTERFACE ${Boost_LOG_LIBRARY} ${Boost_THREAD_LIBRARY} ${Boost_SYSTEM_LIBRARY})

install(TARGETS kittyLogs LIBRARY DESTINATION ${KITTY_INSTALL_PATH}/lib)
INSTALL (DIRECTORY ${CMAKE_SOURCE_DIR}/include/ DESTINATION ${KITTY_INSTALL_PATH}/include FILES_MATCHING PATTERN "*.h*")


add_subdirectory(tests)

file(GLOB_RECURSE SRCS ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h )
add_library(not_a_main ${SRCS} fake_main.cpp)


