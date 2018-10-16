#!/bin/bash
echo -n "compile..."
g++ -std=c++11 -O2 -ojson11bench json11bench.cpp json11.cpp
g++ -std=c++11 -O2 -orapidbench -Iinclude rapidbench.cpp
flori c --opt=2 jsonbench.flori
echo " [done]"

echo "JSON parser benchmark"
echo -n "C++ (json11):"
./json11bench
echo -n "C++ (rapidjson):"
./rapidbench
echo -n "Flori:"
./jsonbench
