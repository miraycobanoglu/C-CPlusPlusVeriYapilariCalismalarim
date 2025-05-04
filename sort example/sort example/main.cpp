//
//  main.cpp
//  sort example
//
//  Created by Miray Çobanoğlu on 17.01.2025.
//


// sort algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <time.h>
using namespace std;

int main () {
  int A[] = {32,3,9,71,12,45,9,3,26,80,9,53,33};
  vector<int> V (A,A+11); // 32 71 12 45 26 80 53 33
  vector<int>::iterator it;
  sort (V.begin(), V.end());//(12 32 45 71)26 80 53 33
  //srand(time(NULL));
  //random_shuffle(V.begin(), V.end());
  reverse(V.begin(), V.end());
  
 cout<<"En buyuk: "<< *max_element(V.begin(), V.end()) <<endl;
  cout<<"En kucuk: "<< *min_element(V.begin(), V.end()) <<endl;
  it=V.begin();
  it = find(V.begin(),V.end(),65);
  
  if(it==V.end())
  cout << "uzgunuz yok bulamiyoruz" << endl;
  else
  cout << "bulduk"<< endl;
 

  // print out content:
 cout << "myvector contains:";
 
 it=V.begin();
 while(it!=V.end()){
     cout << " " << *it;
     it++;
 }
 
 unique(V.begin(), V.end());
 /*
  it=V.begin();
 while(it!=V.end()){
     cout << " " << *it;
     it++;
 }
 */
 /*
  for ( it=V.begin(); it!=V.end(); ++it)
    cout << " " << *it;
  cout << "\n";
*/
  return 0;
}







/*
 Bu kod parçası, çeşitli C++ STL (Standart Şablon Kütüphanesi) algoritmalarını bir arada kullanan bir örnektir.

 1. Kütüphaneler ve Değişken Tanımları

 #include <iostream>     // std::cout
 #include <algorithm>    // std::sort, std::reverse, std::max_element, std::min_element, vb.
 #include <vector>       // std::vector
 #include <time.h>       // random_shuffle için (opsiyonel)
 using namespace std;
 Bu kütüphaneler:

 iostream: Konsola çıktı almak için.
 algorithm: Sıralama, ters çevirme, en büyük/küçük eleman bulma gibi algoritmalar için.
 vector: Dinamik diziler için.
 time.h: Rastgele sayı üreteçleriyle çalışmak için.
 
 
 
 
 
 2. Dizi ve Vektör Tanımları

 int A[] = {32,3,9,71,12,45,9,3,26,80,9,53,33};
 vector<int> V (A,A+11); // İlk 11 eleman, {32, 3, 9, ..., 26}
 A: Normal bir dizi.
 V: Dizinin ilk 11 elemanını içeren bir vektör.
 
 
 
 
 
 3. Sıralama ve Ters Çevirme

 sort (V.begin(), V.end());
 reverse(V.begin(), V.end());
 sort: Vektörü küçükten büyüğe sıralar.
 reverse: Sıralı vektörü ters çevirerek büyükten küçüğe sıralar.
 
 
 
 
 4. En Büyük ve En Küçük Elemanlar

 cout << "En buyuk: " << *max_element(V.begin(), V.end()) << endl;
 cout << "En kucuk: " << *min_element(V.begin(), V.end()) << endl;
 max_element ve min_element: Vektördeki en büyük ve en küçük elemanları bulur.
 
 
 
 
 5. Belirli Bir Elemanı Arama

 it = find(V.begin(), V.end(), 65);
 if (it == V.end())
     cout << "uzgunuz yok bulamiyoruz" << endl;
 else
     cout << "bulduk aq" << endl;
 find: Vektörde 65 sayısını arar. Bulursa iterator döner, bulamazsa V.end() döner.
 Kod, 65 bulunamadığı için "uzgunuz yok bulamiyoruz" yazdırır.
 
 
 
 
 
 6. Vektör Elemanlarını Yazdırma

 cout << "myvector contains:";
 it = V.begin();
 while (it != V.end()) {
     cout << " " << *it;
     it++;
 }
 Vektörün tüm elemanları, bir while döngüsü ile yazdırılır.
 
 
 
 
 7. Tekrarlayan Elemanları Kaldırma (İptal Edilmiş Kısım)

 unique(V.begin(), V.end());
 unique: Vektördeki ardışık tekrarları kaldırır. Ancak sonuç bir "geçici duruma alınır ve yazdırılmamış.
 
 
 
 
 8. Kodun İptal Edilmiş Bölümleri

 // random_shuffle(V.begin(), V.end());
 // unique(V.begin(), V.end());
 // for ( it=V.begin(); it!=V.end(); ++it) ...
 random_shuffle: Rastgele sıralama (kullanılmamış, eski bir yöntem).
 unique: Kullanımı yarıda bırakılmış.
 for döngüsü ile yazdırma da yorum satırı haline alınmış.
 
 
 
 
 9. Çıktı
 Eğer kod çalıştırılırsa, aşağıdaki gibi bir çıktı oluşabilir:

 En buyuk: 80
 En kucuk: 3
 uzgunuz yok bulamiyoruz
 myvector contains: 80 71 53 45 33 32 26 12 9 9 9
 
 
 Özet
 Kod, STL algoritmaları olan sıralama, ters çevirme, en büyük/küçük eleman bulma, arama ve yazdırma işlemlerini göstermektedir. Ancak bazı fonksiyonlar (ör. unique) tam olarak kullanılmamış veya test edilmemiş.
 */






