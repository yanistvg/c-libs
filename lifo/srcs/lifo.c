#include "../headers/lifo.h"

/**
 * createLifo init the structure lifo_t to use lifo functions
 * with default values
 * 
 * @returns lifo_t * if structure intialized successuly
 * @returns NULL     if an error of allocation
 * 
 * @author Yanis GENY
 * @version 1.1 : update because adding function pointer into lifo structure
 */
lifo_t *lifoCreate(void) {
	lifo_t *newLifo = NULL;

	if ((newLifo = malloc(sizeof(lifo_t))) == NULL)
		return (lifo_t *)newLifo;

	newLifo->head = (struct lifo_structure *)NULL;
	newLifo->lifo_length = (unsigned int)0x00;

	newLifo->lifoPrintCell = (void (*)(void*))NULL;
	newLifo->lifoFreeCell = (void (*)(void*))NULL;
	newLifo->lifoSearchMax = (void *(*)(void*, void*))NULL;
	newLifo->lifoSearchMin = (void *(*)(void*, void*))NULL;

	return (lifo_t *)newLifo;
}

/**
 * freeLifo delete all the lifo structure. If datas are
 * in the lifo, then, all data are delete, and the structure
 * was clean. The variable lifo was set to NULL aften the
 * deletion
 * 
 * @author Yanis GENY
 * @version 1.0
 */
void lifoFree(lifo_t **lifo) {
	if ((*lifo) == NULL) return;

	lifoDelCells(lifo);
	// set values at null before free
	(*lifo)->head = (struct lifo_structure *)NULL;
	(*lifo)->lifo_length = (unsigned int)0x00;

	(*lifo)->lifoPrintCell = (void (*)(void*))NULL;

	free(*lifo);
	(*lifo) = NULL;
}

/**
 * lifoAdd add new cell into the lifo list
 * 
 * @param lifo addresse of the lifo structure
 * @param cell addresse of the cell type undefined
 * 
 * @return _LIFO_SUCCESS_      if the cell added without problem
 * @return _LIFO_NOT_INIT_     if the lifo list are not init
 * @return _LIFO_ALLOC_FAILED_ if error with allocation
 * 
 * @author Yanis GENY
 * @version 1.0
 */
int lifoAdd(lifo_t **lifo, void *cell) {
	struct lifo_structure *newCell = (struct lifo_structure *)NULL;

	if ((*lifo) == NULL) return (int)_LIFO_NOT_INIT_;

	if ((newCell = malloc(sizeof(struct lifo_structure))) == NULL)
		return (int)_LIFO_ALLOC_FAILED_;

	newCell->data = (void *)cell;
	newCell->next = (struct lifo_structure *)(*lifo)->head;

	(*lifo)->head = (struct lifo_structure *)newCell;
	(*lifo)->lifo_length++;

	return (int)_LIFO_SUCCESS_;
}

/**
 * lifoPop delete the first element of the fifo list
 * and send back the data from the list
 * 
 * @param lifo addresse of the lifo structure
 * 
 * @return NULL            if no cell in the list
 * @return void *          the value of the first cell
 * @return _LIFO_NOT_INIT_ if the list are not init
 * 
 * @author Yanis GENY
 * @version 1.0
 */
void *lifoPop(lifo_t **lifo) {
	struct lifo_structure *firstCell = (struct lifo_structure *)NULL;
	void *cell = (void *)NULL;

	if ((*lifo) == NULL) return (void *)_LIFO_NOT_INIT_;

	if ((firstCell = (struct lifo_structure *)(*lifo)->head) == NULL)
		return (void *)NULL;

	(*lifo)->head = (struct lifo_structure *)firstCell->next;
	(*lifo)->lifo_length--;

	cell = (void *)firstCell->data;

	firstCell->data = (void *)NULL;
	free(firstCell);

	return cell;
}

