#ifndef TYPES_H_INCLUDED
#define TYPES_H_INCLUDED

// A Maze is simply a collection of cells with a "shape" determined by its
// width and height; size (w * h) is predetermined for convenient looping.
typedef struct {
	int width, height, size;
	char *cells;
} Maze;

// An algorithm is a pointer to a function which takes a Maze and an optional
// bias with which to carry out the given edge removal ("carving") procedure.
typedef void (*algorithm)();

#endif // TYPES_H_INCLUDED

