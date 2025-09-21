#include <bits/stdc++.h>
using namespace std;

void merge(long long int array[], int const left, int const mid, int const right) 
{
    int s1 = mid - left + 1;
    int s2 = right - mid;

    long long int *a1 = new long long int[s1];
    long long int *a2 = new long long int[s2];

    for (int i = 0; i < s1; i++)
        a1[i] = array[left + i];
    for (int j = 0; j < s2; j++)
        a2[j] = array[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    while (i < s1 && j < s2) {
        if (a1[i] <= a2[j]) {
            array[k] = a1[i];
            i++;
        } else {
            array[k] = a2[j];
            j++;
        }
        k++;
    }

    while (i < s1) {
        array[k] = a1[i];
        i++;
        k++;
    }

    while (j < s2) {
        array[k] = a2[j];
        j++;
        k++;
    }

    delete[] a1;
    delete[] a2;
}

void merge_sort(long long int array[], int const begin, int const end)
{
   if (begin >= end)
        return;

    int m = begin + (end - begin) / 2;
    merge_sort(array, begin, m);
    merge_sort(array, m + 1, end);
    merge(array, begin, m, end);
}








