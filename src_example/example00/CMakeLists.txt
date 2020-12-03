set(EXENAME example00)

set(SOURCES
    main.cpp
)

set(HEADERS
)

include_directories(
    ../../include
)

link_directories(
)

add_executable(${EXENAME} ${SOURCES})

set(LIBRARIES
    # Boost
    Boost::system
    Boost::filesystem

    BookFiler-Lib-image-to-hOCR-LibShared
)

if(WIN32)
    set(LIBRARIES ${LIBRARIES}
        # Windows Libraries

    )
elseif(UNIX)
    set(LIBRARIES ${LIBRARIES}
        # Unix Libraries
        dl
    )
endif()

target_link_libraries(${EXENAME} ${LIBRARIES})
