#include<bits/stdc++.h>
using namespace std;


struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};
void generateCodes(Node* root, string code, map<char,string> &huffmanCode) {
    if (!root) return;

    if (!root->left && !root->right) {
        huffmanCode[root->ch] = code;
        return;
    }

    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

int main() {

    string text;
    cout << "Enter text: ";
    getline(cin, text);   

    if(text.empty()){
        cout << "Text is empty!" << endl;
        return 0;
    }

    
    map<char,int> freq;
    for(char c : text)
        freq[c]++;

    cout << "\nFrequencies:\n";
    for(auto it : freq) {
        if(it.first == ' ')
            cout << "[space] : " << it.second << endl;
        else
            cout << it.first << " : " << it.second << endl;
    }


    priority_queue<Node*, vector<Node*>, Compare> pq;
    for(auto it : freq)
        pq.push(new Node(it.first, it.second));


    while(pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;

        pq.push(merged);
    }

    Node* root = pq.top();

    
    map<char,string> huffmanCode;
    generateCodes(root, "", huffmanCode);

    
    cout << "\nHuffman Table:\n";
    cout << "Character\tCode\n";
    for(auto it : huffmanCode) {
        if(it.first == ' ')
            cout << "[space]\t\t" << it.second << endl;
        else
            cout << it.first << "\t\t" << it.second << endl;
    }

    
    int compressedLength = 0;
    for(char c : text)
        compressedLength += huffmanCode[c].size();

    int originalLength = text.length() * 8;
    int tableLength = 0;

    for(auto it : huffmanCode)
        tableLength += 8 + it.second.length();  

    cout << "\nOriginal Length: " << originalLength << " bits" << endl;
    cout << "Compressed Message Length: " << compressedLength << " bits" << endl;
    cout << "Table Length: " << tableLength << " bits" << endl;
    cout << "New Length: " << compressedLength + tableLength << " bits" << endl;

    return 0;
}
