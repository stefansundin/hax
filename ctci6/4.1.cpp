// g++ -std=c++11 -g 4.1.cpp && ./a.out
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
  bool visited;
  bool printed;
  char value;
  vector<Node*> nodes;

  Node(char v) {
    visited = printed = false;
    value = v;
  }
  void add(Node *n) {
    nodes.push_back(n);
  }
  void remove(Node *n) {
    for (int i=0; i < nodes.size(); i++) {
      Node *node = nodes[i];
      if (node == n) {
        nodes.erase(nodes.begin()+i);
        return; // only remove the first encountered
      }
    }
  }
};

void reset(Node *root) {
  if (root == NULL) return;
  root->visited = root->printed = false;
  for (int i=0; i < root->nodes.size(); i++) {
    Node *n = root->nodes[i];
    if (n->visited == true || n->printed == true) {
      reset(n);
    }
  }
}

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

// depth-first searching
void DFS_search(Node *root) {
  if (root == NULL) return;
  // visit(root);
  root->visited = true;
  for (int i=0; i < root->nodes.size(); i++) {
    Node *n = root->nodes[i];
    if (n->visited == false) {
      DFS_search(n);
    }
  }
}

void DFS_check(Node *a, Node *b) {
  reset(a);
  reset(b);
  DFS_search(a);
  cout << "There " << (b->visited?"is":"isn't") << " a path from " << a->value << " to " << b->value << "." << endl;
  reset(a);
  reset(b);
  DFS_search(b);
  cout << "There " << (a->visited?"is":"isn't") << " a path from " << b->value << " to " << a->value << "." << endl;
}

// breadth-first searching
void BFS_search(Node *root) {
  queue<Node*> queue;
  root->visited = true;
  queue.push(root);

  while (!queue.empty()) {
    Node *node = queue.front();
    queue.pop();
    node->visited = true;

    // add connected nodes to queue
    for (int i=0; i < node->nodes.size(); i++) {
      Node *n = node->nodes[i];
      if (n->visited == false) {
        queue.push(n);
      }
    }
  }
}

void BFS_check(Node *a, Node *b) {
  reset(a);
  reset(b);
  BFS_search(a);
  cout << "There " << (b->visited?"is":"isn't") << " a path from " << a->value << " to " << b->value << "." << endl;
  reset(a);
  reset(b);
  BFS_search(b);
  cout << "There " << (a->visited?"is":"isn't") << " a path from " << b->value << " to " << a->value << "." << endl;
}

int main() {
  Node *a = new Node('a');
  Node *b = new Node('b');
  Node *c = new Node('c');
  Node *d = new Node('d');
  Node *e = new Node('e');
  Node *f = new Node('f');
  a->add(b);
  a->add(a);
  b->add(a);
  b->add(c);
  c->add(a);
  c->add(b);
  d->add(f);
  f->add(e);
  e->add(d);

  cout << "First with DFS:" << endl;
  printGraph(a);
  cout << endl;
  printGraph(e);
  cout << endl;
  DFS_check(a, e);
  c->add(e); // add new edge
  printGraph(a);
  cout << endl;
  DFS_check(a, e);
  f->add(b); // add new edge
  printGraph(a);
  cout << endl;
  DFS_check(a, e);
  cout << endl;

  // reset edges
  c->remove(e);
  f->remove(b);

  cout << "Then with BFS:" << endl;
  printGraph(a);
  cout << endl;
  printGraph(e);
  cout << endl;
  BFS_check(a, e);
  c->add(e); // add new edge
  printGraph(a);
  cout << endl;
  BFS_check(a, e);
  f->add(b); // add new edge
  printGraph(a);
  cout << endl;
  BFS_check(a, e);
  c->remove(e);
  f->remove(b);
}
