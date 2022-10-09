#include "Node.h"
#include <iostream>

void makeTree(int, int[], Node *);

int main()
{
  // TODO: Add user input for k-th smallest, custom array?
  int data[] = {6, 17, 20, 41, 45, 52, 57, 65, 71, 76, 79, 87, 92, 95, 99};
  const int SIZE = sizeof(data) / sizeof(int);
  Node root;

  makeTree(SIZE, data, &root);

  return 0;
}

void makeTree(int SIZE, int data[], Node *root)
{
  if (SIZE > 3)
  {
    int median = SIZE / 2;

    // assign node with median
    Node n(data[median]);

    // split array into left and right halves
    int left[SIZE / 2], right[SIZE / 2], i;
    for (i = 0; i < (SIZE / 2); ++i)
    {
      left[i] = data[i];
    }
    for (; i < SIZE; ++i)
    {
      right[i - (SIZE / 2)] = data[i];
    }
  }
}