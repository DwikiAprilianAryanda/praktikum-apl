// Struktur Dasar C++
#include <iostream>
using namespace std;

int main () {
    std :: cout << "Hello, world!" << std::endl;
    return 0;
}

// input dan output
int main () {
    string nama;

    cout << "Masukkan nama anda: ";
    cin >> nama;
    cout << nama;
}

// tipe data primitif
int main () {
    int umur = 20;
    int sumbuY = -45;
    float berat_badan = 40.5;
    double tinggi_badan = 155.5;
    char jenis_kelamin = 'L';
    bool is_menikah = false;
    string nama = "Faiz";
}

// tipe data kolektif
int main () {
    int angka[5] = {1, 2, 3, 4, 5}; // array
    string nama = "Faiz"; 
}

// Tipe Data Abstrak
struct Mahasiswa {
    string nama;
    int umur;
    float ipk;
};
Mahasiswa mhs = {"Faiz", 20, 3.6};

// Operator Ternary
int main () {
    bool sudahMenikah = true;
    string status = sudahMenikah ? "Sudah menikah" : "Belum menikah";
    cout << status << endl;
}

int main () {
    bool sudahMenikah = true;
    string status = sudahMenikah ? "Sudah menikah" : "Belum menikah";

    // if (sudahMenikah) {
    //     cout << "Sudah menikah";
    // } else {
    //     cout << "Belum menikah";
    // }
    cout << status;
    return 0;
}


// Percabangan if
int main () {
    bool malas = true;
    if (malas) {
    cout << "Saya baca novel";
    }
}

// Percabangan if-else
int main () {
    bool malas = true;
    if (malas) {
    cout << "Saya baca novel";
     
    } else {
     cout << "Saya belajar";
    }
}

// Percabangan if-else if
int main () {
    bool malas = false;
    bool lapar = true;
    if (malas) cout << "Saya baca novel";
    else if (lapar) cout << "Saya makan";
    else cout << "Saya belajar";
}

// struktur switch-case
int main () {
    int nilaiUjian = 100;
    switch(nilaiUjian) {
        case 100:
            cout << "Nilai sempurna";
            break;
        case 90:
            cout << "Nilai sangat baik";
            break;
        default:
            cout << "Nilai tidak valid";
            break;
    }
}

// Nested If
int main () {
    bool malas = true;
    bool lapar = true;

    if (malas) {
        if (lapar) {
            cout << "Saya makan";
        }
    } else {
        cout << "Gak ngapa-ngapain";
    }
}

// Perulangan For
int main (int argc, char const * argv) {
    for (int i = 0; i < 5; i++) {
        cout << i << endl;
    }
}

// Perulangan While
int main () {
    int i = 0;
    while (i < 5) {
        cout << i << endl;
        i++;
    }
}

// Perulangan Do-While
int main () {
    int i = 0;
    do {
        cout << i << endl;
        i++;
    } while (i < 5);
}

// Perulangan ForEach
int main () {
    int arr[] = {1, 2, 3, 4, 5};
    for (int x : arr) {
        cout << x << endl;
    }

}