#include <iostream>
#include <string>
using namespace std;

int main() {
    char ulang;
    string nama;
    string nim;
    string namaBenar = "DwikiAprilianAryanda";
    string nimBenar = "2409106001";
    int percobaan = 3;

    // Login
    while (percobaan > 0) {
        cout << "======================\n";
        cout << "=== Silahkan Login ===\n";
        cout << "======================\n";
        cout << "Masukkan Nama: ";
        cin >> nama;
        cout << "Masukkan NIM: ";
        cin >> nim;

        if (nama == namaBenar && nim == nimBenar) {
            cout << "Login Berhasil\n";
            break;
        } else {
            percobaan--;
            cout << "Login Gagal! Sisa percobaan: " << percobaan << endl;
            if (percobaan > 0) {
                cout << "Silakan coba lagi\n";
            }
        }
    }

    if (percobaan == 0) {
        cout << "Hayoo dah gagal login 3 kali. Programnya berhenti le\n";
        return 0;
    }

    do {
        int pilihan;
        double nilai;
        
        cout << "===============================\n";
        cout << "|== PROGRAM KONVERSI SATUAN ==|\n";
        cout << "|=============================|\n";
        cout << "|1. Konversi Meter            |\n";
        cout << "|2. Konversi Centimeter       |\n";
        cout << "|3. Konversi Mile             |\n";
        cout << "|4. Konversi Foot             |\n";
        cout << "|5. Keluar                    |\n";
        cout << "===============================\n";
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;

        if (pilihan >= 1 && pilihan <= 4) {
            cout << "Masukkan nilai yang akan dikonversi: ";
            cin >> nilai;
        }

        switch (pilihan) {
            case 1: // Konversi Meter
                cout << nilai << " Meter = " << nilai * 100 << " Centimeter\n";
                cout << nilai << " Meter = " << nilai * 0.000621371 << " Mile\n";
                cout << nilai << " Meter = " << nilai * 3.28084 << " Foot\n";
                break;
            case 2: // Konversi Centimeter
                cout << nilai << " Centimeter = " << nilai / 100 << " Meter\n";
                cout << nilai << " Centimeter = " << nilai * 0.0000062137 << " Mile\n";
                cout << nilai << " Centimeter = " << nilai * 0.0328084 << " Foot\n";
                break;
            case 3: // Konversi Mile
                cout << nilai << " Mile = " << nilai * 1609.34 << " Meter\n";
                cout << nilai << " Mile = " << nilai * 160934 << " Centimeter\n";
                cout << nilai << " Mile = " << nilai * 5280 << " Foot\n";
                break;
            case 4: // Konversi Foot
                cout << nilai << " Foot = " << nilai * 0.3048 << " Meter\n";
                cout << nilai << " Foot = " << nilai * 30.48 << " Centimeter\n";
                cout << nilai << " Foot = " << nilai * 0.000189394 << " Mile\n";
                break;
            case 5:
                cout << "Terima kasih telah menggunakan program!\n";
                return 0;
            default:
                cout << "Pilihan tidak valid!\n";
        }

        cout << "\nApakah ingin melanjutkan program? (y/n): ";
        cin >> ulang;

    } while (ulang == 'y' || ulang == 'Y');

    cout << "Program selesai.\n";
    return 0;
}