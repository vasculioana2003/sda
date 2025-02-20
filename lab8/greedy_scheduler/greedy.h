#ifndef GREEDY_H
#define GREEDY_H

void read_array(int arr[],int n);
void print_array(int arr[],int n);
int recursive_activity_selector(int s[], 
    int f[], int k, int n, int sol[]
);
int greedy_activity_selector(int s[], 
    int f[], int n, int sol[]
);

#endif