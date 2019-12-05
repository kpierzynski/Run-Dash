.PHONY: clean

CC = gcc
CLIBS := -lsfml-graphics -lsfml-window -lsfml-system -lBox2D -lstdc++
CFLAGS := -Wall

SRCS = $(wildcard *.cpp)
SRCS += $(wildcard Objects/*.cpp)
SRCS += $(wildcard Components/*.cpp)
SRCS += $(wildcard Background/*.cpp)

HDRS = $(wildcard Objects/*.hpp)
HDRS += $(wildcard Components/*.hpp)
HDRS += $(wildcard Background/*.hpp)

OBJS = $(SRCS:%.cpp=%.o)

main: $(OBJS)
	@echo $(OBJS)
	$(CC) -o $@ $^ $(CLIBS) $(CFLAGS)

%.o: %.cpp
	$(CC) -c $< -o $@ 
	
%.o: %.hpp
	$(CC) -c $< -o $@ 

clean:
	rm -rf ./main
	rm -rf main.o
	rm -rf Objects/*.o
	rm -rf Components/*.o
