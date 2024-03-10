#include <iostream>
#include <string>

using namespace std;

struct Karakter_Arknights {
    string name;
    string rarity;
};

void Menampilkan_Karakter_Arkightss(Karakter_Arknights arknights[], int jumlah_karakter_arknights) {
    if (jumlah_karakter_arknights == 0) {
        cout << "Tidak ada karakter Arknights yang tersedia." << endl;
    } else {
        for (int i = 0; i < jumlah_karakter_arknights; ++i) {
            cout << i + 1 << ". Nama: " << arknights[i].name << ", Rarity: " << arknights[i].rarity << endl;
        }
    }
}

int main() {
    Karakter_Arknights arknights[5]; 
    int jumlah_karakter_arknights = 0;
    int attempts = 0;
    string nama, nim;

    while (attempts < 3) {
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

    if (attempts == 3) {
        cout << "Anda telah melebihi batas percobaan login. Program berhenti." << endl;
        return 0; 
    }

    int choice;
    do {
        cout << "----- Menu Utama-----" << endl;
        cout << "1. Menampilakan Karakter Arknights" << endl;
        cout << "2. Tambah Karakter Baru" << endl;
        cout << "3. Ubah Karakter" << endl;
        cout << "4. Hapus Karakter" << endl;
        cout << "5. Log Out" << endl;
        cout << "Pilih menu (1/2/3/4/5): ";
        cin >> choice;

        if (choice >= 1 && choice <= 5) {
            switch (choice) {
                case 1: {
                    Menampilkan_Karakter_Arkightss(arknights, jumlah_karakter_arknights);
                    break;
                }
                case 2: {
                    if (jumlah_karakter_arknights < 5) {
                        cout << "Masukkan nama karakter: ";
                        cin >> arknights[jumlah_karakter_arknights].name;
                        cout << "Masukkan rarity karakter (1-6): ";
                        cin >> arknights[jumlah_karakter_arknights].rarity;
                        if (arknights[jumlah_karakter_arknights].rarity < "1" || arknights[jumlah_karakter_arknights].rarity > "6") {
                            cout << "rarity karakter tidak valid. Harap masukkan angka antara 1 hingga 6." << endl;
                            break;
                        }
                        jumlah_karakter_arknights++;
                        cout << "Karakter Arknights berhasil ditambahkan." << endl;
                    } else {
                        cout << "Batas maksimum karakter Arknights telah tercapai." << endl;
                    }
                    break;
                }
                case 3: {
                    if (jumlah_karakter_arknights == 0) {
                        cout << "Tidak ada karakter Arknights yang tersedia." << endl;
                    } else {
                        int nomor;
                        cout << "Masukkan nomor karakter yang akan diubah: ";
                        cin >> nomor;
                        if (nomor >= 1 && nomor <= jumlah_karakter_arknights) {
                            cout << "Masukkan nama karakter baru: ";
                            cin >> arknights[nomor - 1].name;
                            cout << "Masukkan rarity karakter baru (1-6): ";
                            cin >> arknights[nomor - 1].rarity;
                            if (arknights[nomor - 1].rarity < "1" || arknights[nomor - 1].rarity > "6") {
                                cout << "rarity karakter tidak valid. Harap masukkan angka antara 1 hingga 6." << endl;
                                break;
                            }
                            cout << "Karakter Arknights berhasil diubah." << endl;
                        } else {
                            cout << "Nomor karakter tidak valid." << endl;
                        }
                    }
                    break;
                }
                case 4: {
                    if (jumlah_karakter_arknights == 0) {
                        cout << "Tidak ada karakter Arknights yang tersedia." << endl;
                    } else {
                        int nomor;
                        cout << "Masukkan nomor karakter yang akan dihapus: ";
                        cin >> nomor;
                        if (nomor >= 1 && nomor <= jumlah_karakter_arknights) {
                            for (int i = nomor - 1; i < jumlah_karakter_arknights - 1; ++i) {
                                arknights[i] = arknights[i + 1];
                            }
                            jumlah_karakter_arknights--;
                            cout << "Karakter Arknights berhasil dihapus." << endl;
                        } else {
                            cout << "Nomor karakter tidak valid." << endl;
                        }
                    }
                    break;
                }
            }
        } else {
            cout << "Pilihan tidak valid. Silakan pilih angka 1 sampai 5 saja." << endl;
        }
    } while (choice != 5);

    cout << "Anda telah logout." << endl;

    return 0;
}

