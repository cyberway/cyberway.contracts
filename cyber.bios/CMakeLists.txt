add_contract_with_checked_abi(cyber.bios cyber.bios cyber.bios.abi ${CMAKE_CURRENT_SOURCE_DIR}/src/cyber.bios.cpp)
install_contract(cyber.bios)

target_include_directories(cyber.bios.wasm
   PUBLIC
   ${CMAKE_CURRENT_SOURCE_DIR}/../cyber.govern/include
   ${CMAKE_CURRENT_SOURCE_DIR}/../cyber.stake/include
   ${CMAKE_CURRENT_SOURCE_DIR}/../cyber.token/include
   ${CMAKE_CURRENT_SOURCE_DIR}/include
   ${CMAKE_CURRENT_SOURCE_DIR}/..)

set_target_properties(cyber.bios.wasm
   PROPERTIES
   RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}")
