//
//  main.cpp
//  queue ve stack
//
//  Created by Miray Çobanoğlu on 17.01.2025.
//

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class ogrenci {
    public:
    int no;
    float GANO;
    bool cinsiyet;
    double xxx;
};

int main() {
    // Kuyruk (queue) ile çalışmak
    queue<ogrenci> Pide; // FIFO kuyruğu

    // Kuyruğun boş olup olmadığını kontrol et
    if (Pide.empty())
        cout << "Evet, kuyruk boş.\n";

    // Öğrenciler için bir örnek
    ogrenci ayse;
    ayse.no = 123;  // Öğrenci numarası
    ayse.GANO = 3.5;
    ayse.cinsiyet = true;

    // Kuyruğa bir öğrenci ekle
    Pide.push(ayse);
    cout << "Kuyrukta şu anda " << Pide.size() << " kişi var.\n";

    // Yığından öğeleri çıkar ve işlem yap
    Pide.pop();
    cout << "Kuyrukta şu anda " << Pide.size() << " kişi var.\n";

    // Yığın (stack) ile çalışmak
    stack<int> tabak; // LIFO yığını

    if (tabak.empty())
        cout << "Evet, LIFO (tabaklar) boş.\n";

    // Tabaklara eleman ekle
    tabak.push(1);
    tabak.push(2);
    tabak.push(3);

    // Tabak yığınını boşalt
    while (!tabak.empty()) {
        cout << "Tabaktan çıkan eleman: " << tabak.top() << "\n";
        tabak.pop();
    }

    return 0;
}





/*
 Bu kod, C++ Standart Şablon Kitaplığı (STL)'nin iki önemli veri yapısı olan queue (kuyruk) ve stack (yığın) kullanımını göstermektedir. Aşağıda kodun çalışma mantığını ve her bir kısmını detaylı olarak açıklıyorum.

 Kodun Genel Mantığı
 Kuyruk (Queue) işlemleri:

 FIFO (First In, First Out) prensibine göre çalışır.
 İlk eklenen eleman ilk çıkarılır.
 Örnek olarak, öğrenci bilgilerini işleyen bir kuyruk kullanılmış.
 Yığın (Stack) işlemleri:

 LIFO (Last In, First Out) prensibine göre çalışır.
 Son eklenen eleman ilk çıkarılır.
 Örnek olarak, bir yığın içine sayılar eklenmiş ve ardından boşaltılmış.
 Kodun Bölümleri ve Açıklaması
 1. Sınıf Tanımı: ogrenci

 class ogrenci {
     public:
     int no;
     float GANO;
     bool cinsiyet;
     double xxx;
 };
 ogrenci sınıfı öğrenci bilgilerini temsil eder.
 İçerisinde şu alanlar bulunur:
 int no: Öğrenci numarası.
 float GANO: Genel Ağırlıklı Not Ortalaması.
 bool cinsiyet: Öğrencinin cinsiyetini temsil eder (true veya false).
 double xxx: Kullanılmayan bir alan (muhtemelen gelecekte ek özellikler için düşünülmüş).
 2. Kuyruk (Queue) Kullanımı

 queue<ogrenci> Pide; // FIFO kuyruğu
 queue<ogrenci>: Öğrencilerden oluşan bir kuyruk oluşturur.
 Bu kuyruk şu işlemleri içerir:
 Kuyruğun boş olup olmadığını kontrol et:

 if (Pide.empty())
     cout << "Evet, kuyruk boş.\n";
 Eğer kuyrukta hiç eleman yoksa true döner ve "Evet, kuyruk boş." yazdırılır.
 Kuyruğa bir öğrenci ekle:


 ogrenci ayse;
 ayse.no = 123;
 ayse.GANO = 3.5;
 ayse.cinsiyet = true;
 Pide.push(ayse);
 Bir ogrenci nesnesi oluşturulur (ayse) ve bilgileri atanır.
 Bu öğrenci kuyruğa eklenir.
 Kuyruk boyutunu yazdır:


 cout << "Kuyrukta şu anda " << Pide.size() << " kişi var.\n";
 Kuyruğun eleman sayısı size() ile yazdırılır.
 Kuyruktan eleman çıkar:

 Pide.pop();
 Kuyruğun önündeki (en eski) eleman çıkarılır.
 3. Yığın (Stack) Kullanımı

 stack<int> tabak; // LIFO yığını
 stack<int>: Tamsayılardan oluşan bir yığın oluşturur.
 Bu yığın şu işlemleri içerir:
 Yığının boş olup olmadığını kontrol et:

 if (tabak.empty())
     cout << "Evet, LIFO (tabaklar) boş.\n";
 Eğer yığın boşsa true döner ve "Evet, LIFO (tabaklar) boş." yazdırılır.
 Yığına eleman ekle:

 tabak.push(1);
 tabak.push(2);
 tabak.push(3);
 Yığına sırasıyla 1, 2, ve 3 sayıları eklenir.
 Yığından elemanları çıkar ve yazdır:

 while (!tabak.empty()) {
     cout << "Tabaktan çıkan eleman: " << tabak.top() << "\n";
     tabak.pop();
 }
 Döngüyle yığın boşalana kadar:
 top(): Yığının en üstündeki elemanı alır.
 pop(): En üstteki elemanı yığından çıkarır.
 Kod Çalışma Sırası
 Kuyruk İşlemleri:

 Kuyruğun boş olup olmadığı kontrol edilir.
 Bir öğrenci kuyruğa eklenir ve ardından çıkarılır.
 Yığın İşlemleri:

 Yığının boş olup olmadığı kontrol edilir.
 Yığına elemanlar eklenir ve boşalana kadar çıkarılır.
 Kodun Çıkışı
 Kod çalıştırıldığında, aşağıdaki çıktı üretilir:

 Evet, kuyruk boş.
 Kuyrukta şu anda 1 kişi var.
 Kuyrukta şu anda 0 kişi var.
 Evet, LIFO (tabaklar) boş.
 Tabaktan çıkan eleman: 3
 Tabaktan çıkan eleman: 2
 Tabaktan çıkan eleman: 1
 Kodun Kullanım Alanları
 Kuyruk (queue):
 Müşteri sırası, baskı sırası gibi işlemleri simüle etmek için kullanılabilir.
 Yığın (stack):
 Tarayıcı geçmişi, geri alma işlemleri gibi durumları modellemek için kullanılır.
 */
