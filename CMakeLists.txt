cmake_minimum_required(VERSION 3.21)

project(regex-builder VERSION 0.1.0)

include (${CMAKE_CURRENT_LIST_DIR}/_cmake/common_options.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/dependencies/Nui/cmake/dependencies/nlohmann_json.cmake)

# Add executable (sources are added later, depending on frontend/backend)
add_executable(${PROJECT_NAME})
set_common_options(${PROJECT_NAME})

set(PREJS_FILE ${CMAKE_SOURCE_DIR}/frontend/source/frontend/js/module.js)

# Add dependencies (checked out)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/dependencies/webview)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/dependencies/nui)

if (EMSCRIPTEN)  
    add_subdirectory(${CMAKE_SOURCE_DIR}/frontend/source/frontend)
else()
	add_subdirectory(${CMAKE_SOURCE_DIR}/backend/source/backend)

    # If msys2, copy dynamic libraries to executable directory, visual studio does this automatically.
    # And there is no need on linux.
    if (DEFINED ENV{MSYSTEM})
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND bash -c "ldd $<TARGET_FILE:${PROJECT_NAME}>" | "grep" "clang" | awk "NF == 4 { system(\"${CMAKE_COMMAND} -E copy \" \$3 \" $<TARGET_FILE_DIR:${PROJECT_NAME}>\") }"
            VERBATIM
        )
    endif()
endif()