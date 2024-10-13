#include "iostream"
using namespace std;
class Runner {
public:
    int time;
    string name;
};
void merge(Runner* arr, int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0;
    Runner* temp = new Runner[high - low + 1];
    while (i <= mid && j <= high) {
        if (arr[i].time <= arr[j].time) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= mid) {
        temp[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        temp[k] = arr[j];
        k++;
        j++;
    }
    for (int idx = 0; idx < k; idx++) arr[low + idx] = temp[idx];
    delete[] temp; 
}
void mergeSort(Runner* arr, int low, int high) {
    if (low >= high) return;

    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main() {
    Runner runners[10];
    for (int i = 1; i <= 10; i++) {
        cout << "Enter name for runner " << i << ": ";
        cin.ignore(); 
        getline(cin, runners[i - 1].name);
        cout << "Enter time for runner " << i << " (in seconds): ";
        cin >> runners[i - 1].time;
    }
    mergeSort(runners, 0, 9);
    cout << "\nTop 5 Fastest Runners:\n";
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << runners[i].name << " - " << runners[i].time << " seconds" << endl;
    }
    return 0;
}
