#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>

using namespace std;

class Solution {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string result = "";
        
        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            result += to_string(str.size()) + "#" + str;
        }
        
        return result;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;
        
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int length = stoi(s.substr(i, j - i));
            string str = s.substr(j + 1, length);
            result.push_back(str);
            i = j + 1 + length;
        }
        
        return result;
    }
};

int main()
{
    vector<string> strs;

    string question;

    while(cin >> question)
    {
        if(question == "quit")
            break;

        strs.push_back(question);
    } 

    Solution AnswerFunction;

    string Encode = AnswerFunction.encode(strs);
    cout << Encode << endl;
    for(string str : AnswerFunction.decode(Encode))
        cout << str << " ";
}