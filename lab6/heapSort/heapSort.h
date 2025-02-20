#ifndef HEAPSORT_H
#define HEAPSORT_H

extern int HEAP_SIZE;

int left(int n);
int right(int n);
void max_heapify(int array[], int n, int i);
void build_max_heap(int array[], int n);
void heap_sort(int array[], int n);
void read_array_heap(int array[], int n);
void print_array_heap(int array[], int n);

#endif // HEAPSORT_H
