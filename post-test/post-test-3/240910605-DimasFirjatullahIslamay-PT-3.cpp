#include <iostream>
using namespace std;

struct Tanaman
{
    string nama;
    string jenis;
    int jumlah;
    int siram;
    int pupuk;
    float suhu;
};

struct User
{
    string nama;
    string nim;
    Tanaman tanaman[100];
    int totalTanaman = 0;
};

User users[100];
int TotalAkun = 0;

int main()
{
    string Nama, NIM;
    int Coba = 0, userIndex = -1;

    while (true)
    {
        int PilihMenu;
        cout << "==== MENU ====" << endl;
        cout << "1. Daftar Akun" << endl;
        cout << "2. Login" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih: ";
        cin >> PilihMenu;

        if (PilihMenu == 1)
        {
            cout << "Masukkan Nama: ";
            cin >> users[TotalAkun].nama;
            cout << "Masukkan NIM: ";
            cin >> users[TotalAkun].nim;
            TotalAkun++;
            cout << "Akun Berhasil Didaftarkan" << endl;
        }
        else if (PilihMenu == 2)
        {
            Coba = 0;
            while (Coba < 3)
            {
                cout << "=== Login ===" << endl;
                cout << "Masukkan Nama: ";
                cin >> Nama;
                cout << "Masukkan NIM: ";
                cin >> NIM;

                userIndex = -1;
                for (int i = 0; i < TotalAkun; i++)
                {
                    if (users[i].nama == Nama && users[i].nim == NIM)
                    {
                        userIndex = i;
                        break;
                    }
                }

                if (userIndex != -1)
                {
                    cout << "Login Berhasil" << endl;
                    break;
                }
                else
                {
                    cout << "Nama atau NIM Salah" << endl;
                    Coba++;
                }
            }

            if (Coba == 3)
            {
                cout << "Anda Salah Memasukkan Nama atau NIM 3 Kali" << endl;
                return 0;
            }

            while (true)
            {
                int pilihan;
                cout << "=== MENU TANAMAN HIAS ===\n";
                cout << "1. Tambah Tanaman\n";
                cout << "2. Lihat Tanaman\n";
                cout << "3. Update Tanaman\n";
                cout << "4. Hapus Tanaman\n";
                cout << "5. Logout\n";
                cout << "Pilih: ";
                cin >> pilihan;

                if (pilihan == 1)
                { // Tambah Tanaman
                    int index = users[userIndex].totalTanaman;
                    cout << "Masukkan Nama Tanaman: ";
                    cin >> users[userIndex].tanaman[index].nama;
                    cout << "Masukkan Jenis Tanaman: ";
                    cin >> users[userIndex].tanaman[index].jenis;
                    cout << "Masukkan Jumlah Tanaman: ";
                    cin >> users[userIndex].tanaman[index].jumlah;
                    cout << "Masukkan Frekuensi Penyiraman: ";
                    cin >> users[userIndex].tanaman[index].siram;
                    cout << "Masukkan Frekuensi Pemupukan: ";
                    cin >> users[userIndex].tanaman[index].pupuk;
                    cout << "Masukkan Suhu Tanaman (°C): ";
                    cin >> users[userIndex].tanaman[index].suhu;
                    users[userIndex].totalTanaman++;
                    cout << "Tanaman Berhasil Ditambahkan!\n";
                }
                else if (pilihan == 2)
                { // Lihat Tanaman
                    if (users[userIndex].totalTanaman == 0)
                    {
                        cout << "Belum ada tanaman!\n";
                    }
                    else
                    {
                        cout << "=== DAFTAR TANAMAN ===\n";
                        for (int i = 0; i < users[userIndex].totalTanaman; i++)
                        {
                            cout << i + 1 << ". " << users[userIndex].tanaman[i].nama << " | "
                                 << users[userIndex].tanaman[i].jenis << " | "
                                 << users[userIndex].tanaman[i].jumlah << " tanaman | "
                                 << users[userIndex].tanaman[i].siram << "x siram/minggu | "
                                 << users[userIndex].tanaman[i].pupuk << "x pupuk/bulan | "
                                 << users[userIndex].tanaman[i].suhu << "°C\n";
                        }
                    }
                }
                else if (pilihan == 3)
                { // Update Tanaman
                    int index;
                    cout << "Masukkan Nomor Tanaman Yang Ingin Diupdate: ";
                    cin >> index;

                    if (index > 0 && index <= users[userIndex].totalTanaman)
                    {
                        index--;
                        cout << "Masukkan Nama Tanaman Baru: ";
                        cin >> users[userIndex].tanaman[index].nama;
                        cout << "Masukkan Jenis Tanaman Baru: ";
                        cin >> users[userIndex].tanaman[index].jenis;
                        cout << "Masukkan Jumlah Tanaman Baru: ";
                        cin >> users[userIndex].tanaman[index].jumlah;
                        cout << "Masukkan Frekuensi Penyiraman Baru: ";
                        cin >> users[userIndex].tanaman[index].siram;
                        cout << "Masukkan Frekuensi Pemupukan Baru: ";
                        cin >> users[userIndex].tanaman[index].pupuk;
                        cout << "Masukkan Suhu Tanaman Baru: ";
                        cin >> users[userIndex].tanaman[index].suhu;
                        cout << "Tanaman Berhasil Diperbarui!\n";
                    }
                    else
                    {
                        cout << "Nomor Tidak Valid!\n";
                    }
                }
                else if (pilihan == 4)
                { // Hapus Tanaman
                    int index;
                    cout << "Masukkan Nomor Tanaman Yang Ingin Dihapus: ";
                    cin >> index;

                    if (index > 0 && index <= users[userIndex].totalTanaman)
                    {
                        for (int i = index - 1; i < users[userIndex].totalTanaman - 1; i++)
                        {
                            users[userIndex].tanaman[i] = users[userIndex].tanaman[i + 1];
                        }
                        users[userIndex].totalTanaman--;
                        cout << "Tanaman Berhasil Dihapus!\n";
                    }
                    else
                    {
                        cout << "Nomor Tidak Valid!\n";
                    }
                }
                else if (pilihan == 5)
                { // Logout
                    cout << "Logout Berhasil!\n";
                    break;
                }
                else
                {
                    cout << "Pilihan Tidak Valid!\n";
                }
            }
        }
        else if (PilihMenu == 3)
        { // Keluar dari program
            cout << "Terima kasih telah menggunakan program ini!\n";
            break;
        }
        else
        {
            cout << "Pilihan Tidak Valid!\n";
        }
    }

    return 0;
}
