#include <iostream>

struct Node {
  int value;
  Node *next;
};

class LinkedList {

private:
  Node *head = nullptr;

public:
  // LinkedList() {} This can be done like the way below because head already
  // has a default member initialiser
  LinkedList() = default;
  // This prevents copying. Currently if I were to copy without these, it'd be a
  // shallow copy so they'd all point to the same nodes and both destructors
  // would try to delete them
  LinkedList(const LinkedList &) = delete;
  LinkedList &operator=(const LinkedList &) = delete;

  void pushFront(int value) {
    Node *newNode = new Node{value, this->head};
    this->head = newNode;
  }

  Node *popFront() {
    if (this->head == nullptr) {
      return nullptr;
    }

    Node *poppedNode = this->head;
    this->head = this->head->next;

    poppedNode->next = nullptr;

    return poppedNode;
  }

  // Because these methods don't change the actual linked list they can be const
  int size() const {
    int count = 0;
    const Node *current = this->head;

    while (current != nullptr) {
      ++count;
      current = current->next;
    }
    return count;
  }

  void print() const {
    // Const is allowed for these because changing the pointer is fine, but
    // const prevents changing the value or next pointer
    const Node *current = this->head;

    while (current != nullptr) {
      std::cout << current->value << std::endl;
      current = current->next;
    }
  }

  // Destructor to remove the linked list out of memory
  ~LinkedList() {
    Node *current = head;

    while (current != nullptr) {
      Node *nextNode = current->next;
      delete current;
      current = nextNode;
    }
  }
};

int main() {
  // LinkedList *list = new LinkedList; Can be done like the way below, doesn't
  // require explicit call of the destructor
  LinkedList list;

  list.pushFront(7);
  list.pushFront(3);
  list.pushFront(9);
  list.pushFront(6);
  list.pushFront(5);
  list.pushFront(3);
  std::cout << "List size: " << list.size() << std::endl;

  // std::cout << "Popped value: " << list->popFront()->value << std::endl;
  // Doesn't delete the popped node from memory causing leak
  // Bottom does and also is safe from getting a nullptr error if list is empty
  Node *poppedNode = list.popFront();

  if (poppedNode != nullptr) {
    std::cout << "Popped value: " << poppedNode->value << std::endl;
    delete poppedNode;
  }

  std::cout << "List size: " << list.size() << std::endl;
  list.print();
}
