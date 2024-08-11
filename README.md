# README

g++ -o log4cppapp src/main.cpp -L/usr/local/Cellar/log4cpp/1.1.3/lib -llog4cpp

g++ -o log4cppapp src/main.cpp $(pkg-config --cflags --libs log4cpp)


gcc -std=c11 src/mac_s.c -o mac_s
clang -std=c11 src/mac_s.c -o mac_s

https://www.apiref.com/cpp-zh/cpp/string/byte/strtok.html
https://www.apiref.com/cpp-zh/c/string/byte/strtok.html

mac系统
string.h文件只有strtok_r，没有strtok_s