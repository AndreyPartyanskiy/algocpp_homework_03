// algocpp_homework_03_1.cpp 

#include <iostream>
#include <Windows.h>

void print_arr(std::string str,int* arr, int size) 
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

void merge_sort(int* arr, int size)
{
    if (size == 0) return;
    int size_rights = size / 2;
    int left = 0;
    int right = size_rights;
    int res = 0;
    int* arr_temp = new int [size] {};

    print_arr("Исходный массив: ", arr, size);

    sort_arr(arr,0,size_rights);
    sort_arr(arr,size_rights,size);

    while (left < size_rights || right < size)
    {

        if (left == size_rights)
        {
            arr_temp[res] = arr[right];
            ++right;
        }
        else
        {
            if (right == size)
            {
                arr_temp[res] = arr[left];
                ++left;
            }

            else
            {
                if (arr[left] < arr[right])
                {
                    arr_temp[res] = arr[left];
                    ++left;
                }
                else
                {
                    arr_temp[res] = arr[right];
                    ++right;
                }
            }
        }
        ++res;
    }
    print_arr("Отсортированный массив: ", arr_temp, size);
    std::cout << std::endl;
}



int main()
{
    system("chcp 1251");
    system("cls");
    int* arr = new int [10] {3, 43, 38, 29, 18, 72, 57, 61, 2, 33};
    merge_sort(arr, 10);
    delete[] arr;
    int* arr1 = new int [15] {88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74};
    merge_sort(arr1, 15);
    delete[] arr1;
    int* arr2 = new int [18] {24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62};
    merge_sort(arr2, 18);
    delete[] arr2;
    return 0;
}


