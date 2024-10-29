#include "iostream"
using namespace std;
template <typename T>
void swap(T* a, T* b) {
    T* temp = a; 
    *a = *b;
    *b = *temp;
}

class Ticket {
    Ticket* next,*prev;
    static int numTickets;
    int ID,priority;
    string service_req_desc,timestamp,close_time,name; 
    bool status;
public:
    Ticket(int priority, string srd, string ts, string ct, string name, bool s)
        : priority(priority), service_req_desc(srd), timestamp(ts), close_time(ct), 
          name(name), status(s), next(nullptr), prev(nullptr), ID(numTickets++) {}
    static int getNumTickets(){return numTickets; }
    int getID() const { return ID; }
    int getPriority() const { return priority; }
    string getServiceRequestDescription() const { return service_req_desc; }
    string getTimestamp() const { return timestamp; }
    string getCloseTime() const { return close_time; }
    string getName() const { return name; }
    bool isOpen() const { return status; }
    void close() { status = false; }
    friend class List;
    friend class PendingTicketQueue;
};
int Ticket::numTickets = 0; 
class List {
    Ticket* head;
public:
    List() : head(nullptr) {}
    void addTicket(int priority, string srd, string ts, string ct, string name, bool s) {
        Ticket* newTicket = new Ticket(priority, srd, ts, ct, name, s);
        if (!head) {
            head = newTicket;
        } else {
            Ticket* curr = head;
            while (curr->next) {
                curr = curr->next;
            }
            curr->next = newTicket;
            newTicket->prev = curr;
        }
        cout << "Added Ticket to List" << endl;
    }
    Ticket* searchTicket(int ID) {
        Ticket* curr = head;
        while (curr) {
            if (curr->ID == ID) return curr;
            curr = curr->next;
        }
        return nullptr;
    }
    void removeTicket(int ID) {
        Ticket* ticket = searchTicket(ID);
        if (!ticket) {
            cout << "Ticket not found" << endl;
            return;
        }
        if (ticket->prev) {
            ticket->prev->next = ticket->next;
        } else {
            head = ticket->next; 
        }
        if (ticket->next) {
            ticket->next->prev = ticket->prev;
        }
        delete ticket;
        cout << "Removed Ticket with ID: " << ID << " from the list" << endl;
    }
       void swapTicket(Ticket* a, Ticket* b) {
        if (a == b) return;
        swap(a->priority, b->priority);
        swap(a->service_req_desc, b->service_req_desc);
        swap(a->timestamp, b->timestamp);
        swap(a->close_time, b->close_time);
        swap(a->name, b->name);
        bool temp = a->status;
        a->status = b->status;
        b->status = temp;
    }
    void sortTickets(int criteria) {
        if (!head) return;

        bool swapped;
        do {
            swapped = false;
            Ticket* curr = head;
            while (curr && curr->next) {
                bool condition = false;
                if (criteria == 1) { // Sort by priority
                    condition = (curr->getPriority() > curr->next->getPriority());
                } else if (criteria == 2) { // Sort by creation time
                    condition = (curr->getTimestamp() > curr->next->getTimestamp());
                } else if (criteria == 3) { // Sort by customer name
                    condition = (curr->getName() > curr->next->getName());
                }

                if (condition) {
                    swapTicket(curr, curr->next);
                    swapped = true;
                }
                curr = curr->next;
            }
        } while (swapped);
        cout << "Tickets sorted." << endl;
    }

