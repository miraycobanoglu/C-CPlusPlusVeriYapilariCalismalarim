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






/*
 Bu kod, C programlama dilinde bir yığın (stack) veri yapısını uygulamaktadır. Yığın, Last In, First Out (LIFO) prensibine dayanan bir veri yapısıdır. Yani, en son eklenen eleman, ilk çıkarılan elemandır. Kodun detaylı bir açıklaması aşağıda yer almaktadır:

 Kodun Genel İşlevi
 Kod, bir yığın (stack) veri yapısını, bağlantılı liste (linked list) kullanarak uygular. Yığın üzerinde şu işlemler yapılabilir:

 Eleman ekleme (push): Yığına yeni bir eleman ekler.
 Eleman çıkarma (pop): Yığından en üstteki elemanı çıkarır.
 Yığını görüntüleme (showAll): Yığındaki tüm elemanları ekrana yazdırır.
 Kodun Bölümleri
 
 
 1. struct node Yapısı

 struct node {
     int data;            // Veriyi tutar
     struct node *prev;   // Bir önceki düğüme işaret eder
 };
 Bu yapı, yığındaki her bir düğümü temsil eder.
 Her düğüm bir data alanı ve bir önceki düğüme (prev) işaret eden bir işaretçi içerir.
 
 
 
 2. Küresel Değişkenler

 struct node *root = NULL;
 root: Yığının en üst elemanını işaret eder. Yığın başlangıçta boştur, bu nedenle NULL olarak başlatılır.
 
 
 3. Eleman Ekleme (push)

 void push(int x) {
     struct node *temp = (struct node *)malloc(sizeof(struct node));
     temp->data = x;       // Yeni elemanın verisi atanır
     temp->prev = root;    // Yeni eleman, eski root'u işaret eder
     root = temp;          // Yeni eleman root olur
 }
 push fonksiyonu, yığına bir eleman ekler.
 Yeni düğümün prev işaretçisi, mevcut root değerini işaret eder.
 Daha sonra root, yeni düğümü gösterecek şekilde güncellenir.
 Bu şekilde, yeni düğüm yığının en üstüne eklenmiş olur.
 
 
 
 4. Eleman Çıkarma (pop)

 int pop() {
     if (!root) { // Yığın boşsa hata mesajı verir
         printf("Stack is empty!\n");
         return -1;
     }
     struct node *temp = root; // Mevcut root saklanır
     int data = temp->data;    // Çıkarılacak veriyi alır
     root = root->prev;        // root bir önceki düğüme kaydırılır
     free(temp);               // Bellek serbest bırakılır
     return data;              // Çıkarılan veri döndürülür
 }
 Yığından en üstteki elemanı çıkarır ve değerini döndürür.
 Eğer yığın boşsa, hata mesajı verir ve -1 döndürür.
 Bellek yönetimi sağlanır (free ile düğüm serbest bırakılır).
 
 
 
 5. Yığını Görüntüleme (showAll)

 void showAll() {
     struct node *temp = root;
     if (!temp) { // Yığın boşsa mesaj verir
         printf("Stack is empty!\n");
         return;
     }
     while (temp) { // Tüm düğümler dolaşılır
         printf("%d ", temp->data);
         temp = temp->prev;
     }
     printf("\n");
 }
 Yığındaki tüm elemanları sırasıyla ekrana yazdırır.
 Eğer yığın boşsa, kullanıcıya bilgi verir.
 
 
 
 6. Ana Fonksiyon (main)
 
 int main() {
     push(11); push(22); push(33); push(44); // Yığına eleman ekleme

     printf("%i\n", pop()); // Yığından bir eleman çıkar ve yazdır (44)

     showAll(); // Kalan elemanları yazdır: 33 22 11

     return 0;
 }
 push(11), push(22), push(33), push(44): Yığına sırasıyla 11, 22, 33 ve 44 eklenir.
 pop(): En üstteki eleman (44) yığından çıkarılır ve ekrana yazdırılır.
 showAll(): Yığındaki kalan elemanlar (33, 22, 11) ekrana yazdırılır.
 Yığının Çalışma Mantığı
 Push İşlemleri:

 İlk push(11) çağrıldığında:

 11
 Sonraki push(22):


 22 -> 11
 push(33):


 33 -> 22 -> 11
 push(44):

 44 -> 33 -> 22 -> 11
 Pop İşlemi:

 pop() çağrıldığında, en üst eleman (44) çıkarılır:

 33 -> 22 -> 11
 showAll İşlemi:

 Yığındaki kalan elemanlar yazdırılır:

 33 22 11

 */
