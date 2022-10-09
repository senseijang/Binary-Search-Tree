// Pre-processor directives
#ifndef NODE_H
#define NODE_H
#include <iostream>

class Node
{
private:
  int value;
  Node *right, *left, *parent;

public:
  Node();
  Node(int);
  Node(int, Node *, Node *);

  // setters
  void setParent(Node *);
  void setRight(Node *);
  void setLeft(Node *);
  void setValue(int);

  // getters
  int getValue();
  Node *getParent();
  Node *getRight();
  Node *getLeft();
};

#endif