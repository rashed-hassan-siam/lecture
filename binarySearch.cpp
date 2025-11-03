#include <iostream>
#include <vector>
#include <algorithm> // for sort

using namespace std;

// Iterative implementation
int binarySearch(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // Not found
}

int main() {
    vector<int> data = {2, 5, 8, 12, 16, 23, 38, 56, 72};
    int target = 23;
    int result = binarySearch(data, target);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found." << endl;
    }
    return 0;
}