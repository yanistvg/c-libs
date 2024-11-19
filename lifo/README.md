# Last In First Out

Librairie de liste chainée Last In First Out (LIFO). Cette librairie est prévue pour être générique.

Sommaire :
- [Exemple LIFO Générique](#exemple-lifo-générique)
- [Exemple LIFO int](#exemple-lifo-int)


## Exemple LIFO Générique

```c
struct myStruct {
	int a;
	int b;
};

lifo_t *lifo = lifoCreate();

struct myStruct value1 = {13, 5};
struct myStruct value2 = {6 , 1};

lifoAdd(&lifo, &value1);
lifoAdd(&lifo, &value2);

struct myStruct *value = lifoPop(&lifo);
```

## Exemple LIFO int

```c
lifo_t *lifo = intLifoCreate();

intLifoAdd(&lifo, 10);
intLifoAdd(&lifo, -1);

intLifoPrintList(&lifo);

int value = intLifoPop(&lifo);
```
