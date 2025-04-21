#include <iostream>
using namespace std;

int main()
{
    // struct Address{
    //     string kota;
    //     string provinsi;
    //     string negara;
    //     };
    //     // deklarasi variabel dengan struct
    //     Address address1, address2;
    //     // mengisi value address1
    //         address1.kota = "Samarinda";
    //         address1.provinsi = "Kalimantan Timur";
    //         address1.negara = "Indonesia";
    //         // mengcopy value address1 ke address2
    //         address2 = address1;
    //         // mengganti property kota dari samarinda ke ikn
    //         address2.kota = "ikn";
    //         // value address1
    //         cout<< address1.kota <<endl;
    //         // value address2
    //         cout<< address2.kota <<endl;

    // // mengcopy value address1 ke address2
    // Address *address2 = &address1;
    // // mengganti property kota dari samarinda ke ikn
    // address2->kota = "ikn";
    // // value address1
    // cout << address1.kota << endl;
    // // value address2
    // cout << address2->kota

    // cout << "pointer yang menunjuk ke suatu array"<< endl;
    // int a[5] = {1,2,3,4,5};
    // int (*aPtr)[5] = &a;
    // for (int i =0; i <5; i++){
    // cout << *aPtr <<endl;
    // }
    // cout << "Pointer yang menunjuk ";
    // cout << "ke arah elemen array"<<endl;
    // int b[5] = {1,2,3,4,5,};
    // int *bPtr = b;
    // for (int i = 0; i < 5; i++){
    // cout << bPtr <<endl;
    // // cout << *bPtr <<endl;
    // bPtr++;
    // }

    // int ubahNilai(int a, int b){
    //     return a = b;
    //     }
    //     int a,b;
    //     a = 5;
    //     b = 20;
    //     ubahNilai(a, b);
    //     cout << a << endl;

    // int ubahNilai(int &a, int b){
    //     return a = b;
    //     }
    //     int a,b;
    //     a = 5;
    //     b = 20;
    //     ubahNilai(a, b);
    //     cout << a << endl;

    // int ubahNilai(int *a, int b){
    //     return *a = b;
    //     }
    //     int a,b;
    //     a = 5;
    //     b = 20;
    //     ubahNilai(&a, b);
    //     cout << a << endl;

    // struct Menu {
    //     string nama;
    //     float harga;
    //     };
    //     Menu nasgor;
    //     Menu *nasgorPtr = &nasgor;
    //     nasgor.nama = "Nasi Goreng Cumi Hitam Pak Kris";
    //     nasgor.harga = 15000;
    //     cout << nasgor.nama << " " << nasgor.harga << endl;
    //     // kita bisa mengakses/manipulasi value variabel nasgor melalui variabel nasgorPtr
    //     nasgorPtr->nama = "Nasi Goreng Mawut";
    //     nasgorPtr->harga = 13000;
    //     cout << nasgor.nama << " " << nasgor.harga << endl;
    //     // kalau memberi value pada atribut biasa pakai ( . )
    //     // kalau memberi value pada atribut dari pointer pakai ( -> )

    return 0;
}
