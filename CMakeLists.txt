cmake_minimum_required(VERSION 3.4.1)
project(BOSSAC)
include_directories(${CMAKE_CURRENT_LIST_DIR}/src)

MESSAGE(STATUS "operation system is ${CMAKE_SYSTEM}")

if(WIN32)
set(PORT	
	${CMAKE_CURRENT_LIST_DIR}/src/WinPortFactory.cpp
	${CMAKE_CURRENT_LIST_DIR}/src/WinSerialPort.cpp
	)
elseif(APPLE)
set(PORT	
	${CMAKE_CURRENT_LIST_DIR}/src/OSXPortFactory.cpp
	${CMAKE_CURRENT_LIST_DIR}/src/PosixSerialPort.cpp
	)
else()
set(PORT	
	${CMAKE_CURRENT_LIST_DIR}/src/LinuxPortFactory.cpp
	${CMAKE_CURRENT_LIST_DIR}/src/PosixSerialPort.cpp
	)
endif()


add_executable(bossac
	${CMAKE_CURRENT_LIST_DIR}/src/bossac.cpp
	${CMAKE_CURRENT_LIST_DIR}/src/Device.cpp
	${CMAKE_CURRENT_LIST_DIR}/src/Flash.cpp
	${CMAKE_CURRENT_LIST_DIR}/src/Flasher.cpp
	${CMAKE_CURRENT_LIST_DIR}/src/IMXRTFlash.cpp
	${CMAKE_CURRENT_LIST_DIR}/src/Samba.cpp
	${CMAKE_CURRENT_LIST_DIR}/src/WordCopyApplet.cpp
	${CMAKE_CURRENT_LIST_DIR}/src/WordCopyArm.cpp
	${CMAKE_CURRENT_LIST_DIR}/src/D2xNvmFlash.cpp
	${CMAKE_CURRENT_LIST_DIR}/src/D5xNvmFlash.cpp
	${CMAKE_CURRENT_LIST_DIR}/src/EefcFlash.cpp
	${CMAKE_CURRENT_LIST_DIR}/src/EfcFlash.cpp
	${CMAKE_CURRENT_LIST_DIR}/src/CmdOpts.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/Applet.cpp
	${PORT}
	)
