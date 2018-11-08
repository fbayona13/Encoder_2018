cmake_minimum_required(VERSION 3.10)
project(Encoder_2018_master)

set(CMAKE_CXX_STANDARD 11)

include_directories(Encoder_2018-master/NewProject)

add_executable(Encoder_2018_master
        .idea/codeStyles/Project.xml
        .idea/.name
        .idea/Encoder_2018-master.iml
        .idea/misc.xml
        .idea/modules.xml
        .idea/workspace.xml
        cmake-build-debug/cmake_install.cmake
        cmake-build-debug/CMakeCache.txt
        cmake-build-debug/Encoder_2018_master.cbp
        cmake-build-debug/Makefile
        Encoder_2018-master/.idea/codeStyles/codeStyleConfig.xml
        Encoder_2018-master/.idea/codeStyles/Project.xml
        Encoder_2018-master/.idea/.name
        Encoder_2018-master/.idea/Encoder_2018.iml
        Encoder_2018-master/.idea/misc.xml
        Encoder_2018-master/.idea/modules.xml
        Encoder_2018-master/.idea/vcs.xml
        Encoder_2018-master/.idea/workspace.xml
        Encoder_2018-master/NewProject/ArbolBinario.h
        Encoder_2018-master/NewProject/codifica.cpp
        Encoder_2018-master/NewProject/codifica.h
        Encoder_2018-master/NewProject/main.cpp
        Encoder_2018-master/NewProject/NodoDic_1.h
        CMakeLists.txt)
