//
//  main.cpp
//  queue (linked list ile)
//
//  Created by Miray Çobanoğlu on 17.01.2025.
//

//Implementing queue using linked list
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *prev;
};

struct node *root,*back;

void push(int x){
    struct node *temp = (node *)malloc(1*sizeof(node *));
    temp->data = x;
    temp->prev = NULL;
    
    if(!root){
        root = back = temp;
        return;
    }
    
    back->prev = temp;//second<----first connecting
    back = temp;
    
    return;
}

int pop(){
    int xx = root->data;
    root = root->prev;
    return xx;
}

void showAll(){
    struct node *temp = root;
    
    while(temp){
        printf("%d ",temp->data);
        temp = temp->prev;
    }
}

int main()
{
    //int i=0;
    push(11);push(22);push(33);push(44);
    
    /*
    while(1)
        push(i++);
    */
    
    printf("%i \n",pop());
    //printf("%i",pop());
    showAll();
    return 0;
}







/*
 Kuyruk (Queue) Nedir?
 Kuyruk, bir veri yapısıdır ve genellikle FIFO (First In, First Out) prensibine göre çalışır. Bu prensibe göre, kuyruğa ilk giren eleman ilk çıkar. Gerçek hayattaki kuyruklara (örneğin, bir bilet kuyruğu) benzer şekilde çalışır.

 Kuyruğun Özellikleri
 FIFO Çalışma Prensibi:

 İlk giren eleman ilk çıkar.
 Örneğin:
 Kuyruğa eklenen sıralama: 1, 2, 3.
 Çıkış sırası: 1, 2, 3.
 İki Temel İşlem:

 Ekleme (Enqueue / Push):
 Kuyruğun sonuna eleman eklenir.
 Çıkarma (Dequeue / Pop):
 Kuyruğun başından eleman çıkarılır.
 Tipik Kullanım Alanları:

 İşlemlerin sıralı yürütülmesi (örneğin, CPU işlemleri).
 Veri aktarımı (örneğin, ağ paketleri).
 Baskı sıraları (örneğin, yazıcı kuyrukları).
 Kuyruğun Uygulanması
 Kuyruk farklı yöntemlerle uygulanabilir:

 Dizi (Array) ile:

 Sabit boyutlu kuyruklar için uygundur.
 Dezavantaj: Elemanlar çıktıkça, baş boş kalabilir ve yer israfına neden olabilir.
 Bağlı Liste (Linked List) ile:

 Dinamik bir yapıdır. Eleman ekleme ve çıkarma sırasında belleği gerektiği kadar kullanır.
 Diziye göre daha esnektir.
 Kod Açıklaması
 Aşağıdaki kodda bir kuyruk, bağlı liste kullanılarak uygulanmıştır.

 Kodun Parçaları
 Yapı Tanımı
 struct node {
     int data;
     struct node *prev;
 };
 Her düğümün (node) iki parçası vardır:
 data: Saklanacak veri.
 prev: Bir sonraki düğümü işaret eden gösterici.
 Kuyruk Göstericileri

 struct node *root, *back;
 root: Kuyruğun başını işaret eder (ilk giren eleman).
 back: Kuyruğun sonunu işaret eder (son eklenen eleman).
 Eleman Ekleme (Push İşlemi)

 void push(int x) {
     struct node *temp = (node *)malloc(1 * sizeof(node *));
     temp->data = x;
     temp->prev = NULL;

     if (!root) {
         root = back = temp;
         return;
     }

     back->prev = temp; // Kuyruğun sonuna yeni eleman bağlanır
     back = temp;       // Kuyruğun yeni sonu güncellenir
     return;
 }
 Yeni bir düğüm oluşturulur ve veri atanır.
 İlk Eleman Ekleme:
 Eğer kuyruk boşsa (root == NULL), hem root hem de back, yeni düğümü işaret eder.
 Sonraki Elemanlar:
 Kuyruğun sonuna (back) yeni düğüm eklenir.
 back güncellenir.
 Eleman Çıkarma (Pop İşlemi)

 int pop() {
     int xx = root->data; // İlk elemanın verisi alınır
     root = root->prev;   // Kuyruğun başı güncellenir
     return xx;           // Çıkarılan eleman döndürülür
 }
 Kuyruğun başındaki eleman çıkarılır.
 root, bir sonraki düğüme güncellenir.
 Eksik: Çıkarılan düğümün belleği serbest bırakılmıyor. (Bu, bellek sızıntısına neden olur.)
 Tüm Elemanları Gösterme (ShowAll İşlemi)

 void showAll() {
     struct node *temp = root;

     while (temp) {
         printf("%d ", temp->data);
         temp = temp->prev;
     }
 }
 Bir geçici gösterici (temp) kullanılarak kuyruktaki tüm elemanlar sırasıyla yazdırılır.
 Ana Fonksiyon

 int main() {
     push(11); push(22); push(33); push(44);

     printf("%i \n", pop());
     showAll();
     return 0;
 }
 push İşlemi:

 Kuyruğa 11, 22, 33 ve 44 eklenir.
 Kuyruğun durumu: 11 -> 22 -> 33 -> 44.
 pop İşlemi:

 Kuyruğun başındaki eleman (11) çıkarılır.
 Kuyruğun durumu: 22 -> 33 -> 44.
 showAll İşlemi:

 Kalan elemanlar yazdırılır: 22 33 44.
 Programın Çalışma Akışı
 push(11) ile kuyruk: 11.

 push(22) ile kuyruk: 11 -> 22.

 push(33) ile kuyruk: 11 -> 22 -> 33.

 push(44) ile kuyruk: 11 -> 22 -> 33 -> 44.

 pop():

 11 çıkarılır.
 Kuyruk: 22 -> 33 -> 44.
 showAll():

 Kuyruktaki kalan elemanlar yazdırılır: 22 33 44.
 Çıktı
 11
 22 33 44
 */

