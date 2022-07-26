class Solution {
  int n, m;
//Node to create trie
struct Node {
    char c;
    int ends;
    string word;
    Node* child[26];
};

//To create a new Node
struct Node* getNode(char c) {
    Node* newNode = new Node;
    newNode->c = c;
    newNode->ends = 0;
    newNode->word = ""; 
    
    for(int i=0; i<26; i++) {
        newNode->child[i] = NULL;
    }
    return newNode;
}

Node* root = getNode('/'); //Root of trie 

//To insert a string into the trie
void insert(string s) {
    Node* curr = root;
    int index, i = 0;
    while(i < s.length()) {
        index = s[i]-'a';
        if(curr->child[index] == NULL) {
            curr->child[index] = getNode(s[i]);
        }
        
        curr = curr->child[index];
        i += 1;
    }
    
    curr->ends += 1;
    curr->word = s;
}

void solve(int i, int j, vector<vector<char>>& board, vector<string> &v, Node* curr) {
    int index = board[i][j]-'a'; //Index of current character in board
    //Base case when character is visited or doesn't have the child
    if(board[i][j] == '$' || curr->child[index] == NULL)
        return;
    
   // Move to next refrence and check for word end
    curr = curr->child[index];
    if(curr->ends > 0) {
        v.push_back(curr->word);
        curr->ends -= 1;
    }
    
    //Mark visited and traverse
    char ch = board[i][j];
    board[i][j] = '$';
    
    if(i > 0)
    solve(i-1, j, board, v, curr);
    if(i< n-1)
    solve(i+1, j, board, v, curr);
    if(j > 0)
    solve(i, j-1, board, v, curr);
    if(j < m-1)
    solve(i, j+1, board, v, curr);
    
    board[i][j] = ch; //Backtrack
}

public:

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
         n = board.size();
    m = board[0].size();
    
    //Insert all the words and create trie
    for(int i=0; i<words.size(); i++) {
        insert(words[i]);
    }
    
    //Iterate and do a dfs traversal
    vector<string> v;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            solve(i, j, board, v, root);
        }
    }
    
    return v;
    }
}; 