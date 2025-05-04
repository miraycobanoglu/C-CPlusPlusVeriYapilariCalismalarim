//
//  main.cpp
//  std::map
//
//  Created by Miray Çobanoğlu on 17.01.2025.
//

#include <iostream>
#include <map>

int main() {
    std::map<int, float> mymap;

    // Elemanları ekle
    mymap[123] = 4.0;    // Anahtar: 123, Değer: 4.0
    mymap[456] = 0.0;    // Anahtar: 456, Değer: 0.0
    mymap['c'] = 77.0;   // Anahtar: 99 (ASCII 'c'), Değer: 77.0

    // Map boşalana kadar yazdır ve sil
    while (!mymap.empty()) {
        std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
        mymap.erase(mymap.begin()); // İlk elemanı sil
    }

    return 0;
}






/*

 
 
 
 
 1. Başlangıç
 cpp
 Kopyala
 Düzenle
 #include <iostream>
 #include <map>
 #include <iostream>: Giriş ve çıkış işlemleri için kullanılır (std::cout, std::cin).
 #include <map>: std::map veri yapısını kullanabilmek için gereken başlık dosyasıdır.
 
 
 
 
 2. Ana Program
 cpp
 Kopyala
 Düzenle
 int main ()
 {
   std::map<int,float> mymap;
 Burada bir std::map tanımlanıyor:
 Anahtar türü (key): int (tamsayı).
 Değer türü (value): float (ondalıklı sayı).
 Bu yapı, her bir int anahtarı bir float değere eşler.
 
 
 
 
 
 3. Haritaya Eleman Ekleme
 
   mymap[123] = 4.0;    // Anahtar 123, değer 4.0
 mymap haritasına bir eleman ekleniyor:
 Anahtar: 123
 Değer: 4.0

   mymap[456] = 0.0;    // Anahtar 456, değer 0.0
 Haritaya ikinci bir eleman ekleniyor:
 Anahtar: 456
 Değer: 0.0

   mymap['c'] = 77.0;   // Anahtar 99 (ASCII 'c'), değer 77.0
 'c' bir char (karakter) tipindedir.
 Ancak std::map'in anahtar türü int olduğundan, 'c' karakteri ASCII tablosundaki karşılık gelen değere dönüştürülür:
 'c' karakterinin ASCII değeri: 99
 Haritaya eklenen eleman:
 Anahtar: 99
 Değer: 77.0
 
 
 
 
 
 
 4. Haritanın İşlenmesi

   while (!mymap.empty())
   {
     std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
     mymap.erase(mymap.begin());
   }
 a. while (!mymap.empty())
 mymap.empty():
 Haritanın boş olup olmadığını kontrol eder.
 Harita boş değilse döngü devam eder.
 b. mymap.begin()
 mymap.begin():
 Haritanın en küçük anahtara sahip elemanına işaret eden bir iteratör döndürür.
 c. mymap.begin()->first ve mymap.begin()->second
 mymap.begin()->first: İlk elemanın anahtarını alır.
 mymap.begin()->second: İlk elemanın değerini alır.
 d. mymap.erase(mymap.begin())
 mymap.erase(mymap.begin()):

 Haritanın en küçük anahtara sahip elemanını siler.
 Döngü, harita boşalana kadar devam eder.

 
 
 
 
 5. Programın Çıkışı
 
   return 0;
 Program başarılı bir şekilde sonlanır.
 
 
 
 Çıktı
 Haritaya eklenen elemanlar şunlardır:

 Anahtar: 99 (ASCII 'c'), Değer: 77.0
 Anahtar: 123, Değer: 4.0
 Anahtar: 456, Değer: 0.0
 std::map öğeleri artan anahtar sırasına göre saklar. Bu nedenle, sıralama şu şekildedir:

 99 => 77.0
 123 => 4.0
 456 => 0.0
 
 
 
 
 Çıktı:
 99 => 77
 123 => 4
 456 => 0
 
 
 
 
 Özet
 Program, bir std::map oluşturur ve sıralı şekilde anahtar-değer çiftleri ekler.
 Haritanın elemanları sırayla yazdırılır ve her bir eleman yazdırıldıktan sonra silinir.
 Döngü sonunda harita tamamen boşaltılmış olur.
 */
