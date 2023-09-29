#include<iostream>
#include<string>
#include<vector>
#include <unordered_map>

using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isWord;
    
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isWord = false;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode *root = new TrieNode();
        TrieNode *node = root;
        vector<string> result;
        ilimit = board.size();
        jlimit = board[0].size();

        for(int i = 0; i < words.size(); i++)
            insertWords(words[i], root);
        
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[i].size(); j++)
            {
                search(root, "", result, board, i, j);
            }
        }

        return result;
    }
private:
    int ilimit, jlimit;
    void insertWords(string words, TrieNode *node)
    {
        for(int i = 0; i < words.size(); i++)
        {
            if(node->children[words[i] - 'a'] == NULL)
                node->children[words[i] - 'a'] = new TrieNode();
            node = node->children[words[i] - 'a'];
        }
        node->isWord = true;
        return;
    }

    void search(TrieNode *node, string curr, vector<string>& result, vector<vector<char>>& board, int i, int j)
    {
        if (i < 0 || i >= ilimit || j < 0 || j >= jlimit || board[i][j] == 'N') {
            return;
        }
        
        char temp = board[i][j];
        
        node = node->children[temp - 'a'];
        if (node == NULL) {
            return;
        }
        
        curr += board[i][j];
        if(node->isWord)
        {
            result.push_back(curr);
            node->isWord = false;
        }

        board[i][j] = 'N';

        search(node, curr, result, board, i - 1, j);
        search(node, curr, result, board, i + 1, j);
        search(node, curr, result, board, i, j - 1);
        search(node, curr, result, board, i, j + 1);

        board[i][j] = temp;
    }
};