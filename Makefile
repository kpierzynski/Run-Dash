main: *.cpp *.hpp
	g++ *.cpp -Wall -o main -lsfml-graphics -lsfml-window -lsfml-system -lBox2D

