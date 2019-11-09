main: *.cpp *.hpp 
	g++ *.cpp *.hpp -Wall -Werror -o main -lsfml-graphics -lsfml-window -lsfml-system

