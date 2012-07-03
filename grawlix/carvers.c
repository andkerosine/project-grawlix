#include "carvers.h"

// ALDOUS-BRODER
// Starting from any cell, move randomly to an adjacent cell, removing the edge
// between them if the destination has not yet been visited. Continue until all
// cells have been visited, resulting in a perfectly uniform spanning tree with
// no biases. Given the undirected approach to finding the next edge to remove,
// this algorithm is only guaranteed to complete given infinite time, but it is
// sufficient for mazes of moderate size.
void
carve_aldous_broder(Maze *maze)
{
	int w = maze->width, h = maze->height;
	int current = random() % maze->size, next;
	int visited = 0;

	while (visited < maze->size - 1) {
		// How can something so beautiful be so disgusting?
		int choices[] = {
			current  < w         /* top row */      ? w  : -w, // disallow going up
			(current + 1) % w    /* right column */ ? 1  : -1, // no rights for you
			current  < w * h - w /* bottom row */   ? w  : -w, // suffer no downers
			current  % w         /* left column */  ? -1 : 1}; // the only one left
		next = current + choices[random() % 4];

		if (~maze->cells[next] & 16) // found an unvisited cell
			visited += traverse_edge(maze, current, next);
		current = next;
	}
}

// BINARY TREE
// Iterate over the cells, deciding each time to randomly remove either the
// horizontal or vertical edge specified by the bias, which is to be one of
// the four ordinal directions. This results in a heterogeneous maze with a
// blatantly obvious solution along the given bias.

// * Southeasterly is the only variant that is implemented correctly at the
//   moment as this one's surprisingly hard to be succinct about.
void
carve_binary_tree(Maze *maze, int bias)
{
	int i;

	// TODO: Cleverly remove the need for this lookup.
	char choices[] = {bias < 2 ? 1 : 4, bias % 2 ? 8 : 2};

	for (i = 0; i < maze->size; ++i)
		maze->cells[i] ^= (i + 1) % maze->width == 0
			? choices[0]
			: (i >= maze->width * maze->height - maze->width)
				? choices[1]
				: choices[random() % 2];
}

