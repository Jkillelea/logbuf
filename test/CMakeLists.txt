add_executable(test
    maintest.c
)

target_link_libraries(test
    PRIVATE
        logbuf
)
