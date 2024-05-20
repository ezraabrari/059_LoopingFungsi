#include <iostream>
#include <vector>
using namespace std;

class dokter;
class pasien{
public:
    string nama;
    vector<dokter*> daftar_dokter;
    pasien(string pNama) :nama(pNama) {
        cout << "pasien \"" << nama << "\" ada\n";
    }
    ~pasien() {
        cout << "pasien \"" << nama << "\" Tidak ada\n";
    }
    void tambahDokter(dokter*);
    void cetakDokter();
};

class dokter {
public:
    string nama;
    vector<pasien*> daftar_pasien;

    dokter(string pNama) :nama(pNama) {
        cout << "dokter\"" << nama << "\" ada\n";
    }
    ~dokter() {
        cout << "dokter \"" << nama << "\" Tidak ada\n";
    }
    void tambahPasien(pasien*);
    void cetakPasien();
};

void pasien::tambahDokter (dokter* pDokter) {
    daftar_dokter.push_back(pDokter);
}

void pasien::cetakDokter() {
    cout << "Daftar dokter yang menangani pasien\"" << this->nama << "\":\n";
    for (auto& a : daftar_dokter) {
        cout << a->nama << "\n";
    }
    cout << endl;
}

void dokter::tambahPasien(pasien* pPasien) {
    daftar_pasien.push_back(pPasien);
    pPasien->tambahDokter(this);
}
void dokter::cetakPasien() {
    cout << "Daftar pasien dari dokter\"" << this->nama << "\":\n";
    for (auto& a : daftar_pasien) {
        cout << a->nama << "\n";
    }
    cout << endl;
}

