#ifndef GRAWLIX_H_INCLUDED
#define GRAWLIX_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <error.h>

#include "types.h"

// Seeing them all together here makes me question the naming convention a bit.
// s/(.+)_maze/grawlix_\1/, perhaps?
Maze init_maze(int width, int height, char state);
void carve_maze(Maze*, algorithm, int bias);
void reset_maze(Maze*, char state);
void display_maze(Maze*);
void destroy_maze(Maze*);
int  traverse_edge(Maze*, int from, int to);

enum { NE, NW, SE, SW }; // biases for the binary tree carver

#endif // GRAWLIX_H_INCLUDED

