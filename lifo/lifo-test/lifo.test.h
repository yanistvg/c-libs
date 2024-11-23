#ifndef _LIFO_TEST_H_
#define _LIFO_TEST_H_

	#include <stdio.h>

	#include "../headers/lifo.h"
	#include "color.h"

	/* test for lifo function */
	extern lifo_t *lifo;

	extern int lifo_test_with_not_init_lifo(void);
	extern int lifo_test_create_and_destroy_lifo(void);
	extern int lifo_test_cell_creation_and_delation(void);

#endif
