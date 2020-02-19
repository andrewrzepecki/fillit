# Fillit
First Algo Project @ 42 Paris.

**Project score : [99 / 100]**

Fillit is an algorithmic project that consists of finding the smallest square possible using the given tetriminos.
Execution time was a constraint in this project, so implementing an optimal backtracking algorithm was the core of this project. 


## Installation and usage

```
git clone https://github.com/andrewrzepecki/fillit && cd fillit && make
./fillit [file containing tetriminos]
```

The program recieves a file containing valid tetriminos in this format:

![fillit](png/tetris)

Comments "##start" and "##end" are necessary for defining the start and end points of the graph, and must be linked together.

**Example:**

```
./lem-in < maps/big
```
![lem-in](https://i.ibb.co/7pSmxPM/Screen-Shot-2019-10-28-at-1-20-03-PM.png)

[[ant number]-[current vertex]]

The first entry of the first line is [L0-99], meaning that the first ant goes to room "99", then [L1-806], the second ant goes to room "806"... 

The rules of lem-in state that there can be only one ant in a room at a time and one can only visit a vertex once, which caused superposition problems that were fixed using a variation of Edmond-Karp's algorithm and graph theory.
