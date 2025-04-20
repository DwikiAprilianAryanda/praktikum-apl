#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Struct untuk produk
struct Produk {
    string kode;
    string nama;
    string merk;
    string kategori;
    int harga;
};

// Struct untuk user
struct User {
    string nama;
    string nim;
    bool isAdmin;
    Produk daftarProduk[100];
    int jumlahProduk;
};

// Deklarasi array of struct untuk multiuser
User daftarUser[50];
int jumlahUser = 0;

// Prosedur untuk menampilkan header
void tampilHeader(string judul) {
    cout << "\n==================================" << endl;
    cout << "=== " << judul << " ===" << endl;
    cout << "==================================" << endl;
}

// Fungsi overloading untuk mencari index produk dengan pointer
int cariProduk(User* user, string kode) {
    for (int i = 0; i < user->jumlahProduk; i++) {
        if (user->daftarProduk[i].kode == kode) return i;
    }
    return -1;
}

int cariProduk(User* user, string nama, string merk) {
    for (int i = 0; i < user->jumlahProduk; i++) {
        if (user->daftarProduk[i].nama == nama && user->daftarProduk[i].merk == merk) return i;
    }
    return -1;
}

// Prosedur untuk menampilkan data produk dengan pointer
void tampilDataProduk(User* user) {
    if (user->jumlahProduk == 0) {
        cout << "Belum ada data handphone!" << endl;
        return;
    }
    cout << "\n================================ Data Handphone ================================" << endl;
    cout << setw(10) << "Kode" << setw(20) << "Nama" << setw(15) << "Merk" 
         << setw(20) << "Kategori" << setw(15) << "Harga" << endl;
    cout << string(80, '-') << endl;
    for (int i = 0; i < user->jumlahProduk; i++) {
        cout << setw(10) << user->daftarProduk[i].kode
             << setw(20) << user->daftarProduk[i].nama
             << setw(15) << user->daftarProduk[i].merk
             << setw(20) << user->daftarProduk[i].kategori
             << setw(15) << user->daftarProduk[i].harga << endl;
    }
}

// Prosedur untuk tambah data dengan address-of
void tambahData(User& user) {
    User* ptrUser = &user;
    if (ptrUser->jumlahProduk >= 100) {
        cout << "Kapasitas produk penuh!" << endl;
        return;
    }
    int idx = ptrUser->jumlahProduk;
    cout << "Masukkan Kode Produk: ";
    cin >> ptrUser->daftarProduk[idx].kode;
    cout << "Masukkan Nama Produk: ";
    cin.ignore();
    getline(cin, ptrUser->daftarProduk[idx].nama);
    cout << "Masukkan Merk Produk: ";
    getline(cin, ptrUser->daftarProduk[idx].merk);
    cout << "Masukkan Kategori Produk: ";
    getline(cin, ptrUser->daftarProduk[idx].kategori);
    cout << "Masukkan Harga: ";
    cin >> ptrUser->daftarProduk[idx].harga;
    ptrUser->jumlahProduk++;
    cout << "Data berhasil ditambahkan!" << endl;
}

// Prosedur untuk ubah data dengan address-of
void ubahData(User& user) {
    User* ptrUser = &user;
    tampilDataProduk(ptrUser);
    if (ptrUser->jumlahProduk == 0) return;
    
    int pilihan;
    cout << "\nCari produk berdasarkan:" << endl;
    cout << "1. Kode Produk" << endl;
    cout << "2. Nama dan Merk" << endl;
    cout << "Pilih opsi (1-2): ";
    cin >> pilihan;

    int idx = -1;
    if (pilihan == 1) {
        string kode;
        cout << "Masukkan Kode Produk: ";
        cin >> kode;
        idx = cariProduk(ptrUser, kode);
    } else if (pilihan == 2) {
        string nama, merk;
        cout << "Masukkan Nama Produk: ";
        cin.ignore();
        getline(cin, nama);
        cout << "Masukkan Merk Produk: ";
        getline(cin, merk);
        idx = cariProduk(ptrUser, nama, merk);
    } else {
        cout << "Pilihan tidak valid!" << endl;
        return;
    }

    if (idx != -1) {
        cout << "Masukkan Nama Produk baru: ";
        cin.ignore();
        getline(cin, ptrUser->daftarProduk[idx].nama);
        cout << "Masukkan Merk Produk baru: ";
        getline(cin, ptrUser->daftarProduk[idx].merk);
        cout << "Masukkan Kategori Produk baru: ";
        getline(cin, ptrUser->daftarProduk[idx].kategori);
        cout << "Masukkan Harga baru: ";
        cin >> ptrUser->daftarProduk[idx].harga;
        cout << "Data berhasil diubah!" << endl;
    } else {
        cout << "Produk tidak ditemukan!" << endl;
    }
}

// Prosedur untuk hapus data dengan pointer
void hapusData(User* user) {
    tampilDataProduk(user);
    if (user->jumlahProduk == 0) return;
    
    string kode;
    cout << "\nMasukkan Kode Produk yang akan dihapus: ";
    cin >> kode;
    int idx = cariProduk(user, kode);
    if (idx != -1) {
        for (int j = idx; j < user->jumlahProduk - 1; j++) {
            user->daftarProduk[j] = user->daftarProduk[j + 1];
        }
        user->jumlahProduk--;
        cout << "Produk berhasil dihapus!" << endl;
    } else {
        cout << "Kode produk tidak ditemukan!" << endl;
    }
}

