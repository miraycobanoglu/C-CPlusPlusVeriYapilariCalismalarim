//
//  main.cpp
//  circular linked list
//
//  Created by Miray Çobanoğlu on 17.01.2025.
//

/*Implementing of Circular Linked List*/
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL , *tail = NULL;

void add(int x)
{
    struct node *temp = (node *)malloc(1*sizeof(node *));
    temp->data = x;
    temp->next = NULL;
    
    while(!head){
        head = tail = temp;
        tail->next = head;
    }
    
    temp->next = head;
    tail->next = temp;
    head = temp;
}
void show(){
    struct node *temp = head;
    do{
        printf("%d\n",temp->data);
        temp = temp->next;
    }while(temp != head);
}

void pop()
{
    struct node *temp = head;
    head = head->next;
    tail->next = head;
    free(temp);
}
int main()
{
    add(1);
    add(2);
    add(3);
    add(4);
    add(5);
    show();
    pop();
    printf("\n");
    show();
    return 0;
}



/*
 Bu kod, bir Circular Linked List (Döngüsel Bağlı Liste) uygulamasıdır. Döngüsel bağlı liste, son düğümün tekrar baş düğümü işaret ettiği bir bağlı liste türüdür. Bu yapı, belirli durumlarda faydalı bir veri yapısıdır, çünkü listenin başlangıcına geri dönmek kolaydır.

 Aşağıda kodun detaylı açıklaması, işleyiş mantığı ve zaman karmaşıklığı verilmiştir.

 Kodun Parçaları ve Mantığı:
 1. struct node Yapısı:

 struct node{
     int data;
     struct node *next;
 };
 Her düğüm (node), bir veri alanı (data) ve bir işaretçi alanı (next) içerir.
 data → Düğümde saklanan veriyi tutar.
 next → Bir sonraki düğümü işaret eder.
 
 
 2. Küresel İşaretçiler:

 struct node *head = NULL , *tail = NULL;
 head → Listenin ilk düğümünü işaret eder.
 tail → Listenin son düğümünü işaret eder.
 
 
 3. add Fonksiyonu (Eleman Ekleme):
 
 void add(int x) {
     struct node *temp = (node *)malloc(1 * sizeof(node *));
     temp->data = x;
     temp->next = NULL;

     while (!head) { // Eğer liste boşsa
         head = tail = temp; // İlk düğümü oluştur
         tail->next = head;  // Döngüsel bağlantıyı kur
     }

     temp->next = head;  // Yeni düğümü bağla
     tail->next = temp;  // Tail'den yeni düğüme bağlantı kur
     head = temp;        // Yeni düğümü baş düğüm yap
 }
 Yeni bir düğüm oluşturulur (temp).
 Eğer liste boşsa (head == NULL), head ve tail bu düğümü işaret eder ve son düğümün next işaretçisi tekrar head'i gösterir.
 Eğer liste boş değilse:
 Yeni düğümün next işaretçisi head'i gösterir.
 tail->next yeni düğümü işaret eder.
 head güncellenerek yeni düğüm baş düğüm olur.
 
 
 4. show Fonksiyonu (Listeyi Yazdırma):

 void show() {
     struct node *temp = head;
     do {
         printf("%d\n", temp->data); // Mevcut düğümün verisini yazdır
         temp = temp->next;         // Sonraki düğüme geç
     } while (temp != head);         // Tekrar baş düğüme gelene kadar devam et
 }
 Döngüsel yapıya dikkat edilerek, head'den başlayarak tüm düğümler yazdırılır.
 Tekrar head düğümüne gelindiğinde döngü sona erer.
 
 
 5. pop Fonksiyonu (İlk Düğümü Silme):
 
 void pop() {
     struct node *temp = head;   // İlk düğümü geçici olarak tut
     head = head->next;          // Baş düğümü bir sonrakine kaydır
     tail->next = head;          // Döngüsel bağlantıyı koru
     free(temp);                 // İlk düğümün belleğini serbest bırak
 }
 İlk düğüm (head) listeden çıkarılır.
 head, bir sonraki düğümü işaret eder.
 tail->next, yeni head düğümüne işaret eder.
 Bellek sızıntısını önlemek için eski head düğümü free ile serbest bırakılır.
 
 
 6. main Fonksiyonu (Kullanım Örneği):

 int main() {
     add(1);
     add(2);
     add(3);
     add(4);
     add(5);
     show();     // Listeyi yazdır
     pop();      // İlk düğümü sil
     printf("\n");
     show();     // Güncellenmiş listeyi yazdır
     return 0;
 }
 Beş eleman sırayla eklenir (1, 2, 3, 4, 5).
 Liste yazdırılır.
 İlk düğüm (1) silinir.
 Güncellenmiş liste tekrar yazdırılır.
 Örnek Çıktı:
 Listeye Elemanlar Eklendiğinde:

 5
 4
 3
 2
 1
 (Not: Yeni elemanlar başa eklendiği için sıra ters.)

 İlk Düğüm Silindikten Sonra:

 4
 3
 2
 1
 Zaman Karmaşıklığı:
 add Fonksiyonu:

 Sabit sayıda işlem yapar → O(1).
 show Fonksiyonu:

 Listedeki tüm düğümleri gezer → O(n), n düğüm sayısıdır.
 pop Fonksiyonu:

 Sabit sayıda işlem yapar → O(1).
 Circular Linked List'in Avantajları:
 Sonsuz Döngü: Listenin sonundan başına kolayca geçilebilir.
 Sabit Bellek Kullanımı: Fazladan belleğe gerek yoktur.
 Dinamik Yapı: Eleman sayısı sabit değildir, ihtiyaç oldukça genişler veya küçülür.

 */
