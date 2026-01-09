#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <algorithm>

using namespace std;

struct treenode {
    int val;
    treenode* left;
    treenode* right;
    treenode(int x) : val(x), left(nullptr), right(nullptr) {}
};

treenode* insertbst(treenode* root, int val) {
    if (!root) return new treenode(val);
    if (val < root->val) {
        root->left = insertbst(root->left, val);
    }
    else {
        root->right = insertbst(root->right, val);
    }
    return root;
}

treenode* buildbstfromlevelorder(const vector<string>& levelorder) {
    treenode* root = nullptr;
    for (const string& value : levelorder) {
        if (value != "n") { // 'n'表示空节点
            root = insertbst(root, stoi(value));
        }
    }
    return root;
}

void postordertraversal(treenode* root, vector<int>& result) {
    if (!root) return;
    postordertraversal(root->left, result);
    postordertraversal(root->right, result);
    result.push_back(root->val);
}

void inordertraversal(treenode* root, vector<int>& result) {
    if (!root) return;
    inordertraversal(root->left, result);
    result.push_back(root->val);
    inordertraversal(root->right, result);
}

int main() {
    int t;
    cin >> t;
    cin.ignore(); // 忽略换行符

    while (t--) {
        string levelorderline;
        getline(cin, levelorderline);
        vector<string> levelorder;
        stringstream ss(levelorderline);
        string token;
        while (ss >> token) {
            levelorder.push_back(token);
        }

        int k;
        cin >> k;
        cin.ignore(); // 忽略换行符

        // 构建 bst
        treenode* bstroot = buildbstfromlevelorder(levelorder);

        // 后序遍历
        vector<int> postorderresult;
        postordertraversal(bstroot, postorderresult);

        // 中序遍历
        vector<int> inorderresult;
        inordertraversal(bstroot, inorderresult);

        // 输出结果
        for (size_t i = 0; i < postorderresult.size(); ++i) {
            cout << postorderresult[i];
            if (i < postorderresult.size() - 1) cout << " ";
        }
        cout << endl;

        cout << inorderresult[k - 1] << endl; // 输出第 k 小的元素
    }

    return 0;
}
