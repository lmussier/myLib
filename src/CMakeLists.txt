#Use our public headers like anyone else 
include_directories(../public/include)

set(SRCS
    MyLib.cpp
    FirstObject.cpp
    )

add_library(myLibShared SHARED ${SRCS})
add_library(myLibStatic STATIC ${SRCS})

#Set an apropriate name for the libs
set_target_properties(myLibShared PROPERTIES OUTPUT_NAME ${PROJECT_NAME})
set_target_properties(myLibStatic PROPERTIES OUTPUT_NAME ${PROJECT_NAME})

target_include_directories(myLibShared PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../public/include>
    $<INSTALL_INTERFACE:include>
    PRIVATE src)
    
target_include_directories(myLibStatic PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../public/include>
    $<INSTALL_INTERFACE:include>
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

#set the version of the shared lib
set_target_properties(myLibShared PROPERTIES VERSION ${PROJECT_VERSION_MAJOR} SOVERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH})

install(TARGETS myLibShared myLibStatic EXPORT myLibConfig 
                                        LIBRARY DESTINATION lib/${PROJECT_NAME}
                                        ARCHIVE DESTINATION lib/${PROJECT_NAME}
                                        RUNTIME DESTINATION bin/${PROJECT_NAME} )

install(DIRECTORY ../public/include/myLib DESTINATION include)

# This makes the project importable from the install directory
# Put config file in per-project dir (name MUST match), can also
# just go into <prefix>/cmake.
install(EXPORT myLibConfig DESTINATION share/${PROJECT_NAME}/cmake)

