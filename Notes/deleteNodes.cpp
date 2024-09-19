      node* deleteNodes(node* head, int n) {
    // Handle the case where the head node itself needs to be deleted
    while (head && head->data > n) {
        node* temp = head;
        head = head->next;
        delete temp;  // Free the memory for the deleted node
    }
    
    // If the list is now empty, return null
    if (!head) return nullptr;
    
    node* curr = head;

    // Traverse the list, deleting nodes where the data is greater than 'n'
    while (curr && curr->next) {
        if (curr->next->data > n) {
            node* temp = curr->next;
            curr->next = curr->next->next;  // Bypass the node to delete
            delete temp;  // Free the memory for the deleted node
        } else {
            curr = curr->next;  // Move to the next node
        }
    }
    return head;  
}
