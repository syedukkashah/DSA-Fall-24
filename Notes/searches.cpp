#include "iostream"
using namespace std;
class searching{
    public:
    int binary(int* arr, int size, int target) //to be performed over a sorted array
    {
        int low = 0, high = size - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if(arr[mid] == target) return mid;
            if(arr[mid]>target) high = mid - 1; //high is lowered to mid - 1 if mid idx is greater than target
            if(arr[mid]<target) low = mid+1; // low is increased to mid + 1 if mid idx is lower than target
        }
        cout<<"target not found"<<endl;
        return -1;
    }
    int interpolation(int* arr, int size, int target)
    {
        int low = 0, high = size - 1;
        while (low <= high) {
            int pos = low + (((target - arr[low])*(high - low)) / (arr[high] - arr[low]));
            if(arr[pos] == target) return pos;
            if(arr[pos]<target) low = pos+1;
            if(arr[pos]>target) high = pos-1;
        }
        return -1;
    }
};
