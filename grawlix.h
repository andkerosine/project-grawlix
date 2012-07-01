#include <stdio.h>
#include <stdlib.h>

// Cells represent the connections (or lack thereof) between any four adjacent
// nodes in the graph. In general, a cell's walls value will be initialized to
// 15 (completely closed) and its visited status false prior to being adjusted
// accordingly by a given "carving" algorithm. I am entertaining the notion of
// joining the values into a single number, but clarity vs. awesome is tricky.
typedef struct {
	char walls;   // value from 0-15 whose bits represent edges between nodes
	char visited; // boolean used during "tracking" carvers
} Cell;

// A Maze is simply a connection of Cells with a "shape" determined by its
// width and height; size (w * h) is predetermined for convenient looping.
typedef struct {
	int width, height, size;
	Cell *cells;
} Maze;

// An algorithm is a pointer to a function which takes a Maze and an optional
// bias with which to carry out the given edge removal ("carving") procedure.
typedef void (*algorithm)(Maze*, int);

// Seeing them all together here makes me question the naming convention a bit.
// s/(.+)_maze/grawlix_\1/, maybe?
Maze init_maze(int width, int height, char walls);
void carve_maze(Maze*, algorithm, int bias);
void reset_maze(Maze *maze, char walls);
void display_maze(Maze*);
void destroy_maze(Maze*);

void carve_binary_tree(Maze*, int bias);

algorithm carvers[] = {
	carve_binary_tree
};

// constants for convenient indexing into the array of algorithms defined above
enum {
	BINARY_TREE
};

enum { NE, NW, SE, SW }; // biases for the binary tree carver
