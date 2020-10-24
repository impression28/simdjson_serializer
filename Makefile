all: main.cpp
	g++ main.cpp -o main -lsimdjson
benchmark: benchmark.cpp
	g++ benchmark.cpp -std=c++17 -O3 -lsimdjson -lbenchmark -lpthread -o benchmark
