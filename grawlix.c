#include "grawlix.h"
#include "carvers.c"

Maze
init_maze(int width, int height, char walls)
{
	Maze new_maze = {width, height, width * height, NULL};
	new_maze.cells = malloc(new_maze.size * sizeof(Cell));
	reset_maze(&new_maze, walls);
	return new_maze;
}

void
carve_maze(Maze *maze, algorithm carver, int bias)
{
	carver(maze, bias);
}

// TODO: Generalize the hell out of this.
void
display_maze(Maze *maze)
{
	int i;
	for (i = 0; i < maze->size; ++i) {
		printf(maze->cells[i].walls == 11 ? " |" : "_.");
		if ((i + 1) % maze->width == 0)
			putchar('\n');
	}
}

void
reset_maze(Maze *maze, char walls)
{
	int i;
	for (i = 0; i < maze->size; ++i)
		maze->cells[i].walls = walls;
}

void
destroy_maze(Maze *maze)
{
	free(maze->cells);
}
