#include <iostream>

struct Node {
  int value;
  Node *next;
};

class LinkedList {

private:
  Node *head = nullptr;

public:
  LinkedList() {}

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

  int size() {
    int count = 0;
    Node *current = this->head;

    while (current != nullptr) {
      count += 1;
      current = current->next;
    }
    return count;
  }

  void print() {
    Node *current = this->head;

    while (current != nullptr) {
      std::cout << current->value << std::endl;
      current = current->next;
    }
  }
};

int main() {
  LinkedList *list = new LinkedList;

  list->pushFront(7);
  list->pushFront(3);
  list->pushFront(9);
  list->pushFront(6);
  list->pushFront(5);
  list->pushFront(3);
  std::cout << "List size: " << list->size() << std::endl;

  std::cout << "Popped value: " << list->popFront()->value << std::endl;
  std::cout << "List size: " << list->size() << std::endl;
  list->print();
}
