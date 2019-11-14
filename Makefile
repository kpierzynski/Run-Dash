LIBS = -lsfml-graphics -lsfml-window -lsfml-system
CFLAGS = -Wall

main: Objects/*.cpp Objects/*.hpp main.cpp
	g++ $? ${CFLAGS} -o $@ ${LIBS}

clean:
	rm -rf ./main
