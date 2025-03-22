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

int main() {
    // Inisialisasi admin default
    if (jumlahUser == 0) {
        daftarUser[0].nama = "lian";
        daftarUser[0].nim = "001";
        daftarUser[0].isAdmin = true;
        daftarUser[0].jumlahProduk = 0;
        jumlahUser = 1;
    }

    while (true) { // Loop utama program
        string nama, nim;
        int percobaan = 0;
        int indexUser = -1;
        int pilihanAwal;

        // Menu Awal
        cout << "\n==================================" << endl;
        cout << "=== Sistem Manajemen Handphone ===" << endl;
        cout << "==================================" << endl;
        cout << "|1. Login                       |" << endl;
        cout << "|2. Register sebagai User Baru  |" << endl;
        cout << "|3. Keluar                      |" << endl;
        cout << "==================================" << endl;
        cout << "Pilih opsi (1-3): ";
        cin >> pilihanAwal;

        if (pilihanAwal == 2) { // Register User Baru
            if (jumlahUser >= 50) {
                cout << "Kapasitas user penuh!" << endl;
            } else {
                cout << "\n=== Registrasi User Baru ===" << endl;
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
            continue;
        } else if (pilihanAwal == 3) { // Keluar
            cout << "Program selesai!" << endl;
            return 0;
        } else if (pilihanAwal != 1) {
            cout << "Pilihan tidak valid!" << endl;
            continue;
        }

        // Login
        while (percobaan < 3) {
            cout << "\n=== Login Sistem ===" << endl;
            cout << "Masukkan Nama: ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan NIM: ";
            cin >> nim;

            // Verifikasi login
            bool loginBerhasil = false;
            for (int i = 0; i < jumlahUser; i++) {
                if (daftarUser[i].nama == nama && daftarUser[i].nim == nim) {
                    indexUser = i;
                    loginBerhasil = true;
                    break;
                }
            }

            if (loginBerhasil) {
                cout << "Login berhasil!" << endl;
                break;
            } else {
                percobaan++;
                if (jumlahUser == 0) {
                    cout << "Belum ada user terdaftar. Silakan register terlebih dahulu." << endl;
                    break;
                } else {
                    cout << "Login gagal. Sisa percobaan: " << (3 - percobaan) << endl;
                }
            }
        }

        if (percobaan >= 3) {
            cout << "Percobaan login habis!" << endl;
            continue;
        } else if (indexUser == -1) {
            continue;
        }

        // Menu utama
        while (true) {
            cout << "\n==================================" << endl;
            cout << "=== Manajemen Produk Handphone ===" << endl;
            cout << "==================================" << endl;
            if (daftarUser[indexUser].isAdmin) {
                cout << "|1. Tampilkan Data               |" << endl;
                cout << "|2. Tambah Data                  |" << endl;
                cout << "|3. Ubah Data                    |" << endl;
                cout << "|4. Hapus Data                   |" << endl;
                cout << "|5. Logout                       |" << endl;
                cout << "==================================" << endl;
                cout << "Pilih menu (1-5): ";
            } else {
                cout << "|1. Tampilkan Data               |" << endl;
                cout << "|2. Beli Produk                  |" << endl;
                cout << "|3. Logout                       |" << endl;
                cout << "==================================" << endl;
                cout << "Pilih menu (1-3): ";
            }
            
            int pilihan;
            cin >> pilihan;

            if (daftarUser[indexUser].isAdmin) {
                switch (pilihan) {
                    case 1: // Tampilkan Data
                        if (daftarUser[0].jumlahProduk == 0) {
                            cout << "Belum ada data handphone!" << endl;
                        } else {
                            cout << "\n================================ Data Handphone ================================" << endl;
                            cout << setw(10) << "Kode" << setw(20) << "Nama" << setw(15) << "Merk" 
                                 << setw(20) << "Kategori" << setw(15) << "Harga" << endl;
                            cout << string(80, '-') << endl;
                            for (int i = 0; i < daftarUser[0].jumlahProduk; i++) {
                                cout << setw(10) << daftarUser[0].daftarProduk[i].kode
                                     << setw(20) << daftarUser[0].daftarProduk[i].nama
                                     << setw(15) << daftarUser[0].daftarProduk[i].merk
                                     << setw(20) << daftarUser[0].daftarProduk[i].kategori
                                     << setw(15) << daftarUser[0].daftarProduk[i].harga << endl;
                            }
                        }
                        break;

                    case 2: // Tambah Data
                        if (daftarUser[0].jumlahProduk >= 100) {
                            cout << "Kapasitas produk penuh!" << endl;
                        } else {
                            cout << "\n=== Tambah Data Handphone ===" << endl;
                            int idx = daftarUser[0].jumlahProduk;
                            cout << "Masukkan Kode Produk: ";
                            cin >> daftarUser[0].daftarProduk[idx].kode;
                            cout << "Masukkan Nama Produk: ";
                            cin.ignore();
                            getline(cin, daftarUser[0].daftarProduk[idx].nama);
                            cout << "Masukkan Merk Produk: ";
                            getline(cin, daftarUser[0].daftarProduk[idx].merk);
                            cout << "Masukkan Kategori Produk: ";
                            getline(cin, daftarUser[0].daftarProduk[idx].kategori);
                            cout << "Masukkan Harga: ";
                            cin >> daftarUser[0].daftarProduk[idx].harga;
                            daftarUser[0].jumlahProduk++;
                            cout << "Data berhasil ditambahkan!" << endl;
                        }
                        break;

                    case 3: // Ubah Data
                        if (daftarUser[0].jumlahProduk == 0) {
                            cout << "Belum ada data handphone!" << endl;
                        } else {
                            cout << "\n================================ Data Handphone ================================" << endl;
                            cout << setw(10) << "Kode" << setw(20) << "Nama" << setw(15) << "Merk" 
                                 << setw(20) << "Kategori" << setw(15) << "Harga" << endl;
                            cout << string(80, '-') << endl;
                            for (int i = 0; i < daftarUser[0].jumlahProduk; i++) {
                                cout << setw(10) << daftarUser[0].daftarProduk[i].kode
                                     << setw(20) << daftarUser[0].daftarProduk[i].nama
                                     << setw(15) << daftarUser[0].daftarProduk[i].merk
                                     << setw(20) << daftarUser[0].daftarProduk[i].kategori
                                     << setw(15) << daftarUser[0].daftarProduk[i].harga << endl;
                            }
                            string kode;
                            cout << "\nMasukkan Kode Produk yang akan diubah: ";
                            cin >> kode;
                            bool ditemukan = false;
                            for (int i = 0; i < daftarUser[0].jumlahProduk; i++) {
                                if (daftarUser[0].daftarProduk[i].kode == kode) {
                                    cout << "Masukkan Nama Produk baru: ";
                                    cin.ignore();
                                    getline(cin, daftarUser[0].daftarProduk[i].nama);
                                    cout << "Masukkan Merk Produk baru: ";
                                    getline(cin, daftarUser[0].daftarProduk[i].merk);
                                    cout << "Masukkan Kategori Produk baru: ";
                                    getline(cin, daftarUser[0].daftarProduk[i].kategori);
                                    cout << "Masukkan Harga baru: ";
                                    cin >> daftarUser[0].daftarProduk[i].harga;
                                    cout << "Data berhasil diubah!" << endl;
                                    ditemukan = true;
                                    break;
                                }
                            }
                            if (!ditemukan) cout << "Kode produk tidak ditemukan!" << endl;
                        }
                        break;

                    case 4: // Hapus Data
                        if (daftarUser[0].jumlahProduk == 0) {
                            cout << "Belum ada data handphone!" << endl;
                        } else {
                            cout << "\n================================ Data Handphone ================================" << endl;
                            cout << setw(10) << "Kode" << setw(20) << "Nama" << setw(15) << "Merk" 
                                 << setw(20) << "Kategori" << setw(15) << "Harga" << endl;
                            cout << string(80, '-') << endl;
                            for (int i = 0; i < daftarUser[0].jumlahProduk; i++) {
                                cout << setw(10) << daftarUser[0].daftarProduk[i].kode
                                     << setw(20) << daftarUser[0].daftarProduk[i].nama
                                     << setw(15) << daftarUser[0].daftarProduk[i].merk
                                     << setw(20) << daftarUser[0].daftarProduk[i].kategori
                                     << setw(15) << daftarUser[0].daftarProduk[i].harga << endl;
                            }
                            string kode;
                            cout << "\nMasukkan Kode Produk yang akan dihapus: ";
                            cin >> kode;
                            bool ditemukan = false;
                            for (int i = 0; i < daftarUser[0].jumlahProduk; i++) {
                                if (daftarUser[0].daftarProduk[i].kode == kode) {
                                    for (int j = i; j < daftarUser[0].jumlahProduk - 1; j++) {
                                        daftarUser[0].daftarProduk[j] = daftarUser[0].daftarProduk[j + 1];
                                    }
                                    daftarUser[0].jumlahProduk--;
                                    cout << "Produk berhasil dihapus!" << endl;
                                    ditemukan = true;
                                    break;
                                }
                            }
                            if (!ditemukan) cout << "Kode produk tidak ditemukan!" << endl;
                        }
                        break;

                    case 5: // Logout
                        cout << "Logout berhasil!" << endl;
                        break;

                    default:
                        cout << "Pilihan tidak valid!" << endl;
                }
                if (pilihan == 5) break;
            } else { // Menu untuk user biasa
                switch (pilihan) {
                    case 1: // Tampilkan Data
                        if (daftarUser[0].jumlahProduk == 0) {
                            cout << "Belum ada data handphone!" << endl;
                        } else {
                            cout << "\n================================ Data Handphone ================================" << endl;
                            cout << setw(10) << "Kode" << setw(20) << "Nama" << setw(15) << "Merk" 
                                 << setw(20) << "Kategori" << setw(15) << "Harga" << endl;
                            cout << string(80, '-') << endl;
                            for (int i = 0; i < daftarUser[0].jumlahProduk; i++) {
                                cout << setw(10) << daftarUser[0].daftarProduk[i].kode
                                     << setw(20) << daftarUser[0].daftarProduk[i].nama
                                     << setw(15) << daftarUser[0].daftarProduk[i].merk
                                     << setw(20) << daftarUser[0].daftarProduk[i].kategori
                                     << setw(15) << daftarUser[0].daftarProduk[i].harga << endl;
                            }
                        }
                        break;

                    case 2: // Beli Produk
                        if (daftarUser[0].jumlahProduk == 0) {
                            cout << "Belum ada data handphone!" << endl;
                        } else {
                            cout << "\n================================ Data Handphone ================================" << endl;
                            cout << setw(10) << "Kode" << setw(20) << "Nama" << setw(15) << "Merk" 
                                 << setw(20) << "Kategori" << setw(15) << "Harga" << endl;
                            cout << string(80, '-') << endl;
                            for (int i = 0; i < daftarUser[0].jumlahProduk; i++) {
                                cout << setw(10) << daftarUser[0].daftarProduk[i].kode
                                     << setw(20) << daftarUser[0].daftarProduk[i].nama
                                     << setw(15) << daftarUser[0].daftarProduk[i].merk
                                     << setw(20) << daftarUser[0].daftarProduk[i].kategori
                                     << setw(15) << daftarUser[0].daftarProduk[i].harga << endl;
                            }
                            string kode;
                            cout << "\nMasukkan Kode Produk yang ingin dibeli: ";
                            cin >> kode;
                            bool ditemukan = false;
                            for (int i = 0; i < daftarUser[0].jumlahProduk; i++) {
                                if (daftarUser[0].daftarProduk[i].kode == kode) {
                                    for (int j = i; j < daftarUser[0].jumlahProduk - 1; j++) {
                                        daftarUser[0].daftarProduk[j] = daftarUser[0].daftarProduk[j + 1];
                                    }
                                    daftarUser[0].jumlahProduk--;
                                    cout << "Produk berhasil dibeli!" << endl;
                                    ditemukan = true;
                                    break;
                                }
                            }
                            if (!ditemukan) cout << "Kode produk tidak ditemukan!" << endl;
                        }
                        break;

                    case 3: // Logout
                        cout << "Logout berhasil!" << endl;
                        break;

                    default:
                        cout << "Pilihan tidak valid!" << endl;
                }
                if (pilihan == 3) break;
            }
        }
    }
}