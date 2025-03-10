#include <iostream>
using namespace std;

int main()
{
    int PIN = 6057;
    int MasukkanPin;
    int coba = 0;
    int pilihan;
    double saldo = 100000;

    while (coba < 3)
    {
        cout << "Masukkan PIN anda: ";
        cin >> MasukkanPin;
        if (MasukkanPin == PIN)
        {
            cout << "Login berhasil" << endl;
            break;
        }
        else
        {
            cout << "PIN salah" << endl;
            coba++;
        }
    }

    if (coba == 3)
    {
        cout << "Anda sudah salah memasukkan PIN 3 kali";
        return 0;
    }

    while (true)
    {
        cout << "=== MENU ATM ===" << endl;
        cout << "1. Setor Tunai" << endl;
        cout << "2. Cek Saldo" << endl;
        cout << "3. Tarik Tunai" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1)
        {
            double setor;
            cout << "Masukkan jumlah setor tunai: ";
            cin >> setor;
            if (setor > 0)
            {
                saldo += setor;
                cout << "Saldo anda sekarang: Rp " << saldo << endl;
            }
            else
            {
                cout << "Jumlah tidak valid" << endl;
            }
        }
        else if (pilihan == 2)
        {
            cout << "Saldo anda: Rp " << saldo << endl;
        }
        else if (pilihan == 3)
        {
            double tarik;
            cout << "Masukkan jumlah tarik tunai: ";
            cin >> tarik;
            if (tarik > 0 and tarik <= saldo)
            {
                saldo -= tarik;
                cout << "Penarikan berhasil, sisa saldo anda: Rp " << saldo << endl;
            }
            else
            {
                cout << "Saldo tidak cukup" << endl;
            }
        }
        else if (pilihan == 4)
        {
            cout << "Terima kasih telah menggunakan ATM" << endl;
            break;
        }
        else
        {
            cout << "Pilihan tidak valid" << endl;
        }
    }

    return 0;
}
