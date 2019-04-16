mkdir makefiles;
cd makefiles
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
mv cpsl ..
cd ..
gdb cpsl