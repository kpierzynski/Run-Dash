main: main.cpp Player.hpp Player.cpp Animation.hpp Animation.cpp GameObject.hpp GameObject.cpp Platform.hpp Platform.cpp Physics.hpp Physics.cpp
	g++ main.cpp Player.cpp Animation.cpp GameObject.cpp Platform.cpp Physics.cpp -Wall -o main -lsfml-graphics -lsfml-window -lsfml-system

