LIBS = -lsfml-graphics -lsfml-window -lsfml-system
CFLAGS = -Wall -Werror

main:
	g++ *.cpp ${CFLAGS} -o $@ ${LIBS}
