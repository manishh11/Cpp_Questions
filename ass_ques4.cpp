#include <iostream>
#include <sstream>
#include <string>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    string serialize(TreeNode* root) {
        if (!root) return "X,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserializeHelper(ss);
    }

private:
    TreeNode* deserializeHelper(stringstream& ss) {
        string val;
        getline(ss, val, ',');
        if (val == "X") return NULL;
        TreeNode* node = new TreeNode(stoi(val));
        node->left = deserializeHelper(ss);
        node->right = deserializeHelper(ss);
        return node;
    }
};

int main() {
    Codec codec;
    int numNodes;
    cout << "Enter the number of nodes in the binary tree: ";
    cin >> numNodes;

    TreeNode* root = NULL;
    queue<TreeNode**> q;

    for (int i = 0; i < numNodes; i++) {
        int val;
        cout << "Enter the value of node " << i + 1 << ": ";
        cin >> val;

        TreeNode* node = new TreeNode(val);
        if (!root) {
            root = node;
            q.push(&root);
        } else {
            TreeNode** front = q.front();
            q.pop();
            if (!*front) {
                q.push(&(*front));
                q.push(&node);
            } else {
                if (!(*front)->left) {
                    (*front)->left = node;
                    q.push(&((*front)->left));
                } else {
                    (*front)->right = node;
                    q.push(&((*front)->right));
                }
            }
        }
    }

    string serialized = codec.serialize(root);
    cout << "Serialized: " << serialized << endl;

    TreeNode* deserializedRoot = codec.deserialize(serialized);
    queue<TreeNode*> q2;
    q2.push(deserializedRoot);

    cout << "Deserialized: ";
    while (!q2.empty()) {
        TreeNode* node = q2.front();
        q2.pop();
        cout << node->val << " ";
        if (node->left) q2.push(node->left);
        if (node->right) q2.push(node->right);
    }
    cout << endl;

    return 0;
}
