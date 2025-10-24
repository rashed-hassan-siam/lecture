#include <iostream>
#include <vector>
#include <limits> // For numeric_limits
using namespace std;


void merge(vector<int>& A, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    vector<int> L(n1 + 1);
    vector<int> R(n2 + 1);

    for (int i = 0; i < n1; ++i) {
        L[i] = A[p + i];
    }

    for (int j = 0; j < n2; ++j) {
        R[j] = A[q + 1 + j];
    }

    L[n1] = numeric_limits<int>::max();

    R[n2] = numeric_limits<int>::max();

    int i = 0;
    int j = 0;

    for (int k = p; k <= r; ++k) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}


void mergeSort(vector<int>& A, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        
        mergeSort(A, p, q);
        
        mergeSort(A, q + 1, r);
        
        merge(A, p, q, r);
    }
}

int main() {
    // Create an unsorted vector
    vector<int> arr = {12, 11, 13, 5, 6, 7, 2, 19, 8};

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array (Merge Sort):   ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
