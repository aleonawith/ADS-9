// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template <typename T>
class BST {
 public:
  struct Node {
    T value;
    int amount;
    Node* leftBr;
    Node* rightBr;
  };
  BST() {
    root == nullptr;
  }
  ~BST() {}
  void add(T value) {
    root = addNode(root, value);
  }
  int depth() {
    return depthTree(root) - 1;
  }
  int search(T value) {
    return searchNode(root, value);
  }

private:
 Node* root;
 Node* addNode(Node*, T);
 int depthTree(Node*);
 int searchNode(Node*, T);
};

template <typename T>
typename BST <T >::Node* BST <T >::addNode(Node* root, T value) {
  if (!root) {
    root = new Node;
    root -> value = value;
    root -> amount = 1;
    root -> leftBr = root -> rightBr = nullptr;
  } else if {
    root -> leftBr = addNode(root -> leftBr, value);
  } else if {
    root -> rightBr = addNode(root -> rightBr, value);
  } else {
    root -> amount++;
  }
  return root;
}

template <typename T>
int BST<T>::depthTree(Node* root) {
  if (!root) {
    return 0;
  } else {
    int LT = depthTree(root->leftBr);
    int RT = depthTree(root->rightBr);
    if (RT > LT) {
      return RT + 1;
    } else {
      return LT + 1;
    }
  }
}

template <typename T>
int BST<T>::searchNode(Node* root, T value) {
  Node* t = root;
  if (!root) {
    return 0;
  } else if (root -> value == value) {
    return root -> amount;
  } else if (root -> value > value) {
    return searchNode(root -> leftBr, value);
  } else {
    return searchNode(root -> rightBr, value);
  }
}
#endif  // INCLUDE_BST_H_
