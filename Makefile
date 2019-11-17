LIBS = -lsfml-graphics -lsfml-window -lsfml-system
CFLAGS = -Wall

main: main.cpp Objects/*.cpp Objects/*.hpp
	g++ $? ${CFLAGS} -o $@ ${LIBS}

clean:
	rm -rf ./main
