#include "headers/lifo.h"

int main(void) {
	lifo_t *myLifo = NULL;
	int tab[3] = {3, 6, 8};

	myLifo = intLifoCreate();


	intLifoAdd(&myLifo, 10);
	intLifoAdd(&myLifo, 9);
	intLifoAdd(&myLifo, 8);
	intLifoAdd(&myLifo, 2);
	intLifoAdd(&myLifo, 1);

	intLifoPrintList(&myLifo);
	intLifoPop(&myLifo);
	intLifoPrintList(&myLifo);
	intLifoPop(&myLifo);
	intLifoPrintList(&myLifo);
	intLifoPop(&myLifo);
	intLifoPrintList(&myLifo);
	intLifoPop(&myLifo);
	intLifoPrintList(&myLifo);
	intLifoPop(&myLifo);
	intLifoPrintList(&myLifo);

	intLifoAddNCells(&myLifo, tab, 3);
	intLifoPrintList(&myLifo);

	lifoFree(&myLifo);


	return 0;
}
