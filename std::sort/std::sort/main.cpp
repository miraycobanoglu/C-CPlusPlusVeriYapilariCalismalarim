//
//  main.cpp
//  std::sort
//
//  Created by Miray Çobanoğlu on 17.01.2025.
//

// sort algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
using namespace std;

int main () {
  int A[] = {32,71,12,45,26,80,53,33};
  vector<int> V (A, A+8); // 32 71 12 45 26 80 53 33
  vector<int>::iterator it;
  
  sort (V.begin(), V.end());           //(12 32 45 71)26 80 53 33

  // print out content:
  cout << "myvector contains: ";
  
  it=V.begin();
  while( it != V.end() ){
      cout << " " << *it;
      it++;
  }

  return 0;
}



/*
 Bu, C++ programlama dilinde bir sıralama algoritması (sorting algorithm) örneğidir. Kod, standart kütüphanenin (STL) bir parçası olan std::sort fonksiyonunu kullanarak bir diziyi küçükten büyüğe sıralar.

 Kodun Açıklaması:
 Kütüphaneler Dahil Edilmiş:

 #include <iostream>: Ekrana yazdırma işlemleri için gerekli.
 #include <algorithm>: std::sort fonksiyonu gibi algoritmalar içerir.
 #include <vector>: std::vector sınıfı kullanımı için gerekli.
 Veri Tanımları ve Atamalar:

 int A[] = {32,71,12,45,26,80,53,33};: Sıralanacak bir tam sayı dizisi tanımlanıyor.
 vector<int> V (A, A+8);: Diziyi bir std::vector nesnesine kopyalar. A+8 ifadesi, dizinin son elemanından bir sonrasını işaret eder, böylece dizinin tüm elemanları vektöre aktarılır.
 Sıralama İşlemi:

 sort (V.begin(), V.end());: std::sort fonksiyonu, vektörün başlangıç (V.begin()) ve bitiş (V.end()) iterator'ları arasında bulunan elemanları sıralar. Varsayılan olarak sıralama işlemi küçükten büyüğe yapılır.
 Sonuçları Ekrana Yazdırma:

 it=V.begin(); ve while( it != V.end() ): Bir iterator (it) kullanılarak vektörün elemanları sırasıyla ekrana yazdırılır.
 Kodun Çıktısı:
 Bu kod çalıştırıldığında, ekranda şu sonuç görüntülenir:


 myvector contains: 12 26 32 33 45 53 71 80
 Özet:
 Bu kod, C++'ta sıralama işlemini göstermek için temel bir örnektir. std::sort fonksiyonu, hızlı ve etkili bir şekilde sıralama yapmak için kullanılır. Kod ayrıca vektörlerin nasıl kullanılacağını ve iterator'lar yardımıyla elemanların nasıl işleneceğini de öğretir.
 */
