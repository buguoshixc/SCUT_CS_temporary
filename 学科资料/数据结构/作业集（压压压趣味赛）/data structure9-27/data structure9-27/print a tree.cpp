//#include <iostream>
//#include <queue>
//#include <string>
//#include <vector>
//using namespace std;
//struct TreeNode//树节点
//{
//    char value;//值
//    TreeNode* left;//左孩子
//    TreeNode* right;//右孩子
//
//    TreeNode(char val) : value(val), left(nullptr), right(nullptr) {}
//};
//
//TreeNode* buildTree(const string& preorder, int& index) //前序遍历满二叉树
//{
//    if (index >= preorder.length()) return nullptr;
//
//    TreeNode* node = new TreeNode(preorder[index++]);
//
//    if (islower(node->value)) {
//        node->left = buildTree(preorder, index);
//        node->right = buildTree(preorder, index);
//    }
//
//    return node;//返回树
//}
////水平打印树
//void printLevelOrder(TreeNode* root) {
//    if (!root) return;
//
//    queue<TreeNode*> q;
//    q.push(root);
//
//    while (!q.empty()) {
//        int levelSize = q.size();
//        for (int i = 0; i < levelSize; ++i) {
//            TreeNode* node = q.front();
//            q.pop();
//            cout << node->value;
//
//            // Push left and right children (if they exist)
//            if (node->left) q.push(node->left);
//            if (node->right) q.push(node->right);
//        }
//    }
//    cout << endl;
//}
//
//int main() {
//    int T;
//    cin >> T;  // Read number of test cases
//    cin.ignore();  // To ignore the newline after the integer input
//
//    for (int i = 0; i < T; ++i) {
//        string preorder;
//        getline(cin, preorder);  // Read the preorder traversal string
//
//        int index = 0;
//        TreeNode* root = buildTree(preorder, index); // Build the tree
//        printLevelOrder(root); // Print the tree level-wise
//
//    }
//
//    return 0;
//}
