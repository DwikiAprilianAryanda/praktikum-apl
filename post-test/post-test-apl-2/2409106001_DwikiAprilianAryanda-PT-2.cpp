#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Deklarasi array
string kodeNama[100][2];
string merkProduk[100];
string kategoriProduk[100];
int hargaProduk[100];
int jumlahData = 0;

int main() {
    string nama, nim;
    string namabenar = "lian";
    string nimbenar = "001";
    int percobaan = 0;
    
    while (percobaan < 3) {
        cout << "\n=== Login Sistem ===" << endl;
        cout << "Masukkan Nama: ";
        cin >> nama;
        cin.ignore();
        cout << "Masukkan NIM: ";
        cin >> nim;
        cin.ignore();
        
        if (nama == namabenar && nim == nimbenar) {
            cout << "Login berhasil!" << endl;
            break;
        } else {
            percobaan++;
            cout << "Yang bener dikit le. Sisa percobaan: " << (3 - percobaan) << endl;
        }
    }
    if (percobaan >= 3) {
        cout << "Cukurukuk gak bisa nyoba login lagi" << endl;
        return 0;
    }

    // Menu utama
    char ulang;
    do {
        cout << "==================================\n";
        cout << "=== Manajemen Produk Handphone ===\n";
        cout << "==================================\n";
        cout << "|1. Tampilkan Data               |\n";
        cout << "|2. Tambah Data                  |\n";
        cout << "|3. Ubah Data                    |\n";
        cout << "|4. Hapus Data                   |\n";
        cout << "|5. Keluar                       |\n";
        cout << "==================================\n";
        cout << "Pilih menu (1-5): ";
        
        int pilihan;
        cin >> pilihan;
        
        switch (pilihan) {
            case 1: // Tampilkan Data
                if (jumlahData == 0) {
                    cout << "Masukin dulu data handphone nya" << endl;
                } else {
                    cout << "\n=== Data Handphone ===" << endl;
                    cout << setw(10) << "Kode" << setw(20) << "Nama Produk" << setw(15) << "Merk" 
                         << setw(20) << "Kategori" << setw(15) << "Harga" << endl;
                    cout << string(80, '-') << endl;
                    for (int i = 0; i < jumlahData; i++) {
                        cout << setw(10) << kodeNama[i][0] 
                             << setw(20) << kodeNama[i][1]
                             << setw(15) << merkProduk[i]
                             << setw(20) << kategoriProduk[i] 
                             << setw(15) << hargaProduk[i] << endl;
                    }
                }
                break;

            case 2: // Tambah Data
                if (jumlahData >= 100) {
                    cout << "Kapasitas penuh!" << endl;
                } else {
                    cout << "\n=== Tambah Data Handphone ===" << endl;
                    cout << "Masukkan Kode Produk: ";
                    cin >> kodeNama[jumlahData][0];
                    cout << "Masukkan Nama Produk: ";
                    cin.ignore();
                    getline(cin, kodeNama[jumlahData][1]);
                    cout << "Masukkan Merk Produk: ";
                    getline(cin, merkProduk[jumlahData]);
                    cout << "Masukkan Kategori Produk: ";
                    getline(cin, kategoriProduk[jumlahData]);
                    cout << "Masukkan Harga: ";
                    cin >> hargaProduk[jumlahData];
                    jumlahData++;
                    cout << "Data berhasil ditambahkan!" << endl;
                }
                break;

            case 3: // Ubah Data
                {
                    string kode;
                    cout << "\nMasukkan Kode Produk yang akan diubah: ";
                    cin >> kode;
                    bool ditemukan = false;
                    for (int i = 0; i < jumlahData; i++) {
                        if (kodeNama[i][0] == kode) {
                            cout << "Masukkan Nama Produk baru: ";
                            cin.ignore();
                            getline(cin, kodeNama[i][1]);
                            cout << "Masukkan Merk Produk: ";
                            getline(cin, merkProduk[i]);
                            cout << "Masukkan Kategori Produk baru: ";
                            getline(cin, kategoriProduk[i]);
                            cout << "Masukkan Harga baru: ";
                            cin >> hargaProduk[i];
                            cout << "Data berhasil diubah!" << endl;
                            ditemukan = true;
                            break;
                        }
                    }
                    if (!ditemukan) {
                        cout << "Kode produk tidak ditemukan!" << endl;
                    }
                }
                break;

            case 4: // Hapus Data
                {
                    string kode;
                    cout << "\nMasukkan Kode Produk yang akan dihapus: ";
                    cin >> kode;
                    bool ditemukan = false;
                    for (int i = 0; i < jumlahData; i++) {
                        if (kodeNama[i][0] == kode) {
                            for (int j = i; j < jumlahData - 1; j++) {
                                kodeNama[j][0] = kodeNama[j + 1][0];
                                kodeNama[j][1] = kodeNama[j + 1][1];
                                merkProduk[j] = merkProduk[j + 1];
                                kategoriProduk[j] = kategoriProduk[j + 1];
                                hargaProduk[j] = hargaProduk[j + 1];
                            }
                            jumlahData--;
                            cout << "Data berhasil dihapus!" << endl;
                            ditemukan = true;
                            break;
                        }
                    }
                    if (!ditemukan) {
                        cout << "Kode produk tidak ditemukan!" << endl;
                    }
                }
                break;

            case 5: // Keluar
                cout << "Terima kasih!" << endl;
                return 0;

            default:
                cout << "Pilihan tidak valid!" << endl;
        }
        
        cout << "\nKembali ke menu? (y/n): ";
        cin >> ulang;
    } while (ulang == 'y' || ulang == 'Y');
    
    cout << "Program selesai!" << endl;
    return 0;
}
