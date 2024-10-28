#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "darray.h"

// Define the data structure of a darray.
struct darray{
    // Size of the darray in bytes.
    size_t size_in_bytes;
    long 
};

darray *da_create() { 
    // Creates a pointer called array. 
    // Assigns it to point to a block of memory of size 0.
    // malloc then creates space for 0 integers, or 0 * 4 bytes = 0 bytes
    // malloc returns the starting block in memory, or NULL if it fails.
    darray *create_array = malloc(0 * sizeof(int)); 
    // Define that this new array has a size of 0.
    create_array->size_in_bytes = 0;
    // Return array's memory address as an int, or NULL if malloc failed.
    return create_array;
}

int *da_get(darray *array, size_t idx) {
    // IF the array passed into da_get is NULL or the index passed in idx is greater than the size of the array,
    if (NULL == array | (idx < 0 || idx > array->size_in_bytes)) {
        // return NULL.
        printf("idx: NULL\n");
        return NULL;
    // Otherwise,
    } else {
        int *pIdx = &array[idx];
        printf("idx: %d\n",*pIdx);
        return *pIdx;
    }
}

int da_append(darray *array, int value) {
    // IF the array passed into da_append is NULL,
    if (NULL == array) {
        // return 0.
        printf("array is: NULL\n");
        return 0;
    // Otherwise if not NULL,
    } else {
        // reallocate memory by adding 1 more byte in memory.
        // holds reallocated memory in a temp pointer.
        darray *temp_array = realloc(array, sizeof(int)*(array->size_in_bytes)+1);
        if (NULL == temp_array) {
            printf("realloc failed\n");
            return 0;
        }
        // something
        return 1;
    }
}

size_t da_size(darray *array) {

}

void da_delete(darray *array) {

}

int main() {
    darray *array = da_create();
    da_get(array, 0);
    da_get(array, 1);
    da_get(array, 2);
    da_append(array, 42);
}