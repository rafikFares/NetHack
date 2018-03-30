# NetHack C/C++ ROGUE GAME
A Nethack game based on Rogue type using C++
so in the begging the game will ask you to choose a mode :
1- an automatic mode :
  + the levels are created automaticly and rondomly
  + the rooms are made rondomly
  + the doors in each room are made rondomly
  + the routes between each rooms/doors  are made using the A* algorithm
2- a manual mode : 
  + the levels are created from the files 1, 2, 3, 4, 5 (which contains the levels)

- indications :
  - d move to right
  - s move down
  - a move to left
  - w move up
  - q exit the game
  - i for moving to inventory mode (n for next object, u for using an object, s for deleting an object)
  - @ are the doors
  - '#' are the routes between rooms
  - K, A, B are the monsters (K and A move rondomly, B follow you)
  - to kill a monster you need to touch it many times (each time your health and his health are draining)
  - F is the door (closed) to the next level to open this door you need to obtain experience by killing monsters
  - S is the open door to the next level
  - P is the open door to the previous level
  - for each move you do monsters will move alsso
  - after killing a monster you may get an object (W, R increase your power | M, P increase your health)
  - you will only see the monsters in your current room (each room contains between 2 to 4 monsters)

 - compile :
   - make sure you have the library ncursus in your pc
   - in a terminal just execute make (to compile)
   - execute ./main to run the game
 
... maybe i forgot something

# All this project was made with the colaboration of my binomial @Ziyi Zhou
