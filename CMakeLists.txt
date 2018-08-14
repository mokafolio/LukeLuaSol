cmake_minimum_required (VERSION 2.8.11)
project (LukeLuaSol)
set(CMAKE_CXX_FLAGS "-std=c++14")

find_package(Lua 5.3 REQUIRED)
include_directories (${CMAKE_CURRENT_SOURCE_DIR} /usr/local/include ${LUA_INCLUDE_DIR})
link_directories(/usr/local/lib)

set (LUKELUADEPS Stick pthread ${LUA_LIBRARIES})

set (LUKELUAINC
LukeLuaSol/LukeLuaSol.hpp
)

install (FILES ${LUKELUAINC} DESTINATION /usr/local/include/LukeLuaSol)
#add_subdirectory (Tests)
