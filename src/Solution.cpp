#include "Solution.h"

TrieNode::TrieNode() {
    isWord = false;
    for(int i = 0; i < 26; i++) children[i] = nullptr;
}

std::vector<std::string> Solution::findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words) {
    TrieNode* root = new TrieNode();
    for (const std::string& w : words) {
        TrieNode* cur = root;
        for (char c : w) {
            int idx = c - 'a';
            if (!cur->children[idx]) cur->children[idx] = new TrieNode();
            cur = cur->children[idx];
        }
        cur->isWord = true;
    }

    int ROWS = board.size();
    int COLS = board[0].size();
    std::list<std::string> foundList; 

    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            backtracking(r, c, root, "", board, foundList, ROWS, COLS);
        }
    }

    return std::vector<std::string>(foundList.begin(), foundList.end());
}

void Solution::backtracking(int r, int c, TrieNode* node, std::string word, 
                             std::vector<std::vector<char>>& board, std::list<std::string>& foundList, 
                             int ROWS, int COLS) {
    
    if (r < 0 || c < 0 || r >= ROWS || c >= COLS || board[r][c] == '#' || !node->children[board[r][c] - 'a']) {
        return;
    }

    char temp = board[r][c];
    node = node->children[temp - 'a'];
    word += temp;

    if (node->isWord) {
        foundList.push_back(word);
        node->isWord = false; 
    }

    board[r][c] = '#'; 

    backtracking(r + 1, c, node, word, board, foundList, ROWS, COLS);
    backtracking(r - 1, c, node, word, board, foundList, ROWS, COLS);
    backtracking(r, c + 1, node, word, board, foundList, ROWS, COLS);
    backtracking(r, c - 1, node, word, board, foundList, ROWS, COLS);

    board[r][c] = temp; 
}