#!/bin/sh

set -e

cmake \
    -B build \
    -S "$EXT_MOUNT/source" \
    -G Ninja \
    -DBUILD_TESTING=ON  \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=ON  \
    -DISO15118_COMPILE_OPTIONS_WARNING="-Wall;-Wextra;-Wno-unused-function"

ninja -j$(nproc) -C build

trap "cp build/Testing/Temporary/LastTest.log /ext/ctest-report" EXIT

ninja -j$(nproc) -C build test
