#include <iostream>
using namespace std;
class Exam {
private:
    string *name;
    int *score, *date;
public:
    Exam() : name(nullptr), score(nullptr), date(nullptr) {}
    void setName(string name) {
        delete this->name;
        this->name = new string(name);
    }
    void setScore(const int score) {
        delete this->score;
        this->score = new int(score);
    }
    void setDate(int date) {
        delete this->date;
        this->date = new int(date);
    }
    inline void display() const {
        cout << "Name : " << *name
             << "\nScore: " << *score
             << "\nDate : " << *date
             << endl; 
    }
};
int main() {
    Exam test1;
    test1.setName("Ukkashah");
    test1.setScore(92);
    test1.setDate(8);
    Exam test2(test1);
    test1.display();
    test2.display();
    test2.setName("Ahmed");
    cout<<"\nafter setting new name to test2"<<endl;
    test1.display();
    test2.display();
    return 0;
}