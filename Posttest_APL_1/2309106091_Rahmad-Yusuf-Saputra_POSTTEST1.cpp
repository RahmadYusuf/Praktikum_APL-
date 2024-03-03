// Rahmad Yusuf Saputra
// 2309106091
#include <iostream>
#include <string>
using namespace std;

int main() {
    int attempts = 0;
    string nama, nim;

    while (attempts <= 3) {
        cout << "Masukkan Nama: ";
        cin >> nama;
        cout << "Masukkan NIM: ";
        cin >> nim;

        if (nama == "Amad" && nim == "91") {
            cout << "Login berhasil" << endl;
            break;
        } else {
            cout << "Anda login gagal, coba lagi." << endl;
            attempts++;
        }
    }

    if (attempts == 4) {
        cout << "Anda telah melebihi batas percobaan login. Program berhenti." << endl;
    } else {
        int choice;
        char ulangi;
        float suhu;
        system("cls");
        do {
            cout << "Menu Konversi Suhu:" << endl;
            cout << "1. Konversi Celcius" << endl;
            cout << "2. Konversi Reamur" << endl;
            cout << "3. Konversi Fahrenheit" << endl;
            cout << "4. Konversi Kelvin" << endl;
            cout << "Pilih menu (1/2/3/4): ";
            cin >> choice;

            system("cls");

        if (choice >= 1 && choice <= 4) {
                switch (choice) {
                    case 1:
                        cout << "Masukkan suhu dalam Celcius: ";
                        cin >> suhu;
                        {
                            float reamur = suhu * 4 / 5;
                            float fahrenheit = (suhu * 9 / 5) + 32;
                            float kelvin = suhu + 273.15;

                            cout << "Hasil konversi:" << endl;
                            cout << suhu << " Celcius = " << reamur << " Reamur" << endl;
                            cout << suhu << " Celcius = " << fahrenheit << " Fahrenheit" << endl;
                            cout << suhu << " Celcius = " << kelvin << " Kelvin" << endl;
                        }
                        break;
                    case 2:
                        cout << "Masukkan suhu dalam Reamur: ";
                        cin >> suhu;
                        {
                            float celsius = suhu * 5 / 4;
                            float fahrenheit = (suhu * 9 / 4) + 32;
                            float kelvin = (suhu * 5 / 4) + 273.15;

                            cout << "Hasil konversi:" << endl;
                            cout << suhu << " Reamur = " << celsius << " Celcius" << endl;
                            cout << suhu << " Reamur = " << fahrenheit << " Fahrenheit" << endl;
                            cout << suhu << " Reamur = " << kelvin << " Kelvin" << endl;
                        }
                        break;
                    case 3:
                        cout << "Masukkan suhu dalam Fahrenheit: ";
                        cin >> suhu;
                        {
                            float celsius = (suhu - 32) * 5 / 9;
                            float reamur = ((suhu - 32) * 4 / 9);
                            float kelvin = ((suhu - 32) * 5 / 9) + 273.15;

                            cout << "Hasil konversi:" << endl;
                            cout << suhu << " Fahrenheit = " << celsius << " Celcius" << endl;
                            cout << suhu << " Fahrenheit = " << reamur << " Reamur" << endl;
                            cout << suhu << " Fahrenheit = " << kelvin << " Kelvin" << endl;
                        }
                        break;
                    case 4:
                        cout << "Masukkan suhu dalam Kelvin: ";
                        cin >> suhu;
                        {
                            float celsius = suhu - 273.15;
                            float reamur = ((suhu - 273.15) * 4 / 5);
                            float fahrenheit = ((suhu - 273.15) * 9 / 5) + 32;

                            cout << "Hasil konversi:" << endl;
                            cout << suhu << " Kelvin = " << celsius << " Celcius" << endl;
                            cout << suhu << " Kelvin = " << reamur << " Reamur" << endl;
                            cout << suhu << " Kelvin = " << fahrenheit << " Fahrenheit" << endl;
                        }
                        break;
                    default:
                        cout << "Pilihan tidak valid." << endl;
                }
            } else {
                cout << "Pilihan tidak valid. Silakan pilih angka 1 sampai 4 aja." << endl;
                ulangi = 'y'; 
            }

            cout << "Apakah Anda ingin melakukan konversi lagi? (y/n): ";
            cin >> ulangi;
        } while (ulangi == 'y' || ulangi == 'Y');
        
        cout << "Program selesai." << endl;
    }

    return 0;
}