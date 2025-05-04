#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *root;

void add(int x) {
    struct node *temp = (struct node *)malloc(1 * sizeof(struct node *));
    temp->data = x;
    temp->right = temp->left = NULL;

    if (!root) {
        root = temp;
        return;
    }

    // Yorum: Bu kısmı tamamlayacağız.
    // while kullan, break ile çık. Eğer aşağıdaki null ise yerleştir;
    // değilse altındaki değeri karşılaştır (büyük mü küçük mü diye bak),
    // sonra sol veya sağa yerleştir.
    struct node *current = root;

    while (1) { // Sonsuz döngü, uygun yer bulunduğunda break ile çıkılacak
        if (x < current->data) { // Sol alt ağaca git
            if (!current->left) { // Eğer sol boşsa buraya yerleştir
                current->left = temp;
                break;
            }
            current = current->left; // Sol alt ağaca ilerle
        } else { // Sağ alt ağaca git
            if (!current->right) { // Eğer sağ boşsa buraya yerleştir
                current->right = temp;
                break;
            }
            current = current->right; // Sağ alt ağaca ilerle
        }
    }

    return;
}

int main() {
    add(11);
    add(22);

    return 0;
}



/*
 Kodun Mantığı:
 Bu kod, Binary Search Tree (BST)'ye yeni bir düğüm eklemek için yazılmıştır. BST'nin temel özelliği şudur:

 Her düğümün sol alt ağacındaki tüm değerler, o düğümün değerinden küçüktür.
 Her düğümün sağ alt ağacındaki tüm değerler, o düğümün değerinden büyüktür.
 Yeni bir düğüm eklerken:

 Kökten (root) başlayarak ağacı dolaşırız.
 Yeni değer (x), mevcut düğümün değerinden küçükse sol alt ağaca gideriz.
 Büyükse sağ alt ağaca gideriz.
 Boş bir yer bulduğumuzda, yeni düğümü oraya ekleriz.
 current Nedir?
 Kodda kullanılan current, ağacı dolaşmak için kullanılan bir işaretçidir (pointer). Bu işaretçi, her adımda şu an hangi düğümde olduğumuzu gösterir.

 currentin Rolü:
 Ağaçta Gezinti:

 Kökten başlayarak (current = root), ağacın uygun alt ağaçlarında dolaşır.
 Eğer x küçükse sol alt ağaca (current = current->left), büyükse sağ alt ağaca (current = current->right) ilerler.
 Boş Yer Bulma:

 Her adımda current bir sonraki düğümü gösterir.
 Eğer bir alt ağaç boşsa (current->left == NULL veya current->right == NULL), yeni düğümü oraya yerleştirir.
 Döngüyü Kontrol Eder:

 while (1) döngüsü içindeki karar yapıları (if ve else) sayesinde, uygun bir konum bulunana kadar current sürekli ilerler.
 Zaman Karmaşıklığı:
 Bu kodun zaman karmaşıklığı, Binary Search Tree'nin yüksekliğine bağlıdır.

 En İyi Durum (Best Case):
 Ağacın dengeli bir şekilde büyüdüğünü varsayalım (her düğüm eşit şekilde sol ve sağ alt ağaca dağılıyor).
 Bu durumda, ağacın yüksekliği O(log n) olur ve kodun çalışması O(log n) zaman alır.
 En Kötü Durum (Worst Case):
 Eğer ağaç dengesiz büyürse (örneğin, tüm elemanlar sıralı eklenirse), ağaç bir linked list gibi olur.
 Bu durumda, ağacın yüksekliği O(n) olur ve ekleme işlemi O(n) zaman alır.
 Ortalama Durum (Average Case):
 Rastgele eklenen değerlerle ağacın yaklaşık dengeli olduğunu varsayarsak, zaman karmaşıklığı genelde O(log n) olur.
 Kodun Adım Adım İşleyişi:
 Kök Kontrolü:

 Eğer root boşsa (NULL), yeni düğüm doğrudan kök olarak atanır.
 Ağacı Dolaşma:

 current işaretçisi, ağacı dolaşarak uygun konumu arar.
 Yeni değer (x), current->data ile karşılaştırılır:
 x < current->data → Sol alt ağaçta ilerle.
 x >= current->data → Sağ alt ağaçta ilerle.
 Yeni Düğümü Yerleştirme:

 Uygun boş yer (NULL) bulunursa:
 Sol boşsa (current->left == NULL), yeni düğüm buraya eklenir.
 Sağ boşsa (current->right == NULL), yeni düğüm buraya eklenir.
 Döngüden Çıkış:

 Yeni düğüm yerleştirildiğinde break ile döngüden çıkılır.
 Kodun Avantajları ve Dezavantajları:
 Avantajlar:
 Basitlik: BST'ye eleman eklemek için temel bir yöntemdir.
 Dinamik Yapı: Elemanlar dinamik olarak bellekte tutulur ve sıralı şekilde saklanır.
 Dezavantajlar:
 Dengesiz Ağaç: Eğer değerler sıralı veya ters sıralı şekilde eklenirse, ağaç dengesiz olur ve performans kötüleşir.
 AVL veya Red-Black Tree Gibi Dengeli Yapılar Yok: BST'nin dengesiz hale gelmesini önlemek için daha gelişmiş ağaç yapıları (ör. AVL ağacı) tercih edilebilir.
 Örnek İşleyiş (Adım Adım):
 Elemanlar sırasıyla ekleniyor: 11, 22, 5.

 11 Ekle:

 root boş olduğu için, 11 kök olarak eklenir.
 22 Ekle:

 current = root (11).
 22 > 11, sağ alt ağaç boş olduğu için 22, sağ alt ağaca eklenir.
 5 Ekle:

 current = root (11).
 5 < 11, sol alt ağaç boş olduğu için 5, sol alt ağaca eklenir.
 Sonuç:
     11
    /  \
   5    22
 */
