#include "iostream"
#include "matrix_multiply.h"
using namespace std;
int main()
{
    int** a = new int*[2], cnt = 0;
    for (size_t i = 0; i < 3; i++) a[i] = new int[3];
    int** b = new int*[3];
    for (size_t i = 0; i < 3; i++) b[i] = new int[2];
    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 3; j++) a[i][j] = cnt++;
    }
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 2; j++) b[i][j] = cnt++;
    }
    int** product_matrix = matrix_mul(a,b,2,3,3,2);
    print(product_matrix, 2, 2);
}