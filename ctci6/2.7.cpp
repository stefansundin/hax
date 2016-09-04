#include <iostream>
using namespace std;

class Node {
public:
  int value;
  Node *next;
  Node(int v): value(v), next(NULL) { }
  Node(int v, Node *n): value(v), next(n) { }
};

void PrintNode(Node *n) {
  if (n == NULL) {
    cout << "NULL" << endl;
  }
  else {
    cout << n->value << endl;
  }
}

void PrintList(Node *head) {
  while (head != NULL) {
    cout << head->value << " ";
    head = head->next;
  }
  cout << endl;
}

bool IsIntersecting(Node *a, Node *b) {
  while (a->next != NULL) {
    a = a->next;
  }
  while (b->next != NULL) {
    b = b->next;
  }
  return (a == b);
}

Node* IntersectingNode(Node *a, Node *b) {
  int len_a = 0;
  int len_b = 0;
  for (Node *t=a; t->next != NULL; t=t->next) {
    len_a++;
  }
  for (Node *t=b; t->next != NULL; t=t->next) {
    len_b++;
  }
  if (len_a > len_b) {
    for (; len_b < len_a; len_b++) {
      a = a->next;
    }
  }
  else {
    for (; len_a < len_b; len_a++) {
      b = b->next;
    }
  }
  if (a == b) {
    return a;
  }
  return NULL;
}

int main() {
  Node *a = new Node(10, new Node(5, new Node(10, new Node(3, new Node(5, new Node(10, new Node(3)))))));
  Node *b = new Node(6, new Node(2, new Node(1, a)));
  Node *c = new Node(6, new Node(2, new Node(1)));
  PrintList(a);
  PrintList(b);
  cout << "IsIntersecting? " << IsIntersecting(a,b) << endl;
  cout << "IntersectingNode: ";
  PrintNode(IntersectingNode(a,b));
  PrintList(c);
  cout << "IsIntersecting? " << IsIntersecting(b,c) << endl;
  cout << "IntersectingNode: ";
  PrintNode(IntersectingNode(b,c));
}
