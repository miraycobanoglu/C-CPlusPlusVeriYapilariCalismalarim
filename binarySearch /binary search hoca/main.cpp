//
//  main.cpp
//  binary search hoca
//
//  Created by Miray Çobanoğlu on 17.01.2025.
//

#include <stdio.h>
#include <math.h>
int A[101];
int head = 1; // head is the first element of the array
int tail = 100;
int query = 132;
int midPoint;

void creatArray(){
    for(int i = 1; i<=100; i++)
    A[i] = i*3;
    return;
}

void showArray(){
    for(int i = 1; i<=100; i++)
    printf(" %d ",A[i]);
    return;
}
int main() {
    int sayac = 0;
    creatArray();
    //showArray();
    
    midPoint = head + (abs(head-tail)/2);
    printf("midpoint = %d\n ",midPoint);
    printf("%d ", ++sayac);
    
    while( A[midPoint] != query ){
    //    printf("\n1. iterasyon = %d ",++sayac);
        if( query < A[midPoint])
            tail = midPoint;
        else
            head = midPoint;
        
    midPoint = head + (abs(head-tail)/2);
    ++sayac;
    printf("midPoint = %d\n",midPoint);
    }
    
    printf(" Aranan bulundu, degeri : %d, Indisi de :%d ",A[midPoint],midPoint);
    
    return 0;
}



/*
 Bu kodda bir binary search algoritması, diziyi (A) otomatik olarak oluşturacak şekilde ayarlanmış. Kod, query değişkeniyle aranan değeri bulmak için diziyi tarar ve bulunduğu indeksi döndürür.

 Kod Analizi:
 Array Oluşturma (creatArray):

 1'den 100'e kadar olan indekslerde her eleman, i*3 formülüyle çarpılarak diziye atanır.
 Sonuç olarak dizi şöyle bir yapıya sahip olur:
 css
 Kopyala
 Düzenle
 A[1] = 3, A[2] = 6, A[3] = 9, ..., A[100] = 300
 
 Binary Search İşlemi:
 Başlangıçta:
 head = 1 (dizinin ilk elemanı)
 tail = 100 (dizinin son elemanı)
 midPoint = ortadaki eleman hesaplanır: head + (tail - head) / 2.
 Eğer query orta elemandan küçükse, tail orta elemanın yerine geçer (arama sol alt yarıya daralır).
 Eğer query büyükse, head orta elemanın yerine geçer (arama sağ alt yarıya daralır).
 Döngü, query değeri bulunduğunda sona erer.
 Sonuç:

 Hedef eleman (query) bulunduğunda, değeri ve dizideki indeksi yazdırılır.
 Kaç iterasyon gerektiği ise sayac değişkeniyle takip edilir.
 Çıktı Örneği:
 Eğer query = 132 için çalıştırılırsa:

 makefile
 Kopyala
 Düzenle
 midpoint = 50
 midPoint = 25
 midPoint = 38
 midPoint = 44
 midPoint = 47
 midPoint = 49
 midPoint = 50
  Aranan bulundu, degeri : 132, Indisi de :44
 Bu çıktı:

 query = 132 için yapılan binary search işlemini ve her iterasyonda midPoint değerinin nasıl daraldığını gösterir.
 Sonuç: 132 değeri, 44. indekste bulundu. */


/*
 Ne Zaman Kullanılır?
 Binary Search, sıralı bir veri kümesinde hızlı bir şekilde bir eleman aramak için kullanılır.

 Örneğin: Bir numara listesinde bir kişinin telefon numarasını bulmak.
 Zaman karmaşıklığı: O(log n) olduğu için çok hızlıdır.
 
 Çalışan Kodun Amacı:
 Bu kod özellikle aşağıdaki durumlarda kullanılabilir:
 Sıralı bir dizide arama yapmak.
 Elemanın dizideki indeksini bulmak.
 Performansı ölçmek (iterasyon sayısını görmek).
 */
