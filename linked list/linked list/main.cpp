//
//  main.cpp
//  linked list
//
//  Created by Miray Çobanoğlu on 17.01.2025.
//

#include <stdio.h>
#include <stdlib.h>

// Her düğümü (node) tanımlayan yapı
struct node {
    int data;            // Düğümün tuttuğu veri.
    struct node *next;   // Bir sonraki düğüme işaretçi.
};

// Bağlı listenin başlangıç ve sonunu tutan global pointer'lar.
node *head, *tail;

// Listeye eleman eklemek için kullanılan fonksiyon.
void Ekle(int x) {
    node *temp;  // Yeni düğüm için bir pointer tanımlanır.
    temp = (node *)malloc(1 * sizeof(node*));  // Yeni düğüm için bellek tahsis edilir.
    temp->next = NULL;       // Yeni düğümün bir sonraki düğümü olmadığı için NULL atanır.
    temp->data = x;          // Gelen değer düğümün veri alanına atanır.

    if (!head) {             // Eğer liste boşsa (head NULL ise):
        head = tail = temp;  // Hem head hem de tail yeni düğüme işaret eder.
        return;              // İşlem tamamlandığı için fonksiyon sonlanır.
    }

    tail->next = temp;       // Tail'in next'i yeni düğümü gösterir (bağlantı kurulur).
    tail = temp;             // Tail güncellenir, artık yeni düğümü işaret eder.
    return;                  // İşlem tamamlanır.
}

// Listenin elemanlarını ekrana yazdıran fonksiyon.
void Listele() {
    node *temp = (node *)malloc(1 * sizeof(node *)); // Geçici bir pointer tanımlanır.
    temp = head;          // Listeyi dolaşmak için baştan (head'den) başlanır.

    do {
        printf("%d\n", temp->data);  // Mevcut düğümün verisi ekrana yazdırılır.
        temp = temp->next;          // Bir sonraki düğüme geçilir.
    } while (temp);                 // Son düğüme gelene kadar devam edilir.

    return;  // Listeleme işlemi tamamlanır.
}

// Ana program.
int main() {
    // 1'den 100'e kadar olan sayılar listeye eklenir.
    for (int i = 1; i <= 10; i++)
        Ekle(i);

    // Listeyi ekrana yazdırma işlemi (isteğe bağlı).
    Listele();

    return 0;  // Program başarıyla sonlanır.
}




/*
 Kodun Açıklaması
 Bu kod, bağlı liste (linked list) veri yapısını oluşturmak, eleman eklemek ve listeyi görüntülemek için temel bir uygulamadır. Kod, tek yönlü bağlı liste (singly linked list) kullanmaktadır.

 Kodun Temel Yapısı
 Node Tanımı:


 struct node {
     int data;
     struct node *next;
 };
 data: Düğümün (node) tuttuğu veriyi temsil eder.
 next: Bir sonraki düğüme işaret eden bir pointer.
 
 
 Global Değişkenler:

 node *head, *tail;
 head: Listenin başlangıç düğümünü tutar.
 tail: Listenin son düğümünü tutar.
 Fonksiyonlar:

 Ekle(int x): Bir düğüm oluşturup listeye ekler. Yeni düğüm listenin sonuna eklenir.

 Eğer liste boşsa (head == NULL), hem head hem de tail bu düğüme işaret eder.
 Eğer liste doluysa, tail->next yeni düğüme bağlanır ve tail güncellenir.
 Zaman karmaşıklığı: O(1) (Son düğümü bilmemiz avantajdır).
 Listele(): Listenin tüm elemanlarını sırayla ekrana yazdırır.

 head ile başlar ve her düğümde next pointer'ını takip ederek listenin sonuna kadar gider.
 Zaman karmaşıklığı: O(n) (Listeyi dolaşmak gerektiği için).
 Ana Fonksiyon (main):

 Ekle fonksiyonunu kullanarak 1'den 100'e kadar olan sayıları bağlı listeye ekler.
 Listele() fonksiyonu ile eklenen sayılar ekrana yazdırılabilir (ama şu an çağrılmamış).
 Bağlı Liste Avantajları
 Dinamik Bellek Kullanımı:

 Bağlı listeler, bellek ihtiyaçlarını programın çalışma zamanında karşılar. Bellek önceden tahsis edilmez; ihtiyaca göre tahsis edilir.
 Eleman Eklemek/Çıkarmak:

 Listenin başına, sonuna veya ortasına eleman eklemek ve çıkarmak kolaydır. Bunun için dizilerdeki gibi elemanları kaydırmak gerekmez.
 Esneklik:

 Bağlı listeler, boyutları sabit olmayan dinamik veri yapılarıdır. Eleman ekleme/çıkarma işlemleri boyut sınırlaması olmadan yapılabilir.
 Dezavantajları
 Rastgele Erişim Yok:

 Bir bağlı listedeki belirli bir elemana erişmek için tüm düğümleri sırasıyla dolaşmak gerekir. Dizilerde olduğu gibi doğrudan indeksleme yapılamaz. Bu nedenle erişim zamanı O(n)'dir.
 Ekstra Bellek Tüketimi:

 Her düğüm bir veri ve bir pointer içerdiği için, dizilere göre daha fazla bellek tüketir.
 Daha Karmaşık Uygulama:

 Pointer manipülasyonu gerektirir ve kod karmaşıklığını artırır.

 */





