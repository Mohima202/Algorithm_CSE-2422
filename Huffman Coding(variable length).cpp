#include<iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;

struct Node{
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f){
        ch = c;
        freq = f;
        left = right = NULL;
    }
};
struct Compare {
    bool operator()(Node* a, Node* b){
        return a->freq > b->freq;
    }
};

map<char, string> huffmanCode;

void printCodes(Node* root, string code){
    if(!root) return;

    if(!root->left&&!root->right){
        huffmanCode[root->ch] = code;
        cout << "'" << root->ch << "' : " << code << endl;
    }
    printCodes(root->left,  code + "0");
    printCodes(root->right, code + "1");
}
int main(){
    string text;
    cout<<"Enter text:";
    getline(cin,text);

    if(text.empty()){
        cout<<"Text is empty!"<< endl;
        return 0;
    }
    map<char, int> freq;
    for(char c:text) freq[c]++;

    cout <<"\nFrequency Calculation:\n";
    for(auto &p:freq){
        if(p.first==' ')
            cout<<"[space] : "<<p.second<<endl;
        else
            cout<<p.first<<" : "<< p.second<<endl;
    }

    priority_queue<Node*, vector<Node*>, Compare> pq;
    for(auto &p : freq){
        pq.push(new Node(p.first, p.second));
    }

    while(pq.size() > 1){
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* newNode = new Node('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    Node*root=pq.top();

    cout<<"\nHuffman Codes:\n";
    printCodes(root,"");

    int originalSize = text.size()*8;
    int compressedSize = 0;

    for(auto &p : freq){
        compressedSize += p.second * huffmanCode[p.first].size();
    }

    cout <<"\nOriginal size:"<<originalSize <<"bits"<<endl;
    cout <<"Compressed size:"<<compressedSize <<"bits"<< endl;
    cout <<"Compression ratio:"<<(double)compressedSize / originalSize << endl;

    return 0;
}
