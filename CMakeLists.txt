# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.8)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("BBE")

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
set(GLFW_USE_DWM_SWAP_INTERVAL ON CACHE BOOL "" FORCE)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(thirdparty/glfw)
add_subdirectory(thirdparty/glad)
add_subdirectory(thirdparty/glm)

add_executable(${PROJECT_NAME} "src/main.cpp" "src/Core/Window.h" "src/Core/Window.cpp" "src/Core/Application.h" "src/Core/Application.cpp" "src/Core/Cube.h" "src/Core/Cube.cpp" "src/Core/Shader.cpp" "src/Core/Shader.h" "src/Core/Camera.h" "src/Core/Camera.cpp" "src/Core/Graphics/Tranformable.h" "src/Core/Graphics/Tranformable.cpp" "src/Core/Triangle.h" "src/Core/Triangle.cpp" "src/Core/Graphics/VAO.h" "src/Core/Graphics/VAO.cpp" "src/Core/Graphics/VBO.h" "src/Core/Graphics/VBO.cpp" "src/Core/Graphics/EBO.h" "src/Core/Graphics/EBO.cpp")

find_package(OpenGL REQUIRED)

target_link_libraries(${PROJECT_NAME} glad)
target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} OpenGL::GL)
target_link_libraries(${PROJECT_NAME} glm)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${CMAKE_SOURCE_DIR}/shaders $<TARGET_FILE_DIR:${PROJECT_NAME}>/shaders)

