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
 * @version 1.1 : Delation of "SUCCESS" ans "ERROR" in all printf
 */
int lifo_test_with_not_init_lifo(void) {
	int returned_value;

	printf("Test lifo functions with structure not init\n");

	/** lifoPop function      **/
	returned_value = (int)(size_t)lifoPop(&lifo);
	if (returned_value != _LIFO_NOT_INIT_) {
		printf("\t%slifoFree not returne _LIFO_NOT_INIT_\n", NOK);
		return -1;
	}
	printf("\t%slifoFree returne _LIFO_NOT_INIT_\n", OK);

	/** lifoAdd function       **/
	returned_value = lifoAdd(&lifo, (void*)0xDEADC0DE);
	if (returned_value != _LIFO_NOT_INIT_) {
		printf("\t%slifoAdd not returne _LIFO_NOT_INIT_\n", NOK);
		return -1;
	}
	printf("\t%slifoAdd returne _LIFO_NOT_INIT_\n", OK);

	/** lifoPrintList function **/
	returned_value = lifoPrintList(&lifo);
	if (returned_value != _LIFO_NOT_INIT_) {
		printf("\t%slifoPrintList not returne _LIFO_NOT_INIT_\n", NOK);
		return -1;
	}
	printf("\t%slifoPrintList returne _LIFO_NOT_INIT_\n", OK);

	/** lifoDelCell function   **/
	returned_value = lifoDelCell(&lifo);
	if (returned_value != _LIFO_NOT_INIT_) {
		printf("\t%slifoDelCell not returne _LIFO_NOT_INIT_\n", NOK);
		return -1;
	}
	printf("\t%slifoDelCell returne _LIFO_NOT_INIT_\n", OK);

	/** lifoDelCells function  **/
	returned_value = lifoDelCells(&lifo);
	if (returned_value != _LIFO_NOT_INIT_) {
		printf("\t%slifoDelCells not returne _LIFO_NOT_INIT_\n", NOK);
		return -1;
	}
	printf("\t%slifoDelCells returne _LIFO_NOT_INIT_\n", OK);

	/** lifoDelNCells function **/
	returned_value = lifoDelNCells(&lifo, 10);
	if (returned_value != _LIFO_NOT_INIT_) {
		printf("\t%slifoDelNCells not returne _LIFO_NOT_INIT_\n", NOK);
		return -1;
	}
	printf("\t%slifoDelNCells returne _LIFO_NOT_INIT_\n", OK);

	/** lifoAddNCells fuction  **/
	returned_value = lifoAddNCells(&lifo, (void**)(size_t){10}, 10);
	if (returned_value != _LIFO_NOT_INIT_) {
		printf("\t%slifoAddNCells not returne _LIFO_NOT_INIT_\n", NOK);
		return -1;
	}
	printf("\t%slifoAddNCells returne _LIFO_NOT_INIT_\n", OK);

	return 0;
}

/**
 * lifo_test_create_and_destroy_lifo create an new lifo structure
 * and verify if the creation successfuly and if the delation succcess
 * too
 * 
 * @return 0  if success
 * @return -1 if failed
 * 
 * @author Yanis GENY
 * @version 1.1 : verify new pointer of fuction added in the structure
 */
