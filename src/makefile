maze_generator.o: maze_generator.cpp maze_generator.h
	g++ -pedantic-errors -std=c++11 -c $<

main.o: main.cpp main.h
	g++ -pedantic-errors -std=c++11 -c $< -lncurses

main: main.o maze_generator.o
	g++ -pedantic-errors -std=c++11 $^ -o $@ -lncurses

clean:
	rm -f main main.o maze_generator.o maze_generator.tgz

.PHONY:clean