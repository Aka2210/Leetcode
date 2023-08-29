#include<iostream>
#include<vector>
#include<unordered_map>
#include <algorithm>
#include<string>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26);
        int maxCount = 0;
        
        int i = 0;
        int j = 0;
        
        int result = 0;
        
        while (j < s.size()) {
            count[s[j] - 'A']++;
            maxCount = max(maxCount, count[s[j] - 'A']);
            if (j - i + 1 - maxCount > k) {
                count[s[i] - 'A']--;
                i++;
            }
            result = max(result, j - i + 1);
            j++;
        }
        
        return result;
    }
};

int main()
{
    int target;
    cin >> target;
    string s;

    cin>>s;

    Solution AnswerFunction;

    cout << AnswerFunction.characterReplacement(s, target);
}