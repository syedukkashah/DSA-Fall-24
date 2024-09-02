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
		for(node* currentPtr = head; currentPtr->next!=NULL;currentPtr = currentPtr->next){nodes++;}
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
			node* currPtr;
			for(node* currPtr = head; currPtr->next!=NULL; currPtr = currPtr->next){}
			delete currPtr;
			currPtr = NULL;
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
		cout<<"List: "<<endl;
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
    cout << "After inserting at front: ";
    list.printList();
    list.insertAtTail(40);
    list.insertAtTail(50);
    list.insertAtTail(60);
    // Inserting elements at the back
    cout << "\nAfter inserting at tail: ";
    list.printList();
    list.deleteFromHead();
    cout<<"\n";
    list.printList();
    list.deleteFromTail();
    cout<<"\n";
    list.printList();
    return 0;	
}
