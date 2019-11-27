CC = gcc
CLIBS := -lsfml-graphics -lsfml-window -lsfml-system -lBox2D -lstdc++
CFLAGS := -Wall

SRCS = $(wildcard *.cpp)
SRCS += $(wildcard Objects/*.cpp)
SRCS += $(wildcard Components/*.cpp)

HDRS = $(wildcard Objects/*.hpp)
HDRS += $(wildcard Components/*.hpp)

OBJS = $(SRCS:%.cpp=%.o)

main: $(OBJS)
	@echo $(OBJS)
	$(CC) -o $@ $^ $(CLIBS) $(CFLAGS)

%.o: %.cpp
	$(CC) -c $< -o $@ 
	
%.o: %.hpp
	$(CC) -c $< -o $@ 


.PHONY: clean

clean:
	rm -rf ./main
	rm -rf main.o
	rm -rf Objects/*.o
	rm -rf Components/*.o
