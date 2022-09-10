/**
 *  \addtogroup sorting Sorting Algorithms
 *  @{
 *  \file
 *  \brief [Merege Sort Algorithm
 *  (MEREGE SORT)](https://en.wikipedia.org/wiki/Merge_sort) implementation
 *
 *  \author [Ayaan Khan](http://github.com/ayaankhan98)
 *
 *  \details
 *  Merge Sort is an efficient, general purpose, comparison
 *  based sorting algorithm.
 *  Merge Sort is a divide and conquer algorithm
 *
 */
#include <iostream>

/**
 *
 * The merge() function is used for merging two halves.
 * The merge(arr, l, m, r) is key process that assumes that
 * arr[l..m] and arr[m+1..r] are sorted and merges the two
 * sorted sub-arrays into one.
 *
 * @param arr - array with two halves arr[l...m] and arr[m+1...l]
 * @param l - left index or start index of first half array
 * @param m - right index or end index of first half array
 *
 * (The second array starts form m+1 and goes till l)
 *
 * @param r - end index or right index of second half array
 */
void merge(int *arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    
    // n1 is the size of first array, n2 is the size of second array.

    int *L = new int[n1], *R = new int[n2];
    
    // Created two arrays namely 'L' and 'R' of sizes n1 and n2 respectively.

    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    
    /** 
       * Populated the arrays 'L' and 'R' from the array 'arr', because now we are going to do changes in 'arr'.
       * The merged result will be stored in 'arr' itself. 
    **/

    i = 0;
    j = 0;
    k = l;
    
    /** 
       * Here i is used for traversing 'L', j is for 'R' and k is for traversing 'arr'.
       * k is initialised with l (i.e. k=l) because we are only considering array 'arr' from l to r.
       * We are assuming that arr[l..m] and arr[m+1..r] are sorted, hence the arrays 'L' and 'R' are sorted respectively.
    **/
    
    while (i < n1 and j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    /** 
      * Now there will be one array which is not traversed completely, but we know for sure that remaining elements in that array are sorted 
        and all are greater than previosly traversed elements. Thus we can simply assign them to arr[].
    **/
    
    while(i<n1){
        arr[k] = L[i];
        k++;
        i++;
    }
    
    while(j<n2){
        arr[k]=R[j];
        k++;
        j++;
    }

    delete[] L;
    delete[] R;
}

/**
 * Merge sort is a divide and conquer algorithm, it divides the
 * input array into two halves and calls itself for the two halves
 * and then calls merge() to merge the two halves
 *
 * @param arr - array to be sorted
 * @param l - left index or start index of array
 * @param r - right index or end index of array
 *
 */
void mergeSort(int *arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

/**
 * Utility function used to print the array after
 * sorting
 */
void show(int *arr, int size) {
    for (int i = 0; i < size; i++) std::cout << arr[i] << " ";
    std::cout << "\n";
}

/** Main function */
int main() {
    int size;
    std::cout << "Enter the number of elements : ";
    std::cin >> size;
    int *arr = new int[size];
    std::cout << "Enter the unsorted elements : ";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }
    mergeSort(arr, 0, size - 1);
    std::cout << "Sorted array : ";
    show(arr, size);
    delete[] arr;
    return 0;
}
/** @} */
