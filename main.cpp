#include <iostream>
#include <fstream>

using namespace std;

void quiz() {

    // untuk menyimpan berapa jumlah angka yang akan di masukkan
    int jumlah;

    cout << "Masukkan jumlah baris angka : ";
    cin >> jumlah; // masukkan jumlah angka

    int baris[jumlah]; // membuat array untuk menyimpan angka-angka dengan index sesuai dengan jumlah baris yang dimasukkan sebelumnya

    // proses iterasi untuk menyimpan nilai pada array satu persatu
    for(int i=0;i<jumlah;i++) {
        cout << "Masukkan angka ke-" << i << " : ";
        cin >> baris[i];
        cout << endl;
    }

    FILE * genap;
    FILE * ganjil;
    genap = fopen("genap.txt", "w");
    ganjil = fopen("ganjil.txt", "w");

    // variabel yang menyimpan total dari inputan yang diklasifikasikan berdasarkan ganjil atau genapnya angka
    int totalGenap = 0;
    int totalGanjil = 0;

    for(int i=0;i<jumlah;i++) {
        cout << "Angka masukkan ke-" << i << " : " << baris[i] << endl;
        if(baris[i]%2) { // jika genap
            totalGanjil += baris[i];
            fprintf(ganjil, "%d\n", baris[i]); // memasukkan angka ganjil pada file ganjil
        }
        else {
            totalGenap += baris[i];
            fprintf(genap, "%d\n", baris[i]); // memasukkan angka genap pada file genap
        }
    }
    fprintf(genap, "%s %d", "Total : ", totalGenap); // menambahkan nilai total untuk genap
    fprintf(ganjil, "%s %d", "Total : ", totalGanjil); // menambahkan nilai total untuk ganjil

    // menutup file genap dan ganjil
    fclose(genap);
    fclose(ganjil);
}

int main()
{
    // memanggil method prosedur quiz
    quiz();
}
