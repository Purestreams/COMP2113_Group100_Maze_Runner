# Maze runner
*— a game made for ENGG1340 group project*

## Video demonstration
[Youtube](https://youtu.be/xPtkwtKMitk)


[onedrive](https://connecthkuhk-my.sharepoint.com/:v:/g/personal/u3606137_connect_hku_hk/EUOnSX3zZLRHurOyNcDSTXsBI7SFqzsiKEaizfab2SvWtQ?nav=eyJyZWZlcnJhbEluZm8iOnsicmVmZXJyYWxBcHAiOiJPbmVEcml2ZUZvckJ1c2luZXNzIiwicmVmZXJyYWxBcHBQbGF0Zm9ybSI6IldlYiIsInJlZmVycmFsTW9kZSI6InZpZXciLCJyZWZlcnJhbFZpZXciOiJNeUZpbGVzTGlua0RpcmVjdCJ9fQ&e=NGoU4W)


## Team Members

Zhu Yecheng (Purestreams) 3036061373 \
He Peishan (STARQUANTUM) 3036103793\
Liu Kexin (Lydialkx) 3036098182\
Shum Wai Lik Adrian (ActuaryLmao) 3035962441 \
Sun Mingyue (Mingyue13) 3035988615 

## Game Introduction
**Name**

This game is called *Maze Runner*.
You are a knight who is trapped in a maze. You need to find the exit to escape from the maze. But first, you need to find the key in the maze. 
The maze is represented by a 2D array.
However, the key and the exit will change positions randomly after some period. Find the key and escape from the maze. Have fun! 


### Gameplay
- Press "W" to move up
- Press "A" to move left
- Press "S" to move down
- Press "D" to move right
- Press "E" to start the game
- Press "CTRL" + "C" to exit the game
- Press "q" to exit the game
- A score ranking system
- A manual for the game

## Features & Explanation
- The Player is represented by 'X'
- The path that the Player can move is on '......'
- "T" represents the treasury box, you will get bonus points but lose steps when you encounter it
- "M" represents the monster, you will get bonus points and more steps when you encounter it
- If you encounter '#', that is a wall, which cannot be passed through
- You must first obtain the key 'K'
- Get to the exit 'E' to escape the maze
- The key and the exit will change positions randomly after some period
- The game will end when you get to the exit
- Displays the number of steps and time taken and your score when the game ends
  
## Game Features 
- Generation of random game sets or events
- Data structures for storing game status
- Dynamic memory management
- File input/output (Scoreboard)
- Program codes in multiple files
- Proper indentation and naming styles
- In-code documentation

## Dependencies
The following non-standard C/C++ library has been used in this project:
- `curses.h`/`ncurses.h` , for acquiring user input without blocking the processing and rendering the UI and graphics


### Compilation
Run `make main` under the ~/src directory of the project (i.e. where this file is located) to compile.

If you ran into issues with `make main`, you can try `make clean` and then try again with `make main`.

### Execution
The executable file, generated once you have run `make main`, is located at `src/main`. Note that config files and logs will be placed at where you called the executable file, not necessarily where the executable file is located.

