#ifndef AVL_PERF_H
#define AVL_PERF_H

#include <stdlib.h>

typedef struct AVLPerfNode {
    int key;
    int value; // Changed from void* to int
    struct AVLPerfNode* left;
    struct AVLPerfNode* right;
    int height;
} AVLPerfNode;

typedef struct {
    AVLPerfNode* root;
} AVLPerfTree;

static inline AVLPerfTree* avl_perf_create(void) {
    AVLPerfTree* tree = (AVLPerfTree*)malloc(sizeof(AVLPerfTree));
    if (tree) tree->root = NULL;
    return tree;
}

static inline int _avl_p_height(AVLPerfNode* n) { return n ? n->height : 0; }
static inline int _avl_p_max(int a, int b) { return (a > b) ? a : b; }

static inline AVLPerfNode* _avl_p_rotate_right(AVLPerfNode* y) {
    AVLPerfNode* x = y->left;
    y->left = x->right;
    x->right = y;
    y->height = _avl_p_max(_avl_p_height(y->left), _avl_p_height(y->right)) + 1;
    x->height = _avl_p_max(_avl_p_height(x->left), _avl_p_height(x->right)) + 1;
    return x;
}

static inline AVLPerfNode* _avl_p_rotate_left(AVLPerfNode* x) {
    AVLPerfNode* y = x->right;
    x->right = y->left;
    y->left = x;
    x->height = _avl_p_max(_avl_p_height(x->left), _avl_p_height(x->right)) + 1;
    y->height = _avl_p_max(_avl_p_height(y->left), _avl_p_height(y->right)) + 1;
    return y;
}

extern size_t avl_bytes;
size_t avl_bytes = 0;

// Iterative insert accepting explicit (int key, int value)
static inline void avl_perf_insert(AVLPerfTree* tree, int key, int value) {
    if (!tree) return;

    if (!tree->root) {
        AVLPerfNode* new_node = (AVLPerfNode*)malloc(sizeof(AVLPerfNode));
	avl_bytes += sizeof(*new_node);
        new_node->key = key;
        new_node->value = value;
        new_node->left = new_node->right = NULL;
        new_node->height = 1;
        tree->root = new_node;
        return;
    }

    AVLPerfNode* path[64]; // Max height array
    int path_top = 0;
    AVLPerfNode* curr = tree->root;

    while (curr) {
        path[path_top++] = curr;
        if (key < curr->key) {
            if (!curr->left) {
                AVLPerfNode* new_node = (AVLPerfNode*)malloc(sizeof(AVLPerfNode));
		avl_bytes += sizeof(*new_node);
                new_node->key = key; new_node->value = value;
                new_node->left = new_node->right = NULL; new_node->height = 1;
                curr->left = new_node;
                break;
            }
            curr = curr->left;
        } else if (key > curr->key) {
            if (!curr->right) {
                AVLPerfNode* new_node = (AVLPerfNode*)malloc(sizeof(AVLPerfNode));
		avl_bytes += sizeof(*new_node);
                new_node->key = key; new_node->value = value;
                new_node->left = new_node->right = NULL; new_node->height = 1;
                curr->right = new_node;
                break;
            }
            curr = curr->right;
        } else {
            curr->value = value; 
            return;
        }
    }

    while (path_top > 0) {
        curr = path[--path_top];
        curr->height = 1 + _avl_p_max(_avl_p_height(curr->left), _avl_p_height(curr->right));
        int balance = _avl_p_height(curr->left) - _avl_p_height(curr->right);

        AVLPerfNode* rotated = curr;
        if (balance > 1) {
            if (key < curr->left->key) {
                rotated = _avl_p_rotate_right(curr);
            } else {
                curr->left = _avl_p_rotate_left(curr->left);
                rotated = _avl_p_rotate_right(curr);
            }
        } else if (balance < -1) {
            if (key > curr->right->key) {
                rotated = _avl_p_rotate_left(curr);
            } else {
                curr->right = _avl_p_rotate_right(curr->right);
                rotated = _avl_p_rotate_left(curr);
            }
        }

        if (rotated != curr) {
            if (path_top == 0) {
                tree->root = rotated;
            } else {
                AVLPerfNode* parent = path[path_top - 1];
                if (parent->left == curr) parent->left = rotated;
                else parent->right = rotated;
            }
        }
    }
}

// Returns -1 if key not found (or choose a custom fallback sentinel value)
static inline int avl_perf_get(AVLPerfTree* tree, int key) {
    if (!tree) return -1;
    AVLPerfNode* curr = tree->root;
    while (curr) {
        if (key == curr->key) return curr->value;
        curr = (key < curr->key) ? curr->left : curr->right;
    }
    return -1; 
}

extern int avl_search_path_length;
int avl_search_path_length=0;
static inline int avl_perf_search(AVLPerfTree* avl, int search_key) {
    avl_search_path_length = 0;
    if (!avl) return -1;

    AVLPerfNode* curr = avl->root;
    while (curr) {
        if (search_key == curr->key) return curr->value;
        curr = (search_key < curr->key) ? curr->left : curr->right;
        avl_search_path_length++;   // one step forward
    }
    return -1;
}

static inline void _avl_p_free_node(AVLPerfNode* n) {
    if (n) { _avl_p_free_node(n->left); _avl_p_free_node(n->right); free(n); }
}
static inline void avl_perf_free(AVLPerfTree* tree) {
    if (tree) { _avl_p_free_node(tree->root); free(tree); }
}

#endif // AVL_PERF_H

