#include "../headers/lifo.h"

/**
 * intLifoCreate create a new lifo list exclusive
 * for stock int value
 * 
 * @returns lifo_t * if structure intialized successuly
 * @returns NULL     if an error of allocation
 * 
 * @author Yanis GENY
 * @version 1.0
 */
lifo_t *intLifoCreate(void) {
	lifo_t *newIntLifo = (lifo_t*)NULL;

	if ((newIntLifo = lifoCreate()) == NULL)
		return (lifo_t*)NULL;

	newIntLifo->lifoPrintCell = (void(*)(void*))intLifoPrintCell;
	return newIntLifo;
}

/**
 * intLifoAdd call lifoAdd to add the int value into the void*
 * data of the structur lifo. this function is only a case to
 * converte the int value into void*
 * 
 * @param lifo addresse of the lifo structure
 * @param value the int value to store in the lifo
 * 
 * @return _LIFO_SUCCESS_      if the cell added without problem
 * @return _LIFO_NOT_INIT_     if the lifo list are not init
 * @return _LIFO_ALLOC_FAILED_ if error with allocation
 * 
 * @author Yanis GENY
 * @version 1.0
 */
int intLifoAdd(lifo_t **lifo, int value) {
	return lifoAdd(lifo, (void*)(size_t)(value));
}

/**
 * intLifoPop delete firt element of the list and return
 * the value of the cell
 * 
 * @param lifo addresse of the lifo structure
 * 
 * @return NULL            if no cell in the list
 * @return int             the value of the first cell
 * @return _LIFO_NOT_INIT_ if the list are not init
 * 
 * @author Yanis GENY
 * @version 1.0
 */
int intLifoPop(lifo_t **lifo) {
	return (int)(size_t)lifoPop(lifo);
}

/**
 * intLifoPrintList print all the lifo list using the function
 * set in lifoPrintCell from the lifo structure
 * 
 * @param lifo addresse of the lifo structure
 * 
 * @author Yanis GENY
 * @version 1.0
 */
void intLifoPrintList(lifo_t **lifo) {
	printf("[ ");
	lifoPrintList(lifo);
	printf("]\n");
}

/**
 * intLifoAddNCells add N int value in the list
 * 
 * @param lifo addresse of the lifo structure
 * @param cell table of int to add into the list
 * @param N number of int in cell table
 * 
 * @return _LIFO_SUCCESS_      if the cell added without problem
 * @return _LIFO_NOT_INIT_     if the lifo list are not init
 * @return _LIFO_ALLOC_FAILED_ if error with allocation
 * 
 * @author Yanis GENY
 * @version 1.0
 */
int intLifoAddNCells(lifo_t **lifo, int cell[], unsigned int N) {
	unsigned int i = 0;
	int r;

	while (++i <= N) {
		if ((r = lifoAdd(lifo, (void*)(size_t)cell[i-1])) != _LIFO_SUCCESS_)
			return r;
	}
	return _LIFO_SUCCESS_;
}


/**
 * intLifoPrintCell is the function to store in lifo structure
 * using with lifoPrintList to write all contante in the list
 * 
 * @param value is contante in the cell, value to print
 * 
 * @author Yanis GENY
 * @version 1.0
 */
void intLifoPrintCell(int value) {
	printf("%d ", (int)value);
}
