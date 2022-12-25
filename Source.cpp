#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

// Bir düðümü temsil eden yapý
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Tek yönlü linked list sýnýfý
class TekYonlu {
private:
    Node* head;
public:
    TekYonlu() {
        head = NULL;
    }

    // Baþa düðüm ekleme
    void addToHead(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    // Sona düðüm ekleme
    void addToTail(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    // Araya düðüm ekleme
    void addAfter(int data, int after) {
        Node* newNode = new Node();
        newNode->data = data;

        Node* current = head;
        while (current != NULL && current->data != after) {
            current = current->next;
        }

        if (current != NULL) {
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Listeyi yazdýrma
    void printList() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Düðüm silme
    void deleteNode(int data) {
        Node* current = head;
        Node* prev = NULL;

        while (current != NULL && current->data != data) {
            prev = current;
            current = current->next;
        }

        if (current == NULL) return;  // Düðüm bulunamadý

        if (prev == NULL) {
            // Baþ düðümü silme
            head = current->next;
            delete current;
            return;
        }
        // Arada bir düðümü silme
        prev->next = current->next;
        delete current;
    }

    //Liste boyutunu döndüren fonksiyon
    int getSize() {
        int size = 0;

        //Baþ düðümden itibaren tüm düðümler gezilerek liste boyutu hesaplanýr
        Node* temp = head;
        while (temp != NULL) {
            size++;
            temp = temp->next;
        }
        return size;
    }
};

// Çift yönlü linked list sýnýfý
class CiftYonlu {
private:
    Node* head;
   
public:
    CiftYonlu() {
        head = NULL;
    }

    // Baþa düðüm ekleme
    void addToHead(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        if (head != NULL) head->prev = newNode;
        head = newNode;
    }

    // Sona düðüm ekleme
    void addToTail(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;

            if (head == NULL) {
                head = newNode;
                return;
            }

        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }

    // Araya düðüm ekleme
    void addAfter(int data, int after) {
        Node* newNode = new Node();
        newNode->data = data;

            Node* current = head;
        while (current != NULL && current->data != after) {
            current = current->next;
        }

        if (current != NULL) {
            newNode->prev = current;
            newNode->next = current->next;
            current->next = newNode;
            if (newNode->next != NULL) newNode->next->prev = newNode;
        }
    }

    // Listeyi yazdýrma
    void printList() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Düðüm silme
    void deleteNode(int data) {
        Node* current = head;

            while (current != NULL && current->data != data) {
                current = current->next;
            }

        if (current == NULL) return;  // Düðüm bulunamadý

        if (current->prev == NULL) {
            // Baþ düðümü silme
            head = current->next;
            if (head != NULL) head->prev = NULL;
            delete current;
            return;
        }

        // Arada bir düðümü silme
        current->prev->next = current->next;
        if (current->next != NULL) current->next->prev = current->prev;
        delete current;
    }

    //Liste boyutunu döndüren fonksiyon
    int getSize() {
        int size = 0;

        //Baþ düðümden itibaren tüm düðümler gezilerek liste boyutu hesaplanýr
        Node* temp = head;
        while (temp != NULL) {
            size++;
            temp = temp->next;
        }
        return size;
    }

};

// Dairesel linked list sýnýfý
class Dairesel {
private:
    Node* head;
public:
    Dairesel() {
        head = NULL;
    }

    // Baþa düðüm ekleme
    void addToHead(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        if (head == NULL) {
            head = newNode;
            head->next = head;
            return;
        }
        Node* current = head;
        while (current->next != head) {
            current = current->next;
        }
        current->next = newNode;
        head = newNode;
    }

    // Sona düðüm ekleme
    void addToTail(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;

       
            if (head == NULL) {
                head = newNode;
                head->next = head;
                return;
            }

        Node* current = head;
        while (current->next != head) {
            current = current->next;
        }
        current->next = newNode;
    }

    // Araya düðüm ekleme
    void addAfter(int data, int after) {
        Node* newNode = new Node();
        newNode->data = data;

            Node* current = head;
        while (current->next != head && current->data != after) {
            current = current->next;
        }

        if (current != NULL) {
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Listeyi yazdýrma
    void printList() {
        Node* current = head;
        while (current->next != head) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << current->data << " ";
        cout << endl;
    }

    // Düðüm silme
    void deleteNode(int data) {
        Node* current = head;
        Node* prev = NULL;

            while (current->next != head && current->data != data) {
                prev = current;
                current = current->next;
            }

        if (current->data != data) return;  // Düðüm bulunamadý

        if (prev == NULL) {
            // Baþ düðümü silme
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }
            last->next = head->next;
            head = head->next;
            delete current;
            return;
        }

        // Arada bir düðümü silme
        prev->next = current->next;
        delete current;
    }

    //Liste boyutunu döndüren fonksiyon
    int getSize() {
        int size = 0;

        //Baþ düðümden itibaren tüm düðümler gezilerek liste boyutu hesaplanýr
        Node* temp = head;
        while (temp != NULL) {
            size++;
            temp = temp->next;
        }
        return size;
    }

};



int main() {
    setlocale(LC_ALL, "Turkish");
    system("color 60");
    cout << "--- MENÜ ---" << endl;

    // Linked list yapýsýný seçme
    cout << "Linked List Yapýsýný Seçiniz: " << endl;
    cout << "1. Tek Yönlü" << endl;
    cout << "2. Çift Yönlü" << endl;
    cout << "3. Dairesel" << endl;
    int secim;
    cin >> secim;

    // Kullanýcýnýn seçtiði linked list yapýsýný oluþturma
    TekYonlu* tekyonlu = NULL;
    CiftYonlu* ciftyonlu = NULL;
    Dairesel* dairesel = NULL;
    if (secim == 1) {
        tekyonlu = new TekYonlu();
    }
    else if (secim == 2) {
        ciftyonlu = new CiftYonlu();
    }
    else if (secim == 3) {
        dairesel = new Dairesel();
    }
    else {
        cout << "Geçersiz Seçim" << endl;
        return 0;
    }

    // Dizi giriþi
    cout << "Kaç Elemanlý Dizi Gireceksiniz: ";
    int n=NULL;
    cin >> n;
    int* arr = new int[n];
    cout << "Dizinin Elemanlarini Girin: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Dizinin elemanlarýný linked list yapýsýna ekleme
    for (int i = 0; i < n; i++) {
        if (secim == 1) {
            tekyonlu->addToTail(arr[i]);
        }
        else if (secim == 2) {
            ciftyonlu->addToTail(arr[i]);
        }
        else if (secim == 3) {
            dairesel->addToTail(arr[i]);
        }
    }


    // Menü
    while (true) {
        cout << "Yapmak Ýstediðiniz Ýþlemi Seçin: " << endl;
        cout << "1. Baþa Eleman Ekleme" << endl;
        cout << "2. Sona Eleman Ekleme" << endl;
        cout << "3. Araya Eleman Ekleme" << endl;
        cout << "4. Listeyi Yazdýrma" << endl;
        cout << "5. Eleman Silme" << endl;
        cout << "6. Boyut" << endl;
        cout << "7. Çýkýþ" << endl;
        
        int islem;
        cin >> islem;

        if (islem == 1) {
            // Baþa eleman ekleme
            int data;
            cout << "Eklenecek Eleman: ";
            cin >> data;
            if (secim == 1) {
                tekyonlu->addToHead(data);
            }
            else if (secim == 2) {
                ciftyonlu->addToHead(data);
            }
            else if (secim == 3) {
                dairesel->addToHead(data);
            }
        }

        else if (islem == 2) {
            // Sona eleman ekleme
            int data;
            cout << "Eklenecek eleman: ";
            cin >> data;
            if (secim == 1){
                tekyonlu->addToTail(data);
            } else if (secim == 2) {
                ciftyonlu->addToTail(data);
            } else if (secim == 3) {
                dairesel->addToTail(data);
            }
        } 
        
        else if (islem == 3) {
            // Araya eleman ekleme
            int data, after;
            cout << "Eklenecek eleman: ";
            cin >> data;
            cout << "Sonrasýna ekle: ";
            cin >> after;
            if (secim == 1) {
                tekyonlu->addAfter(data, after);
            } else if (secim == 2) {
                ciftyonlu->addAfter(data, after);
            } else if (secim == 3) {
                dairesel->addAfter(data, after);
            }
        } 
        
        else if (islem == 4) {
            // Listeyi yazdýrma
            if (secim == 1) {
                tekyonlu->printList();
            } else if (secim == 2) {
                ciftyonlu->printList();
            } else if (secim == 3) {
                dairesel->printList();
            }
        }
        
        else if (islem == 5) {
            // Eleman silme
            int data;
            cout << "Silinecek Eleman: ";
            cin >> data;
            if (secim == 1) {
                tekyonlu->deleteNode(data);
            } else if (secim == 2) {
                ciftyonlu->deleteNode(data);
            } else if (secim == 3) {
                dairesel->deleteNode(data);
            }
        } 

        else if (islem == 6) {
            if (secim == 1) {
                cout << "Boyut: " << tekyonlu->getSize() << endl;
            }
            else if (secim == 2) {
                cout << "Boyut: " << ciftyonlu->getSize() << endl;
            }
            else if (secim == 3) {
                cout << "Boyut: " << dairesel->getSize() << endl;
            }          
        }

        else if (islem == 7) {
            // Çýkýþ
            break;
        }
        
        else {
            cout << "Geçersiz Seçim" << endl;
        }
    }

    return 0;
}