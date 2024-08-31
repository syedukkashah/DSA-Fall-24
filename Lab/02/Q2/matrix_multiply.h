#include "iostream"
using namespace std;
int** matrix_mul(int** arr, int** arr2, unsigned r1, unsigned c1, unsigned r2, unsigned c2)
{
    int** result = new int*[r1];
    for (int i = 0; i < r1; i++) result[i] = new int(0);
    if(c1 == r2)
    {
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                for (int k = 0; k < c1; k++)
                {
                    result[i][j]+= arr[i][k]*arr2[k][j];
                }
            }
       }
       return result;
    }
   return nullptr;
}
void print(int** arr, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++){
            cout<<"["<<arr[i][j]<<"]";
        }
        cout<<endl;
    }
    
}