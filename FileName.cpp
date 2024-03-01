#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
int partition(T arr[], int low, int high) {
    T pivot = arr[low];
    int i = low + 1;

    for (int j = low + 1; j <= high; j++) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    swap(arr[low], arr[i - 1]);
    return (i - 1);
}

template <typename T>
void quickSort(T arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

template <typename T>
void printArray(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void bubbleSort(T arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template <typename T>
void insertionSort(T arr[], int size) {
    for (int i = 1; i < size; i++) {
        T key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() {

    //QuickSort
    std::cout << "Quick Sort: " << std::endl;

    int size_qs;
    std::cout << "Enter the size of the array: ";
    std::cin >> size_qs;

    int* arr_qs = new int[size_qs];

    std::srand(std::time(NULL));
    for (int i = 0; i < size_qs; i++) {
        arr_qs[i] = std::rand() % 100;
    }

    std::cout << "Array: ";
    printArray(arr_qs, size_qs);

    quickSort(arr_qs, 0, size_qs - 1);

    std::cout << "Sorted array: ";
    printArray(arr_qs, size_qs);

    delete[] arr_qs;
    std::cout << std::endl << std::endl;




    //Bubble Sort
    std::cout << "Bubble Sort: " << std::endl;

    int size_bs;
    std::cout << "Enter the size of the array: ";
    std::cin >> size_bs;

    int* arr_bs = new int[size_bs];

    for (int i = 0; i < size_bs; i++) {
        arr_bs[i] = std::rand() % 100;
    }

    std::cout << "Array: ";
    printArray(arr_bs, size_bs);

    bubbleSort(arr_bs, size_bs);

    std::cout << "Sorted array: ";
    printArray(arr_bs, size_bs);

    delete[] arr_bs;
    std::cout << std::endl << std::endl;



    //Insertion Sort
    std::cout << "Insertion Sort: " << std::endl;

    int size_is;
    std::cout << "Enter the size of the array: ";
    std::cin >> size_is;

    int* arr_is = new int[size_is];

    for (int i = 0; i < size_is; i++) {
        arr_is[i] = std::rand() % 100;
    }

    std::cout << "Array: ";
    printArray(arr_is, size_is);

    insertionSort(arr_is, size_is);

    std::cout << "Sorted array: ";
    printArray(arr_is, size_is);

    delete[] arr_is;


    return 0;
}