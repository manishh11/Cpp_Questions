#include <iostream>
#include <algorithm>
Using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxPathSumHelper(TreeNode* node, int& maxSum) {
    if (node == nullptr) return 0;

    int leftSum = max(0, maxPathSumHelper(node->left, maxSum));
    int rightSum = max(0, maxPathSumHelper(node->right, maxSum));

    int currentSum = node->val + leftSum + rightSum;
    maxSum = max(maxSum, currentSum);

    return node->val + max(leftSum, rightSum);
}

int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN;
    maxPathSumHelper(root, maxSum);
    return maxSum;
}

TreeNode* createTree() {
    int val;
    cout << "Enter node value (or -1 for null): ";
    cin >> val;

    if (val == -1) {
        return nullptr;
    }

    TreeNode* node = new TreeNode(val);
    cout << "Enter left child of " << val << ":" << endl;
    node->left = createTree();
    cout << "Enter right child of " << val << ":" << endl;
    node->right = createTree();

    return node;
}

int main() {
    cout << "Enter nodes of the binary tree (enter -1 for null):" << endl;
    TreeNode* root = createTree();

    int result = maxPathSum(root);
    cout << "Maximum path sum in the binary tree: " << result << endl;
    return 0;
}
