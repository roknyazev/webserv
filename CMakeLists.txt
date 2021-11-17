cmake_minimum_required(VERSION 3.0.2)
project(configParser)
# add_compile_options(-std=c++11)
set(CMAKE_CXX_STANDARD 98)

include_directories(
	config_handler/
	config_handler/config_objects/
	config_handler/config_objects/location_config/
	config_handler/config_objects/server_config/
	config_handler/config_parser/
	config_handler/object_data/
	logger/
)

set(CONFIG_CPP_FILES
	config_handler/ConfigHandler.cpp
	config_handler/config_objects/AConfigObject.cpp
	config_handler/config_objects/location_config/LocationConfObj.cpp
	config_handler/config_objects/server_config/ServerConfObj.cpp
	config_handler/config_parser/ConfigParserLL.cpp
	config_handler/object_data/ConfObjectData.cpp
)

set(LOGGER_CPP_FILES
	logger/Logger.cpp
)

add_library(config_lib STATIC ${CONFIG_CPP_FILES})
add_library(logger_lib STATIC ${LOGGER_CPP_FILES})

add_executable(bin_config main_test.cpp)

target_link_libraries(bin_config config_lib logger_lib)
