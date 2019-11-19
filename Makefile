LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lBox2D
CFLAGS = -Wall

main: main.cpp Objects/*.cpp Objects/*.hpp Components/*.cpp Components/*.hpp
	g++ $? ${CFLAGS} -o $@ ${LIBS}

clean:
	rm -rf ./main
