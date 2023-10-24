// gcc ncurses-2.c -o a.out -lncurses
#include <curses.h>
#include <string.h>

int main()
{
    char str[80];

    initscr();
    cbreak();
    echo();
    char hello[] = "Hello World!!! Welcome to COMP2113 Group 100's Escape Game!";
    mvprintw(LINES/2, (COLS-strlen(hello))/2, hello);
    mvprintw(10, 10, "Please enter something to continue:");

    getstr(str);

    //if (strcmp("5", str) == 0)
        //mvprintw(11, 10, "Correct\n");
    //else
        //mvprintw(11, 10, "Wrong\n");

    mvprintw(12, 10, "press any key to quit...");
    getch();
    endwin();
    return 0;
}