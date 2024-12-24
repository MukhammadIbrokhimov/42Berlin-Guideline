#include "push_swap.h"

// Helper function to extract elements of the same chunk into an array
void extract_chunk_elements(t_list *list, int chunk, int *arr) {
    int index = 0;
    while (list) {
        if (list->chunk == chunk) {
            arr[index++] = list->content;
        }
        list = list->next;
    }
}

// Partition function for Quickselect
int partition(int arr[], int left, int right, int pivot) {
    int pivotValue = arr[pivot];
    int temp = arr[pivot];
    arr[pivot] = arr[right];
    arr[right] = temp;

    int storeIndex = left;
    for (int i = left; i < right; i++) {
        if (arr[i] < pivotValue) {
            temp = arr[i];
            arr[i] = arr[storeIndex];
            arr[storeIndex] = temp;
            storeIndex++;
        }
    }

    temp = arr[storeIndex];
    arr[storeIndex] = arr[right];
    arr[right] = temp;

    return storeIndex;
}

// Quickselect function
int quickselect(int arr[], int left, int right, int k) {
    if (left == right) {
        return arr[left];
    }

    int pivotIndex = left + rand() % (right - left + 1);
    pivotIndex = partition(arr, left, right, pivotIndex);

    if (k == pivotIndex) {
        return arr[k];
    } else if (k < pivotIndex) {
        return quickselect(arr, left, pivotIndex - 1, k);
    } else {
        return quickselect(arr, pivotIndex + 1, right, k);
    }
}

// Find the median of elements with the same chunk
int findMedian(t_list *list, int chunk) 
{
    // Count elements with the same chunk
    int n = ft_chunksize(list, chunk);

    if (n == 0) {
        printf("No elements found with chunk %d\n", chunk);
        return 0;
    }

    // Extract elements into an array
    int *arr = (int *)malloc(n * sizeof(int));
    extract_chunk_elements(list, chunk, arr);

    // Find the median using Quickselect
    int median;
    if (n % 2 == 1) {
        median = quickselect(arr, 0, n - 1, n / 2);
    } else {
        int mid1 = quickselect(arr, 0, n - 1, n / 2 - 1);
        int mid2 = quickselect(arr, 0, n - 1, n / 2);
        median = (mid1 + mid2) / 2.0;
    }

    free(arr);
    return median;
}

//// Main function to test
//int main() {
//    // Create a doubly linked list
//    t_list nodes[] = {
//        {0, 1, &nodes[1], NULL},
//        {2, 1, &nodes[2], &nodes[0]},
//        {4, 1, &nodes[3], &nodes[1]},
//        {3, 1, &nodes[4], &nodes[2]},
//        {6, 1, &nodes[5], &nodes[3]},
//        {8, 1, &nodes[6], &nodes[4]},
//        {9, 2, &nodes[7], &nodes[5]},
//        {12, 0, &nodes[8], &nodes[6]},
//        {34, 0, NULL, &nodes[7]}
//    };

//    int chunk = 1; // Change this to test for different chunks
//    int median = findMedian(nodes, chunk);
//    printf("Median of chunk %d: %d\n", chunk, median);

//    return 0;
//}
