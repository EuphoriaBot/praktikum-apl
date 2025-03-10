#include <iostream>
using namespace std;

int main()
{
    string nama;
    cout << "Masukkan nama: ";
    // cin >> nama;
    getline(cin, nama);
    cout << "Nama saya adalah " << nama;

    int umur = 20;
    int sumbuY = -45;
    float berat_badan = 50.5;
    double tinggi_badan = 170.5;
    char jenis_kelamin = 'L';
    bool is_menikah = false;

    cout << "Umur saya adalah " << umur;
    cout << "Tinggi badan saya adalah " << tinggi_badan;
    cout << "Jenis kelamin saya adalah " << jenis_kelamin;

    int angka[5] = {1, 2, 3, 4, 5};
    string Name = "Raana";
    cout << Name[1];

    string firstName;
    string last_name;
    string FullName;

    // tipeData namaVariabel; null
    string nama = "Daffa";
    firstName = "Daffa";
    last_name = "Dimas";

    bool sudahMenikah = true;
    string status = sudahMenikah ? "Sudah menikah" : "Belum menikah";
    cout << status << endl;

    bool malas = true;
    if (malas)
    {
        cout << "Saya scroll fesbuk";
    }
    else if (false) // Perbaikan else if yang tidak memiliki kondisi
    {
        cout << "Saya makan";
    }
    else
    {
        cout << "Saya Belajar";
    }

    int nilaiUjian = 100;
    switch (nilaiUjian)
    {
    case 100:
        cout << "Nilai sempurna";
        break;
    case 90:
        cout << "Nilai sangat baik";
        break;
    default:
        cout << "Nilai tidak valid";
    }

    for (int i = 0; i < 5; i++)
    {
        cout << i << endl;
    }

    int i = 0;
    while (i < 5)
    {
        cout << i << endl;
        i++;
    }

    i = 0; // Perbaikan: mendeklarasikan ulang variabel i tanpa tipe data
    do
    {
        cout << i << endl;
        i++;
    } while (i < 5);

    return 0;
}
