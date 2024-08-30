#include "iostream"
using namespace std;
int main()
{
    int **arr = new int*[3]; 
    int Size[3];
    int i,j,k;
    for(i=0;i<3;i++){
        cout<<"Row "<<i+1<< " size: ";
        cin>>Size[i];
        if (Size[i]!=10) Size[i] = 10; //resizing arr to 10 
        arr[i] = new int[Size[i]];
    }
    for(i=0;i<3;i++){
        for(j=0;j<Size[i];j++){ 
            cout<<"Enter row " <<i+1<<" elements: "; 
            cin>>*(*(arr + i)+ j);
        }
    }
for (size_t i = 0; i < 3; i++)
{
    for (size_t j = 0; j < Size[i]; j++) cout<<"element at ["<< i<<"]["<<j<<"]: "<<arr[i][j]<<endl;
}
delete[] arr;
}