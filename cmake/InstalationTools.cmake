#[[ Construção e definição de pacotes config ]]#
include(GNUInstallDirs)
#------------------------------------------------- Defines -------------------------------------------------------
set(path_config " " CACHE STRING "CONFIG")
set(path_install " " CACHE STRING "INSTALL")
    if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
        set(path_config "/lib/cmake/Mosaicos")
        set(path_install "/usr/local/")
    elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Android")
        set(path_install "/data/data/com.termux/files/usr")       
        set(path_config "${path_install}/lib/cmake/Mosaicos")
        set(CMAKE_INSTALL_PREFIX "")
    else()
        set(path_config "${CMAKE_INSTALL_LIBDIR}/cmake/Mosaicos")
        set(path_install "${CMAKE_INSTALL_PREFIX}")
endif()

#--------------------------------------------- Instal Configures ---------------------------------------------
macro(install_file_config)
    
    include(CMakePackageConfigHelpers)
    
    # Definir arquivo de configuração:
    configure_package_config_file(
        "${CMAKE_CURRENT_LIST_DIR}/cmake/Config.cmake.in"
        "${CMAKE_BINARY_DIR}/Library/MosaicosConfig.cmake"
        INSTALL_DESTINATION ${path_config} 
    )
    
    # Definir versão da library:    
    write_basic_package_version_file(
        "${CMAKE_BINARY_DIR}/Library/MosaicosConfigVersion.cmake"
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY AnyNewerVersion
    )
    
    install(FILES
        "${CMAKE_BINARY_DIR}/Library/MosaicosConfig.cmake"
        "${CMAKE_BINARY_DIR}/Library/MosaicosConfigVersion.cmake"
        DESTINATION ${path_config}
    )
    
endmacro(install_file_config)


#--------------------------------------------- Install targets export ---------------------------------------------
macro(install_library)
    set(options OPTIONAL)
    set(oneValueArgs  VAR)
    set(multiValueArgs TARGETS_EXPORT)
    
    cmake_parse_arguments(install_library
        ${options}
        ${oneValueArgs}
        ${multiValueArgs}
        ${ARGN}
    )
    
    install(
        TARGETS ${install_library_TARGETS_EXPORT}
        EXPORT mosaico_export
        ARCHIVE 
                DESTINATION "${path_install}/lib"
                COMPONENT lib
        FILE_SET HEADERS 
                COMPONENT head
                DESTINATION "${path_install}/include/mosaicos"
    )
    
    
    foreach(item IN LISTS install_library_TARGETS_EXPORT)
        install(
            EXPORT mosaico_export
            FILE "${item}Target.cmake"
            NAMESPACE Mosaicos::
            DESTINATION ${path_config}
        )
    endforeach()
    
endmacro(install_library)
