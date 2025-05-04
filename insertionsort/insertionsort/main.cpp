//
//  main.cpp
//  insertionsort
//
//  Created by Miray Çobanoğlu on 2.01.2025.
//

#include <iostream>

using namespace std;
int sayilar[] = { 5, 6, 8, 1, 88, 99, 78, 45, 36, 25, 12, 9, 7 };

void printArray(int dizi[], int size)
{
    for (int i = 0; i < size; i++)
        cout << dizi[i] << " ";
    cout << endl;
}

void insertionSort(int arr[], int n)
{
    int  deger, j;
    for (int i = 1; i < n; i++)
    {
        deger = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > deger)
        {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = deger;
        
    }
}

int main()
{
    int n = sizeof(sayilar) / sizeof(sayilar[0]);
    insertionSort(sayilar, n);
    printArray(sayilar, n);
}