/*
 ÇIKTISI:
 
 
 
 


 1. Dizinin Tanımlanması

 int A[] = {32, 3, 9, 71, 12, 45, 9, 3, 26, 80, 9, 53, 33};
 vector<int> V(A, A+11);
 V, A dizisinin ilk 11 elemanını alır:
 makefile
 Kopyala
 Düzenle
 V = {32, 3, 9, 71, 12, 45, 9, 3, 26, 80, 9}
 
 
 
 2. Sıralama ve Ters Çevirme

 sort(V.begin(), V.end());
 reverse(V.begin(), V.end());
 sort ile V küçükten büyüğe sıralanır:

 {3, 3, 9, 9, 9, 12, 26, 32, 45, 71, 80}
 reverse ile sıralama ters çevrilir:

 {80, 71, 45, 32, 26, 12, 9, 9, 9, 3, 3}
 
 
 
 
 3. En Büyük ve En Küçük Eleman

 cout << "En buyuk: " << *max_element(V.begin(), V.end()) << endl;
 cout << "En kucuk: " << *min_element(V.begin(), V.end()) << endl;
 max_element: 80
 min_element: 3
 yaml
 Kopyala
 Düzenle
 En buyuk: 80
 En kucuk: 3
 
 
 
 4. Eleman Arama (find)

 it = find(V.begin(), V.end(), 65);
 65 vektörde olmadığı için find fonksiyonu V.end() döner.

 uzgunuz yok bulamiyoruz
 
 
 
 5. Vektör Elemanlarını Yazdırma

 cout << "myvector contains:";
 it = V.begin();
 while (it != V.end()) {
     cout << " " << *it;
     it++;
 }
 Ters çevrilen vektör elemanları sırayla yazdırılır:

 myvector contains: 80 71 45 32 26 12 9 9 9 3 3
 
 
 
 
 
 6. unique Kullanımı (İşlevsiz)
 Kodda unique çağrılmış ancak sonucu yazdırılmadığı ve uygulanmadığı için etkisi gözlemlenmez.

 Nihai Çıktı
 Kod çalıştırıldığında konsol çıktısı şu şekilde olacaktır:

 
 En buyuk: 80
 En kucuk: 3
 uzgunuz yok bulamiyoruz
 myvector contains: 80 71 45 32 26 12 9 9 9 3 3
 */
