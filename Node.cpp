#include "Node.h"

// Null-param constructor
Node::Node()
{
  this->value = 0;
  this->right = NULL;
  this->left = NULL;
  this->parent = NULL;
}

// Constructor with given value
Node::Node(int val)
{
  this->value = val;
  this->right = NULL;
  this->left = NULL;
  this->parent = NULL;
}

// Constructor with a given left node, right node, and value
Node::Node(int val, Node *left, Node *right)
{
  this->value = val;
  this->right = right;
  this->left = left;
  this->parent = NULL;
}

// Setters
void Node::setValue(int val) { this->value = val; }
void Node::setRight(Node *right) { this->right = right; }
void Node::setLeft(Node *left) { this->left = left; }
void Node::setParent(Node *parent) { this->parent = parent; }

// Getters
int Node::getValue() { return this->value; }
Node* Node::getParent() { return this->parent; }
Node* Node::getLeft() { return this->left; }
Node* Node::getRight() { return this->right; }