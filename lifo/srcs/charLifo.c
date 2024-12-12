#include "../headers/lifo.h"

/**
 * charLifoCreate create a new lifo list exclusive
 * for stock float value
 * 
 * @returns lifo_t * if structure intialized successuly
 * @returns NULL     if an error of allocation
 * 
 * @author Yanis GENY
 * @version 1.0
 */
lifo_t *charLifoCreate(void) {
	lifo_t *newFloatLifo = (lifo_t*)NULL;

	if ((newFloatLifo = lifoCreate()) == NULL)
		return (lifo_t*)NULL;

	newFloatLifo->lifoPrintCell = (void(*)(void*))floatLifoPrintCell;
	newFloatLifo->lifoSearchMax = (void*(*)(void*, void*))floatLifoSearchMax;
	newFloatLifo->lifoSearchMin = (void*(*)(void*, void*))floatLifoSearchMin;
	return newFloatLifo;
}

/**
 * charLifoAdd call lifoAdd to add the char value into the void*
 * data of the structur lifo. this function is only a case to
 * converte the char value into void*
 * 
 * @param lifo addresse of the lifo structure
 * @param value the char value to store in the lifo
 * 
 * @return _LIFO_SUCCESS_      if the cell added without problem
 * @return _LIFO_NOT_INIT_     if the lifo list are not init
 * @return _LIFO_ALLOC_FAILED_ if error with allocation
 * 
 * @author Yanis GENY
 * @version 1.0
 */
int charLifoAdd(lifo_t **lifo, char value) {
	return lifoAdd(lifo, (void*)(size_t)(value));
}

/**
 * charLifoPop delete firt element of the list and return
 * the value of the cell
 * 
 * @param lifo addresse of the lifo structure
 * 
 * @return NULL            if no cell in the list
 * @return char            the value of the first cell
 * @return _LIFO_NOT_INIT_ if the list are not init
 * 
 * @author Yanis GENY
 * @version 1.0
 */
char charLifoPop(lifo_t **lifo) {
	return (char)(size_t)lifoPop(lifo);
}

/**
 * charLifoPrintList print all the lifo list using the function
 * set in lifoPrintCell from the lifo structure
 * 
 * @param lifo addresse of the lifo structure
 * 
 * @author Yanis GENY
 * @version 1.0
 */
void charLifoPrintList(lifo_t **lifo) {
	printf("[ ");
	lifoPrintList(lifo);
	printf("]\n");
}

/**
 * charLifoAddNCells add N int value in the list
 * 
 * @param lifo addresse of the lifo structure
 * @param cell table of char to add into the list
 * @param N number of float in cell table
 * 
 * @return _LIFO_SUCCESS_      if the cell added without problem
 * @return _LIFO_NOT_INIT_     if the lifo list are not init
 * @return _LIFO_ALLOC_FAILED_ if error with allocation
 * 
 * @author Yanis GENY
 * @version 1.0
 */
int charLifoAddNCells(lifo_t **lifo, char cell[], unsigned int N) {
	unsigned int i = 0;
	int r;

	while (++i <= N) {
		if ((r = lifoAdd(lifo, (void*)(size_t)cell[i-1])) != _LIFO_SUCCESS_)
			return r;
	}
	return _LIFO_SUCCESS_;
}

/**
 * charLifoGetCell extract the char value from the list with an index
 * 
 * @param lifo addresse of the lifo structure
 * @param index
 * 
 * @return char value of the cell at index
 * @return _LIFO_NOT_INIT_     if the lifo list are not init
 * @return _LIFO_OUT_OF_RANGE_ if index is gretter than the number of cells
 * 
 * @author Yanis GENY
 * @version 1.0
 */
char charLifoGetCell(lifo_t **lifo, int index) {
	return (char)(size_t)lifoGetCell(lifo, index);
}

/**
 * charLifoMax over right lifoMax to return an char value
 * 
 * @author Yanis GENY
 * @version 1.0
 */
char charLifoMax(lifo_t **lifo) {
	return (char)(size_t)lifoMax(lifo);
}

/**
 * charLifoMin over right lifoMin to return an char value
 * 
 * @author Yanis GENY
 * @version 1.0
 */
char charLifoMin(lifo_t **lifo) {
	return (char)(size_t)lifoMin(lifo);
}



/**********************************************/
/***                                        ***/
/*** Functions to set in the lifo structure ***/
/***                                        ***/
/**********************************************/

/**
 * charLifoPrintCell is the function to store in lifo structure
 * using with lifoPrintList to write all contante in the list
 * 
 * @param value is contante in the cell, value to print
 * 
 * @author Yanis GENY
 * @version 1.0
 */
void charLifoPrintCell(char value) {
	printf("%c ", (char)value);
}

/**
 * charLifoSearchMax is a function who compare to cells
 * a and b to return the value of the greatter
 * 
 * @param a cell
 * @param b cell
 * 
 * @return void* the greatter cells
 * 
 * @author Yanis GENY
 * @version 1.0
 */
void *charLifoSearchMax(void *a, void *b) {
	return (char)(size_t)a >= (char)(size_t)b
		? a
		: b
	;
}

/**
 * charLifoSearchMin is a function who compare to cells
 * a and b to return the value of the minesse
 * 
 * @param a cell
 * @param b cell
 * 
 * @return void* the minus cells
 * 
 * @author Yanis GENY
 * @version 1.0
 */
void *charLifoSearchMin(void *a, void *b) {
	return (char)(size_t)a < (char)(size_t)b
		? a
		: b
	;
}
