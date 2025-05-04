//
//  main.cpp
//  selection sort
//
//  Created by Miray Çobanoğlu on 17.01.2025.
//

// Selection Sort
#include <iostream>
using namespace std;

int main(){
    int A[10]={20,10,50,60,1,12,90,30,44,5};
    int i, j, x, minIndex=0, min;
    
    for(j=0; j<=9; j++){
        min=9999999;
        for(i=0; i<=9; i++){
            if (min>A[i]){
                min = A[i];
                minIndex = i; // min'in bulundugu yer
            }
        }
        
        // SWAP
        x = A[j];
        A[j] = A[minIndex];
        A[minIndex] = x;
        
    //    A[minIndex] = 9999999;
        
    }
    
    for(i=0; i<=9; i++)
        cout << A[i] << " ";
    
    return 0;
}




/*
 Kodun Çalışma Örneği
 Başlangıç Dizisi

 20, 10, 50, 60, 1, 12, 90, 30, 44, 5
 Adım Adım Sıralama
 İlk turda en küçük eleman (1) en başa alınır:


 1, 10, 50, 60, 20, 12, 90, 30, 44, 5
 İkinci turda 5 ikinci sıraya alınır:


 1, 5, 50, 60, 20, 12, 90, 30, 44, 10
 Bu şekilde sıralama devam eder ve sonunda dizi şu hale gelir:


 1, 5, 10, 12, 20, 30, 44, 50, 60, 90
 
 
 
 Sonuç

 1 5 10 12 20 30 44 50 60 90







 */
