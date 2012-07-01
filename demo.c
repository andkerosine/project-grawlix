#include "grawlix.c"

int
main(int argc, char *argv[])
{
	int size = argc > 1 ? atoi(argv[1]) : 20; // rudimentary CLI
	srandom((int) &size); // An address is sufficiently random. (+1 Recycling)

	Maze binary_tree = init_maze(size, size, 15);
	carve_maze(&binary_tree, carvers[BINARY_TREE], SE);
	display_maze(&binary_tree);
	destroy_maze(&binary_tree);

	return 0;
}
