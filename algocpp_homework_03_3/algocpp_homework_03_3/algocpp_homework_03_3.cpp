// algocpp_homework_03_3.cpp 


#include <iostream>
#include <Windows.h>

void print_arr(std::string str, int* arr, int size)
{
    std::cout << str;
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
};

void count_sort(int* arr, int size)
{
    int min = 10;
    int max = 24;
    int* arr_temp = new int [max - min +1] {};
    int r=0;

    print_arr("Исходный массив: ", arr, size);

    for (int i = 0; i < size; i++)
    {
        arr_temp[arr[i]-min]++;
    }
  
    for (int i = 0; i < (max - min+1); i++)
    {
        for (int y = 0; y < arr_temp[i]; y++) 
        {
            arr[r] = i +min;          
            r++;
        }
    }
    
    print_arr("Отсортированный массив: ", arr, size);
    std::cout << std::endl;
}



int main()
{
    system("chcp 1251");
    system("cls");
    int* arr = new int [30] {19, 14, 22, 22, 17, 22, 13, 21, 20, 24, 18, 10, 17, 16, 17, 20, 22, 11, 20, 16, 14, 13, 10, 22, 18, 14, 16, 24, 19, 17};
    count_sort(arr, 30);
    delete[] arr;
    int* arr1 = new int [40] {16, 17, 14, 20, 22, 20, 17, 22, 16, 19, 23, 24, 20, 22, 21, 18, 14, 16, 17, 21, 10, 11, 19, 23, 11, 11, 17, 17, 11, 21, 17, 11, 17, 16, 12, 11, 16, 22, 23, 16};
    count_sort(arr1, 40);
    delete[] arr1;
    int* arr2 = new int [45] {21, 15, 19, 18, 23, 12, 18, 18, 19, 23, 12, 20, 15, 22, 21, 18, 19, 20, 12, 16, 20, 14, 17, 13, 10, 23, 19, 14, 10, 22, 19, 12, 24, 23, 22, 15, 13, 22, 18, 18, 11, 23, 24, 17, 10};
    count_sort(arr2, 45);
    delete[] arr2;
    return 0;
}
