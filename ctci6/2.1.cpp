#include <iostream>
using namespace std;

class Node {
public:
  int value;
  Node *next;
  Node(int v): value(v), next(NULL) { }
  Node(int v, Node *n): value(v), next(n) { }
};

void PrintList(Node *head) {
  while (head != NULL) {
    cout << head->value << " ";
    head = head->next;
  }
  cout << endl;
}

void RemoveDup1(Node *head) {
  Node *first = head;
  while (head->next != NULL) {
    cout << "checking " << head->next->value << endl;
    Node *n = first;
    while (n != head->next) {
      if (n->value == head->next->value) {
        // found a dup, unlink
        cout << "removing " << head->next->value << endl;
        head->next = head->next->next;
        break;
      }
      n = n->next;
    }
    if (n == head->next) {
      head = head->next;
    }
  }
}

void RemoveDup2(Node *head) {
  Node *first = head;
  while (head->next != NULL) {
    cout << "checking " << head->next->value << endl;
    Node *n = first;
    bool dup = false;
    while (n != head->next) {
      if (n->value == head->next->value) {
        // found a dup, unlink
        cout << "removing " << head->next->value << endl;
        head->next = head->next->next;
        dup = true;
        break;
      }
      n = n->next;
    }
    if (!dup) {
      head = head->next;
    }
  }
}

int main() {
  Node *head = new Node(10, new Node(5, new Node(10, new Node(3, new Node(5, new Node(10, new Node(3)))))));
  PrintList(head);
  RemoveDup2(head);
  PrintList(head);
}
