## index :
* [generator](#generator)
* [solver](#solver)
* [maze](#maze)  

#### info :
System functions and libC are allowed, but no external libraries.  

## Generator :
### __Flood fill__ algorithm
[sources](https://algostructure.com/specials/maze.php)  

### input :
Maze size (width/height)  

### output :
A maze with the required size on the standard output.  

### usage :
```shell
$ ./generator x y [perfect]
```

### warning :
* Maze must have at least one solution.


## Solver :
### __A star__ algorithm
[sources](https://hurna.io/fr/academy/algorithms/maze_pathfinder/a_star.html)  

### input :
Maze file path.  

### output :
The maze solution on the standard output.  

### usage :
```shell
$ ./solver maze.txt
```

### warning :
* If there is no solution you must print “no solution found” on the same output.  

## Maze :
* Mazes are rectangular.
* They are coded in ASCII.
* The ‘X’s represent the walls and the’*’s represent the free spaces.
* It is possible to move to the four surrounding squares (up, down, right, left).
* “Start” is in the upper left-hand corner (0;0)
* “Finish” is in the bottom right-hand corner.
* A solution is a series of free, adjacent squares, from “Start” to “Finish” included.
* “Start” and “Finish” can be occupied. In this case, there is no solution.
* The last line of the maze doesn’t terminate with a return line.
* Resolution: in order to write the solution in the maze, we use ‘o’ for the solution path.  

### exemple :

24x6  

Maze :  
```txt
oooooXX****X********XXXX  
XX******XX***XXXXX***XXX  
XX***XXXX**XXXXX****XXXX  
XX***XXXXXXXXXXXXXX****X  
*****XXXXXX****XX***XXXX  
XX*************XXXX*****  
```
Solved :  
```txt
oooooXXooooXooooooooXXXX  
XX**ooooXXoooXXXXX*o*XXX  
XX***XXXX**XXXXX***oXXXX  
XX***XXXXXXXXXXXXXXo***X  
*****XXXXXX****XX**oXXXX  
XX*************XXXXooooo  
```
