#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <string>
using namespace std;

// 定义二叉树节点
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 根据层序遍历构建二叉搜索树
TreeNode* buildBST(const vector<string>& levelOrder) {
    if (levelOrder.empty() || levelOrder[0] == "n") return NULL;

    TreeNode* root = new TreeNode(stoi(levelOrder[0]));
    queue<TreeNode*> q;
    q.push(root);

    size_t i = 1;
    while (!q.empty() && i < levelOrder.size()) {
        TreeNode* current = q.front();
        q.pop();

        // 左子节点
        if (levelOrder[i] != "n") {
            current->left = new TreeNode(stoi(levelOrder[i]));
            q.push(current->left);
        }
        i++;

        // 右子节点
        if (i < levelOrder.size() && levelOrder[i] != "n") {
            current->right = new TreeNode(stoi(levelOrder[i]));
            q.push(current->right);
        }
        i++;
    }
    return root;
}

// 后序遍历
void postOrderTraversal(TreeNode* root, vector<int>& result) {
    if (!root) return;
    postOrderTraversal(root->left, result);
    postOrderTraversal(root->right, result);
    result.push_back(root->val);
}

// 中序遍历获取第 k 小的元素
void inOrderTraversal(TreeNode* root, vector<int>& sorted) {
    if (!root) return;
    inOrderTraversal(root->left, sorted);
    sorted.push_back(root->val);
    inOrderTraversal(root->right, sorted);
}

int main() {
    int T;
    cin >> T;  // 读取测试案例数量
    cin.ignore(); // 忽略换行符

    while (T--) {
        string levelOrderLine;
        getline(cin, levelOrderLine);  // 读取层序遍历数据
        int k;
        cin >> k;  // 读取k值
        cin.ignore(); // 忽略换行符

        // 处理层序遍历数据
        stringstream ss(levelOrderLine);
        vector<string> levelOrder;
        string value;

        while (ss >> value) {
            levelOrder.push_back(value);
        }

        // 构建BST
        TreeNode* root = buildBST(levelOrder);

        // 后序遍历
        vector<int> postOrderResult;
        postOrderTraversal(root, postOrderResult);

        // 中序遍历以获取排序结果
        vector<int> sortedResult;
        inOrderTraversal(root, sortedResult);

        // 输出后序遍历结果
        for (size_t i = 0; i < postOrderResult.size(); ++i) {
            cout << postOrderResult[i];
            if (i < postOrderResult.size() - 1) cout << " ";
        }
        cout << endl;

        // 输出第k小的元素
        cout << sortedResult[k - 1] << endl;

        // 释放内存（可选，但建议）
        // 这里可以加入代码来释放树的节点内存
    }

    return 0;
}