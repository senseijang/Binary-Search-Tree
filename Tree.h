// Pre-processor directives
#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <vector>
#include <cmath>
#include "Node.h"

class Tree
{
private:
  Node *root;
  int size;

public:
  Tree();
  Tree(Node *);
  ~Tree();

  void setRoot(Node *);

  Node *getRoot();
  int getSize();

  void printInOrder(Node *);
  void deleteTree(Node *);
  void inOrder(Node *, int, std::vector<int> *);

  Node *setNode(int, Node *, bool);
  void createTree(Node *, std::vector<int>);
  int getSmallest(Node *, int);
};

#endif