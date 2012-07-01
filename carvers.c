// BINARY TREE
// Iterate over the cells, deciding each time to randomly remove either the
// horizontal or vertical edge specified by the bias, which is to be one of
// the four ordinal directions. The result is an unpleasantly uniform graph
// with an obvious solution passage along the given bias.
void
carve_binary_tree(Maze *maze, int bias)
{
	int i;

	// TODO: Cleverly remove the need for this lookup.
	char choices[] = {bias < 2 ? 1 : 4, bias % 2 ? 8 : 2};

	for (i = 0; i < maze->size; ++i)
		maze->cells[i].walls ^= choices[random() % 2];
}
