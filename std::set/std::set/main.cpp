//
//  main.cpp
//  std::set
//
//  Created by Miray Çobanoğlu on 17.01.2025.
//

// set::insert (C++98)
#include <iostream>
#include <set>
using namespace std;
int main ()
{
    
  set<int> bst;
  set<int>::iterator it;
  //pair<set<int>::iterator,bool> ret;
  
  //1. manuel eleman ekleme
  bst.insert(20);
  bst.insert(10);
  bst.insert(30);
  bst.insert(5);
  bst.insert(45);
  
  //2. array ile ekleme
  int A[3]= {11,77,1};
  bst.insert (A,A+3);
  
  //3. iterator ile ekleme
  it=bst.begin();
  bst.insert(it,99);
  
  //manuel erase
  bst.erase(30);
  
  it=bst.find(45);
  //bst.erase(it, bst.end());
  
  //bst.erase(bst.begin(),bst.end());

  cout << "bst contains:";
  for (it=bst.begin(); it!=bst.end(); ++it)
  {
      cout << " " << *it;
  }
      
    
  return 0;
}





/*
 Set Nedir?
 std::set, C++ Standard Template Library (STL) içerisinde yer alan, elemanları sıralı ve benzersiz olarak saklayan bir konteynerdir. Aşağıdaki özellikleri vardır:

 Benzersizlik: Aynı değerden birden fazla eleman içeremez. (Duplicate elemanlar eklenmez.)
 Sıralı Yapı: Elemanlar otomatik olarak küçükten büyüğe sıralanır. (Standart: <)
 Hızlı Arama: Eleman ekleme, silme ve arama işlemleri O(log n) zaman karmaşıklığında gerçekleştirilir (genellikle bir Binary Search Tree (BST) kullanılarak).
 Kapsamlı Destek: Eleman ekleme (insert), silme (erase), ve arama (find) gibi birçok işlevi destekler.
 Set'in Temel Metotları
 insert(value): Set'e eleman ekler.
 erase(value): Belirtilen değeri set'ten siler.
 find(value): Belirtilen değeri arar ve bir iterator döner.
 begin() ve end(): Set'in başını ve sonunu gösterir (iterator).
 size(): Set'teki eleman sayısını döner.
 Kodun Açıklaması
 Şimdi yukarıdaki kodu adım adım açıklayalım.

 
 
 
 1. Başlangıç ve Set Tanımı

 #include <iostream>
 #include <set>
 using namespace std;

 int main() {
     set<int> bst;  // Bir set tanımlanır
     set<int>::iterator it;  // Set üzerinde gezinmek için iterator
 set<int>: int türünde elemanları saklayan bir set tanımlanır.
 iterator: Set üzerinde gezinmek veya eleman bulmak için kullanılır.
 
 
 
 
 
 
 2. Eleman Ekleme (Manuel Ekleme)

     bst.insert(20);
     bst.insert(10);
     bst.insert(30);
     bst.insert(5);
     bst.insert(45);
 insert() ile set'e eleman eklenir.
 Set her zaman küçükten büyüğe sıralı bir yapıdadır:
 Şu anda set'in içeriği: {5, 10, 20, 30, 45}.
 
 
 
 
 
 3. Eleman Ekleme (Array ile Ekleme)

     int A[3] = {11, 77, 1};
     bst.insert(A, A+3);
 Bir dizi (array) tanımlanır: A = {11, 77, 1}.
 insert(A, A+3): Dizinin başlangıcından sonuna kadar olan elemanları set'e ekler.
 Set'in yeni durumu: {1, 5, 10, 11, 20, 30, 45, 77}.
 
 
 
 
 
 4. Iterator ile Eleman Ekleme

     it = bst.begin();  // Iterator set'in ilk elemanını (1) işaret eder
     bst.insert(it, 99);
 bst.insert(it, 99);: 99 set'e eklenir. it bir ipucu sağlar ama sıralama yine korunur.
 Set'in yeni durumu: {1, 5, 10, 11, 20, 30, 45, 77, 99}.
 
 
 
 
 5. Eleman Silme

     bst.erase(30);
 erase(30): Set'ten 30 elemanını siler.
 Set'in yeni durumu: {1, 5, 10, 11, 20, 45, 77, 99}.
 
 
 
 
 6. Eleman Arama

     it = bst.find(45);
 find(45): Set içinde 45 elemanını arar.
 Eğer eleman bulunursa, bir iterator döner (elemanı işaret eder). Aksi halde end() döner.




 7. Elemanları Yazdırma

     cout << "bst contains:";
     for (it = bst.begin(); it != bst.end(); ++it) {
         cout << " " << *it;
     }
 begin() ve end() ile set'in başından sonuna kadar döngü oluşturulur.
 Çıktı: Set'in içindeki tüm elemanlar sıralı bir şekilde yazdırılır.
 Program Çıktısı
 
 
 
 
 Son durumda set şunları içerir:

 bst contains: 1 5 10 11 20 45 77 99
 Bu kod, std::set'in temel kullanımını (ekleme, silme, arama) ve nasıl sıralı bir yapı sunduğunu göstermektedir.








 */
