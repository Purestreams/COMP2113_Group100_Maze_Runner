flags=-pedantic-errors -std=c++11 -lncurses

maze_generator.o: maze_generator.cpp maze_generator.h
	g++ $(flags) -c $<

main.o: main.cpp main.h
	g++ $(flags) -c $<

main: main.o maze_generator.o
	g++ $(flags) $^ -o $@

clean:
	rm -f main main.o maze_generator.o maze_generator.tgz

.PHONY:clean