// Prosedur untuk beli produk dengan pointer
void beliProduk(User* admin, User* user) {
    tampilDataProduk(admin);
    if (admin->jumlahProduk == 0) return;
    
    string kode;
    cout << "\nMasukkan Kode Produk yang ingin dibeli: ";
    cin >> kode;
    int idx = cariProduk(admin, kode);
    if (idx != -1) {
        for (int j = idx; j < admin->jumlahProduk - 1; j++) {
            admin->daftarProduk[j] = admin->daftarProduk[j + 1];
        }
        admin->jumlahProduk--;
        cout << "Produk berhasil dibeli!" << endl;
    } else {
        cout << "Kode produk tidak ditemukan!" << endl;
    }
}

// Fungsi rekursif untuk login
int login(string nama, string nim, int indeks = 0) {
    if (indeks >= jumlahUser) {
        return -1;
    }
    if (daftarUser[indeks].nama == nama && daftarUser[indeks].nim == nim) {
        return indeks;
    }
    return login(nama, nim, indeks + 1);
}

// Prosedur untuk registrasi
void registrasi() {
    if (jumlahUser >= 50) {
        cout << "Kapasitas user penuh!" << endl;
        return;
    }
    tampilHeader("Registrasi User Baru");
    cout << "Masukkan Nama: ";
    cin.ignore();
    getline(cin, daftarUser[jumlahUser].nama);
    cout << "Masukkan NIM: ";
    cin >> daftarUser[jumlahUser].nim;
    daftarUser[jumlahUser].isAdmin = false;
    daftarUser[jumlahUser].jumlahProduk = 0;
    jumlahUser++;
    cout << "Registrasi berhasil! Silakan login." << endl;
}

int main() {
    if (jumlahUser == 0) {
        daftarUser[0].nama = "lian";
        daftarUser[0].nim = "001";
        daftarUser[0].isAdmin = true;
        daftarUser[0].jumlahProduk = 0;
        jumlahUser = 1;
    }

    while (true) {
        int pilihanAwal;
        tampilHeader("Sistem Manajemen Handphone");
        cout << "|1. Login                       |" << endl;
        cout << "|2. Register sebagai User Baru  |" << endl;
        cout << "|3. Keluar                      |" << endl;
        cout << "==================================" << endl;
        cout << "Pilih opsi (1-3): ";
        cin >> pilihanAwal;

        if (pilihanAwal == 2) {
            registrasi();
            continue;
        } else if (pilihanAwal == 3) {
            cout << "Program selesai!" << endl;
            return 0;
        } else if (pilihanAwal != 1) {
            cout << "Pilihan tidak valid!" << endl;
            continue;
        }

        // Login
        int percobaan = 0;
        int indexUser = -1;
        while (percobaan < 3) {
            tampilHeader("Login Sistem");
            string nama, nim;
            cout << "Masukkan Nama: ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan NIM: ";
            cin >> nim;

            indexUser = login(nama, nim);
            if (indexUser != -1) {
                cout << "Login berhasil!" << endl;
                break;
            } else {
                percobaan++;
                cout << "Login gagal. Sisa percobaan: " << (3 - percobaan) << endl;
            }
        }

        if (percobaan >= 3) {
            cout << "Percobaan login habis!" << endl;
            continue;
        }

        // Menu utama
        while (true) {
            tampilHeader("Manajemen Produk Handphone");
            int pilihan;
            if (daftarUser[indexUser].isAdmin) {
                cout << "|1. Tampilkan Data               |" << endl;
                cout << "|2. Tambah Data                  |" << endl;
                cout << "|3. Ubah Data                    |" << endl;
                cout << "|4. Hapus Data                   |" << endl;
                cout << "|5. Logout                       |" << endl;
                cout << "==================================" << endl;
                cout << "Pilih menu (1-5): ";
                cin >> pilihan;

                switch (pilihan) {
                    case 1: tampilDataProduk(&daftarUser[0]); break;
                    case 2: tambahData(daftarUser[0]); break;
                    case 3: ubahData(daftarUser[0]); break;
                    case 4: hapusData(&daftarUser[0]); break;
                    case 5: cout << "Logout berhasil!" << endl; break;
                    default: cout << "Pilihan tidak valid!" << endl;
                }
                if (pilihan == 5) break;
            } else {
                cout << "|1. Tampilkan Data               |" << endl;
                cout << "|2. Beli Produk                  |" << endl;
                cout << "|3. Logout                       |" << endl;
                cout << "==================================" << endl;
                cout << "Pilih menu (1-3): ";
                cin >> pilihan;

                switch (pilihan) {
                    case 1: tampilDataProduk(&daftarUser[0]); break;
                    case 2: beliProduk(&daftarUser[0], &daftarUser[indexUser]); break;
                    case 3: cout << "Logout berhasil!" << endl; break;
                    default: cout << "Pilihan tidak valid!" << endl;
                }
                if (pilihan == 3) break;
            }
        }
    }
    return 0;
}