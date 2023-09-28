#include<iostream>
#include<string>
#include<vector>
#include <unordered_map>

using namespace std;

class Trie {
public:
    unordered_map<char, Trie*> childrens;
    bool terminal;
    Trie *curr;

    Trie() {
        terminal = false;
        curr = this;
    }
    
    void insert(string word) {
        cout << word << " ";
        for(int i = 0; i < word.size(); i++)
        {
            if(curr->childrens.find(word[i]) == curr->childrens.end())
                curr->childrens[word[i]] = new Trie();

            curr = curr->childrens[word[i]];
        }

        curr->terminal = true;
        curr = this;
    }
    
    bool search(string word) {
        for(int i = 0; i < word.size(); i++)
        {
            if(curr->childrens.find(word[i]) == curr->childrens.end())
            {
                curr = this;
                return false;
            }
            else
                curr = curr->childrens[word[i]];
        }

        Trie *temp = curr;
        curr = this;
        return temp->terminal;
    }
    
    bool startsWith(string prefix) {
        for(int i = 0; i < prefix.size(); i++)
        {
            if(curr->childrens.find(prefix[i]) == curr->childrens.end())
            {
                curr = this;
                return false;
            }
            else
                curr = curr->childrens[prefix[i]];
        }

        curr = this;
        return true;
    }
};