# ecostruxure

EcoStruxure Automation Expert Runtime Adapter

# Import Projects

## Eclipse CDT
Import the projects to Eclipse CDT based on CMake as follows:

File -> Open Projects from File System...

## Wind River Workbench
Import the projects to the Wind River Workbench based on CMake as follows:

- Create a new CMake RTP project at folder codesys
- revert changes to .gitignore
- revert changes to CMakeLists.txt

# Conan package manager

## Conan

```bash
osal-linux $ conan install . --output-folder=build 
```

## Build

```bash
osal-linux $ cd build
osal-linux $ cmake .. -DCMAKE_PREFIX_PATH=$(pwd)
osal-linux $ cmake --build . 
```

## Git
Delete all ignored/created files.

```bash
osal-linux $ git clean -fxd
```