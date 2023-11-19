all: compile link

compile:
	g++ -c main.cpp shapes.cpp

link:
	g++ main.o shapes.o -o main -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio