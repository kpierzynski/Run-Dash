main: main.cpp Player.hpp Player.cpp Animation.hpp Animation.cpp
	g++ main.cpp Player.cpp Animation.cpp Level.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system

