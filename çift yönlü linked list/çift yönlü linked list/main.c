//
//  main.c
//  çift yönlü linked list
//
//  Created by Miray Çobanoğlu on 17.01.2025.
//

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};
struct node *tail = NULL, *head = NULL;

void add(int x) {
    struct node *temp = (struct node *)malloc(sizeof(struct node)); // malloc düzeltildi
    temp->next = temp->prev = NULL;
    temp->data = x;

    if (!head) {
        head = tail = temp;
        return;
    }

    tail->next = temp;
    temp->prev = tail;
    tail = temp;

    return;
}

void listele() {
    struct node *temp = head;

    while (temp) { // Döngü hatası düzeltildi
        printf("%d\n", temp->data);
        temp = temp->next;
    }

    return;
}

void terstenListele() {
    struct node *temp = tail;

    while (temp) { // Döngü hatası düzeltildi
        printf("%d\n", temp->data);
        temp = temp->prev;
    }

    return;
}

void sil(int x) {
   struct node *temp = head;

    // Düğümü bul
    while (temp && temp->data != x) {
        temp = temp->next;
    }

    if (!temp) return; // Düğüm bulunamadıysa çık

    // Düğümler arası bağlantıyı ayarla
    if (temp->prev) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next; // İlk düğüm siliniyorsa
    }

    if (temp->next) {
        temp->next->prev = temp->prev;
    } else {
        tail = temp->prev; // Son düğüm siliniyorsa
    }

    free(temp); // Belleği serbest bırak
    return;
}

int main() {
    add(11); add(22); add(33); add(44); add(55); add(66);
    sil(33);
    listele();
    //terstenListele();

    return 0;
}





/*
 Bu kod, çift bağlı liste (doubly linked list) adı verilen bir veri yapısını temsil eder. Çift bağlı listeler, her bir düğümün hem bir önceki düğümü hem de bir sonraki düğümü işaret ettiği bir tür dinamik veri yapısıdır. Bu veri yapısı, elemanların dinamik bir şekilde eklenmesi, silinmesi ve dolaşılması gibi işlemleri kolayca yapmayı sağlar.

 Kodun Amacı
 Bu kodun amacı, çift bağlı liste üzerinde aşağıdaki işlemleri yapmaktır:

 Eleman ekleme (add): Listeye yeni bir eleman eklenir. Elemanlar sırayla listeye eklenir ve listenin sonuna yerleştirilir.
 Listeyi baştan sona yazdırma (listele): Listenin tüm elemanları sırasıyla ekrana yazdırılır.
 Listeyi sondan başa yazdırma (terstenListele): Listenin tüm elemanları ters sırada ekrana yazdırılır.
 Bir elemanı silme (sil): Listede belirtilen bir eleman (verisi verilen düğüm) silinir.
 Kodun Çalışma Şekli
 add Fonksiyonu:

 Bir düğüm oluşturulur ve içine bir veri (data) atanır.
 Eğer liste boşsa (yani, head == NULL), bu düğüm hem head hem de tail olur.
 Eğer liste doluysa, düğüm liste sonuna eklenir ve tail işaretçisi güncellenir.
 listele Fonksiyonu:

 head işaretçisinden başlayarak listenin her elemanı sırasıyla gezilir.
 Her düğümün data değeri ekrana yazdırılır.
 terstenListele Fonksiyonu:

 tail işaretçisinden başlayarak listenin her elemanı ters sırada gezilir.
 Her düğümün data değeri ekrana yazdırılır.
 sil Fonksiyonu:

 Belirli bir değeri içeren düğüm bulunur.
 Bu düğüm silinirken, bağlantılar (next ve prev) yeniden ayarlanır.
 Eğer silinen düğüm listenin başıysa (head), head işaretçisi güncellenir.
 Eğer silinen düğüm listenin sonuysa (tail), tail işaretçisi güncellenir.
 Eğer liste tek düğümden oluşuyorsa, hem head hem de tail NULL olur.
 main Fonksiyonu:

 Listeye sırasıyla 11, 22, 33, 44, 55, 66 elemanları eklenir.
 33 değerine sahip düğüm silinir.
 Kalan elemanlar ekrana yazdırılır.

 */
