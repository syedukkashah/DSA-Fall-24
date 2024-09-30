#include "iostream"
using namespace std;
class node{
    int data;
    node* next;
    public:
    node():data(0), next(NULL){}
    node(const int d): data(d), next(NULL){}
    friend class SLL;
};
class SLL{
    node* head;
    public:
    SLL():head(NULL){}
    SLL(node* n): head(n){}
    void insertAtFront(const int val){
        node* n = new node(val);
        if(head==NULL) head = n;
        else{
	        n->next = head;
	        head = n;
        }
    }
    void insertAtTail(const int val)
    {
        node* n = new node(val);
        if(head==NULL) head = n;
        else{
	        node* current = head;
	        while(current->next != NULL){current = current->next;} 
	        current->next = n;
        }
    }
    void InsertAfterValue(const int value, const int insertingValue)
    {
		node* n = new node(insertingValue);
		if(head==NULL){head = n;}
		else{
			node* currentPtr = head;
			while(currentPtr->data!= value){currentPtr = currentPtr->next;}
			node* temp = currentPtr->next;
			currentPtr->next = n;
			n->next = temp;
	        }
    }
    void InsertBeforeValue(const int value, const int insertingValue)
    {
    	node* n = new node(insertingValue);
    	if(head==NULL){head = n;}
    	else{
    		node* currentPtr = head;
    	    while(currentPtr->next->data!=value){currentPtr = currentPtr->next;} 
    	    n->next = currentPtr->next;
		    currentPtr->next = n;
		}
	}
	int numNodes()
	{
		int nodes=0;
		node* currentPtr = head;
		while(currentPtr!=NULL){
			nodes++;
			currentPtr = currentPtr->next;
		}
		return nodes;
	}
	void deleteFromHead()
	{
		if(head!=NULL){
			node* currPtr = head;
			head = currPtr->next;
			delete currPtr;
			currPtr = NULL;
	    }
	    else{
	    	cout<<"Linked list not found"<<endl;
		}
	}
	void deleteFromTail()
	{
		if(head!=NULL){
			node* currPtr = head;
			while(currPtr->next->next!=NULL){currPtr = currPtr->next;}
			delete currPtr->next;
			currPtr->next = NULL;
	    }
	    else{
	    	cout<<"Linked list not found"<<endl;
		}
	}
	void deleteValue(const int value)
	{
		if (head == NULL) {
            cout << "Linked list is empty" << endl;
            return;
        }
		node* n = head;
		while(n->next->data!=value){n = n->next;}
		node* temp = n->next;
		n->next = n->next->next;
		delete temp;
		temp = NULL; 
	}
	void printList()
	{
		node* currentPtr = head;
		while(currentPtr!=NULL)
		{
			cout<<currentPtr->data<<" ";
			currentPtr=currentPtr->next;
		}
	}
};
int main() {
    SLL list;
    // Inserting elements at the front
    list.insertAtFront(10);
    list.insertAtFront(20);
    list.insertAtFront(30);
    cout << "After inserting at front:"<<endl;
    list.printList();
    list.insertAtTail(40);
    list.insertAtTail(50);
    list.insertAtTail(60);
    // Inserting elements at the back
    cout << "\nAfter inserting at tail:"<<endl;
    list.printList();
	cout<<"\nTotal nodes in list: "<<list.numNodes()<<endl;
    list.deleteFromHead();
	cout << "\nAfter deleting from head:"<<endl;
    cout<<"\n";
    list.printList();
    list.deleteFromTail();
	cout << "\nAfter deleting from tail:"<<endl;
    cout<<"\n";
    list.printList();
	list.deleteValue(40);
	cout<<"\nAfter deleting value:"<<endl;
	list.printList();
	list.InsertAfterValue(20, 11);
	cout << "\nInserted value after 20:"<<endl;
	list.printList();
	list.InsertBeforeValue(50, 22);
	cout << "\nInserted value before 50:"<<endl;
	list.printList();
    list.deleteValue(40);
    cout<<"\nAfter deleting value:"<<endl;
    list.printList();
    list.InsertAfterValue(20, 11);
    cout << "\nInserted value after 20:"<<endl;
    list.printList();
    list.InsertBeforeValue(50, 22);
    cout << "\nInserted value before 50:"<<endl;
    list.printList();
    return 0;	
}
