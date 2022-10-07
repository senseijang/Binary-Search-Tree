#include <iostream>
#include "Node.h"

// Constructor
Node::Node()
{
  left = NULL;
  right = NULL;
  value = -1;
};

// Constructor with specified num value
Node::Node(int num)
{
  left = NULL;
  right = NULL;
  value = num;
};