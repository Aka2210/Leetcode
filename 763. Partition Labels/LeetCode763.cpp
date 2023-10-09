#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<int, pair<int, int>> records;
        vector<int> result;

        for(int i = 0; i < s.size(); i++)
        {
            if(records.find(s[i]) == records.end())
                records[s[i]] = {i, i};
            else
                records[s[i]].second = i;
        }

        int Start = records[s[0]].first, Stop = records[s[0]].second;

        for(int i = 0; i < s.size(); i++)
        {
            if(records[s[i]].second > Stop && records[s[i]].first < Stop)
                Stop = records[s[i]].second;
            else if(records[s[i]].first > Stop)
            {
                result.push_back(Stop - Start + 1);
                Start = records[s[i]].first;
                Stop = records[s[i]].second;
            }
        }

        result.push_back(Stop - Start + 1);

        return result;
    }
};