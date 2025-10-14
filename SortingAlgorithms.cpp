#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

class SortingAlgorithms {
private:
    // Helper function for quicksort
    static int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        
        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }

    // Helper function for merge sort
    static void merge(vector<int>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        
        vector<int> L(n1), R(n2);
        
        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];
            
        int i = 0, j = 0, k = left;
        
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }
        
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

public:
    // Bubble Sort - Time Complexity: O(n²)
    static void bubbleSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < n-i-1; j++) {
                if (arr[j] > arr[j+1]) {
                    swap(arr[j], arr[j+1]);
                }
            }
        }
    }
    
    // Selection Sort - Time Complexity: O(n²)
    static void selectionSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n-1; i++) {
            int min_idx = i;
            for (int j = i+1; j < n; j++) {
                if (arr[j] < arr[min_idx]) {
                    min_idx = j;
                }
            }
            swap(arr[min_idx], arr[i]);
        }
    }
    
    // Quick Sort - Time Complexity: O(n log n) average, O(n²) worst case
    static void quickSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
    
    // Merge Sort - Time Complexity: O(n log n)
    static void mergeSort(vector<int>& arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }

    // Utility function to print array
    static void printArray(const vector<int>& arr) {
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }
};

// Function to measure execution time
template<typename Func>
long long measureTime(Func f) {
    auto start = chrono::high_resolution_clock::now();
    f();
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::microseconds>(end - start).count();
}

int main() {
    // Test data
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    int n = arr.size();
    
    cout << "Original array: ";
    SortingAlgorithms::printArray(arr);
    
    // Test Bubble Sort
    vector<int> bubble_arr = arr;
    auto bubbleTime = measureTime([&]() {
        SortingAlgorithms::bubbleSort(bubble_arr);
    });
    cout << "\nBubble Sort result: ";
    SortingAlgorithms::printArray(bubble_arr);
    cout << "Time taken by Bubble Sort: " << bubbleTime << " microseconds\n";
    
    // Test Selection Sort
    vector<int> selection_arr = arr;
    auto selectionTime = measureTime([&]() {
        SortingAlgorithms::selectionSort(selection_arr);
    });
    cout << "\nSelection Sort result: ";
    SortingAlgorithms::printArray(selection_arr);
    cout << "Time taken by Selection Sort: " << selectionTime << " microseconds\n";
    
    // Test Quick Sort
    vector<int> quick_arr = arr;
    auto quickTime = measureTime([&]() {
        SortingAlgorithms::quickSort(quick_arr, 0, n-1);
    });
    cout << "\nQuick Sort result: ";
    SortingAlgorithms::printArray(quick_arr);
    cout << "Time taken by Quick Sort: " << quickTime << " microseconds\n";
    
    // Test Merge Sort
    vector<int> merge_arr = arr;
    auto mergeTime = measureTime([&]() {
        SortingAlgorithms::mergeSort(merge_arr, 0, n-1);
    });
    cout << "\nMerge Sort result: ";
    SortingAlgorithms::printArray(merge_arr);
    cout << "Time taken by Merge Sort: " << mergeTime << " microseconds\n";
    
    return 0;
}
