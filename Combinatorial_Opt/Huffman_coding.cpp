#include<bits/stdc++.h>
using namespace std;

struct HuffmanNode {
    char data;
    unsigned frequency;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char data, unsigned frequency){
        this->data = data;
        this->frequency = frequency;
        left = right = NULL;
    }
};

bool compareNodes(const HuffmanNode* node1, const HuffmanNode* node2) {
    return node1->frequency > node2->frequency;
}

HuffmanNode* buildHuffmanTree(const vector<char> &data, const vector<unsigned> &freq) {
    vector<HuffmanNode*> nodes;

    for (size_t i = 0; i < data.size(); ++i) {
        nodes.push_back(new HuffmanNode(data[i], freq[i]));
    }

    while (nodes.size() > 1) {
        sort(nodes.begin(), nodes.end(), compareNodes);

        HuffmanNode* left = nodes.back();
        nodes.pop_back();

        HuffmanNode* right = nodes.back();
        nodes.pop_back();

        HuffmanNode* parent = new HuffmanNode('$', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;

        nodes.push_back(parent);
    }

    return nodes.front();
}

void generateHuffmanCodes(HuffmanNode* root, const string& code, unordered_map<char, string>& huffmanCodes) {
    if (root == nullptr) {
        return;
    }

    if (root->data != '$') {
        huffmanCodes[root->data] = code;
    }

    generateHuffmanCodes(root->left, code + "0", huffmanCodes);
    generateHuffmanCodes(root->right, code + "1", huffmanCodes);
}

string encodeData(const string& data, const unordered_map<char, string>& huffmanCodes) {
    string encodedData;
    for (char c : data) {
        encodedData += huffmanCodes.at(c);
    }
    return encodedData;
}

int main() {
    vector<char> data = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<unsigned> freq = {5, 9, 12, 13, 16, 45};

    HuffmanNode* root = buildHuffmanTree(data, freq);

    unordered_map<char, string> huffmanCodes;
    generateHuffmanCodes(root, "", huffmanCodes);

    string inputText = "abacabad";
    string encodedText = encodeData(inputText, huffmanCodes);

    cout << "Character Codes:" << endl;
    for (const auto& code : huffmanCodes) {
        cout << "'" << code.first << "': " << code.second << endl;
    }

    cout << "Encoded data: " << encodedText << endl;

    return 0;
}
