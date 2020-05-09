rm -rf ./bin
rm -rf ./*.o
gcc -c *.c
mkdir bin
gcc -o ./bin/$1 ./*.o
./bin/$1
rm -rf ./*.o  