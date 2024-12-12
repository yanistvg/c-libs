#include "../headers/lifo.h"

/**
 * floatLifoCreate create a new lifo list exclusive
 * for stock float value
 * 
 * @returns lifo_t * if structure intialized successuly
 * @returns NULL     if an error of allocation
 * 
 * @author Yanis GENY
 * @version 1.0
 */
lifo_t *floatLifoCreate(void) {
	lifo_t *newFloatLifo = (lifo_t*)NULL;

	if ((newFloatLifo = lifoCreate()) == NULL)
		return (lifo_t*)NULL;

	newFloatLifo->lifoPrintCell = (void(*)(void*))floatLifoPrintCell;
	newFloatLifo->lifoSearchMax = (void*(*)(void*, void*))floatLifoSearchMax;
	newFloatLifo->lifoSearchMin = (void*(*)(void*, void*))floatLifoSearchMin;
	return newFloatLifo;
}

/**
 * floatLifoAdd call lifoAdd to add the float value into the void*
 * data of the structur lifo. this function is only a case to
 * converte the float value into void*
 * 
 * @param lifo addresse of the lifo structure
 * @param value the float value to store in the lifo
 * 
 * @return _LIFO_SUCCESS_      if the cell added without problem
 * @return _LIFO_NOT_INIT_     if the lifo list are not init
 * @return _LIFO_ALLOC_FAILED_ if error with allocation
 * 
 * @author Yanis GENY
 * @version 1.0
 */
int floatLifoAdd(lifo_t **lifo, float value) {
	return lifoAdd(lifo, (void*)(size_t)(value));
}

/**
 * floatLifoPop delete firt element of the list and return
 * the value of the cell
 * 
 * @param lifo addresse of the lifo structure
 * 
 * @return NULL            if no cell in the list
 * @return float           the value of the first cell
 * @return _LIFO_NOT_INIT_ if the list are not init
 * 
 * @author Yanis GENY
 * @version 1.0
 */
float floatLifoPop(lifo_t **lifo) {
	return (float)(size_t)lifoPop(lifo);
}

/**
 * floatLifoPrintList print all the lifo list using the function
 * set in lifoPrintCell from the lifo structure
 * 
 * @param lifo addresse of the lifo structure
 * 
 * @author Yanis GENY
 * @version 1.0
 */
void floatLifoPrintList(lifo_t **lifo) {
	printf("[ ");
	lifoPrintList(lifo);
	printf("]\n");
}

/**
 * floatLifoAddNCells add N int value in the list
 * 
 * @param lifo addresse of the lifo structure
 * @param cell table of float to add into the list
 * @param N number of float in cell table
 * 
 * @return _LIFO_SUCCESS_      if the cell added without problem
 * @return _LIFO_NOT_INIT_     if the lifo list are not init
 * @return _LIFO_ALLOC_FAILED_ if error with allocation
 * 
 * @author Yanis GENY
 * @version 1.0
 */
int floatLifoAddNCells(lifo_t **lifo, float cell[], unsigned int N) {
	unsigned int i = 0;
	int r;

	while (++i <= N) {
		if ((r = lifoAdd(lifo, (void*)(size_t)cell[i-1])) != _LIFO_SUCCESS_)
			return r;
	}
	return _LIFO_SUCCESS_;
}

/**
 * floatLifoGetCell extract the float value from the list with an index
 * 
 * @param lifo addresse of the lifo structure
 * @param index
 * 
 * @return float value of the cell at index
 * @return _LIFO_NOT_INIT_     if the lifo list are not init
 * @return _LIFO_OUT_OF_RANGE_ if index is gretter than the number of cells
 * 
 * @author Yanis GENY
 * @version 1.0
 */
float floatLifoGetCell(lifo_t **lifo, int index) {
	return (float)(size_t)lifoGetCell(lifo, index);
}

/**
 * floatLifoMax over right lifoMax to return an float value
 * 
 * @author Yanis GENY
 * @version 1.0
 */
float floatLifoMax(lifo_t **lifo) {
	return (float)(size_t)lifoMax(lifo);
}

/**
 * floatLifoMin over right lifoMin to return an float value
 * 
 * @author Yanis GENY
 * @version 1.0
 */
float floatLifoMin(lifo_t **lifo) {
	return (float)(size_t)lifoMin(lifo);
}



/**********************************************/
/***                                        ***/
/*** Functions to set in the lifo structure ***/
/***                                        ***/
/**********************************************/

/**
 * floatLifoPrintCell is the function to store in lifo structure
 * using with lifoPrintList to write all contante in the list
 * 
 * @param value is contante in the cell, value to print
 * 
 * @author Yanis GENY
 * @version 1.0
 */
void floatLifoPrintCell(float value) {
	printf("%f ", (float)value);
}

/**
 * floatLifoSearchMax is a function who compare to cells
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
void *floatLifoSearchMax(void *a, void *b) {
	return (float)(size_t)a >= (float)(size_t)b
		? a
		: b
	;
}

/**
 * floatLifoSearchMin is a function who compare to cells
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
void *floatLifoSearchMin(void *a, void *b) {
	return (float)(size_t)a < (float)(size_t)b
		? a
		: b
	;
}
