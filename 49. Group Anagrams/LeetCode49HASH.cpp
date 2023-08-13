#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <cmath>
#include <random>

using namespace std;

// HASH方法，要開足夠大才能使得轉換後數字相加不重疊。A

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<float, vector<string>> storage;

        random_device rd;
        mt19937 gen(rd());

        uniform_int_distribution<> dist(1, 100000000000000LL);

        unordered_map<char, long long int> record = 
        {
            {'a', dist(gen)},{'b', dist(gen)},{'c', dist(gen)},{'d', dist(gen)},{'e', dist(gen)},
            {'f', dist(gen)},{'g', dist(gen)},{'h', dist(gen)},{'i', dist(gen)},{'j', dist(gen)},
            {'k', dist(gen)},{'l', dist(gen)},{'m', dist(gen)},{'n', dist(gen)},{'o', dist(gen)},
            {'p', dist(gen)},{'q', dist(gen)},{'r', dist(gen)},{'s', dist(gen)},{'t', dist(gen)},
            {'u', dist(gen)},{'v', dist(gen)},{'w', dist(gen)},{'x', dist(gen)},{'y', dist(gen)},
            {'z', dist(gen)}
        };

        for(int i = 0; i < strs.size(); i++)
        {
            long long int temp = 0;

            for(int j = 0; j < strs[i].length(); j++)
            {
                temp += record[strs[i][j]] * record[strs[i][j]];
            }

            if(storage.find(temp) == storage.end())
                storage.insert(make_pair(temp, vector<string>{}));
                
            storage[temp].push_back(strs[i]);
        }

        for(auto it = storage.begin(); it != storage.end(); it++)
        {
            ans.push_back(it->second);
            for(string str : it->second)
                cout << it->first << ":" << str << " ";
            cout << endl;
        }       

        for(vector<string> Arr : ans)
        {
            for(string str : Arr)
                cout << str << " ";
            cout << endl;
        }

        return ans;
    }
};

int main()
{
    vector<string> nums;

    string question;

    int i = 0;

    while(cin >> question)
    {
        if(question == "quit")
            break;

        nums.push_back(question);
    }

    Solution AnswerFunction;

    AnswerFunction.groupAnagrams(nums);
}