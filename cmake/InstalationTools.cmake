#[[ Construção e definição de pacotes config ]]#
include(GNUInstallDirs)
#------------------------------------------------- Defines -------------------------------------------------------
set(path_config)
if(UNIX)
        set(path_config "/lib/cmake/Mosaicos")
else()
        set(path_config "${CMAKE_INSTALL_LIBDIR}/cmake/Mosaicos")
endif()

#--------------------------------------------- Instal Configures ---------------------------------------------
macro(install_file_config)
    
    include(CMakePackageConfigHelpers)
    
    # Definir arquivo de configuração:
    configure_package_config_file(
        "${CMAKE_CURRENT_LIST_DIR}/cmake/Config.cmake.in"
        "${CMAKE_BINARY_DIR}/Library/MosaicosConfig.cmake"
        INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/Mosaicos" 
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
                DESTINATION ${CMAKE_INSTALL_LIBDIR}
                COMPONENT lib
        FILE_SET HEADERS 
                COMPONENT head
                DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/mosaicos
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
