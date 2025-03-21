#include <iostream>
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
    Tanaman daftarTanaman[100];
    int totalTanaman = 0;
};

// Array penyimpanan akun
User daftarUser[100];
int totalUser = 0;

int main()
{
    int pilihan;
    string Nama, NIM;
    int coba = 0;
    int indexUser = -1; // Menyimpan index user yang login

    while (true)
    {
        cout << "=== MENU UTAMA ===" << endl;
        cout << "1. Daftar Akun" << endl;
        cout << "2. Login Akun" << endl;
        cout << "3. Keluar Program" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1)
        { // **Register Akun**
            cout << "Masukkan Nama: ";
            cin >> daftarUser[totalUser].akun.Nama;
            cout << "Masukkan NIM: ";
            cin >> daftarUser[totalUser].akun.NIM;
            totalUser++;
            cout << "Akun Berhasil Didaftarkan!" << endl;
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

                for (int i = 0; i < totalUser; i++)
                {
                    if (Nama == daftarUser[i].akun.Nama && NIM == daftarUser[i].akun.NIM)
                    {
                        indexUser = i;
                        break;
                    }
                }

                if (indexUser != -1)
                {
                    cout << "Login Berhasil!" << endl;
                    break;
                }
                else
                {
                    cout << "Nama atau NIM salah!" << endl;
                    coba++;
                }
            }

            if (coba == 3)
            {
                cout << "Anda salah 3 kali, program berhenti." << endl;
                return 0;
            }

            // **MENU TANAMAN SETELAH LOGIN**
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
                { // **Tambah Tanaman**
                    int idx = daftarUser[indexUser].totalTanaman;
                    cout << "Masukkan Nama Tanaman: ";
                    cin >> daftarUser[indexUser].daftarTanaman[idx].NamaTanaman;
                    cout << "Masukkan Jenis Tanaman: ";
                    cin >> daftarUser[indexUser].daftarTanaman[idx].JenisTanaman;
                    cout << "Masukkan Jumlah Tanaman: ";
                    cin >> daftarUser[indexUser].daftarTanaman[idx].Jumlah;
                    cout << "Masukkan Frekuensi Penyiraman (kali/minggu): ";
                    cin >> daftarUser[indexUser].daftarTanaman[idx].FrekuensiSiram;
                    cout << "Masukkan Frekuensi Pemupukan (kali/bulan): ";
                    cin >> daftarUser[indexUser].daftarTanaman[idx].FrekuensiPupuk;
                    cout << "Masukkan Suhu Tanaman (derajat Celcius): ";
                    cin >> daftarUser[indexUser].daftarTanaman[idx].Suhu;
                    daftarUser[indexUser].totalTanaman++;
                    cout << "Tanaman Berhasil Ditambahkan!" << endl;
                }
                else if (pilihan == 2)
                { // **Tampilkan Tanaman**
                    if (daftarUser[indexUser].totalTanaman == 0)
                    {
                        cout << "Belum ada tanaman." << endl;
                    }
                    else
                    {
                        cout << "=== DAFTAR TANAMAN ===" << endl;
                        for (int i = 0; i < daftarUser[indexUser].totalTanaman; i++)
                        {
                            cout << i + 1 << ". "
                                 << daftarUser[indexUser].daftarTanaman[i].NamaTanaman << " | "
                                 << daftarUser[indexUser].daftarTanaman[i].JenisTanaman << " | "
                                 << daftarUser[indexUser].daftarTanaman[i].Jumlah << " | "
                                 << daftarUser[indexUser].daftarTanaman[i].FrekuensiSiram << " kali/minggu | "
                                 << daftarUser[indexUser].daftarTanaman[i].FrekuensiPupuk << " kali/bulan | "
                                 << daftarUser[indexUser].daftarTanaman[i].Suhu << " °C" << endl;
                        }
                    }
                }
                else if (pilihan == 3)
                { // **Update Tanaman**
                    int index;
                    cout << "Masukkan Nomor Tanaman yang ingin diupdate: ";
                    cin >> index;
                    if (index > 0 && index <= daftarUser[indexUser].totalTanaman)
                    {
                        index--; // Menyesuaikan dengan array (mulai dari 0)
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
                        cout << "Tanaman Berhasil Diperbarui!" << endl;
                    }
                    else
                    {
                        cout << "Nomor Tidak Valid" << endl;
                    }
                }
                else if (pilihan == 4)
                { // **Hapus Tanaman**
                    int index;
                    cout << "Masukkan Nomor Tanaman yang ingin dihapus: ";
                    cin >> index;
                    if (index > 0 && index <= daftarUser[indexUser].totalTanaman)
                    {
                        index--;
                        for (int i = index; i < daftarUser[indexUser].totalTanaman - 1; i++)
                        {
                            daftarUser[indexUser].daftarTanaman[i] = daftarUser[indexUser].daftarTanaman[i + 1];
                        }
                        daftarUser[indexUser].totalTanaman--;
                        cout << "Tanaman Berhasil Dihapus!" << endl;
                    }
                    else
                    {
                        cout << "Nomor Tidak Valid" << endl;
                    }
                }
                else if (pilihan == 5)
                { // **Logout**
                    cout << "Logout Berhasil!" << endl;
                    break;
                }
                else
                {
                    cout << "Pilihan Tidak Valid" << endl;
                }
            }
        }
        else if (pilihan == 3)
        { // **Keluar Program**
            cout << "Program Berhenti." << endl;
            return 0;
        }
        else
        {
            cout << "Pilihan Tidak Valid" << endl;
        }
    }
}
