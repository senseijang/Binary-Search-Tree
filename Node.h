#ifndef NODE_H
#define NODE_H

class Node
{
public:
  // attributes
  Node *left;
  Node *right;
  int value;

  // methods
  Node();
  Node(int);
};

#endif