int lifo_test_create_and_destroy_lifo(void) {
	int errors = 0x00;

	printf("Test lifo functions: create and destroy lifo\n");

	lifo = lifoCreate();
	if (lifo == NULL) {
		printf("\t%s Creation of structure\n", NOK);
		return -1;
	}
	printf("\t%s Creation of structure\n", OK);

	lifo->head == NULL
		? printf("\t%s lifoCreate: no cell create\n", OK)
		: printf("\t%s lifoCreate: no cell create, error : %d\n", NOK, (++errors))
	;

	lifo->lifo_length == (unsigned int)0
		? printf("\t%s lifoCreate: cell counter at 0\n", OK)
		: printf("\t%s lifoCreate: cell counter at 0, error : %d\n", NOK, (++errors))
	;

	lifo->lifoPrintCell == NULL
		? printf("\t%s lifoCreate: lifoPrintCell init at NULL\n", OK)
		: printf("\t%s lifoCreate: lifoPrintCell init at NULL, error : %d\n", NOK, (++errors))
	;

	lifo->lifoFreeCell == NULL
		? printf("\t%s lifoCreate: lifoFreeCell init at NULL\n", OK)
		: printf("\t%s lifoCreate: lifoFreeCell init at NULL, error : %d\n", NOK, (++errors))
	;

	lifo->lifoSearchMax == NULL
		? printf("\t%s lifoCreate: lifoSearchMax init at NULL\n", OK)
		: printf("\t%s lifoCreate: lifoSearchMax init at NULL, error : %d\n", NOK, (++errors))
	;

	lifo->lifoSearchMin == NULL
		? printf("\t%s lifoCreate: lifoSearchMin init at NULL\n", OK)
		: printf("\t%s lifoCreate: lifoSearchMin init at NULL, error : %d\n", NOK, (++errors))
	;

	lifoFree(&lifo);
	lifo == NULL
		? printf("\t%s lifoFree: reset to NULL\n", OK)
		: printf("\t%s lifoFree: reset to NULL\n", NOK)
	;
	if (lifo != NULL || errors) return -1;
	return 0;
}

/**
 * lifo_test_cell_creation_and_delation interat with list
 * to verify the great working of lifo functions
 * 
 * @return 0  if success
 * @return -1 if failed
 * 
 * @author Yanis GENY
 * @version 1.0
 */
int lifo_test_cell_creation_and_delation(void) {
	void *cells[10] = {
		(void *)1, (void *)2, (void *)3, (void *)4, (void *)5,
		(void *)6, (void *)7, (void *)8, (void *)9, (void *)10
	};
	int i;
	void *data;
	int errors = 0x00, tmp_error = 0x00;

	printf("Test lifo: cells creation and delation\n");

	lifo = lifoCreate();

	// lifoAdd verify if cell is created
	lifoAdd(&lifo, cells[0]);
	lifo->lifo_length == 1
		? printf("\t%s lifoAdd: length after adding one cell\n", OK)
		: printf("\t%s lifoAdd: length after adding one cell\n", NOK)
	;
	errors += lifo->lifo_length == 1 ? 0 : 1;

	// lifoPop verify is cell as good extracted
	data = lifoPop(&lifo);
	lifo->lifo_length == 0
		? printf("\t%s lifoPop: length after del one cell\n", OK)
		: printf("\t%s lifoPop: length after del one cell\n", NOK)
	;
	errors += lifo->lifo_length == 0 ? 0 : 1;
	data == cells[0]
		? printf("\t%s lifoPop: data extracted\n", OK)
		: printf("\t%s lifoPop: data extracted\n", NOK)
	;
	errors += data == cells[0] ? 0 : 1;

	// lifoAddNCells add multiple cells
	lifoAddNCells(&lifo, cells, 10);
	lifo->lifo_length == 10
		? printf("\t%s lifoAddNCells: length after add multi cells\n", OK)
		: printf("\t%s lifoAddNCells: length after add multi cells\n", NOK)
	;
	errors += lifo->lifo_length == 10 ? 0 : 1;

	// Verify order of cells
	for (i=0; i<10; i++) {
		data = lifoGetCell(&lifo, i);
		tmp_error += data == cells[9-i] ? 0 : 1;
	}
	tmp_error == 0
		? printf("\t%s lifoGetCell: all cells get correctly\n", OK)
		: printf("\t%s lifoGetCell: all cells get correctly, errors:%d\n", NOK, tmp_error)
	;
	errors += tmp_error;

	// lifoDelNCells
	lifoDelNCells(&lifo, 3);
	data = lifoGetCell(&lifo, 0);
	data == (void *)7
		? printf("\t%s lifoDelNCells: delation of 3 cells\n", OK)
		: printf("\t%s lifoDelNCells: delation of 3 cells\n", NOK)
	;
	errors += data == (void *)7 ? 0 : 1;

	lifo->lifo_length == 7
		? printf("\t%s lifoDelNCells: lifo_length\n", OK)
		: printf("\t%s lifoDelNCells: lifo_length\n", NOK)
	;
	errors += lifo->lifo_length == 7 ? 0 : 1;


	if (errors) return -1;

	lifoFree(&lifo);
	return 0;
}
