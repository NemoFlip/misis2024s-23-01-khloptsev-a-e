add_library(queuelstprt INTERFACE queuelstprt.hpp)
target_link_libraries(queuelstprt INTERFACE complex)
set_property(TARGET queuelstprt PROPERTY CXX_STANDARD 20)
target_include_directories(queuelstprt INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
        $<INSTALL_INTERFACE:include>
)