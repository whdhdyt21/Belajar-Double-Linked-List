//double linked list
#include <iostream>
using namespace std;

struct DNode
{
    string nodeValue;
    DNode* next;
    DNode* prev;
    
};

struct DoubleLinkedList
{
    private :
        DNode* head;
        DNode* tail;

    public :
        DoubleLinkedList()
        {
            head = NULL;
            tail = NULL;
        }
    
        void addNode(string newValues) //Menambah data / menambah dari belakang
        {
            DNode* tmp = new DNode();
            tmp->nodeValue = newValues;

            if(head == NULL)
            {
                head = tmp;
                tail = tmp;
            }
            else
            {
                tail->next = tmp;
                tmp->prev = tail;
                tmp->next = NULL;
                tail = tmp;
            }
        }

        void addNodefront(string newValues) //Menambah data depan
        {
            DNode* tmp = new DNode();
            tmp->nodeValue = newValues;

            if(head == NULL)
            {
                head = tmp;
                tail = tmp;
            }
            else
            {
                tmp->next = head;
                head->prev = tmp;
                head = tmp;
            }
        }

        void readdataforward() //membaca dari depan
        {
            DNode* cur = head;
            while(cur != NULL)
            {
                cout << cur->nodeValue << " ";
                cur = cur->next;
            }
            cout << endl;
        }

        void readdatabackward() //membaca dari belakang
        {
            DNode* cur = tail;
            while(cur != NULL)
            {
                cout << cur->nodeValue << " ";
                cur = cur->prev;
            }
            cout << endl;
        }

        void deletefirst() //menghapus depan
        {
            if(head != NULL)
            {
                DNode* tmp = head;
                head = head->next;
                head->prev = NULL;
                delete tmp;
            }
        }

        void deletelast() //menghapus belakang
        {
            if(tail != NULL)
            {
                DNode* tmp = tail;
                tail = tail->prev;
                tail->next = NULL;
                delete tmp;
            }
        }

        void insert(string nData, string n) //Menyisipkan Node di Double Linked List Sesuai Target
        {
            DNode* newNode = new DNode();
            DNode* cur = head;
            DNode* prevNode = NULL;
            bool foundItem = false;
            while (cur != NULL && !foundItem)
            {
                if (cur->nodeValue == nData) 
                { 
                    newNode->prev = prevNode; 
                    newNode->nodeValue = n; 
                    newNode->next = cur; 
                    prevNode->next = newNode; 
                    cur->prev = newNode; 
                    foundItem = true;
                } 
                else 
                {
                    prevNode = cur;
                    cur = cur->next;
                }
            }
        }

        void deleteNode(string nData)//Menghapus Node di Double Linked List Sesuai Target
        {
            DNode* cur = head;
            DNode* prevNode = NULL;
            bool foundItem = false;
            while (cur != NULL && !foundItem)
            {
                if (cur->nodeValue == nData) 
                { 
                    prevNode->next = cur->next; 
                    cur->next->prev = prevNode; 
                    delete cur; 
                    foundItem = true;
                } 
                else 
                {
                    prevNode = cur;
                    cur = cur->next;
                }
            }
        }
};

DoubleLinkedList myList;

        void tambahnode()
        {
            string newValues;
            cout << "Input New Value : ";
            cin >> newValues;
            myList.addNode(newValues);
        }

        void tambahnodefront()
        {
            string newValues2;
            cout << "Input New Value : ";
            cin >> newValues2;
            myList.addNodefront(newValues2);
        }

        void bacaforward()
        {
            myList.readdataforward();
        }

        void bacabackward()
        {
            myList.readdatabackward();
        }

        void hapusdepan()
        {
            myList.deletefirst();
        }

        void hapusbelakang()
        {
            myList.deletelast();
        }

        void menyisipkan()
        {
            string nData, n;
            cout << "Input Position : ";
            cin >> nData;
            cout << "Input New Value : ";
            cin >> n;
            myList.insert(nData, n);
        }

        void hapusnode()
        {
            string nData;
            cout << "Input Position : ";
            cin >> nData;
            myList.deleteNode(nData);
        }

        void menu()
        {
            int option;
            do
            {
                cout << "\n1. Tambah Node" << endl;
                cout << "2. Tambah Node Depan" << endl;
                cout << "3. Baca Data Forward" << endl;
                cout << "4. Baca Data Backward" << endl;
                cout << "5. Hapus Depan" << endl;
                cout << "6. Hapus Belakang" << endl;
                cout << "7. Menyisipkan Node" << endl;
                cout << "8. Hapus Node" << endl;
                cout << "9. Exit" << endl;
                cout << "Pilih Menu : ";
                cin >> option;
                switch (option)
                {
                case 1:
                    tambahnode();
                    break;
                case 2:
                    tambahnodefront();
                    break;
                case 3:
                    bacaforward();
                    break;
                case 4:
                    bacabackward();
                    break;
                case 5:
                    hapusdepan();
                    break;
                case 6:
                    hapusbelakang();
                    break;
                case 7:
                    menyisipkan();
                    break;
                case 8:
                    hapusnode();
                    break;
                case 9:
                    cout << "Terima Kasih" << endl;
                    break;
                default:
                    cout << "Pilihan Tidak Tersedia" << endl;
                    break;
                }
            } while (option != 9);
        }    

int main(int argc, char const *argv[])
{
    menu();
    
    return 0;
}
