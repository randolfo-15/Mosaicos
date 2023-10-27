# Construção e definição de pacotes config:

function(install_file_config)

    include(CMakePackageConfigHelpers)
    #include(CMakeFindDependencyMacro)
    
    # Definir arquivo de configuração:
    
    configure_package_config_file(
        "${CMAKE_CURRENT_LIST_DIR}/cmake/Config.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/MosaicosConfig.cmake"
        INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/Mosaicos" 
    )
    message(STATUS "Arquivo de configuração - OK ")
    # Definir versão da library:    
    
    write_basic_package_version_file(
        "${CMAKE_CURRENT_BINARY_DIR}/MosaicosConfigVersion.cmake"
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY AnyNewerVersion
    )
     message(STATUS "Arquivo de versão - OK ")
endfunction(install_file_config)
