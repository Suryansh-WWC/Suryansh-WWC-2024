#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to build a height-balanced BST
TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
    if (start > end) return nullptr;

    // Find the middle element
    int mid = start + (end - start) / 2;

    // Create the root node with the middle element
    TreeNode* root = new TreeNode(nums[mid]);

    // Recursively build the left and right subtrees
    root->left = sortedArrayToBST(nums, start, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, end);

    return root;
}

// Wrapper function for convenience
TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sortedArrayToBST(nums, 0, nums.size() - 1);
}

// Function to print the tree in-order for verification
void inOrderTraversal(TreeNode* root) {
    if (!root) return;
    inOrderTraversal(root->left);
    cout << root->val << " ";
    inOrderTraversal(root->right);
}

int main() {
    // Input: Sorted integer array
    vector<int> nums = {-10, -3, 0, 5, 9};

    // Convert the array to a height-balanced BST
    TreeNode* root = sortedArrayToBST(nums);

    // Print the tree in-order to verify correctness
    cout << "In-order traversal of the height-balanced BST: ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}

