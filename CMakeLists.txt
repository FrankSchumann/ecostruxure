cmake_minimum_required(VERSION 3.15)

# Set some basic project attributes
project (ecostruxure
		VERSION 0.0.0.7
		DESCRIPTION "EcoStruxure Runtime plugin")
		
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES "src/Plugin.cpp" "src/*/*.cpp")

find_package(osal REQUIRED)
find_package(runtime REQUIRED)

add_library(${PROJECT_NAME} SHARED ${SOURCES})

# Create a simple configuration header
configure_file(config.h.in config.h)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR} include ${osal_INCLUDE_DIR} ${runtime_INCLUDE_DIR})

message("CMAKE_PROJECT_VERSION = ${CMAKE_PROJECT_VERSION}")

set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})

IF(EXISTS "${WIND_CC_SYSROOT}/secureLoader/privatekey.pem")
	IF(EXISTS "${WIND_CC_SYSROOT}/secureLoader/publiccert.pem")
		add_custom_command(TARGET ${MY_TARGET} POST_BUILD
			COMMAND echo "start singtool command ..."
			COMMAND signtool --strip=all --key=${WIND_CC_SYSROOT}/secureLoader/privatekey.pem --cert=${WIND_CC_SYSROOT}/secureLoader/publiccert.pem --type=ELF ${MY_TARGET}
			COMMENT  "end singtool command ..."
		)
	ENDIF()
ENDIF()
