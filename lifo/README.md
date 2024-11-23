# Last In First Out

Librairie de liste chainée Last In First Out (LIFO). Cette librairie est prévue pour être générique.

Sommaire :
- [How to compile with this lib](#how-to-compile-with-this-lib)
- [Exemple LIFO Générique](#exemple-lifo-générique)
- [Exemple LIFO int](#exemple-lifo-int)

## How to compile with this lib

```bash
git clone https://github.com/yanistvg/c-libs.git
cd c-lib/lifo
make
cp liblifo.so /path/to/your/project/
cp headers/lifo.h /path/to/your/project/
cd /path/to/your/project/
```

Now in your project you have the librairie compiled and the header file. To use it in your code do this

```c
#include "lifo.h"

int main(int argc, char **argv) {
	lifo_t *lifo;

	/* write your code using the lifo lib */
}
```

To finish, the comilation with the librairie do

```bash
gcc main.c -L./ -llifo -o main
```


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
