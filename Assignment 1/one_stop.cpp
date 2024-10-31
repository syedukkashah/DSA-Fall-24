/*
Syed Ukkashah Ahmed Shah
23K-0055
BS(AI) 3-A
DSA Assignment #1

Since the code is complex, I have added comments for readability. Please note that the Resolution log (Stack) & Pending Ticket (queue)
has been implemented with Linked List.

config.txt contains the default_sort, default_search and threshold. The sort can be set to any one of bubble, insertion or selection (elementary sorts).
If threshold (number of tickets) is exceeded then merge sort will be applied (advanced sort)
The search can be be set to any one of binary or interpolation.

The main has been implemented to satisfy the assignment parameters 

*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdlib>
using namespace std;
template <typename T>
void swap(T* a, T* b) { // a template function that swaps any given parameters
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
    Ticket(int priority, int id, string srd, string ts, string ct, string name, bool s)
        : priority(priority), service_req_desc(srd), timestamp(ts), close_time(ct), 
          name(name), status(s), next(nullptr), prev(nullptr), ID(id) {}
    Ticket(const Ticket& other) 
        : priority(other.priority), ID(other.ID), service_req_desc(other.service_req_desc),
          timestamp(other.timestamp), close_time(other.close_time), name(other.name), 
          status(other.status), next(nullptr), prev(nullptr) {
        // Note: next and prev pointers will not be copied, as they are specific to the list structure
    }
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
    void addTicket(int priority, int id, string srd, string ts, string ct, string name, bool s) {
    Ticket* newTicket = new Ticket(priority, id, srd, ts, ct, name, s);
    if (!head)head = newTicket;
    else {
        Ticket* curr = head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = newTicket;
        newTicket->prev = curr;
    }
    Ticket::numTickets++;
}
   void sortByID() { //bubble sort swaps Ticket Tickets 
    bool swapped;
    do {
        swapped = false;
        Ticket* curr = head;
        while (curr && curr->next) {
            if (curr->getID() > curr->next->getID()) {
                // Swap entire Tickets
                int tempID = curr->ID;
                string tempDesc = curr->service_req_desc;
                int tempPriority = curr->priority;
                string tempTimestamp = curr->timestamp;
                string tempCloseTime = curr->close_time;
                string tempName = curr->name;
                bool tempStatus = curr->status;

                curr->ID = curr->next->ID;
                curr->service_req_desc = curr->next->service_req_desc;
                curr->priority = curr->next->priority;
                curr->timestamp = curr->next->timestamp;
                curr->close_time = curr->next->close_time;
                curr->name = curr->next->name;
                curr->status = curr->next->status;

                curr->next->ID = tempID;
                curr->next->service_req_desc = tempDesc;
                curr->next->priority = tempPriority;
                curr->next->timestamp = tempTimestamp;
                curr->next->close_time = tempCloseTime;
                curr->next->name = tempName;
                curr->next->status = tempStatus;

                swapped = true;
            }
            curr = curr->next;
        }
    } while (swapped);
}
bool isSortedByID = false; //to ensure tickets are sorted by ID only once in searching functions
 Ticket* getMiddle(Ticket* start, Ticket* end)
        {
            Ticket* slow = start;
            Ticket* fast = start;
            while(fast!=end && fast->next != end)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        }
        Ticket* searchTicket_binary(int ID)//applying interpolation search
        {
            if(!isSortedByID)
    {
        sortByID(); // Ensure the list is sorted
        isSortedByID = true;
    }
      
            Ticket* start = head;
            Ticket* end = nullptr;
            while(true){
                Ticket* mid = getMiddle(start, end);
                if(!mid) return nullptr;
                if(mid->ID == ID && mid->isOpen()) return mid; //Ticket should be open
                else if(start==end) break;
                else if(mid->ID < ID) start = mid->next;
                else end = mid;
            }
            return nullptr;
        }
Ticket* searchTicket_interpolation(int ID) { //applying interpolation search
    if(!isSortedByID)
    {
        sortByID(); // Ensure the list is sorted
        isSortedByID = true;
    }
    if (!head) return nullptr; // List is empty

    // First, find the last Ticket to establish `high`
    Ticket* low = head;
    Ticket* high = head;

    // Traverse to find the last Ticket
    while (high->next) {
        high = high->next;
    }

    while (low && high && low->getID() <= ID && high->getID() >= ID) {
        // Check if low and high are the same (avoid division by zero)
        if (low == high) {
            if (low->getID() == ID) {
                return low; // Found the ID
            }
            return nullptr; // Not found
        }

        // Calculate the position using interpolation
        int pos = low->getID() + ((ID - low->getID()) * (high->getID() - low->getID()) / (high->getID() - low->getID())) - 1;

        // Traverse to find the mid Ticket based on calculated position
        Ticket* mid = low;
        int count = 0;

        while (mid && count < pos) {
            mid = mid->next;
            count++;
        }

        // If mid is null, the ID is not present
        if (!mid) return nullptr;

        // If the mid Ticket is found (Ticket should be open)
        if (mid->getID() == ID && mid->isOpen()) {
            return mid; // Found the ID
        }

        // Adjust low and high pointers
        if (mid->getID() < ID) {
            low = mid->next; // Move low up
        } else {
            high = mid; // Move high down
        }
    }

    return nullptr; // ID not found
}

    void removeTicket(int ID) {
        Ticket* ticket = searchTicket_interpolation(ID);
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
        Ticket::numTickets--;
    }
   
void bubbleSort(int criteria) {
    if (!head) return; // List is empty

    bool swapped;
    do {
        swapped = false;
        Ticket* curr = head;
        
        while (curr && curr->next) {
            bool condition = false;

            // Compare based on the specified criteria
            if (criteria == 1) { // Sort by priority
                condition = (curr->getPriority() > curr->next->getPriority());
            } else if (criteria == 2) { // Sort by creation time
                condition = (curr->getTimestamp() > curr->next->getTimestamp());
            } else if (criteria == 3) { // Sort by customer name
                condition = (curr->getName() > curr->next->getName());
            }

            // Swap Ticket data if condition is met
            if (condition) {
                swapTicketData(curr, curr->next);
                swapped = true;
            }
            curr = curr->next;
        }
    } while (swapped);

    string criteriaType;
    if(criteria == 1) criteriaType = "priority";
    if(criteria == 2) criteriaType = "creation time";
    if(criteria == 3) criteriaType = "customer name";
    cout << "Tickets sorted by " << criteriaType << " using bubble sort." << endl;
}
void insertionSort(int criteria) {
    if (!head) return; // List is empty

    Ticket* sorted = nullptr; // New sorted list

    Ticket* curr = head;
    while (curr) {
        Ticket* next = curr->next; // Save next Ticket
        Ticket* pos = sorted;
        Ticket* prev = nullptr;

        // Find the correct position in sorted list based on the criteria
        while (pos) {
            bool condition = false;
            if (criteria == 1) { // Sort by priority
                condition = (curr->getPriority() < pos->getPriority());
            } else if (criteria == 2) { // Sort by creation time
                condition = (curr->getTimestamp() < pos->getTimestamp());
            } else if (criteria == 3) { // Sort by customer name
                condition = (curr->getName() < pos->getName());
            }

            if (condition) break; // Correct position found
            prev = pos;
            pos = pos->next;
        }

        // Insert `curr` in sorted list
        if (prev) {
            prev->next = curr;
        } else {
            sorted = curr; // New head of sorted list
        }
        curr->next = pos;
        curr = next; // Move to the next Ticket
    }

    head = sorted; // Set head to sorted list
    string criteriaType;
    if(criteria == 1) criteriaType = "priority";
    if(criteria == 2) criteriaType = "creation time";
    if(criteria == 3) criteriaType = "customer name";
    cout << "Tickets sorted by " << criteriaType << " using insertion sort." << endl;
}

void selectionSort(int criteria) {
    Ticket* curr = head;

    while (curr) {
        Ticket* minTicket = curr;
        Ticket* nextTicket = curr->next;

        while (nextTicket) {
            bool condition = false;

            // Determine the sorting criterion
            if (criteria == 1) { // Sort by priority
                condition = (nextTicket->getPriority() < minTicket->getPriority());
            } else if (criteria == 2) { // Sort by creation time
                condition = (nextTicket->getTimestamp() < minTicket->getTimestamp());
            } else if (criteria == 3) { // Sort by customer name
                condition = (nextTicket->getName() < minTicket->getName());
            }

            if (condition) {
                minTicket = nextTicket;
            }
            nextTicket = nextTicket->next;
        }

        // Swap data between curr and minTicket if necessary
        if (minTicket != curr) {
            swapTicketData(curr, minTicket);
        }
        curr = curr->next;
    }
    string criteriaType;
    if(criteria == 1) criteriaType = "priority";
    if(criteria == 2) criteriaType = "creation time";
    if(criteria == 3) criteriaType = "customer name";
    cout << "Tickets sorted by " << criteriaType << " using selection sort." << endl;
}

// Helper function to swap the data between two Ticket Tickets
void swapTicketData(Ticket* a, Ticket* b) {
    swap(a->ID, b->ID);
    swap(a->service_req_desc, b->service_req_desc);
    swap(a->priority, b->priority);
    swap(a->timestamp, b->timestamp);
    swap(a->close_time, b->close_time);
    swap(a->name, b->name);
    swap(a->status, b->status);
}

// Merges two sorted linked lists based on the specified criteria
Ticket* merge(Ticket* left, Ticket* right, int criteria) {
    if (!left) return right;
    if (!right) return left;

    if (criteria == 1) { // Sort by priority
        if (left->getPriority() <= right->getPriority()) {
            left->next = merge(left->next, right, criteria);
            left->next->prev = left;
            left->prev = nullptr;
            return left;
        } else {
            right->next = merge(left, right->next, criteria);
            right->next->prev = right;
            right->prev = nullptr;
            return right;
        }
    } else if (criteria == 2) { // Sort by creation time
        if (left->getTimestamp() <= right->getTimestamp()) {
            left->next = merge(left->next, right, criteria);
            left->next->prev = left;
            left->prev = nullptr;
            return left;
        } else {
            right->next = merge(left, right->next, criteria);
            right->next->prev = right;
            right->prev = nullptr;
            return right;
        }
    } else if (criteria == 3) { // Sort by customer name
        if (left->getName() <= right->getName()) {
            left->next = merge(left->next, right, criteria);
            left->next->prev = left;
            left->prev = nullptr;
            return left;
        } else {
            right->next = merge(left, right->next, criteria);
            right->next->prev = right;
            right->prev = nullptr;
            return right;
        }
    }
    return nullptr; // Default case
}

// Split the linked list into two halves
void split(Ticket* source, Ticket** frontRef, Ticket** backRef) {
    Ticket* fast;
    Ticket* slow;
    slow = source;
    fast = source->next;

    // Move fast two Tickets and slow one Ticket
    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // Split the list at the middle
    *frontRef = source;
    *backRef = slow->next;
    slow->next = nullptr; // Split the list
}

// Merge sort function
void mergeSort(Ticket** headRef, int criteria) {
    Ticket* head = *headRef;
    Ticket* left;
    Ticket* right;

    // Base case: if the list is empty or has one Ticket
    if (!head || !head->next) {
        return;
    }

    // Split the list into halves
    split(head, &left, &right);

    // Recursively sort the two halves
    mergeSort(&left, criteria);
    mergeSort(&right, criteria);

    // Merge the sorted halves
    *headRef = merge(left, right, criteria);
}

// Wrapper function for mergeSort
void sortTickets(int criteria) {
    mergeSort(&head, criteria);
    string criteriaType;
    if(criteria == 1) criteriaType = "priority";
    if(criteria == 2) criteriaType = "creation time";
    if(criteria == 3) criteriaType = "customer name";
    cout << "Tickets sorted by  " << criteriaType << " using merge sort." << endl;
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
    void printOpenTickets()
    {
        cout<<"\nList of open Tickets: \n";
        Ticket* curr = head;
        while (curr) {
            if(curr->isOpen())
            {
                 cout << "ID: " << curr->getID()
                 << ", Name: " << curr->getName()
                 << ", Priority: " << curr->getPriority()
                 << ", Status: " << (curr->isOpen() ? "Open" : "Closed")
                 << ", Created: " << curr->getTimestamp()
                 << ", Closed: " << curr->getCloseTime() << endl;
            }
            curr = curr->next;
        }
    }
    Ticket* getHead()
    {
        return head;
    }
    Ticket* getNext(Ticket* t)
    {
        return t->next;
    }
    static int getNumTickets()
    {
        return Ticket::numTickets;
    }
    int getID(Ticket* t)
    {
        return t->ID;
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
};
class PendingTicketQueue{//we insert from tail in queue, pop from front
    Ticket *front, *rear; //rear is the tail, front is the head
    public:
    PendingTicketQueue():front(NULL), rear(NULL){}
    bool isEmpty() const{
        return front == NULL;
    }
    void addTickets(List& t) //enqueue function
    {
        Ticket* curr = t.getHead();
        while(curr){
            if(curr->isOpen())
            {
                Ticket* newTicket = new Ticket(*curr); // Create a copy of the ticket for the queue
                newTicket->next = nullptr; // Ensure next is initialized
                if(isEmpty())
            {
                front = rear = newTicket;
                cout << "Ticket ID " << newTicket->getID() << " added to pending queue." << endl;
            }
            else{
                rear->next = newTicket; 
                rear = newTicket; //we adjust the rear (tail) here
                cout << "Ticket ID " << newTicket->getID() << " added to pending queue." << endl;
            }
            }
            curr = t.getNext(curr);
        }
        
    }
   void dequeueTicket() //dequeue function
{ 
    if(isEmpty()) 
    { 
        cout << "No tickets in pending queue." << endl; 
        return; 
    } 
    Ticket* ticket = front; // Get the ticket at the front
    if(front == rear) 
    { 
        cout << "Dequeued Ticket with ID: " << ticket->getID() << " from the queue" << endl; 
        front = rear = NULL; 
    } 
    else 
    { 
        cout << "Dequeued Ticket with ID: " << ticket->getID() << " from the queue\n" << endl; 
        front = front->next; // Move the front to the next ticket
    }
}
    void viewPendingTickets() const{ //function used to view all the tickets in the queue
        cout << "Pending Tickets:" << endl;
        if (isEmpty()) {
            cout << "No pending tickets." << endl;
            return;
        }
        Ticket* curr = front;
        while(curr)
        {
            cout<<"Ticket ID: "<<curr->ID<<endl;
            curr = curr->next;
        }
    }
};
class Agent{
    static int numAgents;
    int ID, totalTickets;
    string name;
    bool availability;
    List ticketList;
    public:
    Agent(string n) : name(n), availability(true), ID(numAgents++), totalTickets(0){}
    bool assignTicket(Ticket* t, PendingTicketQueue& pq, TicketResolutionLog &rl) {
    if (totalTickets >= 5) {
        availability = false;
        cout << name << " is now unavailable." << endl;
        return false;
    }

    if (availability && t->isOpen()) {
        // Create a new ticket using the copy constructor
        Ticket* newTicket = new Ticket(*t);
        
        ticketList.addTicket(newTicket->getPriority(), newTicket->getID(), newTicket->getServiceRequestDescription(), 
                             newTicket->getTimestamp(), newTicket->getCloseTime(), newTicket->getName(), 
                             newTicket->isOpen());

        cout << "Assigned Ticket ID " << t->getID() << " to Agent " << name << endl;
        // Log the resolution of the original ticket
        rl.logResolution(t->getID()); // Log the closed ticket
        t->close(); // Close the original ticket
        pq.dequeueTicket(); // Remove the ticket from the queue
        totalTickets++;
        return true;
    }
    return false;
}
    bool isAvailable(){return availability;}
    void printAgent() {
        cout << "Agent ID: " << ID << ", Name: " << name
             << ", Status: " << (availability ? "Available" : "Unavailable") << endl;
        cout << "Assigned Tickets:" << endl;
        ticketList.printList();
    }
    int getTotalTickets(){return totalTickets;}
    static int getNumAgents(){return numAgents;}
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
    void sortAgentsByTickets() {
        for (int i = 0; i < Agent::getNumAgents() - 1; i++) {
            for (int j = 0; j < Agent::getNumAgents() - i - 1; j++) {
                if (agents[j]->getTotalTickets() < agents[j + 1]->getTotalTickets()) {
                    // Swap agents[j] and agents[j + 1]
                    Agent* temp = agents[j];
                    agents[j] = agents[j + 1];
                    agents[j + 1] = temp;
                }
            }
        }
        cout << "Agents sorted by number of tickets in descending order." << endl;
    }
    Agent** getAgents(){return agents;}
    void assignTickets(List& tickets, PendingTicketQueue& pq, TicketResolutionLog& rl){
     Ticket* curr = tickets.getHead();
     int size = Agent::getNumAgents();
     bool flag = true;
     while(curr){
        Ticket* ticketToAssign = curr;
        bool assigned = false; // Flag to check if the ticket was assigned
        for (int j = 0; j < size; j++) {
            if (getAgents()[j]->isAvailable()) { // Check if the agent is available and if the ticket status is open
                bool flag = agents[j]->assignTicket(ticketToAssign, pq, rl);
                if(flag) assigned = true;
            }
        }
        
        if(!flag) continue;
        if (!assigned) {
            cout << "No available agents for Ticket ID " << ticketToAssign->getID() << ".\n";
        }
        curr = tickets.getNext(curr);
     }
    } 
    void displayAgents() { //displays how many tickets each agent has and general info about the agent
        cout << "Agent Ticket Load:" << endl;
        for (int i = 0; i < agentCount; i++) {
            agents[i]->printAgent();
            cout << "Total Assigned Tickets: " << agents[i]->getTotalTickets() << "\n";
            cout << "----------------------------------" << endl;
        }
    }
    
};
void applySortingFromConfig(List &tickets, int criteria) { //function reads the config file & applies appropriate sorting algorithm
    // Open config.txt
    ifstream configFile("C:/Users/Hp/OneDrive/Desktop/config.txt");
    if (!configFile) {
        cerr << "Error opening configuration file!" << std::endl;
        return;
    }
    cout<<"Config file opened successfully\n"<<endl;
    string line, default_sort;
    int threshold = 10; // Default threshold if not found in file
    // Parse the config file for settings
   while (getline(configFile, line)) {
    if (line.find("default_sort") != string::npos) {
        default_sort = line.substr(line.find("=") + 1);
        default_sort.erase(remove(default_sort.begin(), default_sort.end(), ' '), default_sort.end()); // Remove spaces
    } else if (line.find("threshold") != string::npos) {
        threshold = stoi(line.substr(line.find("=") + 1));
    }
}
    configFile.close();
    int numTickets = tickets.getNumTickets();
    if (numTickets < threshold && default_sort == "bubble") {
        tickets.bubbleSort(criteria); // Use bubble sort
    } else if (numTickets < threshold && default_sort == "selection") {
        tickets.selectionSort(criteria); // Use selection sort
    }
    else if(numTickets < threshold && default_sort == "insertion"){
        tickets.insertionSort(criteria); //use insertion sort
    } else if(numTickets > threshold) {
        tickets.sortTickets(criteria); // Use merge sort if number of tickets exceed the threshold set in config file
    }
}
Ticket* applySearchingFromConfig(List& tickets, int ID) { //function reads the config file & applies appropriate searching algorithm
    ifstream configFile("C:/Users/Hp/OneDrive/Desktop/config.txt");
    if (!configFile.is_open()) { //exception handling for potential file handling errors
        throw runtime_error("Could not open config file.");
    }
    string line, default_search;
    while (getline(configFile, line)) {
        size_t delimiterPos = line.find('=');
        if (delimiterPos != string::npos) {
            string key = line.substr(0, delimiterPos);
            string value = line.substr(delimiterPos + 1);
            if (key == "default_search") {
                default_search = value;
            }
            // You can add more keys here if needed, e.g., default_sort, threshold
        }
    }
    configFile.close();
    if(default_search == "interpolation") 
    {
        cout<<"Applying interpolation search for Ticket ID: "<<ID<<endl;
        Ticket* t = tickets.searchTicket_interpolation(ID);
        return t;
    }
   if(default_search == "binary")
   {
    cout<<"Applying binary search for Ticket ID: "<<ID<<endl;
    Ticket* t = tickets.searchTicket_binary(ID);
    return t;
   } 
    return nullptr;
}
int main() {
     List tickets;
    TicketResolutionLog resolutionLog;
    PendingTicketQueue pendingQueue;
    AgentManagement agentManagement;
    /* Adding tickets (Added 14 tickets which exceeds the threshold (10) that has been set in the config file, 
    hence, merge sort will be used to sort tickets by the criteria of user's choice) */
    tickets.addTicket(3, 5, "Login issues", "2023-10-01 12:00", "17:00", "Alice", true);
    tickets.addTicket(1, 2, "Inquiry about service", "2023-10-02 13:00", "18:00", "Charlie", true);
    tickets.addTicket(2, 4, "Password reset", "2023-10-03 14:00", "15:30", "Bob", true);
    tickets.addTicket(1, 1, "Account locked", "2023-10-04 10:00", "11:00", "Eve", true);
    tickets.addTicket(2, 8, "Billing question", "2023-10-05 09:00", "10:00", "Mallory", true);
    tickets.addTicket(3, 7, "Technical support", "2023-10-06 08:00", "09:00", "Trent", false);  //added some closed tickets to showcase how they aren't considered when adding tickets
    tickets.addTicket(1, 3, "Upgrade inquiry", "2023-10-07 16:00", "17:00", "Oscar", false);
    tickets.addTicket(2, 6, "Refund request", "2023-10-08 15:00", "16:00", "Dave", true);
    tickets.addTicket(1, 9, "Subscription query", "2023-10-09 14:00", "15:00", "Rob", true);
    tickets.addTicket(2, 11, "Feature request", "2023-10-10 13:00", "14:00", "Judy", true);
    tickets.addTicket(3, 10, "Order issue", "2023-10-11 12:00", "13:00", "Peggy", true);
    tickets.addTicket(1, 12, "Service complaint", "2023-10-12 14:30", "15:00", "Jack", true);
    tickets.addTicket(2, 14, "Feedback", "2023-10-12 17:00", "14:00", "Leo", true);
    tickets.addTicket(3, 13, "Technical query", "2023-10-13 12:45", "13:00", "Diego", true);
    
    tickets.printList();
    cout<<"-------------------------------------------\n"<<endl;
    tickets.printOpenTickets();
    cout<<"-------------------------------------------\n"<<endl;
    applySortingFromConfig(tickets, 1); //  sorting by: (1) priority, (2) creation time, (3) customer name
   
    tickets.printList();
    cout<<"-------------------------------------------\n"<<endl;
    pendingQueue.addTickets(tickets); //adding tickets to queue after they have been sorted by priority & creation time

    // Adding agents
    cout<<"-------------------------------------------\n"<<endl;
    agentManagement.addAgent("Smith"); 
    agentManagement.addAgent("Johnson");

    // Assign tickets to agents
    // Loop through the tickets and assign them to agents
    cout<<"-------------------------------------------\n"<<endl;
    agentManagement.assignTickets(tickets, pendingQueue, resolutionLog); //(All agents have a limit of 5 tickets)

    Ticket* searchExample = applySearchingFromConfig(tickets, 2);  //searching ticket to show searching algorithm functionality (since ID 2 was present in the list but is now closed, it will not find Ticket ID 2)
    if(!searchExample) cout<<"Ticket was either closed or ID was not found"<<endl;
    else cout<<"Ticket ID: "<<searchExample->getID()<<" was found"<<endl; 
    cout<<"-------------------------------------------\n"<<endl;
    agentManagement.sortAgentsByTickets();
    cout<<"-------------------------------------------\n"<<endl;
    agentManagement.displayAgents();
    cout<<"-------------------------------------------\n"<<endl;
    // View resolution logs
    resolutionLog.viewLogs();
    cout<<"-------------------------------------------\n"<<endl;
    // View pending tickets
    pendingQueue.viewPendingTickets();
    
    searchExample = applySearchingFromConfig(tickets, 10);
     if(!searchExample) cout<<"Ticket was either closed or ID was not found"<<endl;
    else cout<<"Ticket ID: "<<searchExample->getID()<<" was found"<<endl; //Since Ticket with ID 10 is pending (status:open), it will be found by the appropriate searching algorithm 
    return 0;
}

/*
Time Complexity Analysis:
- Adding a ticket: O(1) for adding to an empty list, O(n) for appending to the end.
- Removing a ticket: O(n) to find the ticket.
- Searching for a ticket: O(n) as we traverse the list.
- Printing the list: O(n).
- Assigning a ticket: O(n) for searching the ticket and O(1) for adding it to the agent's list if found.
- Adding Agents: O(1) per agent, O(m) for m agents
- Sorting Agents: O(m log m)
- Displaying Agents: O(m)
- Logging a resolution: O(1).
- Viewing logs: O(n).
- Managing the pending queue: O(1) for enqueue, O(1) for dequeue.
- Viewing Pending Tickets: O(p)
*/

