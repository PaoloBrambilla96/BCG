######################################################################
# CMakeLists.txt generated for component Carware_final2
# Product type: executable
######################################################################
cmake_minimum_required(VERSION 3.12)
project(Carware_final2)
if(DEFINED ENV{CMAKE_EXPORT_COMPILE_COMMANDS} AND NOT DEFINED CMAKE_EXPORT_COMPILE_COMMANDS)
    set(CMAKE_EXPORT_COMPILE_COMMANDS $ENV{CMAKE_EXPORT_COMPILE_COMMANDS})
endif()


######################################################################
## Path variables
######################################################################
get_filename_component(START_DIR .. ABSOLUTE)
set(MATLAB_ROOT /home/ubuntu/BCG/bcg_website/autoparts/simulation_files/R2023a CACHE PATH "")
if(${CMAKE_CURRENT_BINARY_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
    set(BUILDING_IN_SOURCE_DIR TRUE)
    set(BINARY_START_DIR "${START_DIR}")
else()
    set(BUILDING_IN_SOURCE_DIR FALSE)
    set(BINARY_START_DIR "${CMAKE_BINARY_DIR}")
endif()
if(WIN32 AND NOT MINGW)
    set(SYSLIB_PREFIX "lib")
else()
    set(SYSLIB_PREFIX "")
endif()

######################################################################
## System libraries
######################################################################
find_library(FOUND_LIBM m NO_SYSTEM_ENVIRONMENT_PATH PATHS ${CMAKE_C_IMPLICIT_LINK_DIRECTORIES}
    ${CMAKE_CXX_IMPLICIT_LINK_DIRECTORIES})

######################################################################
## Target definition and commands
######################################################################
add_executable(Carware_final2  ${MATLAB_ROOT}/rtw/c/src/rt_logging.c
    ${START_DIR}/Carware_final2_grt_rtw/Carware_final2.c
    ${START_DIR}/Carware_final2_grt_rtw/Carware_final2_data.c
    ${START_DIR}/Carware_final2_grt_rtw/rtGetInf.c
    ${START_DIR}/Carware_final2_grt_rtw/rtGetNaN.c
    ${START_DIR}/Carware_final2_grt_rtw/rt_nonfinite.c
    ${MATLAB_ROOT}/rtw/c/src/common/rt_main.c)
set_target_properties(Carware_final2 PROPERTIES
    PREFIX ""
    POSITION_INDEPENDENT_CODE ON
    RUNTIME_OUTPUT_DIRECTORY "${BINARY_START_DIR}/./$<0:>"
    LIBRARY_OUTPUT_DIRECTORY "${BINARY_START_DIR}/./$<0:>"
    ARCHIVE_OUTPUT_DIRECTORY "${BINARY_START_DIR}/./$<0:>")
target_compile_features(Carware_final2 PUBLIC c_std_99)
target_compile_definitions(Carware_final2 PRIVATE -DMODEL=Carware_final2
    -DNUMST=2
    -DNCSTATES=11
    -DHAVESTDIO
    -DRT
    -DUSE_RTMODEL
    -DCLASSIC_INTERFACE=0
    -DALLOCATIONFCN=0
    -DTID01EQ=1
    -DMAT_FILE=1
    -DONESTEPFCN=1
    -DTERMFCN=1
    -DMULTI_INSTANCE_CODE=0
    -DINTEGER_CODE=0
    -DMT=0)
target_include_directories(Carware_final2 PRIVATE ${START_DIR}
    ${START_DIR}/Carware_final2_grt_rtw
    ${MATLAB_ROOT}/extern/include
    ${MATLAB_ROOT}/simulink/include
    ${MATLAB_ROOT}/rtw/c/src
    ${MATLAB_ROOT}/rtw/c/src/ext_mode/common)
target_link_libraries(Carware_final2 PRIVATE $<$<BOOL:${FOUND_LIBM}>:m>)
if(WIN32)
   target_link_libraries(Carware_final2 PRIVATE kernel32
       ws2_32
       mswsock
       advapi32)
endif()

######################################################################
## Extract debug symbols
######################################################################
if(APPLE AND (CMAKE_C_COMPILER_ID STREQUAL "AppleClang"))
    string(APPEND _dsymutilcmd "$<IF:$<CONFIG:DEBUG,RELWITHDEBINFO>,"
                "xcrun;dsymutil;$<TARGET_FILE:Carware_final2>;--flat,"
                "true"
        >)
    add_custom_command(TARGET Carware_final2
            POST_BUILD
            COMMAND "${_dsymutilcmd}"
            COMMAND_EXPAND_LISTS
            BYPRODUCTS Carware_final2.dwarf)
endif()


######################################################################
## Build success message
######################################################################
add_custom_command(TARGET Carware_final2 POST_BUILD
     COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --cyan "\\#\\#\\# Created executable: $<TARGET_FILE:Carware_final2>")

######################################################################
## Call toolchain hook function if defined
######################################################################
if(COMMAND toolchain_target_hook)
    toolchain_target_hook(Carware_final2)
endif()
