#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#include "Node.h"
#include "Tree.h"

int main()
{
  // std::string userInput;
  std::vector<int> data;
  int k;

  data = {6, 17, 20, 41, 45, 52, 57, 65, 71, 76, 79, 87, 92, 95, 99};

  std::cout << "K (max size: " << data.size() << "): ";
  std::cin >> k;
  std::cout << "\n";

  std::cout << "\n\nCurrent Dataset:\n";
  for (int i = 0; data.size(); i++)
  {
    std::cout << "(" << i + 1 << ") " << data[i] << ", ";
  }

  int median = floor((data.size() - 1) / 2);
  Node *root = new Node(data[median]);
  Tree tree(root);

  tree.createTree(tree.getRoot(), data);
  std::cout << "\n\nData in Tree (in-order traversal)\n";
  tree.printInOrder(tree.getRoot());

  int treeSize = tree.getSize();
  int kthSmallest = tree.getSmallest(tree.getRoot(), k);
  std::cout << "\n"
            << k << "-th smallest value: " << kthSmallest << "\n";
}