#include <cstring> // add this header for strlen
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <cstdlib> // add this header for randomly changing position of the key
#include <fstream>
#include <ctime>
#include <string>
#include <cstring> // add this header for strlen
#include <ncurses.h> // add this header for mvprintw and wgetnstr
#include "main.h"
#include "maze_generator.h"

using namespace std;

//using string instead of char array anytime possible
//use cpp style casting instead of c style casting
//This project is aim to develop a game by using ncurses library
//The knight is trapped in a maze and he needs to escape from the maze by finding the key
//using dynamic memory allocation to store the maze


//define function portal
//if the knight steps on the portal, he will be randomly tp to another place
void portal(int &x, int &y, int **maze){
    int i = rand()%30;
    int j = rand()%30;
    while(maze[i][j] == 0){ //error here because maze is not defined
        i = rand()%30;
        j = rand()%30;
    }
    mvprintw(x+1, y+1, ".");
    x = i;
    y = j;
    mvprintw(x+1, y+1, "X");
}

//define function find_treasure
//if the knight finds the treasure box, he will get extra point from 100 to 200

int main()
{
    char str[80];

    initscr();
    cbreak();
    echo();


    //initial the main menu of the game
    //press enter to start the game
    //press q to quit the game
    mvprintw(0, 0, "Press E to start the game! Press Q to quit the game!");
    mvprintw(1, 0, "This is the group project of COMP2113 in 2023 by Group 100");
    mvprintw(2, 0, "The game is developed by Purestreams, STARQUANTUM, Lydialkx, ActuaryLmao and Mingyue13");

                                                                                                                
                                                                                                                                                                                                                         

    int location = 0;

    while (true) {
        mvprintw(10,10, "         :::   :::       :::     ::::::::: ::::::::::          :::::::::  :::    ::: ::::    ::: ::::    ::: :::::::::: :::::::::");
        mvprintw(11,10, "       :+:+: :+:+:    :+: :+:        :+:  :+:                 :+:    :+: :+:    :+: :+:+:   :+: :+:+:   :+: :+:        :+:    :+:");
        mvprintw(12,10, "     +:+ +:+:+ +:+  +:+   +:+      +:+   +:+                 +:+    +:+ +:+    +:+ :+:+:+  +:+ :+:+:+  +:+ +:+        +:+    +:+");
        mvprintw(13,10, "    +#+  +:+  +#+ +#++:++#++:    +#+    +#++:++#            +#++:++#:  +#+    +:+ +#+ +:+ +#+ +#+ +:+ +#+ +#++:++#   +#++:++#:");
        mvprintw(14,10, "   +#+       +#+ +#+     +#+   +#+     +#+                 +#+    +#+ +#+    +#+ +#+  +#+#+# +#+  +#+#+# +#+        +#+    +#+");
        mvprintw(15,10, "  #+#       #+# #+#     #+#  #+#      #+#                 #+#    #+# #+#    #+# #+#   #+#+# #+#   #+#+# #+#        #+#    #+#");
        mvprintw(16,10, " ###       ### ###     ### ######### ##########          ###    ###  ########  ###    #### ###    #### ########## ###    ###");

        //create a menu of start the game , score board and quit the game
        mvprintw(20, 10, "Start the game");
        mvprintw(21, 10, "Score board");
        mvprintw(22, 10, "View the instruction");
        mvprintw(23, 10, "Quit the game");
        //handle the input
        char input = getch();
        //make input invisible
        noecho();

        if (input == 'e') {
            if (location == 0) {
                //clean all the previous display
                clear();
                break;
            }
            else if (location ==1){
                //display the score board
                //read the file record.txt
                ifstream fin;
                fin.open("record.txt");
                string name[100];
                int score[100];
                int i = 0;
                while(fin >> name[i] >> score[i]){
                    i++;
                }
                for(int j=0;j<i;j++){
                    for(int k=0;k<i-j-1;k++){
                        if(score[k] < score[k+1]){
                            int temp = score[k];
                            score[k] = score[k+1];
                            score[k+1] = temp;
                            string temp1 = name[k];
                            name[k] = name[k+1];
                            name[k+1] = temp1;
                        }
                    }
                }
                fin.close();
                //display the top 10 scores in record.txt
                //if EOL is reached, stop displaying
                mvprintw(30, 50, "Top 10 scores:");
                for(int j=0;j<10;j++){
                    mvprintw(31+j, 50, "%s %d", name[j].c_str(), score[j]);
                }
                getch();
                endwin();
                return 0;
            }
            else if (location == 2) {
                //display the instruction
                mvprintw(30, 50, "The knight is trapped in a maze and he needs to escape from the maze by finding the key");
                mvprintw(31, 50, "Use a to move left, d to move right, w to move up, s to move down");
                mvprintw(32, 50, "The knight will move until he finds the key and the exit");
                mvprintw(34, 50, "* If the knight finds the treasure box, he will get extra point from 100 to 200 and lose 20 steps");
                mvprintw(35, 50, "* If the knight meets the monster, he will get extra 10 steps");
                mvprintw(37, 50, "The score is calculated by the number of steps the player takes and time taken to complete the game");
                mvprintw(38, 50, "The player can get extra points by finding special items");
                mvprintw(39, 50, "The player can press q to quit the game anytime");
                mvprintw(40, 50, "Press any key to return to the main menu");
                getch();
                clear();
            }
            else if (location == 3) {
                endwin();
                return 0;
            }
        }


        //move the cursor up and down
        if (input == 'w') {
            //clean the previous cursor
            mvprintw(20 + location, 8, " ");
            location--;
            mvprintw(20 + location, 8, "*");
            if (location < 0) {
                //clean the previous cursor
                mvprintw(20 + location, 8, " ");
                location = 2;
                mvprintw(20 + location, 8, "*");
            }
        }
        else if (input == 's') {
            //clean the previous cursor
            mvprintw(20 + location, 8, " ");
            location++;
            mvprintw(20 + location, 8, "*");
            if (location > 3) {
                //clean the previous cursor
                mvprintw(20 + location, 8, " ");
                location = 0;
                mvprintw(20 + location, 8, "*");
            }
        }

    }



    int step=0;

    //calculate the time taken
    time_t start, end, current;
    time(&start);
    time_t showtime=start;
    int timetaken=0;


    //display the maze, step counter and timer
    int **maze = new int*[30];
    for(int i=0;i<30;i++){
        maze[i] = new int[30];
    }
    generate_maze(maze); //it will be shown according to the randomly generated maze
    for(int i=0;i<30;i++){
        for(int j=0;j<30;j++){
            if(maze[i][j] == 0){
                mvprintw(i+1, j+1, "#");
            }
            else if(maze[i][j] == 1){
                mvprintw(i+1, j+1, ".");
            }
            else if(maze[i][j] == 2){
                mvprintw(i+1, j+1, "K"); //key
            }
            else if(maze[i][j] == 3){
                mvprintw(i+1, j+1, "E"); //exit
            }
            else if(maze[i][j] == 6){
                mvprintw(i+1, j+1, "T"); //treasury box
            }
            else if(maze[i][j] == 5){
                mvprintw(i+1, j+1, "M"); //monster
            }
        }

    }
    mvprintw(3,50,"Steps: %d",step);
    mvprintw(4,50,"Time:          ");


    //allow player to move the knight
    int x = 1;
    int y = 1;
    int key = 0;
    int extra = 0; //extra point from the treasure box and monster
    int exit = 0;
    bool keyexist=true;
    //initial position of the knight
    mvprintw(x+1, y+1, "X");
    //the knight will move until he finds the key and the exit using non-interruptive input
    // use a to move left, d to move right, w to move up, s to move down
    //make input invisible
    noecho();
    while(key == 0 || exit == 0){  //the game will terminate after the player finds both key and exit
        //include a timer to display the time taken
        time(&current);
        if (current!=showtime){
            showtime=current;
            timetaken=int(difftime(current,start));
            mvprintw(4,50,"Time: %d seconds",timetaken);
        }

        srand(time(NULL));
        //change the position of key every 10 seconds
        if (keyexist){
        int changex=rand()%25+3;
        int changey=rand()%25+3;
        if (timetaken%10==0){
            for(int i=0;i<30;i++){
                for(int j=0;j<30;j++){
                    if (maze[i][j]==2){
                        maze[i][j]=1;
                        mvprintw(i+1, j+1, ".");
                        mvprintw(changex+1, changey+1, "K");
                        maze[changex][changey]=2;

                        //make sure the key is accessible, if not, change the surrounding of key into paths
                        if ((maze[changex-1][changey]==0)&&(maze[changex+1][changey]==0)&&(maze[changex][changey+1]==0)&&(maze[changex][changey-1]==0)){
                            maze[changex-1][changey]=1;
                            mvprintw(changex,changey+1,".");
                            maze[changex+1][changey]=1;
                            mvprintw(changex+2,changey+1,".");
                            maze[changex][changey+1]=1;
                            mvprintw(changex+1,changey+2,".");
                            maze[changex][changey-1]=1;
                            mvprintw(changex+1,changey,".");
                        }
                    }
                }
            }
        }}

        //change the position of exit every 15 seconds
        int changeexit=rand()%26+2;
        if (timetaken%15==0){
            for (int k=0;k<30;k++){
                if (maze[28][k]==3){
                    maze[28][k]=0;
                    mvprintw(29, k+1, "#");
                    mvprintw(29,changeexit+1, "E");
                    maze[28][changeexit]=3;

                    //make sure the exit is accessible, if not, change the surrounding of key into paths
                    if ((maze[27][changeexit]==0) && (maze[28][changeexit-1]==0) && (maze[28][changeexit+1]==0)){
                        maze[27][changeexit]=1;
                        mvprintw(28,changeexit+1,".");
                        maze[28][changeexit-1]=1;
                        mvprintw(29,changeexit,".");
                        maze[28][changeexit-1]=1;
                        mvprintw(29,changeexit+2,".");
                    }
                }
            }
        }

         //change the position of monster every 15 seconds
        int changemx=rand()%27+3;
        int changemy=rand()%27+3;
        if (timetaken%15==0){
            if (maze[changemx][changemy]==1){
                for(int i=0;i<30;i++){
                    for(int j=0;j<30;j++){
                        if (maze[i][j]==5){  //the original position of monster will change to path
                            maze[i][j]=1;
                            mvprintw(i+1,j+1,".");
                            maze[changemx][changemy]=5;
                            mvprintw(changemx+1,changemy+1,"M");
                        }
                    }
                }
            }
        }

        //Treasury box will appear randomly after 50 steps
        if (step==50){
            int boxx=rand()%26+3;
            int boxy=rand()%26+3;
            if ((maze[boxx][boxy]==1) ||(maze[boxx][boxy]==0)){ //make sure it will only appear in position that is originally path or wall
                maze[boxx][boxy]=6;
                mvprintw(boxx+1,boxy+1,"T");}
            else {  //if the randomly generated position coincides with key, exit or monster, it will be changed
                maze[boxx+1][boxy+1]=6;
                mvprintw(boxx+2,boxy+2,"T");}
        }

        char ch = getch();
        //the position of the knight will be changed step by step according to player's commands
        if(ch == 'a'){ 
            if(maze[x][y-1] == 1 || maze[x][y-1] == 2 || maze[x][y-1] == 5 || maze[x][y-1] == 6){
                step += 1; //the knight can move one step left successfully if the left is not wall
                mvprintw(x+1, y+1, ".");
                y--; 
                mvprintw(x+1, y+1, "X"); 
                if(maze[x][y] == 2){ 
                    key = 1;
                    mvprintw(9, 50, "You have found the key!");
                    mvprintw(10, 50, "Try to find the exit!");
                    keyexist=false;  //the position of key will stop randomly generating any more
                }
                else if(maze[x][y] == 4){
                    portal(x, y, maze);
                }
                else if(maze[x][y] == 5){  //if the knight meets the monster, the step will increase by 10
                    mvprintw(11, 50, "You meet the monster! Extra move and score!");
                    extra += 50 + rand()%50;
                    step += 10;
                }
                else if(maze[x][y] == 6){  //if the knight finds the treasury box, the step will decrease by 20
                    mvprintw(12, 50, "You find the treasury box! Extra move and score!");
                    extra = 100 + rand()%100;
                    step -= 20;
                }
            }
            else if (maze[x][y-1] == 3){  //the exit is only valid after finding the key
                if (key==1){
                    step += 1;
                    mvprintw(x+1, y+1, ".");
                    exit=1;
                }
            }
        }
        else if(ch == 'd'){
            if(maze[x][y+1] == 1 || maze[x][y+1] == 2 || maze[x][y+1] == 5 || maze[x][y+1] == 6 ){
                step += 1; //the knight can move one step right successfully if the right is not wall
                mvprintw(x+1, y+1, ".");
                y++;
                mvprintw(x+1, y+1, "X");
                if(maze[x][y] == 2){
                    key = 1;
                    mvprintw(9, 50, "You found the key!");
                    mvprintw(10, 50, "Try to find the exit!");
                    keyexist=false;
                }
                else if(maze[x][y] == 4){
                    portal(x, y, maze);
                }
                else if(maze[x][y] == 5){
                    mvprintw(11, 50, "You meet the monster! Extra move and score!");
                    extra += 50 + rand()%50;
                    step += 10;
                }
                else if(maze[x][y] == 6){
                    mvprintw(12, 50, "You find the treasury box! Extra move and score!");
                    extra = 100 + rand()%100;
                    step -= 20;
                }
            }
            else if (maze[x][y+1] == 3){  //the exit is only valid after finding the key
                if (key==1){
                    step += 1;
                    mvprintw(x+1, y+1, ".");
                    exit=1;
                }
            }
        }
        else if(ch == 'w'){
            if(maze[x-1][y] == 1 || maze[x-1][y] == 2 || maze[x-1][y] == 5 || maze[x-1][y] == 6){
                step += 1; //the knight can move one step up successfully if the above is not wall
                mvprintw(x+1, y+1, ".");
                x--;
                mvprintw(x+1, y+1, "X");
                if(maze[x][y] == 2){
                    key = 1;
                    mvprintw(9, 50, "You found the key!");
                    mvprintw(10, 50, "Try to find the exit!");
                    keyexist=false;
                }
                else if(maze[x][y] == 4){
                    portal(x, y, maze);
                }
                else if(maze[x][y] == 5){
                    mvprintw(11, 50, "You meet the monster! Extra move and score!");
                    extra += 50 + rand()%50;
                    step += 10;
                }
                else if(maze[x][y] == 6){
                    mvprintw(12, 50, "You find the treasury box! Extra move and score!");
                    extra = 100 + rand()%100;
                    step -= 20;
                }
            }
            else if (maze[x-1][y] == 3){  //the exit is only valid after finding the key
                if (key==1){
                    step += 1;
                    mvprintw(x+1, y+1, ".");
                    exit=1;
                }
            }
        }
        else if(ch == 's'){
            if(maze[x+1][y] == 1|| maze[x+1][y] == 2|| maze[x+1][y] == 5 || maze[x+1][y] == 6 ){
                 step += 1; //the knight can move one step down successfully if the below is not wall
                 mvprintw(x+1, y+1, ".");
                 x++;
                 mvprintw(x+1, y+1, "X");
                 if(maze[x][y] == 2){
                      key = 1;
                      mvprintw(9, 50, "You found the key!");
                      mvprintw(10, 50, "Try to find the exit!");
                      keyexist=false;
                 }
                else if(maze[x][y] == 4){
                    portal(x, y, maze);
                    }
                else if(maze[x][y] == 5){
                    mvprintw(11, 50, "You meet the monster! Extra move and score!");
                    step += 10;
                }
                else if(maze[x][y] == 6){
                    mvprintw(12, 50, "You find the treasury box! Extra move and score!");
                    step -= 20;
                }
            }
            else if (maze[x+1][y] == 3){  //the exit is only valid after finding the key
                if (key==1){
                    step += 1;
                    mvprintw(x+1, y+1, ".");
                    exit=1;
                }
            }       
        }
        else if (ch == 'q'){
            endwin();
            return 0;
        }
        mvprintw(3,50,"Steps: %d",step); 
    }
    //when the knight finds the key and the exit, quit the ono-interruptive input
    echo();

    time (&end);
    double dif = difftime (end,start);
    //display the score of the player on screen
    //the score is calculated by the number of steps the player takes and time taken to complete the game
    mvprintw(9, 50, "You have taken %d steps to complete the game!", step);
    mvprintw(10, 50, "You have taken %f seconds to complete the game!", dif);
    int score = dif/step*1000 ;
    mvprintw(14, 50, "Your score is %d!", score);
    if (extra != 0) {
        mvprintw(15, 50, "You have gained %d extra points by finding speicals!", extra);
        score += extra;
        mvprintw(16, 50, "Your final score is %d!", score);
    }

    //type the name for storing the score
    mvprintw(18, 50, "Please type your name: ");
    getstr(str);
    mvprintw(19, 50, "Your name is %s", str);
    //if name is blank or too long, ignore the name
    if(strlen(str) == 0 || strlen(str) > 20){
        mvprintw(20, 50, "Your name is invalid!");
        getch();
        endwin();
        return 0;
    }

    //add the score to the file record.txt
    //format: name score
    ofstream fout;
    fout.open("record.txt",ios::app);
    fout << str << " " << score << endl;
    fout.close();
    //sort the file record.txt by score
    //use bubble sort
    ifstream fin;
    fin.open("record.txt");
    string name[100];
    int score1[100];
    int i = 0;
    while(fin >> name[i] >> score1[i]){
        i++;
    }
    for(int j=0;j<i;j++){
        for(int k=0;k<i-j-1;k++){
            if(score1[k] < score1[k+1]){
                int temp = score1[k];
                score1[k] = score1[k+1];
                score1[k+1] = temp;
                string temp1 = name[k];
                name[k] = name[k+1];
                name[k+1] = temp1;
            }
        }
    }
    fin.close();
    //display the top 10 scores in record.txt
    //if EOL is reached, stop displaying
    mvprintw(30, 50, "Top 10 scores:");
    for(int j=0;j<10;j++){
        mvprintw(31+j, 50, "%s %d", name[j].c_str(), score1[j]);
    }



    mvprintw(24, 50, "Thanks for playing the game, %s!",str);
    getch();
    endwin();
    return 0;
}

