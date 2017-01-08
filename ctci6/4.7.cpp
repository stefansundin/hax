// g++ -std=c++11 -g 4.7.cpp && ./a.out
#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
  char value;
  vector<Node*> nodes;
  bool built;

  bool printed;

  Node(char v) {
    value = v;
    built = printed = false;
  }
  void add(Node *n) {
    nodes.push_back(n);
  }
  bool buildable() {
    for (int i=0; i < nodes.size(); i++) {
      if (!nodes[i]->built) {
        return false;
      }
    }
    return true;
  }
};

void printGraph(Node *n) {
  if (n == NULL) {
    cout << "NULL";
    return;
  }
  cout << n->value;
  if (n->printed) {
    cout << "*";
  }
  else {
    n->printed = true;
    cout << " [";
    for (int i=0; i < n->nodes.size(); i++) {
      printGraph(n->nodes[i]);
      if (i+1 != n->nodes.size()) {
        cout << ", ";
      }
    }
    cout << "]";
  }
}

int main() {
  vector<Node*> projects;

  Node *a = new Node('a');
  Node *b = new Node('b');
  Node *c = new Node('c');
  Node *d = new Node('d');
  Node *e = new Node('e');
  Node *f = new Node('f');
  projects.push_back(a);
  projects.push_back(b);
  projects.push_back(c);
  projects.push_back(d);
  projects.push_back(e);
  projects.push_back(f);
  d->add(a);
  b->add(f);
  d->add(b);
  a->add(f);
  c->add(d);
  // a->add(c); // break it

  // Node *a = new Node('a');
  // Node *b = new Node('b');
  // Node *c = new Node('c');
  // Node *d = new Node('d');
  // Node *e = new Node('e');
  // Node *f = new Node('f');
  // Node *g = new Node('g');
  // projects.push_back(a);
  // projects.push_back(b);
  // projects.push_back(c);
  // projects.push_back(d);
  // projects.push_back(e);
  // projects.push_back(f);
  // projects.push_back(g);
  // c->add(f);
  // a->add(f);
  // b->add(f);
  // a->add(c);
  // a->add(b);
  // e->add(b);
  // e->add(a);
  // g->add(d);
  // // b->add(e); // break it

  for (int i=0; i < projects.size(); i++) {
    for (int j=0; j < projects.size(); j++) {
      projects[j]->printed = false;
    }
    printGraph(projects[i]);
    cout << endl;
  }

  vector<Node*> build_order;
  while (build_order.size() != projects.size()) {
    bool give_up = true;
    for (int i=0; i < projects.size(); i++) {
      if (projects[i]->built) continue;
      if (projects[i]->buildable()) {
        projects[i]->built = true;
        build_order.push_back(projects[i]);
        give_up = false;
      }
    }
    if (give_up) {
      cout << "Error: there is no acceptable build order." << endl;
      return 1;
    }
  }

  for (int i=0; i < build_order.size(); i++) {
    cout << build_order[i]->value << ' ';
  }
  cout << endl;
}
