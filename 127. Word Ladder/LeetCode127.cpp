#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size(), wordSize = beginWord.size();
        unordered_set<string> UnVisited; 
        queue<string> q;
        q.push(beginWord);

        for(int i = 0; i < n; i++)
           UnVisited.insert(wordList[i]);
        UnVisited.erase(beginWord); //將beginWord設為已訪問過
        int result = 1; //深度計數器

        while(!q.empty())
        {
            int count = q.size();
            for(int i = 0; i < count; i++)
            {
                for(int j = 0; j < wordSize; j++)
                {
                    char temp = q.front()[j]; //儲存原字元(最後要換回來)
                    for(int k = 0; k < 26; k++)
                    {
                        q.front()[j] = k + 'a'; //改變當前字元(a~z)
                        if(UnVisited.find(q.front()) != UnVisited.end())
                        {
                            UnVisited.erase(q.front()); //將此單詞設為拜訪過
                            q.push(q.front()); //推入隊列
                            if(q.front() == endWord) //若已找到end詞則回傳，但因為計數器是在while末端才增加，因此回傳前要先+1
                                return ++result;   
                        }
                    }
                    q.front()[j] = temp;
                }
                q.pop();
            }
            result++;
        }

        return 0; //代表沒找到endWord，回傳0(題目要求)
    }
};