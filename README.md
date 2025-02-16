
# TCARDS

A small card game in the terminal written in C++.

# 0.contents

1. Dependencies
2. Building
3. Testing

# 1. Dependencies

1. Standard C++ library
2. CMake
3. C++ compiler

# 2. Building

1. Create an output directory:  
`mkdir build`
2. Write build files to the output directory:  
`cmake -S . -B build`
3. Build with cmake:  
`cmake --build build`

# 3. Testing

Run tests: `ctest --test-dir build`
