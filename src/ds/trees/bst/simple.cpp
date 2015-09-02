#include <cstdio>

class TreeNode {
  public:
    int value;
    TreeNode *left_child, *right_child;

    TreeNode(int value): value(value) {
      left_child = nullptr;
      right_child = nullptr;
    }

    ~TreeNode() {
      if (nullptr != left_child) {
        delete left_child;
      }

      if (nullptr != right_child) {
        delete right_child;
      }
    }
};

class BinarySearchTree {
  private:
    TreeNode *root;

  public:
    BinarySearchTree() {
      root = nullptr;
    }

    ~BinarySearchTree() {
      if (nullptr != root) {
        delete root;
      }
    }

    void insert(TreeNode *node) {
      if (nullptr == root) {
        root = node;
        return;
      }

      TreeNode *parent = root;

      while (nullptr != parent) {
        if (parent->value < node->value) {
          if (nullptr == parent->right_child) {
            parent->right_child = node;
            return;
          } else {
            parent = parent->right_child;
          }
        } else {
          if (nullptr == parent->left_child) {
            parent->left_child = node;
            return;
          } else {
            parent = parent->left_child;
          }
        }
      }
    }

    bool search(int value) {
      TreeNode *current = root;

      while (nullptr != current) {
        if (current->value == value) {
          return true;
        }

        if (current->value < value) {
          current = current->right_child;
        } else {
          current = current->left_child;
        }
      }

      return false;
    }

    void print(TreeNode *node) {
      if (nullptr != node) {
        print(node->left_child);
        printf("%d\n", node->value);
        print(node->right_child);
      }
    }

    void print_tree() {
      print(root);
    }
};

int main() {
  printf("1 - insert, 2 - search, 3 - print, 4 - exit\n");
  BinarySearchTree *tree = new BinarySearchTree();
  int cmd, value;

  while (scanf("%d", &cmd) && cmd != 4) {
    switch (cmd) {
      case 1:
        scanf("%d", &value);
        tree->insert(new TreeNode(value));
        printf("Inserted.\n");
        break;

      case 2:
        scanf("%d", &value);
        printf(tree->search(value) ? "Hit!\n" : "Whoops!\n");
        break;

      case 3:
        printf("Printing the tree...\n");
        tree->print_tree();
    }
  }

  delete tree;
  return 0;
}
