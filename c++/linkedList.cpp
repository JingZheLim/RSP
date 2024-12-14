// C++ implementation of Linked List
#include <iostream>
using namespace std;

struct Node {
  int data;    // data
  Node* next;  // pointer to next item
};

class linkedList {
 public:
  Node* head;
  linkedList() { this->head = nullptr; }
  bool search(Node* head, int value);
  void insertAtBegin(int value);
  bool deleteItem(Node* head, int value);
};

// searches if value is in list O(n) time, O(n) space
bool linkedList::search(Node* head, int value) {
  // base case
  if (head == nullptr) {
    return false;
  }
  // check node if is value
  if (head->data == value) {
    return true;
  }
  // go to the next node
  return search(head->next, value);
}

// inserts data at the begining of the list O(1) time, O(1) space
void linkedList::insertAtBegin(int value) {
  // create a new node
  Node* newNode = new Node();
  // set new node's data to value
  newNode->data = value;
  // set new node to point to the head node's address
  newNode->next = head;
  // change the head node to the new node
  head = newNode;
}

// deletes node given a value O(n) time, O(1) space
bool linkedList::deleteItem(Node* head, int value) {
  // Check if list is empty
  if (head == nullptr) {
    return false;
  }

  // If value is at head node
  if (head->data == value) {
    Node* temp = head;
    head = head->next;
    delete temp;
    return true;
  }

  Node* curr = head;
  Node* prevNode = nullptr;

  // Traverse to node with the value
  while (curr != nullptr) {
    // if the current node data == value
    if (curr->data == value) {
      // set previousNode's next pointer point to current node's next pointer
      prevNode->next = curr->next;
      // delete current node
      delete curr;
      return true;
    }
    // else make current node as the new previous node
    prevNode = curr;
    // move onto the next node
    curr = curr->next;
  }
  return false;  // value not found
}

int main() { // AI Generated
  // Create a new linked list
  linkedList list;

  // Insert some elements at the beginning
  cout << "Inserting elements:" << endl;
  list.insertAtBegin(30);
  list.insertAtBegin(20);
  list.insertAtBegin(10);

  // Search for existing elements
  cout << "Searching for elements:" << endl;
  cout << "Search for 20: "
       << (list.search(list.head, 20) ? "Found" : "Not Found") << endl;
  cout << "Search for 40: "
       << (list.search(list.head, 40) ? "Found" : "Not Found") << endl;

  // Delete an element
  cout << "Deleting elements:" << endl;
  cout << "Delete 20: "
       << (list.deleteItem(list.head, 20) ? "Deleted" : "Not Deleted")
       << endl;

  // Search again after deletion
  cout << "Search for 20 after deletion: "
       << (list.search(list.head, 20) ? "Found" : "Not Found") << endl;

  return 0;
}
