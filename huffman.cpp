#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) : ch(c), freq(f), left(NULL), right(NULL) {}
};

// Compare function for min-heap
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void printCodes(Node* root, string code) {
    if (!root) return;
    if (!root->left && !root->right)  // leaf node
        cout << root->ch << " : " << code << endl;
    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

void HuffmanCoding(vector<char> chars, vector<int> freq) {
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (int i = 0; i < chars.size(); i++)
        pq.push(new Node(chars[i], freq[i]));

    while (pq.size() > 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();
        Node *newNode = new Node('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }

    Node* root = pq.top();
    printCodes(root, "");
}

int main() {
    vector<char> chars = {'A', 'B', 'C', 'D', 'E', 'F'};
    vector<int> freq = {5, 9, 12, 13, 16, 45};

    cout << "Huffman Codes:\n";
    HuffmanCoding(chars, freq);
    return 0;
}
