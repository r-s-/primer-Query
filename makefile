all:
	g++ TextQuery.cpp QueryResult.cpp RunQuery.cpp main.cpp -std=c++0x -Wall -o main.o
	