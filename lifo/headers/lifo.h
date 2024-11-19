#ifndef __YG_LIFO__
#define __YG_LIFO__

	#include <stdlib.h>
	#include <stdio.h>

	#define _LIFO_SUCCESS_            0
	#define _LIFO_NOT_INIT_          -1
	#define _LIFO_ALLOC_FAILED_      -2
	#define _LIFO_NO_FUNC_PRINT_SET_ -3

	struct lifo_structure {
		void                  *data;
		struct lifo_structure *next;
	};

	struct lifo_head {
		struct lifo_structure *head;        // head of the fifo list
		unsigned int           lifo_length; // size of the list

		// function used to print a cell, this used to print all
		// cells of the list. The function do create by developer
		// and addr do set into this variable
		void (*lifoPrintCell)(void *cell);
		// function used to free data containe in data, if the data
		// structure is complexe, this function do delete all allocated
		// data to the memory. This function do implented by developer
		void (*lifoFreeCell)(void *cell);
	};

	typedef struct lifo_head lifo_t;

	/***********************************************/
	/**                                           **/
	/** Declaration of functions to interact with **/
	/** the lifo structure. All interactions are  **/
	/** the most basics                           **/
	/**                                           **/
	/***********************************************/
	extern lifo_t *lifoCreate(void);
	extern void lifoFree(lifo_t **lifo);
	extern int lifoAdd(lifo_t **lifo, void *cell);
	extern void *lifoPop(lifo_t **lifo);
	extern int lifoPrintList(lifo_t **lifo);
	extern int lifoDelCell(lifo_t **lifo);
	extern int lifoDelCells(lifo_t **lifo);
	extern int lifoDelNCells(lifo_t **lifo, unsigned int N);
	extern int lifoAddNCells(lifo_t **lifo, void **cell, unsigned int N);

	/****************************************************/
	/**                                                **/
	/** Declaration of code to create a lifo structure **/
	/** for int values                                 **/
	/**                                                **/
	/****************************************************/
	extern lifo_t *intLifoCreate(void);
	extern int intLifoAdd(lifo_t **lifo, int value);
	extern int intLifoPop(lifo_t **lifo);
	extern int intLifoPop(lifo_t **lifo);
	extern void intLifoPrintList(lifo_t **lifo);
	extern int intLifoAddNCells(lifo_t **lifo, int cell[], unsigned int N);

	extern void intLifoPrintCell(int value);

#endif