# Test Tasks

## First task ()

- Write a function which checks if one String is a rotation of other string.

- If s1 = “helloworld" then the following are some of its rotated versions:
- elloworldh
- lloworldhe
- loworldhel
- oworldhell
- worldhello

## Second task ()

The sentence "A quick brown fox jumps over the lazy dog" contains every single letter in the alphabet. Such sentences are called pangrams. You are to write a method getMissingLetters, which takes a String, sentence, and returns all the letters it is missing (which prevents it from being a pangram). You should ignore the case of the letters in Sentence, and your return should be all upper case letters, in alphabetical order.

## Third task ()

A collection of particles is contained in a linear chamber. They all have the same speed, but some are headed toward the right and others are headed toward the left. These particles can pass through each other without disturbing the motion of the particles, so all the particles will leave the chamber relatively quickly. We will be given the initial conditions by a String init containing at each position an ‘L' for a leftward moving particle, an 'R’ for a rightward moving particle, or a'.' for an empty location. init shows all the positions in the chamber. Initially, no location in the chamber contains two particles passing through each other. We would like an animation of the process. At each unit of time, we want a string showing occupied locations with an 'X' and unoccupied locations with a’.
Implement “animate” function which takes int - speed and std::string (or vector) containing initial condition. The speed is the number of positions each particle moves in one time unit. The method will return a std::vector of std::string in which each successive element shows the occupied locations at the next time unit. The first element of the return should show the occupied locations at the initial instant (at time = 0) in the 'X',’.’ format. The last element in the return should show the empty chamber at the first time that it becomes empty.

Constraints
    1. speed will be between 1 and 10 inclusive
    2. init will contain between 1 and 50 characters inclusive
    3. each character in init will be '.' or 'L' or 'R’

Examples
a) "..R....", 2
Returns: {“..X.......”, “....X.....”, “.......X..”, “..........”}
The single particle starts at the 3rd position, moves to the 5th, then 7th, and then out of the chamber.

b) "RR..LRL", 3 
Returns: {"XX..XXX", “.X.XX..”, “X.....X”, “.......”}
At time 1, there are actually 4 particles in the chamber, but two are passing through each other at the 4th position.

c) "LRLR.LRLR", 2
Returns: { "XXXX.XXXX”, “X..X.X..X", “.X.....X.”, “.......” }
At time 0 there are 8 particles. At time 1, there are still 6 particles, but only 4 positions are occupied since particles are passing through each other.

d) "RLRLRLRLRL", 10
Returns: { "XXXXXXXXXX, “..........”} 
These particles are moving so fast that they all exit the chamber by time 1.

e) "...", 1
Returns: {"..."}
f) "LRRL.LR.LRR.R.LRRL.", 1
Returns:
{  "XXXX.XX.XXX.X.XXXX.”,
   “..XXX..X..XX.X..XX.”,
   “.X.XX.X.X..XX.XX.XX”,
   “X.X.XX...X.XXXXX..X”,
   “.X..XXX...X..XX.X..”,
   “X..X..XX.X.XX.XX.X.”,
   “..X....XX..XX..XX.X”,
   “.X.....XXXX..X..XX.”,
   “X.....X..XX...X..XX”,
   “.....X..X.XX...X..X”,
   “....X..X...XX...X..”,
   “...X..X.....XX...X.”,
   “..X..X.......XX...X”,
   “.X..X.........XX...”,
   “X..X...........XX..”,
   “..X.............XX.”,
   “.X...............XX”,
   “X.................X”,
   “...................” }


## How to build

```sh
$ cd ImagineTasks
$ mkdir build
$ cd build
$ cmake ../
$ make
```

## How to run

```sh
$ cd ImagineTasks/build/ImagineTasks
```

## How to run Unit Tests

```sh
$ ./ImagineTasks/build/pangrams_test
$ ./ImagineTasks/build/particles_test
$ ./ImagineTasks/build/rotation_test
```