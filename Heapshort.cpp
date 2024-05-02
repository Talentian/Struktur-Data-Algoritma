#include <iostream>
#include <vector>

// Fungsi untuk menyesuaikan heap
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i; // Asumsikan simpul terbesar adalah simpul induk
    int left = 2 * i + 1; // Indeks anak kiri
    int right = 2 * i + 2; // Indeks anak kanan

    // Jika anak kiri lebih besar dari induk
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Jika anak kanan lebih besar dari induk atau terbesar
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Jika simpul terbesar bukan lagi induk
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        // Perbaiki heap pada sub-heap yang terpengaruh
        heapify(arr, n, largest);
    }
}

// Fungsi heapsort
void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    // Bangun heap maksimum dari array
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Ekstraksi elemen satu per satu dari heap
    for (int i = n - 1; i > 0; i--) {
        // Pindahkan elemen maksimum ke akhir array
        std::swap(arr[0], arr[i]);
        // Pangkas ukuran heap dan perbaiki heap yang tersisa
        heapify(arr, i, 0);
    }
}

int main() {
    int temp_arr[] = {12, 11, 13, 5, 6, 7}; // Ubah inisialisasi menggunakan array sementara
    std::vector<int> arr(temp_arr, temp_arr + sizeof(temp_arr) / sizeof(temp_arr[0])); // Inisialisasi vektor dengan array

    std::cout << "Array sebelum pengurutan: ";
    for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    heapSort(arr);

    std::cout << "Array setelah pengurutan: ";
    for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    return 0;
}


