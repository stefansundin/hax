// g++ -std=c++11 -g 4.3.cpp && ./a.out
#include <iostream>
#include <vector>
#include <queue>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

using namespace std;

class Node {
public:
  int value;
  Node *left;
  Node *right;

  Node(int v) {
    value = v;
    left = NULL;
    right = NULL;
  }
  Node(int v, Node *l, Node *r) {
    value = v;
    left = l;
    right = r;
  }
};

void printTree(Node *n) {
  if (n == NULL) {
    cout << "NULL";
    return;
  }
  cout << n->value;
  if (n->left != NULL || n->right != NULL) {
    cout << " [";
    printTree(n->left);
    cout << ", ";
    printTree(n->right);
    cout << "]";
  }
}

Node *createBST(int *arr, int start, int end) {
  if (end < start) return NULL;
  int mid = (start + end)/2;
  Node *left = createBST(arr, start, mid-1);
  Node *right = createBST(arr, mid+1, end);
  Node *root = new Node(arr[mid], left, right);
  return root;
}

void DFS_depths(Node *root, vector<vector<Node*>> &depths, int d) {
  if (root == NULL) return;
  if (depths.size() <= d) {
    vector<Node*> depth;
    depths.push_back(depth);
  }
  depths[d].push_back(root);
  DFS_depths(root->left, depths, d+1);
  DFS_depths(root->right, depths, d+1);
}

void BFS_depths(Node *root, vector<vector<Node*>> &depths) {
  queue<Node*> *current_level = new queue<Node*>();
  current_level->push(root);
  int d = 0;

  while (!current_level->empty()) {
    queue<Node*> *next_level = new queue<Node*>();
    vector<Node*> depth;
    while (!current_level->empty()) {
      Node *node = current_level->front();
      current_level->pop();

      // visit node
      depth.push_back(node);

      // add children to next level queue
      if (node->left != NULL) {
        next_level->push(node->left);
      }
      if (node->right != NULL) {
        next_level->push(node->right);
      }
    }
    depths.push_back(depth);
    delete current_level;
    current_level = next_level;
    d++;
  }
  delete current_level;
}

void print_depths(vector<vector<Node*>> &depths) {
  for (int i=0; i < depths.size(); i++) {
    cout << "depth " << i << ":";
    vector<Node*> *depth = &depths[i];
    for (int j=0; j < depth->size(); j++) {
      cout << " " << depth->at(j)->value;
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  {
    int arr[] = {1, 4, 6, 77, 567, 1561, 1666, 3572};
    Node *root = createBST(arr, 0, ARRAY_SIZE(arr)-1);
    printTree(root);
    cout << endl;
    {
      cout << "DFS:" << endl;
      vector<vector<Node*>> depths;
      DFS_depths(root, depths, 0);
      print_depths(depths);
    }
    {
      cout << "BFS:" << endl;
      vector<vector<Node*>> depths;
      BFS_depths(root, depths);
      print_depths(depths);
    }
  }
  {
    int arr[] = {1, 4, 6, 77, 567, 1666, 3572};
    Node *root = createBST(arr, 0, ARRAY_SIZE(arr)-1);
    printTree(root);
    cout << endl;
    {
      cout << "DFS:" << endl;
      vector<vector<Node*>> depths;
      DFS_depths(root, depths, 0);
      print_depths(depths);
    }
    {
      cout << "BFS:" << endl;
      vector<vector<Node*>> depths;
      BFS_depths(root, depths);
      print_depths(depths);
    }
  }
  {
    int arr[] = {26, 47, 57, 71, 85, 174, 179, 260, 291, 298, 342, 344, 382};
    Node *root = createBST(arr, 0, ARRAY_SIZE(arr)-1);
    printTree(root);
    cout << endl;
    {
      cout << "DFS:" << endl;
      vector<vector<Node*>> depths;
      DFS_depths(root, depths, 0);
      print_depths(depths);
    }
    {
      cout << "BFS:" << endl;
      vector<vector<Node*>> depths;
      BFS_depths(root, depths);
      print_depths(depths);
    }
  }
}

// Use javascript to generate a random array:
// var arr = [];
// for (var i=0; i < Math.floor(10+Math.random()*14); i++) { arr.push(Math.floor(Math.random()*400)) }
// arr.sort((a,b) => a-b).filter((el,i,a) => i == a.indexOf(el));
