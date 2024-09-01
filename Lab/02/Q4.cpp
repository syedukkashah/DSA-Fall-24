#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
float** init_courses() {
    int row = 4;
    float** arr = new float*[row];
    srand(static_cast<unsigned>(time(0)));

    for (size_t i = 0; i < row; i++) {
        arr[i] = new float[row - i];
        for (size_t j = 0; j < row - i; j++) {
           arr[i][j] = float(rand() % 4 + 1); 
        }
    }
    return arr;
}

void printArr(float** arr, int row) {
    for (size_t i = 0; i < row; i++) {
        if (i==0) cout<<"AI Core Course GPAs: ";
        if (i==1) cout<<"SE Core Course GPAs: ";
        if (i==2) cout<<"CS Core Course GPAs: ";
        if (i==3) cout<<"DS Core Course GPAs: ";
        for (size_t j = 0; j < row - i; j++) {
            cout << arr[i][j]<< " ";
        }
        cout << endl;
    }
}

int main() {
    float** jaggedArr = init_courses();
    printArr(jaggedArr, 4);
    for (int i = 0; i < 4; i++) {
        delete[] jaggedArr[i];
    }
    delete[] jaggedArr;
    return 0;
}
