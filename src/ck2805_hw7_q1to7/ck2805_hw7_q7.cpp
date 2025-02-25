#include <iostream>

using namespace std;


int* findMissing(int arr[], int n, int& resArrSize) {
    int* counts = new int[n + 1];
    for (int i = 0; i <= n; i++) {
        counts[i] = 0; 
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0 && arr[i] <= n) { 
            counts[arr[i]]++;
        }
    }

    int missingCount = 0;
    for (int i = 0; i <= n; i++) {
        if (counts[i] == 0) {
            missingCount++;
        }
    }

    resArrSize = missingCount;
    int* resArr = new int[resArrSize];

    int resIndex = 0;
    for (int i = 0; i <= n; i++) {
        if (counts[i] == 0) {
            resArr[resIndex++] = i;
        }
    }

    delete[] counts; 
    counts = nullptr;

    return resArr;
}

int main() {
    int arr[] = {3, 1, 3, 0, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int resArrSize;

    int* missingNumbers = findMissing(arr, n, resArrSize);

    cout << "Missing numbers: ";
    for (int i = 0; i < resArrSize; i++) {
        cout << missingNumbers[i] << " ";
    }
    cout << endl;

    delete[] missingNumbers;
    missingNumbers = nullptr;

    return 0;
}