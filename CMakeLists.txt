cmake_minimum_required(VERSION 3.16)
project(CipheFile LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(CipheFile
    src/main.cpp
    src/core/FileManager.cpp
    src/crypto/CryptoContext.cpp
    src/crypto/Argon2KDF.cpp
    src/crypto/ChaCha20Cipher.cpp
)

# libsodium (vcpkg)
find_package(unofficial-sodium CONFIG REQUIRED)
target_link_libraries(CipheFile PRIVATE unofficial-sodium::sodium)

# Includes
target_include_directories(CipheFile PRIVATE src)