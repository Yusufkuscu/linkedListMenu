#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

// Bir d���m� temsil eden yap�
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Tek y�nl� linked list s�n�f�
class TekYonlu {
private:
    Node* head;
public:
    TekYonlu() {
        head = NULL;
    }

    // Ba�a d���m ekleme
    void addToHead(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    // Sona d���m ekleme
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

    // Araya d���m ekleme
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

    // Listeyi yazd�rma
    void printList() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // D���m silme
    void deleteNode(int data) {
        Node* current = head;
        Node* prev = NULL;

        while (current != NULL && current->data != data) {
            prev = current;
            current = current->next;
        }

        if (current == NULL) return;  // D���m bulunamad�

        if (prev == NULL) {
            // Ba� d���m� silme
            head = current->next;
            delete current;
            return;
        }
        // Arada bir d���m� silme
        prev->next = current->next;
        delete current;
    }

    //Liste boyutunu d�nd�ren fonksiyon
    int getSize() {
        int size = 0;

        //Ba� d���mden itibaren t�m d���mler gezilerek liste boyutu hesaplan�r
        Node* temp = head;
        while (temp != NULL) {
            size++;
            temp = temp->next;
        }
        return size;
    }
};

// �ift y�nl� linked list s�n�f�
class CiftYonlu {
private:
    Node* head;
   
public:
    CiftYonlu() {
        head = NULL;
    }

    // Ba�a d���m ekleme
    void addToHead(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        if (head != NULL) head->prev = newNode;
        head = newNode;
    }

    // Sona d���m ekleme
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

    // Araya d���m ekleme
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

    // Listeyi yazd�rma
    void printList() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // D���m silme
    void deleteNode(int data) {
        Node* current = head;

            while (current != NULL && current->data != data) {
                current = current->next;
            }

        if (current == NULL) return;  // D���m bulunamad�

        if (current->prev == NULL) {
            // Ba� d���m� silme
            head = current->next;
            if (head != NULL) head->prev = NULL;
            delete current;
            return;
        }

        // Arada bir d���m� silme
        current->prev->next = current->next;
        if (current->next != NULL) current->next->prev = current->prev;
        delete current;
    }

    //Liste boyutunu d�nd�ren fonksiyon
    int getSize() {
        int size = 0;

        //Ba� d���mden itibaren t�m d���mler gezilerek liste boyutu hesaplan�r
        Node* temp = head;
        while (temp != NULL) {
            size++;
            temp = temp->next;
        }
        return size;
    }

};

// Dairesel linked list s�n�f�
class Dairesel {
private:
    Node* head;
public:
    Dairesel() {
        head = NULL;
    }

    // Ba�a d���m ekleme
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

    // Sona d���m ekleme
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

    // Araya d���m ekleme
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

    // Listeyi yazd�rma
    void printList() {
        Node* current = head;
        while (current->next != head) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << current->data << " ";
        cout << endl;
    }

    // D���m silme
    void deleteNode(int data) {
        Node* current = head;
        Node* prev = NULL;

            while (current->next != head && current->data != data) {
                prev = current;
                current = current->next;
            }

        if (current->data != data) return;  // D���m bulunamad�

        if (prev == NULL) {
            // Ba� d���m� silme
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }
            last->next = head->next;
            head = head->next;
            delete current;
            return;
        }

        // Arada bir d���m� silme
        prev->next = current->next;
        delete current;
    }

    //Liste boyutunu d�nd�ren fonksiyon
    int getSize() {
        int size = 0;

        //Ba� d���mden itibaren t�m d���mler gezilerek liste boyutu hesaplan�r
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
    cout << "--- MEN� ---" << endl;

    // Linked list yap�s�n� se�me
    cout << "Linked List Yap�s�n� Se�iniz: " << endl;
    cout << "1. Tek Y�nl�" << endl;
    cout << "2. �ift Y�nl�" << endl;
    cout << "3. Dairesel" << endl;
    int secim;
    cin >> secim;

    // Kullan�c�n�n se�ti�i linked list yap�s�n� olu�turma
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
        cout << "Ge�ersiz Se�im" << endl;
        return 0;
    }

    // Dizi giri�i
    cout << "Ka� Elemanl� Dizi Gireceksiniz: ";
    int n=NULL;
    cin >> n;
    int* arr = new int[n];
    cout << "Dizinin Elemanlarini Girin: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Dizinin elemanlar�n� linked list yap�s�na ekleme
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


    // Men�
    while (true) {
        cout << "Yapmak �stedi�iniz ��lemi Se�in: " << endl;
        cout << "1. Ba�a Eleman Ekleme" << endl;
        cout << "2. Sona Eleman Ekleme" << endl;
        cout << "3. Araya Eleman Ekleme" << endl;
        cout << "4. Listeyi Yazd�rma" << endl;
        cout << "5. Eleman Silme" << endl;
        cout << "6. Boyut" << endl;
        cout << "7. ��k��" << endl;
        
        int islem;
        cin >> islem;

        if (islem == 1) {
            // Ba�a eleman ekleme
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
            cout << "Sonras�na ekle: ";
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
            // Listeyi yazd�rma
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
            // ��k��
            break;
        }
        
        else {
            cout << "Ge�ersiz Se�im" << endl;
        }
    }

    return 0;
}