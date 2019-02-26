#include <iostream>
int * Reverse_Array(int[], int);

int main() {
    int array[6] = {1,2,3,4,5};
    Reverse_Array(array, 5);

    return 0;
}


int * Reverse_Array(int arr[], int size) {
    int new_array[size];
    int * array_ptr;

    array_ptr = &arr[size-1];
    for(int i = 0; i < size; i++)
    {
        new_array[i] = *array_ptr;
        array_ptr--;
    }

    for(int i = 0; i < size; i++)
        printf("%d ",new_array[i]);


    return array_ptr;
}
