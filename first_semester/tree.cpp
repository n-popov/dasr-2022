#include <iostream>
#include <cmath>

template<typename T>
T max(T left, T right) {
    return left < right ? right : left;
}

template<typename T>
T abs(T value) {
    return value > 0 ? value : -value;
}

struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    int tree_height;
    int value;
};

int compute_height(TreeNode*);

TreeNode* left_rotation(TreeNode* node) {
    auto right_node = node->right;
    node->right = right_node->left;
    right_node->left = node;
    node->tree_height = compute_height(node);
    right_node->tree_height = compute_height(right_node);
    return right_node;
}

TreeNode* right_rotation(TreeNode* node) {
    std::cout << (!node) << std::endl;
    auto left_node = node->left;
    std::cout << (!left_node) << std::endl;
    node->left = left_node->right;
    left_node->right = node;
    node->tree_height = compute_height(node);
    left_node->tree_height = compute_height(left_node);
    return left_node;
}

int compute_height(TreeNode* node) {
    return max(node->left->tree_height,
        node->right->tree_height) + 1u;
}

bool contains(TreeNode* node, int value) {
    if (!node) {
        return false;
    }
    if (value < node->value) {
        return contains(node->left, value);
    }
    if (value > node->value) {
        return contains(node->right, value);
    }
    return true;
}

void print(TreeNode* node) {
    if (!node) return;
    print(node->left);
    std::cout << node->value << ' ';
    print(node->right);
}

TreeNode* balance(TreeNode* root) {
    if (!root->right || !root->left) {
        return root;
    }
    auto difference =
        root->right->tree_height - root->left->tree_height;
    if (std::abs(difference) <= 1) {
        return root;
    }
    if(difference > 0) {
        if (root->right->left->tree_height <
            root->right->right->tree_height) {
            return left_rotation(root);
        } else {
            root->right = right_rotation(root->right);
            return left_rotation(root);
        }
    } else {
        if (root->left->right->tree_height <
            root->left->left->tree_height) {
            return right_rotation(root);
        } else {
            root->left = left_rotation(root->left);
            return right_rotation(root);
        }
    }
}


void insert_inner(TreeNode* root, int value) {
    root->tree_height++;
    if (value <= root->value) {
        if (!root->left) {
            auto new_node = new TreeNode();
            new_node->value = value;
            new_node->left = nullptr;
            new_node->right = nullptr;
            root->left = new_node;
        } else {
            return insert_inner(root->left, value);
        }
    } else {
        if (!root->right) {
            auto new_node = new TreeNode();
            new_node->value = value;
            new_node->left = nullptr;
            new_node->right = nullptr;
            root->right = new_node;
        } else {
            return insert_inner(root->right, value);
        }
    }
}


TreeNode* insert(TreeNode* root, int value) {
    insert_inner(root, value);
    return balance(root);
}

void deallocate(TreeNode* root) {
    std::cout << "Deallocate called";
    deallocate(root->left);
    deallocate(root->right);
    delete root;
}

int main(){
    TreeNode* root = new TreeNode();
    root->left = nullptr;
    root->right = nullptr;
    root->value = 5;
    int value;
    for(auto i = 0; i < 10; i++) {
        std::cin >> value;
        root = insert(root, value);
        print(root);
    }
    deallocate(root);
}