/**
 * lifoPrintList print all the lifo list using the function
 * set in lifoPrintCell from the lifo structure
 * 
 * @param lifo addresse of the lifo structure
 * 
 * @return _LIFO_SUCCESS_           if lifo list printed successfuly
 * @return _LIFO_NOT_INIT_          if the lifo list are not init
 * @return _LIFO_NO_FUNC_PRINT_SET_ if no function set into lifo list
 * 
 * @author Yanis GENY
 * @version 1.0
 */
int lifoPrintList(lifo_t **lifo) {
	struct lifo_structure *cell = (struct lifo_structure *)NULL;

	if ((*lifo) == (lifo_t*)NULL) return (int)_LIFO_NOT_INIT_;

	if ((*lifo)->lifoPrintCell == NULL)
		return (int)_LIFO_NO_FUNC_PRINT_SET_;

	cell = (struct lifo_structure *)(*lifo)->head;
	while (cell != (struct lifo_structure *)NULL) {
		(*lifo)->lifoPrintCell((void *)cell->data);
		cell = (struct lifo_structure *)cell->next;
	}

	return _LIFO_SUCCESS_;
}

/**
 * lifoDelCell delete the first element of the list
 * without returning the data.
 * 
 * @param lifo addresse of the lifo structure
 * 
 * @return _LIFO_NOT_INIT_ if the lifo list are not init
 * @return _LIFO_SUCCESS_  if the first element was delete
 * 
 * @author Yanis GENY
 * @version 1.0
 */
int lifoDelCell(lifo_t **lifo) {
	struct lifo_structure *cell = (struct lifo_structure *)NULL;

	if ((*lifo) == (lifo_t*)NULL) return (int)_LIFO_NOT_INIT_;

	if ((*lifo)->lifo_length == (unsigned int)0)
		return _LIFO_SUCCESS_;

	cell = (struct lifo_structure *)(*lifo)->head;
	(*lifo)->head = (struct lifo_structure *)cell->next;
	(*lifo)->lifo_length--;

	if ((*lifo)->lifoFreeCell != (void (*)(void*))NULL)
		(*lifo)->lifoFreeCell(cell->data);
	free(cell);

	return _LIFO_SUCCESS_;
}

/**
 * lifoDelCells delete all cells from the list without
 * returning datas
 * 
 * @param lifo addresse of the lifo structure
 * 
 * @return _LIFO_NOT_INIT_ if the lifo list are not init
 * @return _LIFO_SUCCESS_  if all elements was delete
 * 
 * @author Yanis GENY
 * @version 1.0
 */
int lifoDelCells(lifo_t **lifo) {
	struct lifo_structure *cell = (struct lifo_structure *)NULL;

	if ((*lifo) == (lifo_t*)NULL) return (int)_LIFO_NOT_INIT_;

	if ((*lifo)->lifo_length == (unsigned int)0)
		return _LIFO_SUCCESS_;

	cell = (struct lifo_structure *)(*lifo)->head;
	while (cell != (struct lifo_structure *)NULL) {
		(*lifo)->head = (struct lifo_structure *)cell->next;
		if ((*lifo)->lifoFreeCell != (void(*)(void *))NULL)
			(*lifo)->lifoFreeCell((void*)cell->data);
		free(cell);
		cell = (struct lifo_structure *)(*lifo)->head;
	}

	(*lifo)->lifo_length = (unsigned int)0;

	return _LIFO_SUCCESS_;
}

/**
 * lifoDelNCells delete N cells from the list without
 * returning datas
 * 
 * @param lifo addresse of the lifo structure
 * @param N number of cells to delete
 * 
 * @return _LIFO_SUCCESS_  if N elements was delete
 * @return _LIFO_NOT_INIT_ if the lifo list are not init
 */
int lifoDelNCells(lifo_t **lifo, unsigned int N) {
	unsigned int i = 0;
	int r;

	if ((*lifo) == (lifo_t*)NULL) return (int)_LIFO_NOT_INIT_;

	while (++i <= N) {

		if ((*lifo)->lifo_length == (unsigned int)0)
			return _LIFO_SUCCESS_;

		if ((r = lifoDelCell(lifo)) != _LIFO_SUCCESS_)
			return (int)r;
	}

	return _LIFO_SUCCESS_;
}

