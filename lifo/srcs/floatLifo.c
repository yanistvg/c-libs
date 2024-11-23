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



/**********************************************/
/***                                        ***/
/*** Functions to set in the lifo structure ***/
/***                                        ***/
/**********************************************/

/**
 * intLifoPrintCell is the function to store in lifo structure
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
 * intLifoSearchMax is a function who compare to cells
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
 * intLifoSearchMin is a function who compare to cells
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
