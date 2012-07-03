#ifndef EXPERIMENTS_H_INCLUDED
#define EXPERIMENTS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Temporary for seeding the RNG

#include "carvers.h"
#include "grawlix.h"

#include "types.h"

// Constants for convenient indexing into the array of algorithms defined above
enum {
	ALDOUS_BRODER,
	BINARY_TREE
};

#endif // EXPERIMENTS_H_INCLUDED

