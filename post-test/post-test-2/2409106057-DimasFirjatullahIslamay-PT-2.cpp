#include <iostream>
using namespace std;

int main()
{
    string nama;
    string PasswordNama = "Dimas";
    string NIM;
    string PasswordNIM = "2409106057";
    string DaftarTanaman[100][3];
    int coba = 0;
    int pilihan;
    int max_tanaman = 100;
    int Data = 0;

    while (coba < 3)
    {
        cout << "Masukkan Nama Anda: ";
        cin >> nama;
        cout << "Masukkan NIM Anda: ";
        cin >> NIM;

        if (nama == PasswordNama && NIM == PasswordNIM)
        {
            cout << "Login Berhasil" << endl;
            break;
        }
        else
        {
            cout << "Nama Atau NIM Salah" << endl;
            coba++;
        }
    }

    if (coba == 3)
    {
        cout << "Anda Salah Memasukkan Nama Atau NIM 3 kali";
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
        cin >> pilihan;

        if (pilihan == 1)
        {
            if (Data < max_tanaman)
            {
                cout << "Masukkan Nama Tanaman: ";
                cin >> DaftarTanaman[Data][0];
                cout << "Masukkan Jenis Tanaman: ";
                cin >> DaftarTanaman[Data][1];
                cout << "Masukkan Jumlah Tanaman: ";
                cin >> DaftarTanaman[Data][2];
                Data++;
                cout << "Tanaman Berhasil Ditambahkan" << endl;
            }
            else
            {
                cout << "Tanaman Penuh" << endl;
            }
        }
        else if (pilihan == 2)
        {
            cout << "=== DAFTAR TANAMAN ===" << endl;
            for (int i = 0; i < Data; i++)
            {
                cout << i + 1 << ". " << DaftarTanaman[i][0] << " | " << DaftarTanaman[i][1] << " | " << DaftarTanaman[i][2] << endl;
            }
        }
        else if (pilihan == 3)
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
                cout << "Tanaman Berhasil Diperbarui" << endl;
            }
            else
            {
                cout << "Nomor Tidak Valid" << endl;
            }
        }
        else if (pilihan == 4)
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
                }
                Data--;
                cout << "Tanaman Berhasil Dihapus" << endl;
            }
            else
            {
                cout << "Nomor Tidak Valid" << endl;
            }
        }
        else if (pilihan == 5)
        {
            cout << "Terima kasih Telah Menggunakan Program Ini" << endl;
            break;
        }
        else
        {
            cout << "Pilihan Tidak Valid" << endl;
        }
    }

    return 0;
}
