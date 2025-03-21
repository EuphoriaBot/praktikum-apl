#include <iostream>
using namespace std;

struct Tanaman
{
    string nama;
    string jenis;
    int jumlah;
    int frekuensiSiram;
    int frekuensiPupuk;
    float suhu;
};

struct User
{
    string nama;
    string nim;
};

User users[100];                      // Array untuk menyimpan akun
Tanaman daftarTanaman[100];           // Array untuk menyimpan tanaman hias
int totalUsers = 0, totalTanaman = 0; // Jumlah data yang tersimpan

void registerUser()
{
    cout << "=== Registrasi Akun ===" << endl;
    cout << "Masukkan Nama: ";
    cin >> users[totalUsers].nama;
    cout << "Masukkan NIM: ";
    cin >> users[totalUsers].nim;
    cout << "Akun Berhasil Didaftarkan!\n"
         << endl;
    totalUsers++;
}

bool loginUser(string &nama, string &nim)
{
    int coba = 0;
    while (coba < 3)
    {
        cout << "=== Login ===" << endl;
        cout << "Masukkan Nama: ";
        cin >> nama;
        cout << "Masukkan NIM: ";
        cin >> nim;

        for (int i = 0; i < totalUsers; i++)
        {
            if (nama == users[i].nama && nim == users[i].nim)
            {
                cout << "Login Berhasil!\n"
                     << endl;
                return true;
            }
        }
        cout << "Nama atau NIM salah!\n"
             << endl;
        coba++;
    }
    cout << "Anda telah gagal login 3 kali. Program berhenti." << endl;
    return false;
}

void tambahTanaman()
{
    if (totalTanaman < 100)
    {
        cout << "Masukkan Nama Tanaman: ";
        cin >> daftarTanaman[totalTanaman].nama;
        cout << "Masukkan Jenis Tanaman: ";
        cin >> daftarTanaman[totalTanaman].jenis;
        cout << "Masukkan Jumlah Tanaman: ";
        cin >> daftarTanaman[totalTanaman].jumlah;
        cout << "Masukkan Frekuensi Penyiraman (kali/minggu): ";
        cin >> daftarTanaman[totalTanaman].frekuensiSiram;
        cout << "Masukkan Frekuensi Pemupukan (kali/bulan): ";
        cin >> daftarTanaman[totalTanaman].frekuensiPupuk;
        cout << "Masukkan Suhu Tanaman (derajat Celsius): ";
        cin >> daftarTanaman[totalTanaman].suhu;
        totalTanaman++;
        cout << "Tanaman berhasil ditambahkan!\n"
             << endl;
    }
    else
    {
        cout << "Daftar tanaman penuh!\n"
             << endl;
    }
}

void tampilkanTanaman()
{
    if (totalTanaman == 0)
    {
        cout << "Belum ada tanaman yang terdaftar.\n"
             << endl;
        return;
    }
    cout << "=== Daftar Tanaman Hias ===" << endl;
    for (int i = 0; i < totalTanaman; i++)
    {
        cout << i + 1 << ". " << daftarTanaman[i].nama << " | "
             << daftarTanaman[i].jenis << " | "
             << daftarTanaman[i].jumlah << " | "
             << daftarTanaman[i].frekuensiSiram << " kali/minggu | "
             << daftarTanaman[i].frekuensiPupuk << " kali/bulan | "
             << daftarTanaman[i].suhu << "°C" << endl;
    }
    cout << endl;
}

void updateTanaman()
{
    int index;
    cout << "Masukkan nomor tanaman yang ingin diperbarui: ";
    cin >> index;

    if (index > 0 && index <= totalTanaman)
    {
        index--;
        cout << "Masukkan Nama Baru: ";
        cin >> daftarTanaman[index].nama;
        cout << "Masukkan Jenis Baru: ";
        cin >> daftarTanaman[index].jenis;
        cout << "Masukkan Jumlah Baru: ";
        cin >> daftarTanaman[index].jumlah;
        cout << "Masukkan Frekuensi Siram Baru: ";
        cin >> daftarTanaman[index].frekuensiSiram;
        cout << "Masukkan Frekuensi Pupuk Baru: ";
        cin >> daftarTanaman[index].frekuensiPupuk;
        cout << "Masukkan Suhu Baru: ";
        cin >> daftarTanaman[index].suhu;
        cout << "Tanaman berhasil diperbarui!\n"
             << endl;
    }
    else
    {
        cout << "Nomor tidak valid!\n"
             << endl;
    }
}

void hapusTanaman()
{
    int index;
    cout << "Masukkan nomor tanaman yang ingin dihapus: ";
    cin >> index;

    if (index > 0 && index <= totalTanaman)
    {
        for (int i = index - 1; i < totalTanaman - 1; i++)
        {
            daftarTanaman[i] = daftarTanaman[i + 1];
        }
        totalTanaman--;
        cout << "Tanaman berhasil dihapus!\n"
             << endl;
    }
    else
    {
        cout << "Nomor tidak valid!\n"
             << endl;
    }
}

int main()
{
    int pilihan;
    string nama, nim;

    while (true)
    {
        cout << "=== MENU ===" << endl;
        cout << "1. Daftar Akun" << endl;
        cout << "2. Login" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1)
        {
            registerUser();
        }
        else if (pilihan == 2)
        {
            if (loginUser(nama, nim))
            {
                while (true)
                {
                    cout << "=== MENU TANAMAN HIAS ===" << endl;
                    cout << "1. Tambah Tanaman" << endl;
                    cout << "2. Tampilkan Tanaman" << endl;
                    cout << "3. Update Tanaman" << endl;
                    cout << "4. Hapus Tanaman" << endl;
                    cout << "5. Logout" << endl;
                    cout << "Pilih menu: ";
                    cin >> pilihan;

                    if (pilihan == 1)
                        tambahTanaman();
                    else if (pilihan == 2)
                        tampilkanTanaman();
                    else if (pilihan == 3)
                        updateTanaman();
                    else if (pilihan == 4)
                        hapusTanaman();
                    else if (pilihan == 5)
                    {
                        cout << "Logout Berhasil!\n"
                             << endl;
                        break;
                    }
                    else
                    {
                        cout << "Pilihan tidak valid!\n"
                             << endl;
                    }
                }
            }
        }
        else if (pilihan == 3)
        {
            cout << "Terima kasih telah menggunakan program ini.\n";
            break;
        }
        else
        {
            cout << "Pilihan tidak valid!\n"
                 << endl;
        }
    }

    return 0;
}
