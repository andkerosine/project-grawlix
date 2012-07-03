#include "grawlix/grawlix.h"

int
main(int argc, char *argv[])
{
	algorithm carvers[] = {
		carve_aldous_broder,
		carve_binary_tree
	};

	int size = argc > 1 ? atoi(argv[1]) : 8; // rudimentary CLI
	srandom((int) &size); // An address is sufficiently random. (+1 Recycling)

	Maze test_maze = init_maze(size, size, 15);
	carve_maze(&test_maze, carvers[BINARY_TREE], SW); //
	display_maze(&test_maze);
	puts("");

	reset_maze(&test_maze, 15);
	carve_maze(&test_maze, carvers[ALDOUS_BRODER], 0);
	display_maze(&test_maze);

	destroy_maze(&test_maze);
	return 0;
}
