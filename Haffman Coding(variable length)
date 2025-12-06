#include<iostream>
#include<queue>
#include<vector>
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
void printCodes(Node* root, string code){
    if (!root) return;

    if (!root->left && !root->right){
        cout << root->ch << " : " << code << endl;
    }
    printCodes(root->left,  code + "0");
    printCodes(root->right, code + "1");
}
int main(){
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    vector<char> characters(n);
    vector<int> freq(n);

    cout << "Enter characters:" << endl;
    for (int i = 0; i < n; i++)
        cin >> characters[i];

    cout << "Enter frequencies:" << endl;
    for (int i = 0; i < n; i++)
        cin >> freq[i];

    priority_queue<Node*, vector<Node*>, Compare> pq;


    for (int i = 0; i < n; i++){
        pq.push(new Node(characters[i], freq[i]));
    }
    while (pq.size() > 1){
        Node* left  = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* newNode = new Node('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }
    Node*root=pq.top();

    cout<<"\nHuffman Codes:\n";
    printCodes(root, "");

    return 0;
}
