#include <iostream>
#include <string>
#include <limits> // Untuk menggunakan numeric_limits

using namespace std;

struct Karakter_Arknights {
    struct Karakter_Game {
        string name;
        int rarity;
    };

    Karakter_Game characters[5];
    int count = 0;
};

void BubbleSort(Karakter_Arknights::Karakter_Game *arknights, int jumlah_karakter_arknights) {
    for (int i = 0; i < jumlah_karakter_arknights - 1; ++i) {
        for (int j = 0; j < jumlah_karakter_arknights - i - 1; ++j) {
            if (arknights[j].name > arknights[j + 1].name) {
                swap(arknights[j], arknights[j + 1]);
            }
        }
    }
}

void SelectionSort(Karakter_Arknights::Karakter_Game *arknights, int jumlah_karakter_arknights) {
    for (int i = 0; i < jumlah_karakter_arknights - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < jumlah_karakter_arknights; ++j) {
            if (arknights[j].rarity > arknights[min_idx].rarity) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(arknights[i], arknights[min_idx]);
        }
    }
}

int InterpolationSearch(Karakter_Arknights::Karakter_Game *arknights, int jumlah_karakter_arknights, string key) {
    int low = 0;
    int high = jumlah_karakter_arknights - 1;

    // Array diurutkan berdasarkan nama
    BubbleSort(arknights, jumlah_karakter_arknights);

    while (low <= high && key >= arknights[low].name && key <= arknights[high].name) {
        if (low == high) {
            if (arknights[low].name == key)
                return low;
            return -1;
        }

        int pos = low + (((double)(high - low) / (arknights[high].name.length() - arknights[low].name.length())) * (key.length() - arknights[low].name.length()));

        if (arknights[pos].name == key)
            return pos;
        if (arknights[pos].name < key)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}


int BinarySearch(Karakter_Arknights::Karakter_Game *arknights, int jumlah_karakter_arknights, string key) {
    // Pastikan array diurutkan berdasarkan nama
    BubbleSort(arknights, jumlah_karakter_arknights);

    int low = 0;
    int high = jumlah_karakter_arknights - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arknights[mid].name == key)
            return mid;

        if (arknights[mid].name < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}


void Menampilkan_Karakter_Arknights_Berdasarkan_Rarity(Karakter_Arknights::Karakter_Game *arknights, int jumlah_karakter_arknights, int rarity) {
    if (jumlah_karakter_arknights == 0) {
        cout << "Tidak ada karakter Arknights yang tersedia." << endl;
    } else {
        bool found = false;
        for (int i = 0; i < jumlah_karakter_arknights; ++i) {
            if ((*(arknights + i)).rarity == rarity) {
                cout << "Nama: " << (*(arknights + i)).name << ", Rarity: " << (*(arknights + i)).rarity << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "Tidak ada karakter Arknights dengan rarity " << rarity << "." << endl;
        }
    }
}

void InsertionSort(Karakter_Arknights::Karakter_Game *arknights, int jumlah_karakter_arknights) {
    for (int i = 1; i < jumlah_karakter_arknights; ++i) {
        Karakter_Arknights::Karakter_Game key = arknights[i];
        int j = i - 1;

        while (j >= 0 && arknights[j].rarity > key.rarity) {
            arknights[j + 1] = arknights[j];
            j = j - 1;
        }
        arknights[j + 1] = key;
    }
}


bool Duplikat_Karakter_Arknights(Karakter_Arknights::Karakter_Game *arknights, int jumlah_karakter_arknights, string nama) {
    for (int i = 0; i < jumlah_karakter_arknights; ++i) {
        if ((*(arknights + i)).name == nama) {
            return true;
        }
    }
    return false;
}

void Menampilkan_Karakter_Arknights(Karakter_Arknights::Karakter_Game *arknights, int jumlah_karakter_arknights) {
    int choice;
    cout << "----- Menu Tampilkan Karakter Arknights -----" << endl;
    cout << "1. Menampilkan Pengurutan nama secara ascending menggunakan Bubble Sort" << endl;
    cout << "2. Menampilkan Rarity secara descending menggunakan Selection Sort" << endl;
    cout << "3. Menampilkan Pengurutan Rarity  karakter dari 1-6 secara ascending menggunakan Insertion Sort" << endl;
    cout << "4. Menampilkan Pencarian Nama dengan Interpolation Search Secara Descending" << endl;
    cout << "5.  Menampilkan Pencarian Nama dengan Binary Search Secara Ascending" << endl;
    cout << "Pilih (1/2/3/4/5): ";
    cin >> choice;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (choice == 1) {
        if (jumlah_karakter_arknights == 0) {
            cout << "Tidak ada karakter Arknights yang tersedia." << endl;
        } else {

            cout << "Data sebelum diurutkan:" << endl;
            for (int i = 0; i < jumlah_karakter_arknights; ++i) {
                cout << i + 1 << ". Nama: " << arknights[i].name << ", Rarity: " << arknights[i].rarity << endl;
            }

            // Sorting menggunakan Bubble Sort
            BubbleSort(arknights, jumlah_karakter_arknights);

            
            cout << "Data setelah diurutkan:" << endl;
            for (int i = 0; i < jumlah_karakter_arknights; ++i) {
                cout << i + 1 << ". Nama: " << arknights[i].name << ", Rarity: " << arknights[i].rarity << endl;
            }
        }
    } else if (choice == 2) {
        int rarity;
        cout << "Masukkan rarity karakter yang ingin ditampilkan (1-6): ";
        cin >> rarity;
        if (rarity >= 1 && rarity <= 6) {
            SelectionSort(arknights, jumlah_karakter_arknights);
            Menampilkan_Karakter_Arknights_Berdasarkan_Rarity(arknights, jumlah_karakter_arknights, rarity);
        } else {
            cout << "Rarity tidak valid." << endl;
        }
    } else if (choice == 3) {
        cout << "Data sebelum diurutkan:" << endl;
        for (int i = 0; i < jumlah_karakter_arknights; ++i) {
            cout << i + 1 << ". Nama: " << arknights[i].name << ", Rarity: " << arknights[i].rarity << endl;
        }

        // Sorting menggunakan Insertion Sort
        InsertionSort(arknights, jumlah_karakter_arknights);
        
        
        cout << "Data setelah diurutkan:" << endl;
        for (int i = 0; i < jumlah_karakter_arknights; ++i) {
            cout << i + 1 << ". Nama: " << arknights[i].name << ", Rarity: " << arknights[i].rarity << endl;
        }
    } else if (choice == 4) {
        // Interpolation Search Secara Descending
        string key;
        cout << "Masukkan nama karakter yang ingin dicari: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Sudah membersihkan buffer, sekarang input nama karakter." << endl; 
        getline(cin, key);
        cout << "Input Sekali Lagi nama karakter: " << key << endl;
        int result = InterpolationSearch(arknights, jumlah_karakter_arknights, key);
        if (result != -1) {
            cout << "Karakter ditemukan pada indeks: " << result << endl;
            cout << "Nama: " << arknights[result].name << ", Rarity: " << arknights[result].rarity << endl;
        } else {
            cout << "Karakter tidak ditemukan." << endl;
        }
    } else if (choice == 5) {
        // Binary Search Secara Ascending
        string key;
        cout << "Masukkan nama karakter yang ingin dicari: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Sudah membersihkan buffer, sekarang input nama karakter." << endl; 
        getline(cin, key);
        cout << "Input Sekali Lagi nama karakter: " << key << endl;
        int result = BinarySearch(arknights, jumlah_karakter_arknights, key);
        if (result != -1) {
            cout << "Karakter ditemukan pada indeks: " << result << endl;
            cout << "Nama: " << arknights[result].name << ", Rarity: " << arknights[result].rarity << endl;
        } else {
            cout << "Karakter tidak ditemukan." << endl;
        }
    } else {
        cout << "Pilihan tidak valid. Silakan pilih angka 1 sampai 5 saja." << endl;
    }
}

void Tambah_Karakter_Arknights(Karakter_Arknights::Karakter_Game *arknights, int& jumlah_karakter_arknights) {
    if (jumlah_karakter_arknights < 5) {
            string nama;
            int rarity;
            bool duplikat = false;
            do {
                cout << "Masukkan nama karakter: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                getline(cin, nama); // Menggunakan getline untuk mengambil nama karakter

                duplikat = Duplikat_Karakter_Arknights(arknights, jumlah_karakter_arknights, nama);

                if (duplikat) {
                    cout << "Karakter dengan nama tersebut sudah ada. Silakan masukkan karakter lain." << endl;
                    continue;
                }

                cout << "Masukkan rarity karakter (1-6): ";
                cin >> rarity;

                if (rarity < 1 || rarity > 6) {
                    cout << "Rarity karakter tidak valid. Harap masukkan angka antara 1 hingga 6." << endl;
                    continue;
                }

                arknights[jumlah_karakter_arknights].name = nama;
                arknights[jumlah_karakter_arknights].rarity = rarity;
                jumlah_karakter_arknights++;
                cout << "Karakter Arknights berhasil ditambahkan." << endl;
                break;
            } while (true);
        } else {
            cout << "Batas maksimum karakter Arknights telah tercapai." << endl;
        }
    }
void Ubah_Karakter_Arknights(Karakter_Arknights::Karakter_Game *arknights, int jumlah_karakter_arknights) {
    if (jumlah_karakter_arknights == 0) {
        cout << "Tidak ada karakter Arknights yang tersedia." << endl;
    } else {
        int nomor;
        cout << "Masukkan nomor karakter yang akan diubah: ";
        cin >> nomor;
        if (nomor >= 1 && nomor <= jumlah_karakter_arknights) {
            string nama;
            int rarity;
            cout << "Masukkan nama karakter baru: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            getline(cin, nama);

            bool duplikat = Duplikat_Karakter_Arknights(arknights, jumlah_karakter_arknights, nama);

            if (duplikat) {
                cout << "Karakter dengan nama tersebut sudah ada. Silakan masukkan karakter lain." << endl;
                return;
            }

            cout << "Masukkan rarity karakter baru (1-6): ";
            cin >> rarity;
            if (rarity < 1 || rarity > 6) {
                cout << "Rarity karakter tidak valid. Harap masukkan angka antara 1 hingga 6." << endl;
                return;
            }

            (*(arknights + nomor - 1)).name = nama;
            (*(arknights + nomor - 1)).rarity = rarity;
            cout << "Karakter Arknights berhasil diubah." << endl;
        } else {
            cout << "Nomor karakter tidak valid." << endl;
        }
    }
}


void Hapus_Karakter_Arknights(Karakter_Arknights::Karakter_Game *arknights, int& jumlah_karakter_arknights) {
    if (jumlah_karakter_arknights == 0) {
        cout << "Tidak ada karakter Arknights yang tersedia." << endl;
    } else {
        int nomor;
        cout << "Masukkan nomor karakter yang akan dihapus: ";
        cin >> nomor;
        if (nomor >= 1 && nomor <= jumlah_karakter_arknights) {
            for (int i = nomor - 1; i < jumlah_karakter_arknights - 1; ++i) {
                (*(arknights + i)) = (*(arknights + i + 1));
            }
            jumlah_karakter_arknights--;
            cout << "Karakter Arknights berhasil dihapus." << endl;
        } else {
            cout << "Nomor karakter tidak valid." << endl;
        }
    }
}

void MenuUtama(Karakter_Arknights::Karakter_Game *arknights, int& jumlah_karakter_arknights) {
    int choice;
    do {
        cout << "----- Menu Utama -----" << endl;
        cout << "1. Menampilkan Karakter Arknights" << endl;
        cout << "2. Tambah Karakter Baru" << endl;
        cout << "3. Ubah Karakter" << endl;
        cout << "4. Hapus Karakter" << endl;
        cout << "5. Log Out" << endl;
        cout << "Pilih menu (1/2/3/4/5): ";
        cin >> choice;

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
                Ubah_Karakter_Arknights(arknights,jumlah_karakter_arknights) ;
                break;
            }
            case 4: {
                Hapus_Karakter_Arknights(arknights, jumlah_karakter_arknights );
                break;
            }
            case 5: {
                cout << "Anda telah logout." << endl;
                return;
            }
            default: {
                cout << "Pilihan tidak valid. Silakan pilih angka 1 sampai 5 saja." << endl;
                break;
            }
        }
    } while (true);
}

void Login(int attempts) {
    string nama, nim;

    cout << "Masukkan Nama: ";
    cin >> nama;
    cout << "Masukkan NIM: ";
    cin >> nim;

    if (nama == "Amad" && nim == "91") {
        cout << "Login berhasil" << endl;
        Karakter_Arknights::Karakter_Game arknights[5];
        int jumlah_karakter_arknights = 0;
        MenuUtama(arknights, jumlah_karakter_arknights);
    } else {
        attempts++;
        if (attempts == 2) {
            cout << "Anda sudah gagal login dua kali. Silakan pastikan Anda memasukkan nama dan NIM dengan benar." << endl;
            Login(attempts);
        } else if (attempts == 3) {
            cout << "Anda telah melebihi batas percobaan login. Program berhenti." << endl;
            return;
        } else {
            cout << "Anda gagal login, coba lagi." << endl;
            Login(attempts);
        }
    }
}

int main() {
    Karakter_Arknights::Karakter_Game arknights[5];
    int jumlah_karakter_arknights = 0;
    int attempts = 0;
    Login(attempts);
    return 0;
}
