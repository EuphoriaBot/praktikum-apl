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
        int Pilihan;
        cout << "==== MENU ====" << endl;
        cout << "1. Daftar Akun" << endl;
        cout << "2. Login" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih: ";
        cin >> Pilihan;

        if (Pilihan == 1)
        {
            cout << "Masukkan Nama: ";
            cin >> users[TotalAkun].nama;
            cout << "Masukkan NIM: ";
            cin >> users[TotalAkun].nim;
            TotalAkun++;
            cout << "Akun Berhasil Didaftarkan" << endl;
        }
        else if (Pilihan == 2)
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
                int pilihan;
                cout << "=== MENU TANAMAN HIAS ===" << endl;
                cout << "1. Tambah Tanaman" << endl;
                cout << "2. Lihat Tanaman" << endl;
                cout << "3. Update Tanaman" << endl;
                cout << "4. Hapus Tanaman" << endl;
                cout << "5. Logout" << endl;
                cout << "Pilih: ";
                cin >> pilihan;

                if (pilihan == 1)
                {
                    int index = users[userIndex].totalTanaman;
                    cout << "Masukkan Nama Tanaman: ";
                    cin >> users[userIndex].tanaman[index].nama;
                    cout << "Masukkan Jenis Tanaman: ";
                    cin >> users[userIndex].tanaman[index].jenis;
                    cout << "Masukkan Jumlah Tanaman: ";
                    cin >> users[userIndex].tanaman[index].jumlah;
                    cout << "Masukkan Frekuensi Penyiraman (Berapa kali per minggu): ";
                    cin >> users[userIndex].tanaman[index].siram;
                    cout << "Masukkan Frekuensi Pemupukan (Berapa kali per bulan): ";
                    cin >> users[userIndex].tanaman[index].pupuk;
                    cout << "Masukkan Suhu Tanaman: ";
                    cin >> users[userIndex].tanaman[index].suhu;
                    users[userIndex].totalTanaman++;
                    cout << "Tanaman Berhasil Ditambahkan" << endl;
                }
                else if (pilihan == 2)
                {
                    if (users[userIndex].totalTanaman == 0)
                    {
                        cout << "Belum Ada Tanaman" << endl;
                    }
                    else
                    {
                        cout << "=== DAFTAR TANAMAN ===" << endl;
                        for (int i = 0; i < users[userIndex].totalTanaman; i++)
                        {
                            cout << i + 1 << ". " << users[userIndex].tanaman[i].nama << " | "
                                 << users[userIndex].tanaman[i].jenis << " | "
                                 << users[userIndex].tanaman[i].jumlah << " Tanaman | "
                                 << users[userIndex].tanaman[i].siram << "Kali Siram Per Minggu | "
                                 << users[userIndex].tanaman[i].pupuk << "Kali Pupuk Per Bulan | "
                                 << users[userIndex].tanaman[i].suhu << "Derajat Celsius" << endl;
                        }
                    }
                }
                else if (pilihan == 3)
                {
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

                    if (index > 0 && index <= users[userIndex].totalTanaman)
                    {
                        for (int i = index - 1; i < users[userIndex].totalTanaman - 1; i++)
                        {
                            users[userIndex].tanaman[i] = users[userIndex].tanaman[i + 1];
                        }
                        users[userIndex].totalTanaman--;
                        cout << "Tanaman Berhasil Dihapus" << endl;
                    }
                    else
                    {
                        cout << "Nomor Tidak Valid" << endl;
                    }
                }
                else if (pilihan == 5)
                {
                    cout << "Logout Berhasil" << endl;
                    break;
                }
                else
                {
                    cout << "Pilihan Tidak Valid" << endl;
                }
            }
        }
        else if (Pilihan == 3)
        {
            cout << "Terima kasih telah menggunakan program ini" << endl;
            break;
        }
        else
        {
            cout << "Pilihan Tidak Valid" << endl;
        }
    }

    return 0;
}
