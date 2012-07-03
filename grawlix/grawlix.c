#include "grawlix.h"

// Initial a maze of the given dimensions and set each of its cells to `state`,
// which represents everything known about a particular cell. The four low bits
// represent NESW walls, respectively, and 16 is turned on to indicate that the
// cell has already been visited.
Maze
init_maze(int width, int height, char state) {
	Maze new_maze = {width, height, width * height, NULL};
	new_maze.cells = malloc(new_maze.size); // `state` will always be 1 byte.
	reset_maze(&new_maze, state); // no sense in repeating oneself
	return new_maze;
}

// Single point of entry for all carving procedures. (+1 Modularization)
void
carve_maze(Maze *maze, algorithm carver, int bias)
{
	carver(maze, bias);
}

void
reset_maze(Maze *maze, char state)
{
	int i;
	for (i = 0; i < maze->size; ++i)
		maze->cells[i] = state;
}

// TODO: Generalize this a bit more and figure out how best to incorporate the
// missing borders; kind of tricky given that they're not always the same two.
void
display_maze(Maze *maze)
{
	int i;
	for (i = 0; i < maze->size; ++i) {
		putchar(maze->cells[i] & 4 ? '_' : ' ');
		if (i < maze->size - 1) // Avoid a bounding error with the last cell.
			putchar(maze->cells[i] & 2 && maze->cells[i + 1] & 8 ? '|' : '.');
		if ((i + 1) % maze->width == 0)
			putchar('\n');
	}
}

void
destroy_maze(Maze *maze)
{
	free(maze->cells);
}

int
traverse_edge(Maze* maze, int from, int to)
{
	int diff = to - from; // Determine direction of traversal.
	if (diff != -1 && diff != 1 && diff != -maze->width && diff != maze->width)
		error(1, 0, "(1) Invalid traversal from %d to %d", from, to);

/*
	<lisp>
	char dir = diff < -1 // north
		? 1
		: diff == 1 // east
			? 2
			: diff > 1 // south
				? 4
				: 8; // west
	</lisp>
*/

	char dir = diff < -1 ? 1 : diff == 1 ? 2 : diff > 1 ? 4 : 8; // </python>?

	// Flip the wall between the two cells and mark them both as visited.
	maze->cells[from] ^= dir ^ (~maze->cells[from] & 16);
	maze->cells[to]   ^= dir * 4 % 15 ^ (~maze->cells[to] & 16);

	return 1;
}
