#ifndef GRAWLIX_H_INCLUDED
#define GRAWLIX_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <error.h>

// A Maze is simply a collection of cells with a "shape" determined by its
// width and height; size (w * h) is predetermined for convenient looping.
typedef struct {
	int width, height, size;
	char *cells;
} Maze;

// An algorithm is a pointer to a function which takes a Maze and an optional
// bias with which to carry out the given edge removal ("carving") procedure.
typedef void (*algorithm)();

// Seeing them all together here makes me question the naming convention a bit.
// s/(.+)_maze/grawlix_\1/, perhaps?
Maze init_maze(int width, int height, char state);
void carve_maze(Maze*, algorithm, int bias);
void reset_maze(Maze*, char state);
void display_maze(Maze*);
void destroy_maze(Maze*);

int  traverse_edge(Maze*, int from, int to);
void carve_binary_tree(Maze*, int bias);
void carve_aldous_broder(Maze*);

// constants for convenient indexing into the array of algorithms defined above
enum {
	ALDOUS_BRODER,
	BINARY_TREE
};

enum { NE, NW, SE, SW }; // biases for the binary tree carver

#endif // GRAWLIX_H_INCLUDED
