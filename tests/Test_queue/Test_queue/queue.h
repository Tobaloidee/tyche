/*
 * GNU General Public License Version 3.0, 29 June 2007
 * Header file of queue.
 * Copyright (C) 2018  Sevak Amirkhanian
 * Email: amirkhanyan.sevak@gmail.com
 * For full notice please see https://github.com/amirkhaniansev/tyche/tree/master/LICENSE.
 */

#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdbool.h>
#include "list.h"

 /**
 * error codes start from 0x116
 */

#define QUEUE_DATA_SIZE_NEGATIVE	LIST_DATA_SIZE_NEGATIVE			//0x116
#define QUEUE_COMPARATOR_IS_NULL	LIST_COMPARATOR_IS_NULL 		//0x117
#define QUEUE_ASSIGNER_IS_NULL		LIST_ASSIGNER_IS_NULL			//0x118
#define	QUEUE_FINALIZER_IS_NULL		LIST_FINALIZER_IS_NULL			//0x119
#define	QUEUE_ALLOCATION_ERROR		LIST_ALLOCATION_ERROR			//0x120
#define QUEUE_IS_NULL				LIST_IS_NULL 					//0x121
#define QUEUE_IS_EMPTY				LIST_IS_EMPTY					//0x122
#define QUEUE_NODE_ALLOCATION_ERROR	LIST_NODE_ALLOCATION_ERROR		//0x123
#define QUEUE_ASSIGN_RIGHT_IS_NULL	LIST_ASSIGN_RIGHT_IS_NULL		//0x124
#define INVALID_DATA 				0x125							//0x125
#define POSITION_OUT_OF_RANGE 		0x126							//0x126
#define POSITION_NODE_IS_NULL 		0x127							//0x127
#define ITERATOR_IS_NULL 			0x128							//0x128

/**
 * Structure for queue interface.
 * Note that queue should use list for implementing storage,
 * because queue inserts occur only at the beginning.
 */
typedef struct queue_generic_structure
{
	unsigned int _count;
	unsigned int _data_size;
	bool _is_primitive_type;

	void* _storage;

	int   (*_comparator)(const void*, const void*);
	int   (*_assigner) (void*, void*);
	int   (*_finalizer)(void*);
	void* (*_copy_func)(void*);
} queue;

/**
 * queue_create - creates queue
 *
 * @data_size - data size
 * @is_primitive_type - boolean value indicating whether
 *			queue holds data of primitive type.
 *		Primitive types are considered:
 *			int
 *			short int
 *			double
 *			float
 *			char
 *			unsigned char
 *			long
 *			unsigned int
			etc.
 * @comparator - pointer to function which will be used to compare data.
 * @assigner - pointer to function which will be used to assign data.
 * @finalizer - pointer to function which will be used to finalize object.
 * @copy_func - pointer to function which will be used to copy data.
 *
 * Must be called with valid arguments, otherwise the result will be NULL.
 */
queue* queue_create(
		int* error_code,
		unsigned int data_size,
		bool is_primitive_type,
		int(*comparator)(const void*, const void*),
		int(*assigner)(void*, void*),
		int(*finalizer)(void*),
		void*(copy_func)(void*));

/**
 * queue_front - gets the first element of queue
 * @queue - queue
 * May be called with non-null argument.
 */
void* queue_front(queue* queue);

/**
 * queue_back - gets the last element of queue
 * @queue - queue
 * May be called with non-null argument
 */
void* queue_back(queue* queue);

/**
 * queue_push - pushes element to queue
 *
 * @queue - queue
 * @data - data that will be pushed to queue
 *
 * Errors
 * QUEUE_IS_NULL				 		(0x121)					if queue is NULL
 * QUEUE_NODE_ALLOCATION_ERROR			(0x123)					if queue's node allocation cannot be realized
 * INVALID_DATA							(0x125)					if data is NULL					
 * 								
 */

int queue_push(queue* queue, void* data);

/**
 * queue_pop - pops element from the queue
 *
 * @queue - queue
 * @data - data that will be popped.
 *
 * Errors
 * QUEUE_IS_NULL				 		(0x121)				if queue is NULL
 * QUEUE_IS_EMPTY						(0x122)				if queue is empty
 *
 */
int queue_pop(queue* queue);

/**
 * queue_is_empty - checks if the given queue is empty
 * @queue - queue
 */
bool queue_is_empty(queue* queue);

/**
 * destroy_queue - destroys queue
 * @queue - queue
 */
int queue_destroy(queue* queue);

#endif
