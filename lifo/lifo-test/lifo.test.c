#include "lifo.test.h"

lifo_t *lifo = NULL;

/**
 * lifo_test_with_not_inti_lifo execute all function for the lifo
 * with structure not init, and verify if all functions return
 * error _LIFO_NOT_INIT_
 * 
 * @return 0  if success
 * @return -1 if failed
 * 
 * @author Yanis GENY
 * @version 1.0
 */
int lifo_test_with_not_init_lifo(void) {
	int returned_value;

	printf("Test lifo functions with structure not init\n");

	/** lifoPop function      **/
	returned_value = (int)(size_t)lifoPop(&lifo);
	if (returned_value != _LIFO_NOT_INIT_) {
		printf("\t%slifoFree not returne _LIFO_NOT_INIT_: ERROR\n", NOK);
		return -1;
	}
	printf("\t%slifoFree returne _LIFO_NOT_INIT_: SUCCESS\n", OK);

	/** lifoAdd function       **/
	returned_value = lifoAdd(&lifo, (void*)0xDEADC0DE);
	if (returned_value != _LIFO_NOT_INIT_) {
		printf("\t%slifoAdd not returne _LIFO_NOT_INIT_: ERROR\n", NOK);
		return -1;
	}
	printf("\t%slifoAdd returne _LIFO_NOT_INIT_: SUCCESS\n", OK);

	/** lifoPrintList function **/
	returned_value = lifoPrintList(&lifo);
	if (returned_value != _LIFO_NOT_INIT_) {
		printf("\t%slifoPrintList not returne _LIFO_NOT_INIT_: ERROR\n", NOK);
		return -1;
	}
	printf("\t%slifoPrintList returne _LIFO_NOT_INIT_: SUCCESS\n", OK);

	/** lifoDelCell function   **/
	returned_value = lifoDelCell(&lifo);
	if (returned_value != _LIFO_NOT_INIT_) {
		printf("\t%slifoDelCell not returne _LIFO_NOT_INIT_: ERROR\n", NOK);
		return -1;
	}
	printf("\t%slifoDelCell returne _LIFO_NOT_INIT_: SUCCESS\n", OK);

	/** lifoDelCells function  **/
	returned_value = lifoDelCells(&lifo);
	if (returned_value != _LIFO_NOT_INIT_) {
		printf("\t%slifoDelCells not returne _LIFO_NOT_INIT_: ERROR\n", NOK);
		return -1;
	}
	printf("\t%slifoDelCells returne _LIFO_NOT_INIT_: SUCCESS\n", OK);

	/** lifoDelNCells function **/
	returned_value = lifoDelNCells(&lifo, 10);
	if (returned_value != _LIFO_NOT_INIT_) {
		printf("\t%slifoDelNCells not returne _LIFO_NOT_INIT_: ERROR\n", NOK);
		return -1;
	}
	printf("\t%slifoDelNCells returne _LIFO_NOT_INIT_: SUCCESS\n", OK);

	/** lifoAddNCells fuction  **/
	returned_value = lifoAddNCells(&lifo, (void**)(size_t){10}, 10);
	if (returned_value != _LIFO_NOT_INIT_) {
		printf("\t%slifoAddNCells not returne _LIFO_NOT_INIT_: ERROR\n", NOK);
		return -1;
	}
	printf("\t%slifoAddNCells returne _LIFO_NOT_INIT_: SUCCESS\n", OK);

	return 0;
}
