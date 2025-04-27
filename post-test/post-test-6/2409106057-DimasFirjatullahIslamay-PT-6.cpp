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

void DaftarAkun(User users[], int &TotalAkun)
{
    if (TotalAkun >= 100)
    {
        cout << "Akun Sudah Mencapai Max" << endl;
        return;
    }

    cout << "Masukkan Nama: ";
    cin >> users[TotalAkun].nama;
    cout << "Masukkan NIM: ";
    cin >> users[TotalAkun].nim;
    TotalAkun++;
    cout << "Akun Berhasil Didaftarkan" << endl;
}

int Login(User *users, int TotalAkun)
{
    string Nama, NIM;
    int Coba = 0;
    while (Coba < 3)
    {
        cout << "=== Login ===" << endl;
        cout << "Masukkan Nama: ";
        cin >> Nama;
        cout << "Masukkan NIM: ";
        cin >> NIM;
        for (int i = 0; i < TotalAkun; i++)
        {
            if (users[i].nama == Nama && users[i].nim == NIM)
            {
                cout << "Login Berhasil" << endl;
                return i;
            }
        }
        cout << "Nama Atau NIM Salah" << endl;
        Coba++;
    }
    cout << "Anda Salah Memasukkan Nama Atau NIM 3 Kali" << endl;
    return -1;
}

void TambahTanaman(User *user)
{
    int index = user->totalTanaman;
    cout << "Masukkan Nama Tanaman: ";
    cin >> user->tanaman[index].nama;
    cout << "Masukkan Jenis Tanaman: ";
    cin >> user->tanaman[index].jenis;
    cout << "Masukkan Jumlah Tanaman: ";
    cin >> user->tanaman[index].jumlah;
    cout << "Masukkan Frekuensi Penyiraman Per Minggu: ";
    cin >> user->tanaman[index].siram;
    cout << "Masukkan Frekuensi Pemupukan Per Bulan: ";
    cin >> user->tanaman[index].pupuk;
    cout << "Masukkan Suhu Tanaman (Celcius): ";
    cin >> user->tanaman[index].suhu;
    user->totalTanaman++;
    cout << "Tanaman Berhasil Ditambahkan" << endl;
}

void LihatTanaman(const User *user)
{
    if (user->totalTanaman == 0)
    {
        cout << "Belum Ada Tanaman" << endl;
        return;
    }

    cout << "=== DAFTAR TANAMAN ===" << endl;
    for (int i = 0; i < user->totalTanaman; i++)
    {
        cout << i + 1 << ". " << user->tanaman[i].nama << " | "
             << user->tanaman[i].jenis << " | "
             << user->tanaman[i].jumlah << " Tanaman | "
             << user->tanaman[i].siram << " Kali Siram/Minggu | "
             << user->tanaman[i].pupuk << " Kali Pupuk/Bulan | "
             << user->tanaman[i].suhu << " Derajat Celcius" << endl;
    }
}

void LihatTanaman(const User *user, string jenisFilter)
{
    bool ditemukan = false;
    cout << "=== Tanaman Dengan Jenis " << jenisFilter << " ===" << endl;
    for (int i = 0; i < user->totalTanaman; i++)
    {
        if (user->tanaman[i].jenis == jenisFilter)
        {
            cout << i + 1 << ". " << user->tanaman[i].nama << " | "
                 << user->tanaman[i].jenis << " | "
                 << user->tanaman[i].jumlah << " Tanaman | "
                 << user->tanaman[i].siram << " Kali Siram/Minggu | "
                 << user->tanaman[i].pupuk << " Kali Pupuk/Bulan | "
                 << user->tanaman[i].suhu << " Derajat Celcius" << endl;
            ditemukan = true;
        }
    }
    if (!ditemukan)
    {
        cout << "Tanaman Tidak Ditemukan" << endl;
    }
}

void UpdateTanaman(User *user)
{
    int index;
    cout << "Masukkan Nomor Tanaman Yang Ingin Diupdate: ";
    cin >> index;
    if (index > 0 && index <= user->totalTanaman)
    {
        index--;
        cout << "Masukkan Nama Tanaman Baru: ";
        cin >> user->tanaman[index].nama;
        cout << "Masukkan Jenis Tanaman Baru: ";
        cin >> user->tanaman[index].jenis;
        cout << "Masukkan Jumlah Tanaman Baru: ";
        cin >> user->tanaman[index].jumlah;
        cout << "Masukkan Frekuensi Penyiraman Per Minggu Baru: ";
        cin >> user->tanaman[index].siram;
        cout << "Masukkan Frekuensi Pemupukan Per Bulan Baru: ";
        cin >> user->tanaman[index].pupuk;
        cout << "Masukkan Suhu Tanaman Baru (Celcius): ";
        cin >> user->tanaman[index].suhu;
        cout << "Tanaman Berhasil Diperbarui" << endl;
    }
    else
    {
        cout << "Nomor Tidak Valid" << endl;
    }
}

void HapusTanaman(User *user)
{
    int index;
    cout << "Masukkan Nomor Tanaman Yang Ingin Dihapus: ";
    cin >> index;
    if (index > 0 && index <= user->totalTanaman)
    {
        for (int i = index - 1; i < user->totalTanaman - 1; i++)
        {
            user->tanaman[i] = user->tanaman[i + 1];
        }
        user->totalTanaman--;
        cout << "Tanaman Berhasil Dihapus" << endl;
    }
    else
    {
        cout << "Nomor Tidak Valid" << endl;
    }
}

