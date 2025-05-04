//
//  main.cpp
//  kağıt katlama
//
//  Created by Miray Çobanoğlu on 17.01.2025.
//

#include <iostream>
using namespace std;

int main()
{
    double p =0.1; //p : page
    double d=384484 ;//km ay
    //double d=149600000;//g¸ne˛ km
    //long double d=105700*3665*24*60*60*300000;//samanyolu galaksisi km
    int sayac=0;
    
    do
    {
        p=p*2;
        sayac++;
        cout<<sayac<<". = "<< p/(10*100*1000)<<endl;
    }while((p/1000) < (d*1000));
    
    cout<< sayac;
    return 0;
}


/*
 Bu kod, bir kağıdın sürekli katlanması durumunda, kalınlığının ne kadar artacağını ve katlanma sayısı (sayac) belirli bir mesafeyi aşana kadar nasıl değiştiğini simüle eder.

 Kodun Detaylı Analizi:
 Başlangıç Değerleri:

 double p = 0.1;: Kağıdın başlangıç kalınlığı 0.1 mm olarak verilmiştir.
 double d = 384484;: Mesafe 384,484 km olarak verilmiş. Bu Ay ile Dünya arasındaki ortalama mesafedir.
 Yorum satırlarında Güneş ve Samanyolu galaksisi gibi farklı mesafeler de belirtilmiş, bu da kodun farklı uzaklıklar için kullanılabileceğini gösteriyor.
 Sayaç:

 int sayac = 0;: Kağıdın kaç kez katlandığını takip etmek için kullanılan sayaç.
 Do-While Döngüsü:

 Döngüde, kağıdın kalınlığı her adımda ikiye katlanıyor: p = p * 2;.
 Kağıdın kalınlığı belirtilen mesafeyi (d * 1000, yani metreye çevrilmiş) aşana kadar bu işlem tekrarlanıyor.
 Çıktılar:

 Her katlama sonrası kağıdın kalınlığı kilometre cinsinden ekrana yazdırılıyor: cout << sayac << ". = " << p/(10*100*1000) << endl;.
 Katlama sayısı (kaç kez katlandığı) döngüden sonra yazdırılıyor.
 Ne Anlama Geliyor?
 Kod, kağıt katlama ile ilgili popüler bir mantık problemini gösteriyor: Bir kağıdı sonsuz katlayabilseydik, kalınlığı kısa sürede büyük mesafeleri aşar.

 Örneğin, bir kağıt sadece 43 kez katlandığında, Ay'a ulaşacak kadar kalın bir yapı elde edilir. Bu, üstel büyüme ile ilgilidir; her katlama kalınlığı ikiye katladığı için kağıdın boyutları hızla büyür.

 Sonuç: Kodun amacı, kağıt katlamanın ne kadar hızlı büyüdüğünü ve belirli bir mesafeyi aşmak için kaç katlama gerektiğini hesaplamaktır.
 */
