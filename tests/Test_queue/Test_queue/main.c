#include "queue.h"
#include <stdio.h>

#define n 16
int comparator(const void*a, const void*b) {

	return 0;
}
int assigner(void*a, void*b) {
	return 0;
}
int finalizer(void*a) {
	return 0;
}
void* copy_func(void*a) {
	return a;
}

int main() {
	queue *l;
	int error = 0;
	l = queue_create(&error, sizeof(int), true, &comparator, &assigner, &finalizer, &copy_func);
	if (error != 0)wprintf(L"Error create %d \n", error);
	
	

	int a[n];
	for (int i = 0; i < n; i++)a[i] = 2*i;
	//getchar();
	for (int i = 0; i < n; i++) {
		error = queue_push(l, &a[i]);
		if (error != 0)
		{
			wprintf(L"Error %d\n", error);
			getchar();
		}
	}
	
	wprintf(L"Count %d\n", l->_count);


	while(!queue_is_empty(l)){
		int *x = queue_front(l);
		wprintf(L"at %d\n", *x);
		queue_pop(l);
	}

	wprintf(L"Count %d\n", l->_count);
	//getchar();
	queue_destroy(l);
	getchar();
	return 0;
}