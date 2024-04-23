set(CMAKE_CXX_STANDARD 20)
add_executable(timing_q timing_q.cpp)
target_link_libraries(timing_q queuelst)
target_include_directories(timing_q PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
        $<INSTALL_INTERFACE:include>
)
install(TARGETS timing_q)