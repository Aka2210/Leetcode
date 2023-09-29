#include<iostream>
#include<string>
#include<vector>
#include <queue>

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

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *node = root;

        for(int i = 0; i < word.size(); i++)
        {
            if(node->children[word[i] - 'a'] == NULL)
                node->children[word[i] - 'a'] = new TrieNode();
            node = node->children[word[i] - 'a'];
        }

        node->isWord = true;
    }
    
    bool search(string word) {
        TrieNode *node = root;
        queue<TrieNode*> q;
        q.push(root);

        for(int i = 0; i < word.size(); i++)
        {
            int count = q.size();

            for(int j = 0; j < count; j++)
            {
                for(int k = 0; k < 26; k++)
                {
                    if(q.front()->children[k] != NULL && (word[i] == '.' || word[i] == (char)(k + 'a')))
                        q.push(q.front()->children[k]);
                    if( word[i] == (char)(k + 'a'))
                        break;
                }

                q.pop();
            }
        }

        while(!q.empty())
        {
            if(q.front()->isWord)
                return true;
            q.pop();
        }

        return false;
    }

private:
    TrieNode *root;
};