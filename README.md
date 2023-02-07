# ecostruxure

# Conan package manager

## Install
Install conan packages and create files for building.
Must be done before Build

### Release
```bash
ecostruxure $ conan install . --output-folder=build
```

### Debug
```bash
ecostruxure $ conan install . --output-folder=build -s build_type=Debug
```

# CMake
Change directory to build.

```bash
ecostruxure $ cd build
```

## Release
```bash
ecostruxure $ cmake .. --preset release
```

## Debug
```bash
ecostruxure $ cmake .. --preset debug
```

# Build

```bash
ecostruxure $ cmake --build . -- -j4
```

# Test
Build and execute GoogleTest.

```bash
ecostruxure/build/test $ conan install . --output-folder=build
```
```bash
ecostruxure/build/test $ cd build
ecostruxure/build/test $ cmake .. --preset=release
```
```bash
ecostruxure/build/test $ cmake --build . -- -j4
```
```bash
ecostruxure/build/test $ ./ecostruxureTest
```

# Import Projects

## Eclipse CDT
Import the projects to Eclipse CDT based on CMake as follows:

File -> Open Projects from File System...

## Wind River Workbench
Import the projects to the Wind River Workbench based on CMake as follows:

- Create a new CMake RTP project at folder ecostruxure
- revert changes to .gitignore
- revert changes to CMakeLists.txt

# Git
Delete all ignored/created files.

```bash
ecostruxure $ git clean -fxd
```