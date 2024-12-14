// C++ implementation of Binary Search Tree
#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* parent;
  Node* left;
  Node* right;

  Node(int item) {
    this->data = item;
    this->parent = nullptr;
    this->left = nullptr;
    this->right = nullptr;
  }
};

class bst {
 private:
  Node* root;

 public:
  Node* search(Node* node, int item);
  Node* insert(Node* node, int item);
  Node* deleteItem(Node* node, int item);
  Node* minVal(Node* node);
  void traversal(Node* node);
};

// recursively searches thru the bst to find the item
Node* bst::search(Node* node, int item) {
  // if there is no tree or data is at node
  if (node == nullptr || node->data == item) {
    return node;
  }
  // if item is greater, go right
  if (node->data < item) {
    return search(node->right, item);
  }
  // else item less, go left
  else {
    return search(node->left, item);
  }
}

Node* bst::insert(Node* node, int item) {
  // if there is no tree
  if (node == nullptr) {
    // plop as first item
    return new Node(item);
  }

  // if item is already present
  if (node->data == item) {
    return node;
  }
  // compare item with value in node
  // if item is greater, go right
  if (node->data < item) {
    // insert into the right subtree
    node->right = insert(node->right, item);

    // set parent of right subtree to current node
    if (node->right != nullptr) {
      node->right->parent = node;
    }
  }
  // else item less, go left
  else {
    // insert into the left subtree
    node->left = insert(node->left, item);
    // set parent of left subtree to current node
    if (node->left != nullptr) {
      node->left->parent = node;
    }
  }

  return node;
}

Node* bst::deleteItem(Node* node, int item) {
  if (node == nullptr) {
    return node;
  }
  // search for the item
  // if item is greater, go right
  if (node->data < item) {
    node->right = deleteItem(node->right, item);
  }
  // else item less, go left
  else if (node->data > item) {
    node->left = deleteItem(node->left, item);
  }
  // else item is equal to the data
  else {
    // three cases for delete
    // node with no children or with 1 child
    // set parent's pointer to point to the one child
    // if child is right
    if (node->left == nullptr) {
      // create a temporary node for the right child
      Node* temp = node->right;
      // delete the current node
      delete node;
      // return the temporary node that was originally the right child
      return temp;
    }
    // else if child is left
    else if (node->right == nullptr) {
      Node* temp = node->left;
      delete node;
      return temp;
    }
    // else it is node with 2 children
    else {
      // Replace node with in-order successor (left most child of our right
      // subtree) child
      // get in-order succ
      Node* temp = minVal(node->right);
      // replace node with in-order succ
      node->data = temp->data;
      // delete the in-order succ from tree
      node->right = deleteItem(node->right, temp->data);
    }
  }
  return node;
}

Node* bst::minVal(Node* node) {
  // go to the left most leaf in the tree
  // if there is no tree
  if (node == nullptr) {
    return 0;
  }

  // create and assign the minimum node as the current node
  Node* min = node;
  // while the left child of the minimum is not a leaf node
  while (min->left != nullptr) {
    // set new minimum node as the left child
    min = min->left;
  }
  return min;
}

void bst::traversal(Node* node) {
  // traverse using inorder
  if (node != nullptr) {
    traversal(node->left);
    cout << node->data << " ";
    traversal(node->right);
  }
}

int main() {  // AI generated
  // Create a Binary Search Tree
  bst BST;
  Node* root = nullptr;

  // Insert elements
  cout << "Inserting elements:" << endl;
  root = BST.insert(root, 50);
  BST.insert(root, 30);
  BST.insert(root, 70);
  BST.insert(root, 20);
  BST.insert(root, 40);
  BST.insert(root, 60);
  BST.insert(root, 80);

  // Print the tree (inorder traversal)
  cout << "Inorder Traversal: ";
  BST.traversal(root);
  cout << endl;

  // Search for an element
  cout << "Searching for elements:" << endl;
  int searchValue = 40;
  Node* foundNode = BST.search(root, searchValue);
  if (foundNode) {
    cout << searchValue << " found in the tree" << endl;
  } else {
    cout << searchValue << " not found in the tree" << endl;
  }

  // Search for a non-existing element
  searchValue = 90;
  foundNode = BST.search(root, searchValue);
  if (foundNode) {
    cout << searchValue << " found in the tree" << endl;
  } else {
    cout << searchValue << " not found in the tree" << endl;
  }

  // Find minimum value
  Node* minNode = BST.minVal(root);
  if (minNode) {
    cout << "Minimum value in the tree: " << minNode->data << endl;
  }

  // Delete an element
  cout << "\nDeleting elements:" << endl;
  cout << "Deleting 30:" << endl;
  root = BST.deleteItem(root, 30);

  // Print the tree after deletion
  cout << "Inorder Traversal after deletion: ";
  BST.traversal(root);
  cout << endl;

  // Delete another element
  cout << "\nDeleting 50 (root):" << endl;
  root = BST.deleteItem(root, 50);

  // Print the tree after deletion
  cout << "Inorder Traversal after deletion: ";
  BST.traversal(root);
  cout << endl;

  return 0;
}