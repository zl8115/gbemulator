add_subdirectory(test)

add_executable(main
    main.cpp
    Cpu.cpp
    MemoryBus.cpp
    Registers.cpp
    CpuOperator.cpp
    CpuTranslator.cpp)
