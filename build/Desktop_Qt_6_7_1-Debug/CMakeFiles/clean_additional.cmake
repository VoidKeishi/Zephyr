# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Zephyr_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Zephyr_autogen.dir/ParseCache.txt"
  "Zephyr_autogen"
  )
endif()
