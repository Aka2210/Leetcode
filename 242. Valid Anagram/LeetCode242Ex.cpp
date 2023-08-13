#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<string.h>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        
        unordered_map<char,int> smap;
        unordered_map<char,int> tmap;
        
        for(int i = 0; i < s.size(); i++){
            smap[s[i]]++;
            tmap[t[i]]++;
        }
        
        cout << smap.size() << endl;

        for (auto it = smap.begin(); it != smap.end(); ++it) {
            char key = it->first;
            int valueInS = it->second;
            int valueInT = tmap[key];

            if (valueInS != valueInT) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    string s, t;

    cin >> s >> t;

    Solution AnswerFunction;

    if(AnswerFunction.isAnagram(s, t))
        cout << "true";
    else
        cout << "false";
}