void BubbleSort(Tanaman tanaman[], int totalTanaman)
{
    for (int i = 0; i < totalTanaman - 1; i++)
    {
        for (int j = 0; j < totalTanaman - i - 1; j++)
        {
            if (tanaman[j].nama > tanaman[j + 1].nama)
            {
                Tanaman temp = tanaman[j];
                tanaman[j] = tanaman[j + 1];
                tanaman[j + 1] = temp;
            }
        }
    }
}

void InsertionSort(Tanaman tanaman[], int totalTanaman)
{
    for (int i = 1; i < totalTanaman; i++)
    {
        Tanaman key = tanaman[i];
        int j = i - 1;
        while (j >= 0 && tanaman[j].siram < key.siram)
        {
            tanaman[j + 1] = tanaman[j];
            j = j - 1;
        }
        tanaman[j + 1] = key;
    }
}

void SelectionSort(Tanaman tanaman[], int totalTanaman)
{
    for (int i = 0; i < totalTanaman - 1; i++)
    {
        int max = i;
        for (int j = i + 1; j < totalTanaman; j++)
        {
            if (tanaman[j].pupuk > tanaman[max].pupuk)
            {
                max = j;
            }
        }
        Tanaman temp = tanaman[i];
        tanaman[i] = tanaman[max];
        tanaman[max] = temp;
    }
}

void SortingTanaman(User *user, int pilihan)
{
    if (user->totalTanaman == 0)
    {
        cout << "Belum Ada Data Tanaman" << endl;
        return;
    }

    switch (pilihan)
    {
    case 1:
        BubbleSort(user->tanaman, user->totalTanaman);
        cout << "Tanaman Berhasil Di Sorting Berdasarkan Nama" << endl;
        break;
    case 2:
        InsertionSort(user->tanaman, user->totalTanaman);
        cout << "Tanaman Berhasil Di Sorting Berdasarkan Frekuensi Penyiraman" << endl;
        break;
    case 3:
        SelectionSort(user->tanaman, user->totalTanaman);
        cout << "Tanaman Berhasil Di Sorting Berdasarkan Frekuensi Pemupukan" << endl;
        break;
    default:
        cout << "Pilihan Tidak Valid" << endl;
        return;
    }

    cout << "=== Daftar Tanaman ===" << endl;
    for (int i = 0; i < user->totalTanaman; i++)
    {
        cout << i + 1 << ". " << user->tanaman[i].nama << " | "
             << user->tanaman[i].jenis << " | "
             << user->tanaman[i].jumlah << " Tanaman | "
             << user->tanaman[i].siram << " Kali Siram/Minggu | "
             << user->tanaman[i].pupuk << " Kali Pupuk/Bulan | "
             << user->tanaman[i].suhu << " Derajat Celcius" << endl;
    }
}

void MenuTanaman(User *user)
{
    while (true)
    {
        int pilihan;
        cout << "=== MENU TANAMAN HIAS ===" << endl;
        cout << "1. Tambah Tanaman" << endl;
        cout << "2. Lihat Tanaman" << endl;
        cout << "3. Update Tanaman" << endl;
        cout << "4. Hapus Tanaman" << endl;
        cout << "5. Cari Tanaman Berdasarkan Jenis" << endl;
        cout << "6. Sorting Tanaman" << endl;
        cout << "7. Logout" << endl;
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            TambahTanaman(user);
            break;
        case 2:
            LihatTanaman(user);
            break;
        case 3:
            UpdateTanaman(user);
            break;
        case 4:
            HapusTanaman(user);
            break;
        case 5:
        {
            string jenis;
            cout << "Masukkan Jenis Tanaman yang Ingin Dicari: ";
            cin >> jenis;
            LihatTanaman(user, jenis);
            break;
        }
        case 6:
        {
            int sortingPilihan;
            cout << "1. Sorting Berdasarkan Nama" << endl;
            cout << "2. Sorting Berdasarkan Frekuensi Penyiraman" << endl;
            cout << "3. Sorting Berdasarkan Frekuensi Pemupukan" << endl;
            cout << "Pilih: ";
            cin >> sortingPilihan;
            SortingTanaman(user, sortingPilihan);
            break;
        }
        case 7:
            cout << "Logout Berhasil" << endl;
            return;
        default:
            cout << "Pilihan Tidak Valid" << endl;
        }
    }
}

int main()
{
    while (true)
    {
        int Pilihan;
        cout << "==== MENU UTAMA ====" << endl;
        cout << "1. Daftar Akun" << endl;
        cout << "2. Login" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih: ";
        cin >> Pilihan;

        if (Pilihan == 1)
        {
            DaftarAkun(users, TotalAkun);
        }
        else if (Pilihan == 2)
        {
            int index = Login(users, TotalAkun);
            if (index != -1)
            {
                MenuTanaman(&users[index]);
            }
            else
            {
                return 0;
            }
        }
        else if (Pilihan == 3)
        {
            cout << "Terimakasih Telah Menggunakan Program Ini" << endl;
            break;
        }
        else
        {
            cout << "Pilihan Tidak Valid" << endl;
        }
    }

    return 0;
}
