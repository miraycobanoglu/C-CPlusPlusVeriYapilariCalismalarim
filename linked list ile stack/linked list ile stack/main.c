//
//  main.c
//  linked list ile stack
//
//  Created by Miray Çobanoğlu on 22.01.2025.
//

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
};
struct node *root = NULL; // Başlangıçta yığın boş, root NULL olarak ayarlanır.

void push(int x) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->prev = root; // Yeni düğüm, mevcut root'u işaret eder.
    root = temp;       // Yeni düğüm root olur.
}

int pop() {
    if (!root) { // Eğer root NULL ise yığın boştur.
        printf("Stack is empty!\n");
        return -1; // Hata durumunda -1 döndürülür.
    }
    struct node *temp = root;
    int data = temp->data; // En üst düğümün verisi alınır.
    root = root->prev;     // root bir önceki düğüme kaydırılır.
    free(temp);            // Çıkarılan düğümün belleği serbest bırakılır.
    return data;
}

void showAll() {
    struct node *temp = root;
    if (!temp) {
        printf("Stack is empty!\n");
        return;
    }
    while (temp) { // Tüm düğümler sırasıyla yazdırılır.
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    push(11); push(22); push(33); push(44);

    printf("%d\n", pop()); // En üst eleman (44) çıkarılır ve yazdırılır.
    showAll();             // Kalan elemanlar yazdırılır: 33 22 11

    return 0;
}
