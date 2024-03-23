#include <iostream>
#include <string>

using namespace std;

struct Karakter_Arknights {
    struct Karakter_Game {
        string name;
        string rarity;
    };

    Karakter_Game characters[5];
    int count = 0;
};

int Jumlah_Rarity_Karakter_Arknights(Karakter_Arknights::Karakter_Game arknights[], int jumlah_karakter_arknights, string rarity_cari) {
    int jumlah_rarity = 0;
    for (int i = 0; i < jumlah_karakter_arknights; ++i) {
        if (arknights[i].rarity == rarity_cari) {
            jumlah_rarity++;
        }
    }
    return jumlah_rarity;
}

bool Duplikat_Karakter_Arknights(Karakter_Arknights::Karakter_Game arknights[], int jumlah_karakter_arknights, string nama) {
    for (int i = 0; i < jumlah_karakter_arknights; ++i) {
        if (arknights[i].name == nama) {
            return true;
        }
    }
    return false;
}

void Menampilkan_Karakter_Arknights_Berdasarkan_Rarity(Karakter_Arknights::Karakter_Game arknights[], int jumlah_karakter_arknights, string rarity) {
    if (jumlah_karakter_arknights == 0) {
        cout << "Tidak ada karakter Arknights yang tersedia." << endl;
    } else {
        bool found = false;
        for (int i = 0; i < jumlah_karakter_arknights; ++i) {
            if (arknights[i].rarity == rarity) {
                cout << "Nama: " << arknights[i].name << ", Rarity: " << arknights[i].rarity << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "Tidak ada karakter Arknights dengan rarity " << rarity << "." << endl;
        }
    }
}

void Menampilkan_Karakter_Arknights(Karakter_Arknights::Karakter_Game arknights[], int jumlah_karakter_arknights) {
    int choice;
    cout << "----- Menu Tampilkan Karakter Arknights -----" << endl;
    cout << "1. Menampilkan Semua Karakter Arknights" << endl;
    cout << "2. Menampilkan Karakter Rarity Arknights" << endl;
    cout << "3. Menampilkan Jumlah Rarity Karakter Arknights"<< endl;
    cout << "Pilih (1/2/3): ";
    cin >> choice;

    if (choice == 1) {
        if (jumlah_karakter_arknights == 0) {
            cout << "Tidak ada karakter Arknights yang tersedia." << endl;
        } else {
            for (int i = 0; i < jumlah_karakter_arknights; ++i) {
                cout << i + 1 << ". Nama: " << arknights[i].name << ", Rarity: " << arknights[i].rarity << endl;
            }
        }
    } else if (choice == 2) {
        string rarity;
        cout << "Masukkan rarity karakter yang ingin ditampilkan (1-6): ";
        cin >> rarity;
        if (rarity >= "1" && rarity <= "6") {
            Menampilkan_Karakter_Arknights_Berdasarkan_Rarity(arknights, jumlah_karakter_arknights, rarity);
        } else {
            cout << "Rarity tidak valid." << endl;
        }
    } else if (choice == 3) {
        string rarity_cari;
        cout << "Masukkan rarity yang ingin dicari: ";
        cin >> rarity_cari;

        int jumlah_ditemukan = Jumlah_Rarity_Karakter_Arknights(arknights, jumlah_karakter_arknights, rarity_cari);
        cout << "Jumlah karakter dengan rarity " << rarity_cari << " adalah: " << jumlah_ditemukan << endl;
    } else {
        cout << "Pilihan tidak valid. Silakan pilih angka 1, 2, atau 3." << endl;
    }
}


void Tambah_Karakter_Arknights(Karakter_Arknights::Karakter_Game arknights[], int& jumlah_karakter_arknights) {
    if (jumlah_karakter_arknights < 5) {
        string nama, rarity;
        bool duplikat = false;
        do {
            cout << "Masukkan nama karakter: ";
            cin >> nama;

            duplikat = Duplikat_Karakter_Arknights(arknights, jumlah_karakter_arknights, nama);

            if (duplikat) {
                cout << "Karakter dengan nama tersebut sudah ada. Silakan masukkan karakter lain." << endl;
                continue;
            }

            cout << "Masukkan rarity karakter (1-6): ";
            cin >> rarity;

            if (rarity < "1" || rarity > "6") {
                cout << "Rarity karakter tidak valid. Harap masukkan angka antara 1 hingga 6." << endl;
                continue;
            }
            break;
        } while (true);

        arknights[jumlah_karakter_arknights].name = nama;
        arknights[jumlah_karakter_arknights].rarity = rarity;
        jumlah_karakter_arknights++;
        cout << "Karakter Arknights berhasil ditambahkan." << endl;
    } else {
        cout << "Batas maksimum karakter Arknights telah tercapai." << endl;
    }
}

void Ubah_Karakter_Arknights(Karakter_Arknights::Karakter_Game arknights[], int jumlah_karakter_arknights) {
    if (jumlah_karakter_arknights == 0) {
        cout << "Tidak ada karakter Arknights yang tersedia." << endl;
    } else {
        int nomor;
        cout << "Masukkan nomor karakter yang akan diubah: ";
        cin >> nomor;
        if (nomor >= 1 && nomor <= jumlah_karakter_arknights) {
            string nama, rarity;
            cout << "Masukkan nama karakter baru: ";
            cin >> nama;
            
            bool duplikat = Duplikat_Karakter_Arknights(arknights, jumlah_karakter_arknights, nama);

            if (duplikat) {
                cout << "Karakter dengan nama tersebut sudah ada. Silakan masukkan karakter lain." << endl;
                return;
            }
            
            cout << "Masukkan rarity karakter baru (1-6): ";
            cin >> rarity;
            if (rarity < "1" || rarity > "6") {
                cout << "Rarity karakter tidak valid. Harap masukkan angka antara 1 hingga 6." << endl;
                return;
            }

            arknights[nomor - 1].name = nama;
            arknights[nomor - 1].rarity = rarity;
            cout << "Karakter Arknights berhasil diubah." << endl;
        } else {
            cout << "Nomor karakter tidak valid." << endl;
        }
    }
}

void Hapus_Karakter_Arknights(Karakter_Arknights::Karakter_Game arknights[], int& jumlah_karakter_arknights) {
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
}

void MenuUtama(Karakter_Arknights::Karakter_Game arknights[], int& jumlah_karakter_arknights) {
    int choice;
    cout << "----- Menu Utama -----" << endl;
    cout << "1. Menampilkan Karakter Arknights" << endl;
    cout << "2. Tambah Karakter Baru" << endl;
    cout << "3. Ubah Karakter" << endl;
    cout << "4. Hapus Karakter" << endl;
    cout << "5. Log Out" << endl;
    cout << "Pilih menu (1/2/3/4/5): ";
    cin >> choice;

    if (choice >= 1 && choice <= 5) {
        switch (choice) {
            case 1: {
                Menampilkan_Karakter_Arknights(arknights, jumlah_karakter_arknights);
                break;
            }
            case 2: {
                Tambah_Karakter_Arknights(arknights, jumlah_karakter_arknights);
                break;
            }
            case 3: {
                Ubah_Karakter_Arknights(arknights, jumlah_karakter_arknights);
                break;
            }
            case 4: {
                Hapus_Karakter_Arknights(arknights, jumlah_karakter_arknights);
                break;
            }
            case 5: {
                cout << "Anda telah logout." << endl;
                return;
            }
        }
    } else {
        cout << "Pilihan tidak valid. Silakan pilih angka 1 sampai 5 saja." << endl;
    }

    MenuUtama(arknights, jumlah_karakter_arknights); 
}

int main() {
    Karakter_Arknights::Karakter_Game arknights[5];
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
            MenuUtama(arknights, jumlah_karakter_arknights); 
            break;
        } else {
            attempts++;
            if (attempts == 2) {
                cout << "Anda sudah gagal login dua kali. Silakan pastikan Anda memasukkan nama dan NIM dengan benar." << endl;
            } else if (attempts == 3) {
                cout << "Anda telah melebihi batas percobaan login. Program berhenti." << endl;
                return 0;
            } else {
                cout << "Anda gagal login, coba lagi." << endl;
            }
        }
    }
    return 0;
}