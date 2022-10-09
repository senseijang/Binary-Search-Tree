#include "Node.h"
#include "Tree.h"

// Null-param constructor
Tree::Tree()
{
  this->root = NULL;
  this->size = 0;
}

// Constructor with given pointer to root
Tree::Tree(Node *root)
{
  this->root = root;
  this->size = 1;
}

// Deconstructor
Tree::~Tree() { this->deleteTree(this->root); }

// setter
void Tree::setRoot(Node *root) { this->root = root; }

// getters
Node *Tree::getRoot() { return this->root; }
int Tree::getSize() { return this->size; }

/*
 * setNode sets a node given a value and assigns it in the proper position relative to the parent
 *
 * @param value is the value of the node
 * @param parent is a pointer to the parent node to assign the new node
 * @param isRight is a boolean value that determines whether to assign the new node to the right or left
 */
Node *Tree::setNode(int value, Node *parent, bool isRight)
{
  Node *newNode = new Node(value);
  newNode->setParent(parent);

  if (isRight)
  {
    parent->setRight(newNode);
  }
  else
  {
    parent->setLeft(newNode);
  }
  return newNode;
}

/*
 * createTree creates subtrees given a parent node and a data vector
 * using recursion to split the vector to make more subtrees to initialize the entire tree.
 *
 * @param parent is a pointer to the parent node used to connect the left and right node
 * @param data is a vector storing all the data to be set in the tree
 */
void Tree::createTree(Node *parent, std::vector<int> data)
{
  int len = data.size();

  if (len > 3)
  {
    int median = floor((len - 1) / 2);

    std::vector<int> dataLeft;
    std::vector<int> dataRight;

    for (int i = 0; i < median; i++)
    {
      dataLeft.push_back(data[i]);
      dataLeft.push_back(data[median + i + 1]);
    }

    if (len % 2 == 0)
    {
      dataRight.push_back(data.back());
    }

    int medianLeft = floor((dataLeft.size() - 1) / 2);
    int medianRight = floor((dataRight.size() - 1) / 2);

    Node *left = setNode(dataLeft[medianLeft], parent, false);
    Node *right = setNode(dataRight[medianRight], parent, true);
    this->size += 2;

    createTree(left, dataLeft);
    createTree(right, dataRight);
  }
  else if (len == 3)
  {
    Node *left = setNode(data[0], parent, false);
    Node *right = setNode(data[2], parent, true);
    this->size += 2;
  }
  else if (len == 2)
  {
    Node *right = setNode(data[1], parent, true);
    this->size += 1;
  }
  else
  {
    std::cout << "Something went wrong with setting the tree!\n";
  }
}

/*
 * printInOrder prints the tree using a in-order traversal (Left->Middle->Right)
 *
 * @param node is a pointer to the starting node to print from.
 */
void Tree::printInOrder(Node *node)
{
  if (node != NULL)
  {
    printInOrder(node->getLeft());
    std::cout << node->getValue() << "\n";
    printInOrder(node->getRight());
  }
}

/*
 * deleteTree is used by the destructor to fully delete the tree from memory
 *
 * @param node is a pointer to the parent node of the subtree to delete
 */
void Tree::deleteTree(Node *node)
{
  if (node != NULL)
  {
    deleteTree(node->getLeft());
    deleteTree(node->getRight());
    delete (node);
  }
}

/*
 * inOrder is used to return the k-th smallest value using in-order traversal
 *
 * @param node is a pointer to a node to traverse from
 * @param k is the target k-th smallest number to find
 * @param sentry is a vector used to stop the traversal when the size == k
 */
void Tree::inOrder(Node *node, int k, std::vector<int> *sentry)
{
  if (node == NULL)
  {
    if (sentry->size() <= k)
    {
      inOrder(node->getLeft(), k, sentry);
      sentry->push_back(node->getValue());
      inOrder(node->getRight(), k, sentry);
    }
  }
}

/*
 * getSmallest is used to find the k-th smallest element
 *
 * @param node is a pointer to the starter traversal node
 * @param k is the target value for the k-th smallest element
 */
int Tree::getSmallest(Node *node, int k)
{
  int target = -1;
  std::vector<int> intBuffer;

  if (k == floor((this->size) / 2))
  {
    target = (*this->root).getValue();
  }
  else
  {
    inOrder(node, k, &intBuffer);
  }
  target = intBuffer[k];
  return intBuffer.size();
}