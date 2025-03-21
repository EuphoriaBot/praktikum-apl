#include <iostream>
#include <vector>
using namespace std;

struct Akun
{
    string Nama;
    string NIM;
};

struct Tanaman
{
    string NamaTanaman;
    string JenisTanaman;
    int Jumlah;
    int FrekuensiSiram;
    int FrekuensiPupuk;
    float Suhu;
};

struct User
{
    Akun akun;
    vector<Tanaman> daftarTanaman;
};

// Vector untuk menyimpan user yang terdaftar
vector<User> daftarUser;

int main()
{
    int pilihan;
    string Nama, NIM;
    int coba;
    int indexUser = -1;

    while (true)
    {
        cout << "=== MENU UTAMA ===\n";
        cout << "1. Daftar Akun\n";
        cout << "2. Login Akun\n";
        cout << "3. Keluar Program\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1)
        { // **Register Akun**
            User userBaru;
            cout << "Masukkan Nama: ";
            cin >> userBaru.akun.Nama;
            cout << "Masukkan NIM: ";
            cin >> userBaru.akun.NIM;
            daftarUser.push_back(userBaru);
            cout << "Akun Berhasil Didaftarkan!\n";
        }
        else if (pilihan == 2)
        { // **Login Akun**
            coba = 0;
            indexUser = -1;
            while (coba < 3)
            {
                cout << "Masukkan Nama: ";
                cin >> Nama;
                cout << "Masukkan NIM: ";
                cin >> NIM;

                for (int i = 0; i < daftarUser.size(); i++)
                {
                    if (Nama == daftarUser[i].akun.Nama && NIM == daftarUser[i].akun.NIM)
                    {
                        indexUser = i;
                        break;
                    }
                }

                if (indexUser != -1)
                {
                    cout << "Login Berhasil!\n";
                    break;
                }
                else
                {
                    cout << "Nama atau NIM salah!\n";
                    coba++;
                }
            }

            if (coba == 3)
            {
                cout << "Anda salah 3 kali, program berhenti.\n";
                return 0;
            }

            // **MENU TANAMAN SETELAH LOGIN**
            while (true)
            {
                cout << "=== MENU TANAMAN HIAS ===\n";
                cout << "1. Tambah Tanaman\n";
                cout << "2. Tampilkan Tanaman\n";
                cout << "3. Update Tanaman\n";
                cout << "4. Hapus Tanaman\n";
                cout << "5. Logout\n";
                cout << "Pilih menu: ";
                cin >> pilihan;

                if (pilihan == 1)
                { // **Tambah Tanaman**
                    Tanaman tanamanBaru;
                    cout << "Masukkan Nama Tanaman: ";
                    cin >> tanamanBaru.NamaTanaman;
                    cout << "Masukkan Jenis Tanaman: ";
                    cin >> tanamanBaru.JenisTanaman;
                    cout << "Masukkan Jumlah Tanaman: ";
                    cin >> tanamanBaru.Jumlah;
                    cout << "Masukkan Frekuensi Penyiraman (kali/minggu): ";
                    cin >> tanamanBaru.FrekuensiSiram;
                    cout << "Masukkan Frekuensi Pemupukan (kali/bulan): ";
                    cin >> tanamanBaru.FrekuensiPupuk;
                    cout << "Masukkan Suhu Tanaman (derajat Celcius): ";
                    cin >> tanamanBaru.Suhu;
                    daftarUser[indexUser].daftarTanaman.push_back(tanamanBaru);
                    cout << "Tanaman Berhasil Ditambahkan!\n";
                }
                else if (pilihan == 2)
                { // **Tampilkan Tanaman**
                    if (daftarUser[indexUser].daftarTanaman.empty())
                    {
                        cout << "Belum ada tanaman.\n";
                    }
                    else
                    {
                        cout << "=== DAFTAR TANAMAN ===\n";
                        for (int i = 0; i < daftarUser[indexUser].daftarTanaman.size(); i++)
                        {
                            cout << i + 1 << ". "
                                 << daftarUser[indexUser].daftarTanaman[i].NamaTanaman << " | "
                                 << daftarUser[indexUser].daftarTanaman[i].JenisTanaman << " | "
                                 << daftarUser[indexUser].daftarTanaman[i].Jumlah << " | "
                                 << daftarUser[indexUser].daftarTanaman[i].FrekuensiSiram << " kali/minggu | "
                                 << daftarUser[indexUser].daftarTanaman[i].FrekuensiPupuk << " kali/bulan | "
                                 << daftarUser[indexUser].daftarTanaman[i].Suhu << " °C\n";
                        }
                    }
                }
                else if (pilihan == 3)
                { // **Update Tanaman**
                    int index;
                    cout << "Masukkan Nomor Tanaman yang ingin diupdate: ";
                    cin >> index;
                    if (index > 0 && index <= daftarUser[indexUser].daftarTanaman.size())
                    {
                        index--;
                        cout << "Masukkan Nama Tanaman Baru: ";
                        cin >> daftarUser[indexUser].daftarTanaman[index].NamaTanaman;
                        cout << "Masukkan Jenis Tanaman Baru: ";
                        cin >> daftarUser[indexUser].daftarTanaman[index].JenisTanaman;
                        cout << "Masukkan Jumlah Tanaman Baru: ";
                        cin >> daftarUser[indexUser].daftarTanaman[index].Jumlah;
                        cout << "Masukkan Frekuensi Penyiraman Baru: ";
                        cin >> daftarUser[indexUser].daftarTanaman[index].FrekuensiSiram;
                        cout << "Masukkan Frekuensi Pemupukan Baru: ";
                        cin >> daftarUser[indexUser].daftarTanaman[index].FrekuensiPupuk;
                        cout << "Masukkan Suhu Baru: ";
                        cin >> daftarUser[indexUser].daftarTanaman[index].Suhu;
                        cout << "Tanaman Berhasil Diperbarui!\n";
                    }
                    else
                    {
                        cout << "Nomor Tidak Valid\n";
                    }
                }
                else if (pilihan == 4)
                { // **Hapus Tanaman**
                    int index;
                    cout << "Masukkan Nomor Tanaman yang ingin dihapus: ";
                    cin >> index;
                    if (index > 0 && index <= daftarUser[indexUser].daftarTanaman.size())
                    {
                        daftarUser[indexUser].daftarTanaman.erase(daftarUser[indexUser].daftarTanaman.begin() + (index - 1));
                        cout << "Tanaman Berhasil Dihapus!\n";
                    }
                    else
                    {
                        cout << "Nomor Tidak Valid\n";
                    }
                }
                else if (pilihan == 5)
                { // **Logout**
                    cout << "Logout Berhasil!\n";
                    break;
                }
                else
                {
                    cout << "Pilihan Tidak Valid\n";
                }
            }
        }
        else if (pilihan == 3)
        { // **Keluar Program**
            cout << "Program Berhenti.\n";
            return 0;
        }
        else
        {
            cout << "Pilihan Tidak Valid\n";
        }
    }
}
