#include <iostream>
#include "sort.hpp"

template<class T>
void printArray(T arr[], size_t size)
{
    for(size_t i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}


int main()
{
    int arr[] = {4, 0, 0, 0, 0};
    size_t size = 5;
    printArray(arr, size);
    //quickSort(arr, size);
    hybridSort(arr, size);
    printArray(arr, size);
    return 0;
}