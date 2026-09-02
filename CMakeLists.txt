cmake_minimum_required(VERSION 3.15)

project(PankeyEngine_Type_Array)

if(NOT TARGET ThePankeyEngine_Type_Array)

    add_library(ThePankeyEngine_Type_Array INTERFACE)

    target_include_directories(
        ThePankeyEngine_Type_Array
          INTERFACE
            ${CMAKE_CURRENT_SOURCE_DIR}
    )

endif()