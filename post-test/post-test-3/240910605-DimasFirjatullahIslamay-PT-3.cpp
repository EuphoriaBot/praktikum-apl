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
    int Coba = 0, UserIndex = -1;

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

                UserIndex = -1;
                for (int i = 0; i < TotalAkun; i++)
                {
                    if (users[i].nama == Nama && users[i].nim == NIM)
                    {
                        UserIndex = i;
                        break;
                    }
                }

                if (UserIndex != -1)
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
                    int index = users[UserIndex].totalTanaman;
                    cout << "Masukkan Nama Tanaman: ";
                    cin >> users[UserIndex].tanaman[index].nama;
                    cout << "Masukkan Jenis Tanaman: ";
                    cin >> users[UserIndex].tanaman[index].jenis;
                    cout << "Masukkan Jumlah Tanaman: ";
                    cin >> users[UserIndex].tanaman[index].jumlah;
                    cout << "Masukkan Frekuensi Penyiraman (Berapa kali per minggu): ";
                    cin >> users[UserIndex].tanaman[index].siram;
                    cout << "Masukkan Frekuensi Pemupukan (Berapa kali per bulan): ";
                    cin >> users[UserIndex].tanaman[index].pupuk;
                    cout << "Masukkan Suhu Tanaman: ";
                    cin >> users[UserIndex].tanaman[index].suhu;
                    users[UserIndex].totalTanaman++;
                    cout << "Tanaman Berhasil Ditambahkan" << endl;
                }
                else if (pilihan == 2)
                {
                    if (users[UserIndex].totalTanaman == 0)
                    {
                        cout << "Belum Ada Tanaman" << endl;
                    }
                    else
                    {
                        cout << "=== DAFTAR TANAMAN ===" << endl;
                        for (int i = 0; i < users[UserIndex].totalTanaman; i++)
                        {
                            cout << i + 1 << ". " << users[UserIndex].tanaman[i].nama << " | "
                                 << users[UserIndex].tanaman[i].jenis << " | "
                                 << users[UserIndex].tanaman[i].jumlah << " Tanaman | "
                                 << users[UserIndex].tanaman[i].siram << "Kali Siram Per Minggu | "
                                 << users[UserIndex].tanaman[i].pupuk << "Kali Pupuk Per Bulan | "
                                 << users[UserIndex].tanaman[i].suhu << "Derajat Celsius" << endl;
                        }
                    }
                }
                else if (pilihan == 3)
                {
                    int index;
                    cout << "Masukkan Nomor Tanaman Yang Ingin Diupdate: ";
                    cin >> index;

                    if (index > 0 && index <= users[UserIndex].totalTanaman)
                    {
                        index--;
                        cout << "Masukkan Nama Tanaman Baru: ";
                        cin >> users[UserIndex].tanaman[index].nama;
                        cout << "Masukkan Jenis Tanaman Baru: ";
                        cin >> users[UserIndex].tanaman[index].jenis;
                        cout << "Masukkan Jumlah Tanaman Baru: ";
                        cin >> users[UserIndex].tanaman[index].jumlah;
                        cout << "Masukkan Frekuensi Penyiraman Baru: ";
                        cin >> users[UserIndex].tanaman[index].siram;
                        cout << "Masukkan Frekuensi Pemupukan Baru: ";
                        cin >> users[UserIndex].tanaman[index].pupuk;
                        cout << "Masukkan Suhu Tanaman Baru: ";
                        cin >> users[UserIndex].tanaman[index].suhu;
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

                    if (index > 0 && index <= users[UserIndex].totalTanaman)
                    {
                        for (int i = index - 1; i < users[UserIndex].totalTanaman - 1; i++)
                        {
                            users[UserIndex].tanaman[i] = users[UserIndex].tanaman[i + 1];
                        }
                        users[UserIndex].totalTanaman--;
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
