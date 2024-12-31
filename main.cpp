#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Pasien {
    string nama;
    int umur;
    int hariRawat;
    double biayaPerHari;
    string jenisKamar;
};

double hitungBiaya(Pasien pasien) {
    return pasien.hariRawat * pasien.biayaPerHari;
}

int main() {
    char lagi;
    do {
        Pasien pasien;

        // Input data pasien
        cout << "Masukkan Nama Pasien: ";
        cin.ignore(); // Mengabaikan newline dari input sebelumnya
        getline(cin, pasien.nama);
        cout << "Masukkan Umur Pasien: ";
        cin >> pasien.umur;
        cout << "Masukkan Jumlah Hari Rawat Inap: ";
        cin >> pasien.hariRawat;

        // Memilih jenis kamar
        cout << "Pilih jenis kamar (1. Kelas 1 - Rp 1.000.000/hari, 2. Kelas 2 - Rp 500.000/hari, 3. Kelas 3 - Rp 250.000/hari): ";
        int pilihan;
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                pasien.jenisKamar = "Kelas 1";
                pasien.biayaPerHari = 1000000;
                break;
            case 2:
                pasien.jenisKamar = "Kelas 2";
                pasien.biayaPerHari = 500000;
                break;
            case 3:
                pasien.jenisKamar = "Kelas 3";
                pasien.biayaPerHari = 250000;
                break;
            default:
                cout << "Pilihan tidak valid. Menggunakan Kelas 3 sebagai default." << endl;
                pasien.jenisKamar = "Kelas 3";
                pasien.biayaPerHari = 250000;
                break;
        }

        // Menghitung total biaya
        double totalBiaya = hitungBiaya(pasien);

        // Menampilkan informasi pasien dan total biaya
        cout << fixed << setprecision(2); // Mengatur format output
        cout << "\nData Pasien:\n";
        cout << "Nama: " << pasien.nama << endl;
        cout << "Umur: " << pasien.umur << endl;
        cout << "Jumlah Hari Rawat Inap: " << pasien.hariRawat << endl;
        cout << "Jenis Kamar: " << pasien.jenisKamar << endl;
        cout << "Total Biaya Rawat Inap: Rp " << totalBiaya << endl;

        // Menanyakan apakah ingin menghitung untuk pasien lain
        cout << "\nApakah Anda ingin menghitung biaya untuk pasien lain? (y/n): ";
        cin >> lagi;

    } while (lagi == 'y' || lagi == 'Y');

    cout << "Terima kasih telah menggunakan program ini!" << endl;

    return 0;
}