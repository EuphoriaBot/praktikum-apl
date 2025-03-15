#include <iostream>
using namespace std;

int main()
{
    string nama[5] = {"Dimas", "Harahap", "Santoso", "BangKalingga", "ucup"};

    // int angka[3];
    // angka[0] = 1;
    // angka[1] = 2;
    // angka[2] = 3;

    // cout << "Nama\t: " << nama[1] << endl;
    // cout << "Angka\t: " << angka[2] << endl;

    // angka[1] = 6;

    // cout << angka << endl;

    // int panjang1 = sizeof(angka) / sizeof(angka[0])

    // cout << "Array: " angka << endl:

    // for(int i = 0; i < panjang1; i++) {
    //     cout << &angka[1] << endl;
    // }
    // int panjang2 = sizeof(angka) / sizeof(int)

    // //cout << sizeof(angka);

    // cout << "Panjang1\t: " << panjang1 << endl;
    // cout << "Panjang2\t: " << panjang2 << endl;

    // cout << sizeof(int) << endl;
    // cout << sizeof(double) << endl;
    // cout << sizeof(bool) << endl;
    // cout << sizeof(string) << endl;

    // for (int i = 0; i < panjang1; I++) {
    //     cout << angka[i] << endl;
    // }

    // for(int item: angka) {
    //     cout << item << endl;
    // }

    // int angka[5] = {1, 2, 3, 4, 5};

    // int angka[3][2] = {
    //     {1,2},
    //     {3,4},
    //     {5,6},
    // };

    // cout << angka[2][0] << endl;

    int angka[2][3][2] = {
        {{1, 2}, {3, 4}, {5, 6}},
        {{7, 8}, {9, 10}, {11, 12}}};

    cout << angka[1][1][1];

    return 0;
}