    void printList() {
        Ticket* curr = head;
        while (curr) {
            cout << "ID: " << curr->getID()
                 << ", Name: " << curr->getName()
                 << ", Priority: " << curr->getPriority()
                 << ", Status: " << (curr->isOpen() ? "Open" : "Closed")
                 << ", Created: " << curr->getTimestamp()
                 << ", Closed: " << curr->getCloseTime() << endl;
            curr = curr->next;
        }
    }
    Ticket* getHead()
    {
        return head;
    }
    int getNumTickets()
    {
        Ticket* curr = head;
        while(curr) curr = curr->next;
        return curr->ID+1;
    }
    int getID(Ticket* t)
    {
        return t->ID;
    }
    ~List() {
        while (head) {
            Ticket* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
class TicketID{
    TicketID* next;
    int ID;
    public:
    TicketID(int id):next(NULL),ID(id){}
    friend class TicketResolutionLog;
};
class TicketResolutionLog{
    TicketID* head;
    public:
    TicketResolutionLog():head(nullptr){}
    bool isEmpty() const{
        return head == nullptr;
    }
    void logResolution(int ticketID) //pushing ID
    {
        TicketID* t = new TicketID(ticketID);
        if (isEmpty())
        {
            head = t;
             cout << "Transaction logged: Ticket ID " << ticketID << " closed." << endl;
            return;
        }
        t->next = head;
        head = t;
        cout << "Transaction logged: Ticket ID " << ticketID << " closed." << endl;
    }
    void pop()
    {
        if(isEmpty())
        {
            cout<<"stack underflow "<<endl;
            return;
        }
        TicketID* temp = head;
        head = head->next;
        cout<<"popped Ticket with ID"<<temp->ID<<" from the stack"<<endl;
        delete temp;
    }
    void viewLogs()
    {
        cout << "Resolution Logs (most recent first):" << endl;
        if(isEmpty())
        {
            cout << "No resolution logs available." << endl;
            return;
        }
        TicketID* curr = head;
        while(curr)
        {
            cout<<"Ticket ID: "<<curr->ID<<endl;
            curr = curr->next;
        }
    }
    int peek() const{
        if(isEmpty()) return -1;
        return head->ID;
    }
};
class PendingTicketQueue{//we insert from tail in queue, pop from front
    Ticket *front, *rear; //rear is the tail, front is the head
    public:
    PendingTicketQueue():front(NULL), rear(NULL){}
    bool isEmpty() const{
        return front == NULL;
    }
    void addTicket(Ticket* t) //enqueue function
    {
        if(isEmpty())
        {
            front = rear = t;
            cout << "Ticket ID " << t->getID() << " added to pending queue." << endl;
            return;
        }
        else{
            rear->next = t; 
            rear = rear->next; //we adjust the rear (tail) here
            cout << "Ticket ID " << t->getID() << " added to pending queue." << endl;
        }
    }
    Ticket* assignTicket()
    {
        if(isEmpty())
        {
            cout << "No tickets in pending queue." << endl;
            return NULL;
        }
        Ticket* ticket = peek();
        if(front==rear)
        {
            cout<<"dequeued Ticket with ID: "<<ticket->getID()<<" from the queue"<<endl;
            front = rear = NULL;
            return ticket;
        }
        Ticket* temp = front; 
        cout<<"dequeued Ticket with ID: "<<ticket->getID()<<" from the queue"<<endl;
        front = front->next; //head is adjusted here
        delete temp;
        return ticket;
    }
    Ticket* peek()
    {
        if(isEmpty())
        {
            cout << "No tickets in pending queue." << endl;
            return NULL;
        }
        return front;
    }
    void viewPendingTickets() const{
        cout << "Pending Tickets:" << endl;
        if (isEmpty()) {
            cout << "No pending tickets." << endl;
            return;
        }
        Ticket* curr = rear;
        while(curr)
        {
            cout<<"Ticket ID: "<<curr->ID<<endl;
            curr = curr->next;
        }
    }
};
class Agent{
    static int numAgents;
    int ID;
    string name;
    bool availability;
    List ticketList;
    public:
    Agent(string n) : name(n), availability(true), ID(numAgents++){}
    void assignTicket(Ticket* t, PendingTicketQueue pq)
    {
        if(availability && t->isOpen())
        {
            ticketList.addTicket(t->getPriority(), t->getServiceRequestDescription(), t->getTimestamp(), t->getCloseTime(),
            t->getName(), t->isOpen());
            t->close();
            pq.addTicket(t);
            cout << "Assigned Ticket ID " << t->getID() << " to Agent " << name << endl;
            // Mark as unavailable if max capacity is reached (e.g., 5 tickets)
            if (ticketList.getNumTickets() >= 5) {
                availability = false;
                cout << name << " is now unavailable." << endl;
            }
        }
    }
    void printAgent() {
        cout << "Agent ID: " << ID << ", Name: " << name
             << ", Status: " << (availability ? "Available" : "Unavailable") << endl;
        cout << "Assigned Tickets:" << endl;
        ticketList.printList();
    }
    static int getNumAgents() {
        return numAgents;
    }
};
int Agent:: numAgents;
class AgentManagement{
    int agentCount;
    Agent** agents;
    public:
    AgentManagement():agentCount(0){
        agents = new Agent*[100];
    }
    void addAgent(string name)
    {
        if(agentCount<100){
            agents[agentCount++] = new Agent(name);
            cout<<"Added agent: "<<name<<endl;
        }
        else cout<<"Agent capacity reached. Can't add more agents."<<endl;
    }
};
int main() {
     List tickets;
    TicketResolutionLog resolutionLog;
    PendingTicketQueue pendingQueue;

    // Adding tickets
    tickets.addTicket(1, "Issue with login", "2023-10-01 12:00", "17:00", "Alice", true);
    tickets.addTicket(3, "General inquiry", "2023-10-02 13:00", "18:00", "Charlie", true);
    tickets.addTicket(2, "Need assistance with payment", "2023-10-03 14:00", "15:30", "Bob", true);

    // Add tickets to the pending queue
    Ticket* ticketToAssign = tickets.searchTicket(1);
    if (ticketToAssign) {
        pendingQueue.addTicket(ticketToAssign);
    }
    
    // Assign the ticket to an agent
    Agent agent("Agent Smith");
    agent.assignTicket(ticketToAssign, pendingQueue);

    // Close the ticket and log the resolution
    if (!pendingQueue.isEmpty()) {
        Ticket* closedTicket = pendingQueue.assignTicket();
        resolutionLog.logResolution(closedTicket->getID());
        closedTicket->close();
    }

    // View resolution logs
    resolutionLog.viewLogs();

    // View pending tickets
    pendingQueue.viewPendingTickets();

    return 0;
}
