#include "iostream"
using namespace std;
int binarySearch(int arr[], int target, int low, int high) {
    if (low > high) {
        return -1; // not found
    }
    int mid = (low + high) / 2;
    if (arr[mid] == target) {
        return mid; // found
    } else if (arr[mid] < target) {
        return binarySearch(arr, target, mid + 1, high);
    } else {
        return binarySearch(arr, target, low, mid - 1);
    }
}
int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int target = 5;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 5, 0, n-1);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in array" << endl;
    }
    return 0;
}
