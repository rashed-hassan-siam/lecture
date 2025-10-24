#include <iostream>
#include <vector>
#include <algorithm> // for swap

using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        // Find the minimum element in the unsorted array
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        swap(arr[min_idx], arr[i]);
    }
}

int main() {
    vector<int> data = {64, 25, 12, 22, 11};
    selectionSort(data);

    cout << "Sorted array (Selection Sort): ";
    for (int i = 0; i < data.size(); i++) 
    {
        cout << data[i] << " ";
    }
    cout << endl;
    return 0;
}