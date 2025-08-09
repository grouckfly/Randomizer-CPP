#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <thread>
#include <chrono>
#include <algorithm> // Diperlukan untuk std::max

// Definisi warna menggunakan ANSI escape codes
#define RESET       "\033[0m"
#define BOLD_CYAN   "\033[1;36m"
#define BOLD_GREEN  "\033[1;32m"
#define YELLOW      "\033[0;33m"

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Fungsi baru untuk menampilkan hasil yang lebih rapi
void tampilkanHasil(const std::string& objekTerpilih) {
    std::string judul = "HASIL PEMILIHAN ACAK";
    std::string barisHasil = ">>> " + objekTerpilih + " <<<";

    // Tentukan lebar kotak berdasarkan teks terpanjang + padding
    size_t lebarKonten = std::max(judul.length(), barisHasil.length());
    size_t lebarTotal = lebarKonten + 4; // Padding 2 spasi di setiap sisi

    // Fungsi helper untuk membuat baris dengan teks di tengah
    auto buatBarisTengah = [&](const std::string& teks, const std::string& warnaTeks = "") {
        size_t spasiTotal = lebarTotal - teks.length();
        size_t spasiKiri = spasiTotal / 2;
        size_t spasiKanan = spasiTotal - spasiKiri;
        std::cout << BOLD_CYAN << "║" << RESET
                  << std::string(spasiKiri, ' ')
                  << warnaTeks << teks << RESET
                  << std::string(spasiKanan, ' ')
                  << BOLD_CYAN << "║" << RESET << std::endl;
    };
    
    // Buat garis batas atas dan bawah
    std::string batasAtas = std::string(BOLD_CYAN) + "╔" + std::string(lebarTotal, '=') + "╗" + RESET;
    std::string batasBawah = std::string(BOLD_CYAN) + "╚" + std::string(lebarTotal, '=') + "╝" + RESET;
    std::string barisKosong = std::string(BOLD_CYAN) + "║" + std::string(lebarTotal, ' ') + "║" + RESET;

    // Cetak semua bagian
    std::cout << "\n\n";
    std::cout << batasAtas << std::endl;
    std::cout << barisKosong << std::endl;
    buatBarisTengah(judul);
    std::cout << barisKosong << std::endl;
    buatBarisTengah(barisHasil, BOLD_GREEN);
    std::cout << barisKosong << std::endl;
    std::cout << batasBawah << std::endl;
    std::cout << "\n";
}

int main() {
    // --- TAHAP 1: INPUT DARI USER (Tidak ada perubahan) ---
    std::cout << "=====================================\n";
    std::cout << "||   PROGRAM PEMILIH OBJEK ACAK    ||\n";
    std::cout << "=====================================\n\n";

    int jumlahObjek;
    std::cout << "Masukkan Jumlah Objek: ";
    std::cin >> jumlahObjek;

    if (std::cin.fail() || jumlahObjek <= 0) {
        std::cout << "Input tidak valid. Harap masukkan angka bulat positif." << std::endl;
        return 1;
    }

    std::vector<std::string> daftarObjek;
    std::string namaObjek;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cout << "\nMasukkan " << jumlahObjek << " nama objek:\n";
    for (int i = 0; i < jumlahObjek; ++i) {
        std::cout << "Objek " << i + 1 << ": ";
        std::getline(std::cin, namaObjek);
        daftarObjek.push_back(namaObjek);
    }

    // --- TAHAP 2: ANIMASI "HACKING" (Tidak ada perubahan) ---
    clearScreen();
    std::cout << "MEMULAI PROSES PEMILIHAN ACAK..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::vector<std::string> pesanAnimasi = {
        "Menganalisis Vektor Memori...", "Menginjeksi Entropi Acak...",
        "Mem-bypass Protokol Seleksi...", "Menghitung Hash Kriptografis...",
        "Mengacak Indeks Array...", "Menjalankan Quantum Fluctuation...",
        "Dekripsi Kandidat Target..."
    };

    std::random_device rd_anim;
    std::mt19937 gen_anim(rd_anim());
    std::uniform_int_distribution<> pesan_distrib(0, pesanAnimasi.size() - 1);
    
    for (int i = 0; i <= 100; ++i) {
        int indexPesan = pesan_distrib(gen_anim);
        std::string objekSaatIni = daftarObjek[i % daftarObjek.size()];
        std::cout << "\r" << YELLOW << "[" << i << "%] " << RESET << pesanAnimasi[indexPesan]
                  << " -> " << objekSaatIni << std::string(10, ' ') << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(60));
    }
    std::cout << "\n\n" << BOLD_GREEN << "[100%] PROSES SELESAI." << RESET << std::endl;

    // --- EFEK DRUM ROLL ---
    std::cout << "\nMengkalkulasi hasil akhir";
    for(int i = 0; i < 3; ++i) {
        std::cout << "." << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(700));
    }

    // --- TAHAP 3: PENGACAKAN DAN HASIL AKHIR ---
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, daftarObjek.size() - 1);
    int indexTerpilih = distrib(gen);

    // Memanggil fungsi baru untuk menampilkan hasil
    tampilkanHasil(daftarObjek[indexTerpilih]);

    return 0;
}