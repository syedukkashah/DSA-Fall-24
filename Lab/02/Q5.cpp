#include "iostream"
#include <cstdlib>
#include <ctime>
#define ROW 3
using namespace std;
string names[][4] = {
        {"Alice", "Bob", "Charlie", "David"},
        {"Eve", "Frank", "Grace", "Hank"},
        {"Ivy", "Chase", "Peter", "Catherine"}
};
string** init_seats(int* seat_cnt) {
    string** arr = new string*[ROW]; //using jagged array
    srand(static_cast<unsigned>(time(0)));
    for (size_t i = 0; i < ROW; i++){
        int seatsInRow = rand()%4 + 1;
        arr[i] = new string[seatsInRow];
        seat_cnt[i] = seatsInRow;
        for (size_t j = 0; j < seatsInRow; j++) arr[i][j] = names[i][j];
    }
    return arr;
}
void print_seating_chart(string** arr, int* seat_cnt) {
    for (size_t i = 0; i < ROW; i++) {
        cout << "Row " << i + 1 << ": ";
        for (size_t j = 0; j < seat_cnt[i]; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl; 
    }
}
int main()
{
    int seatCount[3];
    string** seats = init_seats(seatCount);
    print_seating_chart(seats, seatCount);
    return 0;
}