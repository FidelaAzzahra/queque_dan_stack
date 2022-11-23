// FIDELA AZZAHRA
// A11.2021.13417
// stack

#include <iostream>
using namespace std;

struct Toko
{
    int data;
    struct Toko *next;
};

struct Toko *top = NULL;

// push data / tambah data
void tambah(int val)
{
    struct Toko *tokobaru = (struct Toko *)malloc(sizeof(struct Toko));
    tokobaru->data = val;
    tokobaru->next = top;
    top = tokobaru;
}

// pop data / hapus data
void hapus()
{
    if (top == NULL)
        cout << "Stack Underflow" << endl;
    else
    {
        cout << "Nomor yang dihapus adalah = " << top->data << endl;
        top = top->next;
    }
}

// tampilkan data
void tampil()
{
    struct Toko *ptr;
    if (top == NULL)
        cout << " Tidak ada pelanggan" << endl;
    else
    {
        ptr = top;
        cout << "Nomor urutnya adalah = ";
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
}

int main()
{
    int pilihan, val;

    cout << endl;
    cout << "-------------------------------------" << endl;
    cout << "        TOKO BARANG BEKAS " << endl;
    cout << "-------------------------------------" << endl;
    cout << "1. Masukkan nomor urut pelanggan " << endl;
    cout << "2. Hapus nomor urut pelanggan " << endl;
    cout << "3. Tampilkan nomor urut pelanggan " << endl;
    cout << "4. Keluar " << endl;
    do
    {
        cout << endl;
        cout << "Masukkan pilihan => ";
        cin >> pilihan;
        switch (pilihan)
        {
        case 1:
        {
            cout << "Tambah nomor ke dalam data: ";
            cin >> val;
            tambah(val);
            break;
        }
        case 2:
        {
            hapus();
            break;
        }
        case 3:
        {
            tampil();
            break;
        }
        case 4:
        {
            cout << "Keluar" << endl;
            cout << endl;
            break;
        }
        default:
        {
            cout << "Pilihan Salah" << endl;
        }
        }
    } while (pilihan != 4);
    return 0;
}
