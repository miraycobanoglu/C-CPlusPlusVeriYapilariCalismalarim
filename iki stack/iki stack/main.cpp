//
//  main.cpp
//  iki stack
//
//  Created by Miray Çobanoğlu on 17.01.2025.
//



#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

int main()
{
    stack <int> tabak1;
    stack <int> tabak2;
    
    if (tabak1.empty()) {
        cout << "masa 1 de tabak yok\n";

    }
    cout << "tabaklari eklemek icin tusa basiniz";
    getchar();

    tabak1.push(1);
    cout << "1. masadaki tabak sayisi =" << tabak1.size() << "\n";

    if (tabak2.empty()) {
        cout << "masa 2 de tabak yok\n";

    }
    cout << "tabaklari eklemek icin tusa basiniz";
    getchar();

    for (int i = 0; i < 50; i++) {
        tabak2.push(i);
        
        
        
    }
    cout << "2.masadaki tabak sayisi = " << tabak2.size() << "\n";
    int ntabak;
    cout << "masa 2 deki hangi tabaga ulasmak istiyorsunuz";
    cin >> ntabak;
    ntabak = tabak2.size() - ntabak;
    for (int j = 1; j <= ntabak; j++) {
        tabak1.push(tabak2.top());
        tabak2.pop();

    }

    cout << "1. masadaki tabak sayisi =" << tabak1.size() << "\n";
    cout << "2.masadaki tabak sayisi = " << tabak2.size() <<"\n";
    
    
    

    
}





/*
 Bu C++ kodu, iki yığın (stack) kullanarak bir tabak taşıma senaryosunu simüle eder. İşte kodun detaylı açıklaması:

 Kodun Amacı:
 İki yığın (tabak1 ve tabak2) kullanılarak tabakların bir masadan diğerine taşınmasını simüle eder.
 Kullanıcı, tabak2 yığınında kaçıncı tabağa ulaşmak istediğini belirtir. Bu tabağa ulaşana kadar tabaklar tabak1 yığınına taşınır.
 Kodun Bölümleri ve Açıklamaları:
 Yığınların Tanımlanması:


 stack<int> tabak1;
 stack<int> tabak2;
 tabak1 ve tabak2 isimli iki yığın tanımlanır.
 Başlangıç Durumu:


 if (tabak1.empty()) {
     cout << "masa 1 de tabak yok\n";
 }
 Eğer tabak1 boşsa, masa 1'de tabak olmadığını belirtir.
 Kullanıcıdan Giriş Bekleme:


 cout << "tabaklari eklemek icin tusa basiniz";
 getchar();
 Kullanıcıdan bir tuşa basması istenir. Bu, yığınlara tabak eklemeden önce bir duraklama sağlar.
 tabak1'e Tabak Eklenmesi:


 tabak1.push(1);
 cout << "1. masadaki tabak sayisi =" << tabak1.size() << "\n";
 tabak1 yığınına bir tabak eklenir. Sonrasında, yığındaki toplam tabak sayısı yazdırılır.
 tabak2'nin Kontrolü ve Tabak Eklenmesi:


 if (tabak2.empty()) {
     cout << "masa 2 de tabak yok\n";
 }
 cout << "tabaklari eklemek icin tusa basiniz";
 getchar();
 tabak2 yığınının boş olup olmadığı kontrol edilir. Daha sonra kullanıcıdan bir tuşa basması istenir.
 tabak2 yığınına 50 tabak eklenir (numaraları 0'dan 49'a kadar):
 
 
 for (int i = 0; i < 50; i++) {
     tabak2.push(i);
 }
 Eklenen tabak sayısı yazdırılır:

 cout << "2.masadaki tabak sayisi = " << tabak2.size() << "\n";
 Tabak Taşıma İşlemi:


 int ntabak;
 cout << "masa 2 deki hangi tabaga ulasmak istiyorsunuz";
 cin >> ntabak;
 Kullanıcıdan, tabak2 yığınında ulaşmak istediği tabak numarası istenir.
 Bu numaraya ulaşmak için, o tabağın üzerindeki tabaklar tabak1 yığınına taşınır:

 ntabak = tabak2.size() - ntabak;
 for (int j = 1; j <= ntabak; j++) {
     tabak1.push(tabak2.top());
     tabak2.pop();
 }
 ntabak ile, kullanıcı tarafından seçilen tabağa ulaşmak için kaç tabak taşınması gerektiği hesaplanır.
 Döngü, tabak2'nin üstündeki tabakları birer birer tabak1'e taşır.
 Son Durumun Yazdırılması:


 cout << "1. masadaki tabak sayisi =" << tabak1.size() << "\n";
 cout << "2.masadaki tabak sayisi = " << tabak2.size();
 Her iki yığındaki toplam tabak sayısı yazdırılır.
 Kodun Özet İşleyişi:
 Başlangıçta tabak1 boş bir yığın olarak başlar.
 Kullanıcıdan giriş alındıktan sonra tabak1'e bir tabak eklenir.
 tabak2 başlangıçta boştur, ardından içine 50 tabak eklenir.
 Kullanıcıdan, tabak2'de ulaşmak istediği tabak numarası alınır.
 İlgili tabağa ulaşmak için, üstündeki tabaklar tabak1 yığınına taşınır.
 Son olarak, her iki yığındaki tabak sayıları gösterilir.
 Kullanım Senaryosu:
 Bu kod, tabak taşıma işlemlerini simüle ederek bir yığının temel işlevlerini anlamaya yardımcı olur. Özellikle:

 push (ekleme),
 pop (çıkarma),
 top (en üstteki elemanı görüntüleme),
 size (yığındaki eleman sayısını alma) işlevlerini kullanarak yığın yapısının işleyişini açıklar.
 */
