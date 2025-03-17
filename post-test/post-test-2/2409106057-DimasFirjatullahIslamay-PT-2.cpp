#include <iostream>
using namespace std;

int main()
{
    string Nama;
    string NIM;
    string PasswordNama;
    string PasswordNIM;
    string DaftarTanaman[100][3];
    int FrekuensiSiram[100];
    int FrekuensiPupuk[100];
    float Suhu[100];
    int Coba = 0;
    int Pilihan;
    int Data = 0;

    cout << "=== Daftar Akun ===" << endl;
    cout << "=== Silahkan Masukkan Nama Anda ===" << endl;
    cin >> PasswordNama;
    cout << "=== Silahkan Masukkan NIM Anda ===" << endl;
    cin >> PasswordNIM;

    while (Coba < 3)
    {
        cout << "=== Login Akun ===" << endl;
        cout << "Masukkan Nama Anda: ";
        cin >> Nama;
        cout << "Masukkan NIM Anda: ";
        cin >> NIM;

        if (Nama == PasswordNama && NIM == PasswordNIM)
        {
            cout << "Login Berhasil" << endl;
            break;
        }
        else
        {
            cout << "Nama Atau NIM Salah" << endl;
            Coba++;
        }
    }

    if (Coba == 3)
    {
        cout << "Anda Salah Memasukkan Nama Atau NIM 3 Kali" << endl;
        return 0;
    }

    while (true)
    {
        cout << "=== MENU TANAMAN HIAS ===" << endl;
        cout << "1. Tambah Tanaman" << endl;
        cout << "2. Tampilkan Tanaman" << endl;
        cout << "3. Update Tanaman" << endl;
        cout << "4. Hapus Tanaman" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> Pilihan;

        if (Pilihan == 1)
        {
            if (Data < 100)
            {
                cout << "Masukkan Nama Tanaman: ";
                cin >> DaftarTanaman[Data][0];
                cout << "Masukkan Jenis Tanaman: ";
                cin >> DaftarTanaman[Data][1];
                cout << "Masukkan Jumlah Tanaman: ";
                cin >> DaftarTanaman[Data][2];
                cout << "Masukkan Frekuensi Penyiraman (Berapa Kali Per Minggu): ";
                cin >> FrekuensiSiram[Data];
                cout << "Masukkan Frekuensi Pemupukan (Berapa Kali Per Bulan): ";
                cin >> FrekuensiPupuk[Data];
                cout << "Masukkan Suhu Tanaman (Berapa Derajat Celcius): ";
                cin >> Suhu[Data];
                Data++;
                cout << "Tanaman Berhasil Ditambahkan" << endl;
            }
            else
            {
                cout << "Tanaman Penuh" << endl;
            }
        }
        else if (Pilihan == 2)
        {
            if (Data == 0)
            {
                cout << "Tanaman Masih Kosong" << endl;
            }
            else
            {
                cout << "=== DAFTAR TANAMAN ===" << endl;
                for (int i = 0; i < Data; i++)
                {
                    cout << i + 1 << ". "
                         << DaftarTanaman[i][0] << " | "
                         << DaftarTanaman[i][1] << " | "
                         << DaftarTanaman[i][2] << " | "
                         << FrekuensiSiram[i] << "kali/minggu | "
                         << FrekuensiPupuk[i] << "kali/bulan | "
                         << Suhu[i] << " Derajat Celcius" << endl;
                }
            }
        }
        else if (Pilihan == 3)
        {
            int index;
            cout << "Masukkan Nomor Tanaman Yang Ingin Diupdate: ";
            cin >> index;

            if (index > 0 && index <= Data)
            {
                cout << "Masukkan Nama Tanaman Baru: ";
                cin >> DaftarTanaman[index - 1][0];
                cout << "Masukkan Jenis Tanaman Baru: ";
                cin >> DaftarTanaman[index - 1][1];
                cout << "Masukkan Jumlah Tanaman Baru: ";
                cin >> DaftarTanaman[index - 1][2];
                cout << "Masukkan Frekuensi Penyiraman Baru (Berapa Kali Per Minggu): ";
                cin >> FrekuensiSiram[index - 1];
                cout << "Masukkan Frekuensi Pemupukan Baru (Berapa Kali Per Bulan): ";
                cin >> FrekuensiPupuk[index - 1];
                cout << "Masukkan Suhu Tanaman (Berapa Derajat Celcius): ";
                cin >> Suhu[index - 1];

                cout << "Tanaman Berhasil Diperbarui" << endl;
            }
            else
            {
                cout << "Nomor Tidak Valid" << endl;
            }
        }
        else if (Pilihan == 4)
        {
            int index;
            cout << "Masukkan Nomor Tanaman Yang Ingin Dihapus: ";
            cin >> index;

            if (index > 0 && index <= Data)
            {
                for (int i = index - 1; i < Data - 1; i++)
                {
                    DaftarTanaman[i][0] = DaftarTanaman[i + 1][0];
                    DaftarTanaman[i][1] = DaftarTanaman[i + 1][1];
                    DaftarTanaman[i][2] = DaftarTanaman[i + 1][2];
                    FrekuensiSiram[i] = FrekuensiSiram[i + 1];
                    FrekuensiPupuk[i] = FrekuensiPupuk[i + 1];
                    Suhu[i] = Suhu[i + 1];
                }
                Data--;
                cout << "Tanaman Berhasil Dihapus" << endl;
            }
            else
            {
                cout << "Nomor Tidak Valid" << endl;
            }
        }
        else if (Pilihan == 5)
        {
            cout << "Terima Kasih Telah Menggunakan Program Ini" << endl;
            break;
        }
        else
        {
            cout << "Pilihan Tidak Valid" << endl;
        }
    }

    return 0;
}
