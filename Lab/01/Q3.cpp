#include "iostream"
using namespace std;
class Document{
    public:
    string* text;
    Document(string txt): text(new string(txt)){};
    ~Document(){delete text;}
    Document(Document &obj)
    {
        text = NULL;
        text = new string(*obj.text);
    }
    Document& operator = (const Document& other)
    {
        if(this!= &other) *text = *other.text;
        return *this;
    }
    string getText() const{return *text;}
    void setText(const string txt)
    {
        text = NULL;
        text = new string(txt);
    }
};
int main()
{
    Document d1("doc1 text");
    cout<<"Doc 1 text before making copies: "<< d1.getText()<<endl;
    Document d2 = d1;
    Document d3(d1);
    d1.setText("doc1 text edited");
    cout<<"Doc 1 text after editing text content: "<< d1.getText()<<endl;
    cout<<"Doc 2 text: "<< d2.getText()<<endl;
    cout<<"Doc 3 text: "<< d3.getText()<<endl;
   return 0;
}