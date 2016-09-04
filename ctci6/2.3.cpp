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

void DeleteNode(Node *n) {
  while (n->next != NULL) {
    n->value = n->next->value;
    n = n->next;
  }
}

int main() {
  Node *head = new Node(10, new Node(5, new Node(10, new Node(3, new Node(5, new Node(10, new Node(3)))))));
  PrintList(head);
  DeleteNode(head->next->next);
  PrintList(head);
}
