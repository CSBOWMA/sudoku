# sudoku
A sudoku game utilizing RaylibC

## goal
- Experience creating a basic game engine by utilizing [RaylibC](https://www.raylib.com/), A graphics library that utilizies OpenGL, to create a sudoku game.  
- [branchless optimization](https://en.algorithmica.org/hpc/pipelining/branchless/), a programming technique that prevents the possiblities of branch misprediction.  
- Follow object oriented principals allowing for ease of development and code reusability.
- strictly utilize the [c++ memory libray](https://cplusplus.com/reference/memory/) to properly handle memory management without fear of memory leaks.

## features
- Notes mode, allowing for users to keep track of possibilities for each individual square.  
- Autonotes button, if the user wants to program to quickly write out the obvious notes.  
- Collision highlighting, allowing for easy identification of where the user went wrong.  
- Timer allowing for user to keep track of the amount of time spent on a board.  
- Hilighting of currently selected square, column set, row set, and square set.  
- Preset squares are darkened showing what the user may not modify.  

## optimization
- [branchless optimization](https://en.algorithmica.org/hpc/pipelining/branchless/), I have attempted to make as much of the code as I can branchless, Often times when a program runs a branch prediction algorithm runs besides it, this overall reduces the runtime greatly, but if the prediction algorithm were to fail, especially common with random data, a branch misprediction would occur causing the pipeline to stall for up to 20 cycles. Meaning that if you have something in the code that runs frequently but only uses up a few cycles, a majority of the time running that snippet will be spent with the pipeline stalled.  
- [Bit Field](https://en.wikipedia.org/wiki/Bit_field) In the game scene I have both 81 Tiles, a class representing the value in a spot, and 81 notes, a note representing all possible integer values for a spot ie 1 through 9.  
  - Normally each tile would have to keep track of not only the integer stored but also a boolean value representing if the tile is preset. If I were to use the standard data types an int and a bool on a modern device, each tile would take up 5 bytes, for a total 405 bytes for all tiles. Since I only need a tile to represent a value between 0 and 9, I was able to instead use an uint8_t, or an 8 bit unsigned integer. As such with only an uint_8, and a bool I could reduce the total amount of bytes for tiles down to 162 bytes, so more than half the amount of storage. I furthered this as you only need the first seven bits to represent the value of the tile as either an integer value 0 through 9 or a char value 0 through 9. As such I could use the 8th bit to represent if the tile was preset. This cut the required amount of storage in half now only requiring one byte per tile instead of two.

  - Each note traditionally would be represented by 9 bool values, each representing if the note is on or off for a value. This would cause each struct to be atleast the size of 9 bytes, meaning that the entirety of the notes would take up atleast 729 bytes. I instead decided to use an uint16_t, or a 16 bit unsigned integer, and bit manipulation to store all the notes of a spot in only two bytes. Thus reducing the memory usage from 729 bytes down to 162 bytes, reducing it down to less than a quarter the amount of required storage. The tradeoff to this is of course readablility of the code, but by utilizing abstraction one can easily use the class with just standard values. Although it costs more cycles to modify an individual vlaue of the notes, access times are nearly equivelant due to ability to simply return the entirety of a note by just returning one int, allowing for the user to use bit masks to obtain what values they want.  

- Reduce expensive code calls, The most expensive algorithm in the code is auto-notes algorithm and the collisions algorithm. These algorithms only need to be ran when the board is updated, or when a tile is set. Instead of updating the collisions list and notes every time the main game loop executes, it instead checks if the board has been updated by utlizing the return value calculated returned by the Sudoku class method setTile representing if a tile was updated or not.

## challenges

- When the board is in autonotes mode and a tile is unset, you can not simply re add that value to all the tiles in the sets that contain it. Instead you must check each tile individually and see if that tile is in a different set that contains said value.
- Solving to see if a board has one unique solution. I want this project to at some point beable to generate completely random boards from scratch utilizing a seed. In doing so I must be able to create a sudoku solving algorithm that can not only solve a board, but must do it using logic instead of brute force like the current algorithms. This task is incredibly difficult due to the fact that [sudoku is an NP-Complete problem](https://www.sciencedirect.com/science/article/pii/S097286001630038X).
- Making the scenes switch to other scenes when they finish. I originally had a scene handler that was designed to hold multiple scenes at once, the issue is that each scene needed to have a reference to the different scenes, such as main menu scene to the game scene, but also be able to reference the other way around, game scene to main menu scene, as such this would require a graph like file structure that would result in recursive calls of my source files, causing a compiler error. As such I decided to instead have each of my scenes reference a scene enum that stored all scenes. By using this when a scene is over it could simply return what the next scene is and the scene handler would start up that scene. 
