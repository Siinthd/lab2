cmake_minimum_required(VERSION 3.5)

project(ip_filter)


# configure directories
set(SOURCE_PATH "${PROJECT_SOURCE_DIR}/src")
set(TEST_PATH "${PROJECT_SOURCE_DIR}/test")

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(ip_filter ${SOURCE_PATH}/main.cpp
			 ${SOURCE_PATH}/ip_filter.cpp	)

add_executable(test_filter ${TEST_PATH}/test_filter.cpp
			${SOURCE_PATH}/ip_filter.cpp)


set_target_properties(ip_filter PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
        )
        

set_target_properties(test_filter PROPERTIES
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
    )
    
target_include_directories(test_filter PUBLIC src)
    
target_link_libraries(test_filter
    ${Boost_LIBRARIES}
)

target_compile_options(test_filter PRIVATE
    -Wall -Wextra -pedantic -Werror
)
    

install(TARGETS ip_filter RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

include(CPack)

enable_testing()
add_test(Filter test_filter)
