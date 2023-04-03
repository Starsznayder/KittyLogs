find_package(Boost COMPONENTS system log REQUIRED)
find_package(Threads REQUIRED)


add_executable (test_logs test.cpp )
target_link_libraries(test_logs kittyLogs ${Boost_LOG_LIBRARY} ${Boost_SYSTEM_LIBRARY} Threads::Threads)

install(TARGETS test_logs DESTINATION ${KITTY_INSTALL_PATH}/tests)

