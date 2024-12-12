#ifndef _YG_FIFO_H_
#define _YG_FIFO_H_

	#include <stdlib.h>
	#include <stdio.h>

	struct fifo_structure {
		void *data;
		struct fifo_structure *next;
	};

	struct fifo_head {
		struct fifo_structure *head;
		unsigned int           length;
	};

	typedef struct fifo_head fifo_t;

#endif
