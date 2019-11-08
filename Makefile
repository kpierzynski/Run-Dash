main: main.cpp Player.hpp Player.cpp Animation.hpp Animation.cpp
	g++ *.cpp *.hpp -o main -lsfml-graphics -lsfml-window -lsfml-system

