// FIDELA AZZAHRA
// A11.2021.13417
// queue

#include <iostream>
#include <conio.h>
#include <iomanip> //untuk setw()

using namespace std;

// deklarasi node
struct Data_node
{
    // data di node
    char nama[25];
    char kategori[7];
    char harga[10];
};

struct node
{
    Data_node data;
    node *next; // pointer di node
};

// deklarasi single linked list
node *_head;
node *_tail;
node *_curr;
node *_entry;
node *_del;

// kalo awal kan tidak ada node, berarti tidak ada head
void inisialisasi()
{
    _head = NULL;
    _tail = NULL;
}

// input data node
void input(Data_node dt)
{

    _entry = (node *)malloc(sizeof(node)); // alokasi memori
    _entry->data = dt;                     // penugasan struktur
    _entry->next = NULL;
    if (_head == NULL)
    {
        _head = _entry;
        _tail = _head;
    }
    else
    {
        _tail->next = _entry;
        _tail = _entry;
    }
}

// hapus data node
void hapus()
{
    node _simpan;
    if (_head == NULL)
    {
        cout << "\nLinked list kosong, penghapusan tidak bisa dilakukan." << endl;
    }
    else
    {
        _simpan.data = _head->data;
        cout << "\nMenu yang dihapus adalah ";
        cout << _simpan.data.nama << "/" << _simpan.data.kategori << "/" << _simpan.data.harga << endl;

        // hapus depan
        _del = _head;
        _head = _head->next;
        delete _del;
    }
}

// cetak / tampilkan data node
void cetak()
{
    _curr = _head;
    if (_head == NULL)
        cout << "\ntidak ada menu dalam linked list" << endl;
    else
    {
        cout << "\nMenu yang ada dalam linked list : \n"
             << endl;
        cout << "\t";
        while (_curr != NULL)
        {
            cout << _curr->data.nama << "/" << _curr->data.kategori << "/" << _curr->data.harga;
            cout << " -> ";
            _curr = _curr->next;
        }
        cout << "NULL";
        cout << endl;
    }
}

// list menu. Output yang akan pertama kali di liat ketika program di run
void menu()
{
    char pilih, ulang;
    node tmp;

    do
    {
        fflush(stdin);
        system("cls");
        cout << "-------------------------------------" << endl;
        cout << "          TOKO FIDELA AZZAHRA" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Menu : " << endl;
        cout << "1. Masukkan belanjaan ke troly" << endl;
        cout << "2. Hapus belanjaan dari troly" << endl;
        cout << "3. Lihat belanjaan yang ada di troly" << endl;
        cout << "4. Keluar" << endl;
        cout << "-------------------------------------" << endl;
        cout << endl;
        cout << "Pilih menu anda : ";
        cin >> pilih;

        // switch case
        switch (pilih)
        {
        case '1':
            fflush(stdin);
            cout << "\nMasukkan nama barang : ";
            cin >> tmp.data.nama;
            cout << "Masukkan kategori barang : ";
            cin >> tmp.data.kategori;
            cout << "Masukkan harga barang : ";
            cin >> tmp.data.harga;
            input(tmp.data);
            break;
        case '2':
            hapus();
            break;
        case '3':
            cetak();
            break;
        case '4':
            exit(0);
            break;
        default:
            cout << "\nPilihan salah" << endl;
        }
        cout << "\nKembali ke menu?(y/n)";
        cin >> ulang;
    } while (ulang == 'y' || ulang == 'Y');
}

// fungsi main
int main()
{
    inisialisasi();
    menu();

    return EXIT_SUCCESS;
}
