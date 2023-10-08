#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0)
            return false;
        else if(groupSize == 1)
            return true;

        map<int, int> records;
        int result = 0;

        for(int i = 0; i < hand.size(); i++)
            records[hand[i]]++;

        while(!records.empty())
        {
            int curr = records.begin()->first;
            for(int i = 0; i < groupSize; i++)
            {
                if(records[curr+i] == 0)
                    return false;
                else
                    records[curr+i]--;
                
                if(records[curr+i] == 0)
                    records.erase(curr+i);
            }
        }

        return true;
    }
};