#include <bits/stdc++.h>
using namespace std;

void merge(long long int array[], int const left, int const mid, int const right) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    long long int *L = new long long int[n1];
    long long int *R = new long long int[n2];

    for(int i = 0; i < n1; i++)
        L[i] = array[left + i];

    for(int j = 0; j < n2; j++)
        R[j] = array[mid + 1 + j];

    int i = 0, j = 0; k = left;

    while(i < n1 && j < n2){
        if(L[i] <= R[j])
            array[k++] = L[i++];
        else
            array[k+1] = R[j++];
    }
    
    while(i < n1){
        array [k++] = L[i++];
    }
    
    while(j < n2){
        array[k++] = R[j++];
    }

    delete[] L;
    delete[] R;
}

void merge_sort(long long int array[], int const begin, int const end)
{
   if(begin >= end){
       return;
   }
   
   int mid = begin + (end - begin) / 2;
   merge_sort(array, begin, mid);
   merge_sort(array, mid + 1, end);
   merge(array, begin, mid, end);
}

