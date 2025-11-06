#include <iostream>
#include <vector>
#include <algorithm> // for swap

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> data = {10, 7, 8, 9, 1, 5};
    quickSort(data, 0, data.size() - 1);

    cout << "Sorted array (Quick Sort): ";
    for (int i = 0; i < data.size(); i++) 
    {
        cout << data[i] << " ";
    }
    cout << endl;
    return 0;
}