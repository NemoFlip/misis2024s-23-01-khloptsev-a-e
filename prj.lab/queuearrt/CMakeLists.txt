add_library(queuearrt INTERFACE queuearrt.hpp)
target_link_libraries(queuearrt INTERFACE complex)
set_property(TARGET queuearrt PROPERTY CXX_STANDARD 20)
target_include_directories(queuearrt INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
        $<INSTALL_INTERFACE:include>
)