/*
 Kodun Avantajları
 Dinamik Bellek Kullanımı: Listenin boyutu önceden bilinmek zorunda değildir. İhtiyaç duyuldukça eleman eklenebilir.

 Hızlı Ekleme: tail pointer'ı sayesinde sona ekleme işlemi O(1) karmaşıklığında gerçekleştirilir.

 Basit ve Etkili: Listeleme ve ekleme işlemleri bağımsız olarak uygulanabilir.


 */





/*
 Kodun Açıklamaları:
 Yapı Tanımı (struct node):

 Her düğümde bir data alanı (veri) ve bir next pointer'ı (sonraki düğüme bağlantı) bulunur.
 Global Pointer'lar (head ve tail):

 head: Listenin başlangıcını işaret eder.
 tail: Listenin sonunu işaret eder.
 Fonksiyonlar:

 Ekle(int x):
 Yeni bir düğüm oluşturur ve listenin sonuna ekler.
 Eğer liste boşsa, yeni düğüm hem head hem tail olarak atanır.
 Zaman karmaşıklığı: O(1).
 Listele():
 Listeyi baştan sona dolaşır ve her düğümün data alanını ekrana yazdırır.
 Zaman karmaşıklığı: O(n).
 Ana Program (main):

 Ekle fonksiyonu ile 1'den 100'e kadar olan sayılar listeye eklenir.
 Listeyi ekrana yazdırmak için Listele() çağrılabilir (yorumdan çıkarılırsa).

 */









/*
 Linked List Nedir?
 Linked list, veri yapılarında kullanılan ve düğümlerden (nodes) oluşan bir koleksiyondur. Her düğüm:

 Bir veri alanı (data): Depolanacak veri.
 Bir pointer (next): Bir sonraki düğümün adresini tutar.
 Bir bağlı liste, lineer bir veri yapısıdır ancak veri elemanları bellek içinde fiziksel olarak ardışık (contiguous) değildir. Her eleman bir pointer aracılığıyla diğerine bağlıdır.

 Linked List Türleri
 Tek Yönlü Bağlı Liste (Singly Linked List):

 Her düğüm bir sonraki düğüme bağlanır.
 Son düğümün next pointer'ı NULL değerini alır.
 Çift Yönlü Bağlı Liste (Doubly Linked List):

 Her düğüm hem bir önceki düğüme hem de bir sonraki düğüme işaret eder.
 İki yönlü gezinme mümkündür.
 Dairesel Bağlı Liste (Circular Linked List):

 Son düğüm, ilk düğüme bağlanır ve böylece bir döngü oluşturur.
 Çift Yönlü Dairesel Liste (Doubly Circular Linked List):

 Hem çift yönlü hem de dairesel bir yapıdır.
 Linked List Avantajları
 Dinamik Boyut:

 Eleman sayısı sabit değildir. Program sırasında ihtiyaca göre eleman eklenip çıkarılabilir.
 Bellek Verimliliği:

 Gerektiği kadar bellek tahsisi yapılır. Dizi gibi önceden bir boyut belirtmeye gerek yoktur.
 Kolay Ekleme/Silme:

 Liste başına veya sonuna ekleme/silme işlemleri kolaydır. Diziyle karşılaştırıldığında eleman kaydırma gerektirmez.
 Esneklik:

 Bellekte ardışık olarak depolama gerekmediğinden, bellek alanlarının farklı yerlerinde saklanan elemanlarla çalışabilir.
 Linked List Dezavantajları
 Bellek Aşırılığı:

 Her düğüm bir pointer alanı içerdiğinden, dizilere göre daha fazla bellek kullanır.
 Doğrusal Erişim:

 Rastgele erişim mümkün değildir. Bir elemanı bulmak için baştan başlayarak listeyi dolaşmak gerekir (O(n) zaman karmaşıklığı).
 Daha Karmaşık Yapı:

 Pointer kullanımı ve bellek tahsisi/düzenlemesi nedeniyle uygulaması ve hata ayıklaması dizilere göre daha karmaşıktır.

 

 */




/*
 Linked List'in Kullanıldığı Yerler
 Yığın (Stack) ve Kuyruk (Queue):

 Bağlı listeler, yığın ve kuyruk yapılarının implementasyonunda kullanılır.
 Graf Temsili:

 Komşuluk listesi kullanarak grafiklerin temsilinde kullanılır.
 Bellek Yönetimi:

 İşletim sistemlerinde belleği dinamik olarak tahsis etmek için bağlı listeler kullanılır.
 Metin Editörleri:

 Satır ekleme ve silme gibi işlemler için uygun bir veri yapısıdır.
 Sıkça Sorulan Sorular
 Bağlı liste neden kullanılır?

 Dinamik veri ekleme/silme ihtiyacı olan durumlarda ve belleği etkin kullanmak gerektiğinde tercih edilir.
 Bağlı liste neden diziye göre daha yavaş?

 Rastgele erişim yapılamaz, elemanlara ulaşmak için tüm listeyi dolaşmak gerekir (O(n)).
 Linked list hangi durumlarda kullanılmaz?

 Elemanlara hızlı erişim (örneğin indeksleme) gerektiğinde diziler daha uygundur.
 */
