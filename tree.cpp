#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <netdb.h>

int data_source[7] = {12, 8, 7, 10, 9, 14, 16};

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

struct bs_tree {
    struct bs_tree* left;
    struct bs_tree* right;
    int data;
} bs_tree;

void insert(struct bs_tree* tree, int data) {
    if (tree->data == data) {
        return;
    }
    struct bs_tree* node = new struct bs_tree;
    node->data = data;
    struct bs_tree* p = tree;
    while (p != nullptr) {
        if (data < p->data) {
            if (p->left == nullptr) {
                p->left = node;
                return;
            }
            p = p->left;
        } else {
            if (p->right == nullptr) {
                p->right = node;
                return;
            }
            p = p->right;
        }
    }
}

void remove(struct bs_tree* tree, int data) {
    struct bs_tree* p = tree;
    struct bs_tree* pp = nullptr;
    while (p != nullptr && p->data != data) {
        pp = p;
        if (data < p->data) {
            p = p->left;
        } else {
            p = p->right;
        }
    }
    if (p == nullptr) {
        return;
    }

    // p have tow child
    if (p->left != nullptr && p->right != nullptr) { // find the min data on the right of p
        struct bs_tree* mp = p->right;
        struct bs_tree* mpp = nullptr;
        while (mp->left != nullptr) { // the min data must on the left from mp->left
            mpp = mp;
            mp = mp->left;
        }
        p->data = mp->data;  // replace p with min data
        p = mp;
        pp = mpp; // now this problame become delete min data node
    }

    // p just have one child
    struct bs_tree* child;
    if (p->left != nullptr) {
        child = p->left;
    } else if (p->right != nullptr) {
        child = p->right;
    } else {
        child = nullptr;
    }

    if (pp == nullptr) {
        tree = child;
    } else if (pp->left == p) {
        pp->left = child;
    } else {
        pp->right = child;
    }
    delete p;
}

struct bs_tree* search(struct bs_tree* tree, int data) {
    struct bs_tree* p = tree;
    while (p != nullptr) {
        if (p->data == data) {
            return p;
        }
        if (data < p->data) {
            p = p->left;
        } else {
            p = p->right;
        }
    }
}

// 前序遍历
void preorder_traversal(struct bs_tree* tree) {
    if (tree == nullptr) {
        return;
    }
    int data = tree->data;
    printf("preorder_traversal data %d\n", data);

    preorder_traversal(tree->left);
    preorder_traversal(tree->right);
}

// 中序遍历
void middle_traversal(struct bs_tree* tree) {
    if (tree == nullptr) {
        return;
    }

    middle_traversal(tree->left);

    int data = tree->data;
    printf("middle_traversal data %d\n", data);

    middle_traversal(tree->right);
}

// 后序遍历
void post_traversal(struct bs_tree* tree) {
    if (tree == nullptr) {
        return;
    }

    post_traversal(tree->left);
    post_traversal(tree->right);

    int data = tree->data;
    printf("post_traversal data %d\n", data);
}

int main() {
    for (int i=0; i<7; i++) {
        printf("data_source[%d]=%d\n", i, data_source[i]);
    }

    struct bs_tree* tree = new struct bs_tree;
    tree->data = data_source[0];

    for (int i=1; i<7; i++) {
        insert(tree, data_source[i]);
    }
    preorder_traversal(tree);
    middle_traversal(tree);
    post_traversal(tree);

    remove(tree, 8);
    preorder_traversal(tree);

    return 0;
}
