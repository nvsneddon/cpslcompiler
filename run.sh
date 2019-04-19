mkdir build;
cd build; 
cmake ..
make
mv cpsl ..
cd ..

if [ $# = 1 ]; then
    ./cpsl < $1 > out.asm
    java -jar ~/Desktop/Mars4_5.jar out.asm
    rm out.asm
elif [ $# = 2 ]; then 
    ./cpsl < $1 > $2
fi
