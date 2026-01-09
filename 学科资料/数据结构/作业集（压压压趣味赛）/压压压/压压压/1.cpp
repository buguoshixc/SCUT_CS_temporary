#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#include<bitset>
// 哈夫曼树节点结构
struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char character, int frequency) : ch(character), freq(frequency), left(nullptr), right(nullptr) {}
};

// 自定义比较函数，用于优先队列
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq; // 小根堆，频率小的优先
    }
};

// 生成哈夫曼编码
void generateHuffmanCodes(Node* root, const std::string& code, std::unordered_map<char, std::string>& huffmanCodes) {
    if (!root) return;
    if (root->left == nullptr && root->right == nullptr) {
        huffmanCodes[root->ch] = code; // 存储字符及其编码
    }
    generateHuffmanCodes(root->left, code + "0", huffmanCodes);
    generateHuffmanCodes(root->right, code + "1", huffmanCodes);
}

// 压缩文件
void compressFile(const std::string& filename, const std::unordered_map<char, std::string>& huffmanCodes) {
    std::ifstream inputFile(filename);
    std::ofstream outputFile(filename + ".huff", std::ios::binary);

    // 检查文件是否成功打开
    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "无法打开文件: " << filename << std::endl;
        return;
    }

    std::string encodedString;
    char ch;
    while (inputFile.get(ch)) {
        encodedString += huffmanCodes.at(ch); // 压缩为哈夫曼编码
    }

    // 将编码字符串转换为字节并写入输出文件
    for (size_t i = 0; i < encodedString.size(); i += 8) {
        std::string byteString = encodedString.substr(i, 8); // 每8个比特为一个字节
        if (byteString.size() < 8) { // 补全不足8位的字节
            byteString.append(8 - byteString.size(), '0');
        }
        unsigned char byte = static_cast<unsigned char>(std::bitset<8>(byteString).to_ulong());
        outputFile.put(byte);
    }

    inputFile.close();
    outputFile.close();
}

void countAllCharacters(const std::string& filename) {
    std::ifstream file(filename);

    // 检查文件是否成功打开
    if (!file.is_open()) {
        std::cerr << "无法打开文件: " << filename << std::endl;
        return;
    }

    // 使用 unordered_map 来统计字符的出现次数
    std::unordered_map<char, int> charCount;
    char ch;

    // 逐个字符读取文件
    while (file.get(ch)) {
        // 统计所有字符
        charCount[ch]++;
    }

    file.close();

    // 创建优先队列
    std::priority_queue<Node*, std::vector<Node*>, Compare> minHeap;

    // 为每个字符创建哈夫曼树节点并加入优先队列
    for (const auto& pair : charCount) {
        minHeap.push(new Node(pair.first, pair.second));
    }

    // 创建哈夫曼树
    while (minHeap.size() > 1) {
        Node* left = minHeap.top(); minHeap.pop();
        Node* right = minHeap.top(); minHeap.pop();
        Node* newNode = new Node('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        minHeap.push(newNode);
    }

    // 生成哈夫曼编码
    std::unordered_map<char, std::string> huffmanCodes;
    generateHuffmanCodes(minHeap.top(), "", huffmanCodes);

    // 排序字符
    std::vector<std::pair<char, int>> sortedChars(charCount.begin(), charCount.end());
    std::sort(sortedChars.begin(), sortedChars.end(), [](const auto& a, const auto& b) {
        return a.first < b.first; // 按字符排序
        });

    // 输出结果
    std::cout << "所有字符出现次数:" << std::endl;
    for (const auto& pair : sortedChars) {
        std::cout << "'" << pair.first << "' : " << pair.second << " -> " << huffmanCodes[pair.first] << std::endl;
    }

    // 压缩文件
    compressFile(filename, huffmanCodes);
}

int main() {
    std::string filename;
    std::cout << "请输入要分析的文件名: ";
    std::cin >> filename;

    countAllCharacters(filename);

    return 0;
}
