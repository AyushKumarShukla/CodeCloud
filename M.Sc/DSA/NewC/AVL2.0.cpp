#include <memory>
#include <vector>

using std::unique_ptr;
using std::move;

// AVL Tree Node Structure
struct AVLNode {
    int key;
    int height;
    unique_ptr<AVLNode> left;
    unique_ptr<AVLNode> right;
    
    AVLNode(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
};

// Utility function to get the height of the tree
int height(const unique_ptr<AVLNode>& N) {
    return N ? N->height : 0;
}

// Right rotate
unique_ptr<AVLNode> rightRotate(unique_ptr<AVLNode> y) {
    auto x = move(y->left);
    y->left = move(x->right);
    x->right = move(y);
    
    x->right->height = 1 + std::max(height(x->right->left), height(x->right->right));
    x->height = 1 + std::max(height(x->left), height(x->right));
    
    return x;
}

// Left rotate
unique_ptr<AVLNode> leftRotate(unique_ptr<AVLNode> x) {
    auto y = move(x->right);
    x->right = move(y->left);
    y->left = move(x);
    
    y->left->height = 1 + std::max(height(y->left->left), height(y->left->right));
    y->height = 1 + std::max(height(y->left), height(y->right));
    
    return y;
}

// Get balance factor
int getBalance(const unique_ptr<AVLNode>& N) {
    return N ? height(N->left) - height(N->right) : 0;
}

// Insert function
unique_ptr<AVLNode> insert(unique_ptr<AVLNode> node, int key) {
    if (!node)
        return unique_ptr<AVLNode>(new AVLNode(key));
    
    if (key < node->key)
        node->left = insert(move(node->left), key);
    else if (key > node->key)
        node->right = insert(move(node->right), key);
    else
        return node; // No duplicates allowed
    
    node->height = 1 + std::max(height(node->left), height(node->right));
    
    int balance = getBalance(node);
    
    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(move(node));
    
    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(move(node));
    
    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(move(node->left));
        return rightRotate(move(node));
    }
    
    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(move(node->right));
        return leftRotate(move(node));
    }
    
    return node;
}

// Preorder traversal
void preOrder(const unique_ptr<AVLNode>& root) {
    if (root) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    unique_ptr<AVLNode> root;
    std::vector<int> keys = {8, 9, 10, 2, 1, 5, 6, 4, 7, 11};
    
    for (int key : keys)
        root = insert(move(root), key);
    
    printf("Preorder traversal of the AVL tree:\n");
    preOrder(root);
    printf("\n");
    
    return 0;
}

