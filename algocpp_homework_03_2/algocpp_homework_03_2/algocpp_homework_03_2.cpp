// algocpp_homework_03_2.cpp 

#include <iostream>
#include <Windows.h>

void print_arr(std::string str, int* arr, int size)
{
    std::cout << str;
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
};

void sort_arr(int* arr, int start, int end)
{
    int temp = 0;
    int size_y = end;
    if (start == end) return;
    else
    {
        for (int y = start; y < size_y - 1; y++)
            if (arr[y] > arr[y + 1])
            {
                temp = arr[y];
                arr[y] = arr[y + 1];
                arr[y + 1] = temp;
            }
        size_y--;
    }
    return sort_arr(arr, start, end - 1);
}

void quick_sort(int* arr, int size)
{
    int piv = 0;
    int temp;
    int start = 0;
    int end = size - 1;

 print_arr("Исходный массив: ", arr, size);

    while (start!=end) 
    {
        if (arr[start] > arr[piv]) 
        {
            if (arr[end]<=arr[piv])
            {
                temp = arr[start];
                arr[start] = arr[end];
                arr[end] = temp;
            }
            else 
            {
                end--;
            }
        }
        else 
        {
        start++;
        }
    }
   
    sort_arr(arr, 0, start);
    sort_arr(arr, end, size);
    print_arr("Отсортированный массив: ", arr, size);
    std::cout << std::endl;
}

int main()
{
    system("chcp 1251");
    system("cls");
    int* arr = new int [10] {3, 43, 38, 29, 18, 72, 57, 61, 2, 33};
    quick_sort(arr, 10);
    delete[] arr;
    int* arr1 = new int [15] {88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74};
    quick_sort(arr1, 15);
    delete[] arr1;
    int* arr2 = new int [18] {24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62};
    quick_sort(arr2, 18);
    delete[] arr2;
    return 0;
}