/**
 * lifoAddNCells add N cells in the list
 * 
 * @param lifo addresse of the lifo structure
 * @param cell table of cell to add into the list
 * @param N number of cells in cell table
 * 
 * @return _LIFO_SUCCESS_      if the cell added without problem
 * @return _LIFO_NOT_INIT_     if the lifo list are not init
 * @return _LIFO_ALLOC_FAILED_ if error with allocation
 * 
 * @author Yanis GENY
 * @version 1.0
 */
int lifoAddNCells(lifo_t **lifo, void **cell, unsigned int N) {
	unsigned int i = 0;
	int r;

	if ((*lifo) == (lifo_t*)NULL) return (int)_LIFO_NOT_INIT_;

	while (++i <= N) {
		if ((r = lifoAdd(lifo, cell[i-1])) != _LIFO_SUCCESS_)
			return r;
	}

	return _LIFO_SUCCESS_;
}

/**
 * lifoGetCell give a cell int the list found by is index
 * 
 * @param lifo addresse of the lifo structure
 * @param index of the cell to get
 * 
 * @return void*               addr of the data into the cell
 * @return _LIFO_NOT_INIT_     if the lifo list are not init
 * @return _LIFO_OUT_OF_RANGE_ if index is gretter than the number of cells
 * 
 * @author Yanis GENY
 * @version 1.0
 */
void *lifoGetCell(lifo_t **lifo, unsigned int index) {
	struct lifo_structure *cell = (struct lifo_structure *)NULL;
	unsigned int i=0;

	if ((*lifo) == (lifo_t*)NULL)  return (void*)_LIFO_NOT_INIT_;
	if ((*lifo)->lifo_length < index) return (void*)_LIFO_OUT_OF_RANGE_;

	cell = (struct lifo_structure *)(*lifo)->head;
	while (i++ < index) cell = (struct lifo_structure *)cell->next;

	return (void*)cell->data;
}

/**
 * lifoMax search the cell this the value greater. This function
 * use lifoSearchMax function do create by the developer
 * 
 * @param lifo addresse of the lifo structure
 * 
 * @return void* addr of the greatter cell
 * @return NULL if the list are not init or no cells is in the list
 * or the function lifoSearchMax are not set
 * 
 * @author Yanis GENY
 * @version 1.0
 */
void *lifoMax(lifo_t **lifo) {
	void *max;
	struct lifo_structure *cell;

	if ((*lifo) == (lifo_t*)NULL)  return (void*)NULL;
	if ((*lifo)->lifo_length <= 0) return (void*)NULL;
	if ((*lifo)->lifoSearchMax == (void *(*)(void*,void*))NULL) return NULL;

	max = (void*)((*lifo)->head->data);
	cell = (struct lifo_structure *)((*lifo)->head->next);

	while (cell != (struct lifo_structure *)NULL) {
		max = (void*)(*lifo)->lifoSearchMax(max, cell->data);
		cell = (struct lifo_structure *)cell->next;
	}

	return max;
}

/**
 * lifoMin search the cell this the value minesse. This function
 * use lifoSearchMin function do create by the developer
 * 
 * @param lifo addresse of the lifo structure
 * 
 * @return void* addr of the minesse cell
 * @return NULL if the list are not init or no cells is in the list
 * or the function lifoSearchMin are not set
 * 
 * @author Yanis GENY
 * @version 1.0
 */
void *lifoMin(lifo_t **lifo) {
	void *min;
	struct lifo_structure *cell;

	if ((*lifo) == (lifo_t*)NULL)  return (void*)NULL;
	if ((*lifo)->lifo_length <= 0) return (void*)NULL;
	if ((*lifo)->lifoSearchMin == (void *(*)(void*,void*))NULL) return NULL;

	min = (void*)((*lifo)->head->data);
	cell = (struct lifo_structure *)((*lifo)->head->next);

	while (cell != (struct lifo_structure *)NULL) {
		min = (void*)(*lifo)->lifoSearchMin(min, cell->data);
		cell = (struct lifo_structure *)cell->next;
	}

	return min;
}
