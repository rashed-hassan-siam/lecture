#include <iostream>
#include <vector>
#include <algorithm> // for swap

using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        // Last i elements are already in place
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    vector<int> data = {64, 34, 25, 12, 22, 11, 90};
    bubbleSort(data);
    
    cout << "Sorted array (Bubble Sort): ";
    for (int i = 0; i < data.size(); i++) 
    {
        cout << data[i] << " ";
    }
    cout << endl;
    return 0;
}