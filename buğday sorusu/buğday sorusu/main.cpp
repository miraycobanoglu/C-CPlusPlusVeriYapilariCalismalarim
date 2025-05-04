//
//  main.cpp
//  buğday sorusu
//
//  Created by Miray Çobanoğlu on 17.01.2025.
//

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double agirlik = 1 / 25.0; // Her buğday tanesinin ağırlığı (gram). 1 buğday tanesi = 1/25 gram.
    double borc = 0;          // Toplam ağırlığı (ton) tutacak değişken.
    int i;

    for(i = 0; i < 64; i++)   // Satranç tahtasındaki 64 kareyi temsil eden döngü.
    {
        // pow(2, i): 2^i (i. karedeki buğday tanesi sayısını hesaplar).
        // agirlik / (1000 * 1000): Buğday tanesinin ağırlığını gramlardan tonlara çevirir.
        borc = borc + (pow(2, i) * agirlik / (1000 * 1000));

        // i. kareye kadar biriken toplam ağırlığı ekrana yazdırır.
        cout << i << ". kaareye kadar konulacak bugday//ton = " << borc << endl;
    }

    return 0;
}



/*
 Bu kod, ünlü şah-mat buğday problemini çözmek için yazılmıştır.

 Şah-mat Buğday Problemi:
 Bir satranç tahtası 8x8 boyutunda, yani toplam 64 kareden oluşur. Problem şöyle ifade edilir:

 İlk kareye 1 buğday tanesi, ikinci kareye 2 buğday tanesi, üçüncü kareye 4 buğday tanesi... şeklinde devam ederek her karede önceki karenin iki katı kadar buğday konur.
 Sorunun amacı, tüm 64 karedeki toplam buğday sayısını bulmaktır.
 Bu kod, bu toplamı hesaplamaktadır.
 */




/*
 Kodun Çıktısı Ne Anlama Gelir?
 pow(2, i):

 i. karede bulunan buğday tanesi sayısını hesaplar.
 Örneğin:
 0. kare: 2^0=2 (1tane buğday)
 1.kare : 2^1=2 (2 tane buğday)
 2.kare : 2^2=4 (4tane buğday)
 
 Buğday ağırlığı:

 Her buğday tanesi
1/25 gram

 Tona çevirmek için:
 Toplam ağırlık(ton)= gram/1000*1000

 Toplam Buğday Miktarı:
 Döngüde her karedeki buğday miktarı bir öncekiyle toplanır ve toplam ağırlık güncellenir.
 
 Sonuç:
 Kodun amacı, satranç tahtasındaki tüm karelerde biriken buğday miktarının ağırlığını ton cinsinden hesaplamaktır.

 Matematiksel Gerçek: 64 karelik bir satranç tahtasında biriken toplam buğday sayısı:
 Toplam Buğday = 2^64-1
 Bu, son derece büyük bir sayı olup trilyonlarca ton buğdaya denk gelir.

 */
