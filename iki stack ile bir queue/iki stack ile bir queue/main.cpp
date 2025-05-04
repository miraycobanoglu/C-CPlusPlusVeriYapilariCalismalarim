//
//  main.cpp
//  iki stack ile bir queue
//
//  Created by Miray Çobanoğlu on 22.01.2025.
//

#include <iostream>
#include <stack>

class QueueWithTwoStacks {
private:
    std::stack<int> stack1; // İlk stack, elemanları alır
    std::stack<int> stack2; // İkinci stack, elemanları sıralı şekilde verir

public:
    // Eleman ekleme (enqueue)
    void enqueue(int value) {
        stack1.push(value);
        std::cout << value << " kuyruğa eklendi.\n";
    }

    // Eleman çıkarma (dequeue)
    void dequeue() {
        if (stack2.empty()) {
            // Eğer stack2 boşsa, stack1'in tüm elemanlarını aktar
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        // Eğer hala stack2 boşsa, kuyruk da boştur
        if (stack2.empty()) {
            std::cout << "Kuyruk boş! Çıkarılacak eleman yok.\n";
            return;
        }

        // Stack2'den eleman çıkar
        std::cout << stack2.top() << " kuyruktan çıkarıldı.\n";
        stack2.pop();
    }

    // Kuyruğun boş olup olmadığını kontrol et
    bool isEmpty() {
        return stack1.empty() && stack2.empty();
    }
};

int main() {
    QueueWithTwoStacks queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    queue.dequeue(); // 10 çıkar
    queue.dequeue(); // 20 çıkar

    queue.enqueue(40);

    queue.dequeue(); // 30 çıkar
    queue.dequeue(); // 40 çıkar
    queue.dequeue(); // Kuyruk boş!

    return 0;
}





/*
 Kodun Adım Adım Açıklaması
 Bu kod, iki stack kullanarak bir queue oluşturur. Aşağıda kodun önemli bölümlerini adım adım açıklıyorum.

 1. İki Stack Tanımı

 std::stack<int> stack1; // İlk stack, elemanları alır
 std::stack<int> stack2; // İkinci stack, elemanları sıralı şekilde verir
 stack1: Elemanların direkt eklendiği yığın. Bu yığın, yeni gelen elemanları sıralamadan tutar.
 stack2: Çıkarma işlemi sırasında kullanılan yığın. Elemanlar buraya aktarılır ve sıralı bir şekilde çıkarılır.
 
 
 
 
 
 
 2. Eleman Ekleme (enqueue)

 
 void enqueue(int value) {
     stack1.push(value);
     std::cout << value << " kuyruğa eklendi.\n";
 }
 Mantık:
 Eleman ekleme işlemi her zaman stack1 üzerinde gerçekleşir.
 Bu işlem çok basittir ve zaman karmaşıklığı O(1)’dir.
 
 
 
 
 
 
 3. Eleman Çıkarma (dequeue)

 void dequeue() {
     if (stack2.empty()) {
         while (!stack1.empty()) {
             stack2.push(stack1.top());
             stack1.pop();
         }
     }

     if (stack2.empty()) {
         std::cout << "Kuyruk boş! Çıkarılacak eleman yok.\n";
         return;
     }

     std::cout << stack2.top() << " kuyruktan çıkarıldı.\n";
     stack2.pop();
 }
 Mantık:
 Eğer stack2 boşsa:
 stack1'in elemanları stack2'ye aktarılır. Bu işlem sırasında elemanlar ters sırayla stack2'ye girer. Böylece FIFO sırasına uygun bir yapı elde edilir.
 Örneğin:
 stack1: [10, 20, 30] (en üstte 30 var)
 Aktarım sonrası stack2: [30, 20, 10] (en üstte 10 var)
 Eğer stack2 hâlâ boşsa:
 Bu durumda kuyruk tamamen boştur ve eleman çıkarılamaz.
 Eğer stack2 doluysa:
 En üstteki eleman çıkarılır (FIFO sırasına uygun olarak).
 
 
 
 
 
 4. Kuyruğun Boş Olup Olmadığını Kontrol (isEmpty)

 bool isEmpty() {
     return stack1.empty() && stack2.empty();
 }
 Mantık:
 Kuyruk, ancak her iki stack de boşsa gerçekten boştur.
 Bu metot, kuyruk üzerinde işlem yapmadan önce kontrol yapmak için kullanılabilir.
 
 
 
 
 
 5. main() Fonksiyonu

 int main() {
     QueueWithTwoStacks queue;

     queue.enqueue(10);
     queue.enqueue(20);
     queue.enqueue(30);

     queue.dequeue(); // 10 çıkar
     queue.dequeue(); // 20 çıkar

     queue.enqueue(40);

     queue.dequeue(); // 30 çıkar
     queue.dequeue(); // 40 çıkar
     queue.dequeue(); // Kuyruk boş!

     return 0;
 }
 enqueue(10), enqueue(20), enqueue(30) ile kuyruk şu şekilde olur:

 stack1: [10, 20, 30]
 stack2: Boş
 İlk dequeue() işlemi:

 stack1'den elemanlar stack2'ye aktarılır: [30, 20, 10]
 stack2'den 10 çıkarılır.
 Kalan: stack2: [30, 20]
 İkinci dequeue() işlemi:

 stack2'den 20 çıkarılır.
 Kalan: stack2: [30]
 enqueue(40) ile:

 stack1: [40]
 stack2: [30]
 Sonraki dequeue() işlemleri:

 30 ve ardından 40 çıkarılır.
 Kuyruk boş hale gelir.
 FIFO Davranışı
 FIFO (First In, First Out) davranışı korunur:
 İlk giren eleman (10), ilk çıkar.
 Daha sonra gelen elemanlar sırayla çıkar (20, 30, 40).
 
 
 
 Özet
 Bu yapı, iki stack kullanarak bir kuyruk tasarlamayı sağlar:

 Eleman ekleme (enqueue) işlemi hızlıdır ve stack1 kullanır.
 Eleman çıkarma (dequeue) işlemi gerektiğinde stack1'in elemanlarını stack2'ye aktarır ve FIFO sırasını sağlar.
 */
