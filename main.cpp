#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#include "Node.h"
#include "Tree.h"

int main()
{
  // Initialization, dataset can be changed manually
  std::vector<int> data{6, 17, 20, 41, 45, 52, 57, 65, 71, 76, 79, 87, 92, 95, 99};
  int k;

  // sorting data just in case its not in order
  sort(data.begin(), data.end());

  // k user input
  std::cout << "K (max size: " << data.size() << "): ";
  std::cin >> k;
  k--;

  // mirror dataset: [number of the element] value of the element
  std::cout << "\nCurrent Dataset:\n";
  for (int i = 0; i < data.size(); i++)
  {
    if (i == data.size() - 1)
    {
      std::cout << "[" << i + 1 << "] " << data[i];
    }
    else
    {
      std::cout << "[" << i + 1 << "] " << data[i] << ", ";
    }
  }

  // set up root
  int median = floor((data.size() - 1) / 2);
  Node *root = new Node(data[median]);
  Tree tree(root);

  // set up tree
  tree.createTree(tree.getRoot(), data);

  // show traversals
  std::cout << "\n\nData in Tree (in-order traversal):\n";
  tree.printInOrder(tree.getRoot());

  std::cout << "\n\nData in Tree (pre-order traversal):\n";
  tree.printPreOrder(tree.getRoot());

  std::cout << "\n\nData in Tree (post-order traversal):\n";
  tree.printPostOrder(tree.getRoot());

  // find k-th smallest
  int treeSize = tree.getSize();
  int kthSmallest = tree.getSmallest(tree.getRoot(), k);
  std::cout << "\n"
            << k + 1 << "-th smallest value: " << kthSmallest << "\n";
}