# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "ALIVE_autogen"
  "CMakeFiles\\ALIVE_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ALIVE_autogen.dir\\ParseCache.txt"
  )
endif()
