#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<math.h>

using namespace std;

struct CompareByLength {
    bool operator()(string& a, string& b) {
        if(a.size() != b.size())
            return a.size() < b.size();
        else
            return a < b;
    }
};

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, CompareByLength> pq(nums.begin(), nums.end());
        for(k--; k > 0; k--)
            pq.pop();
        
        return pq.top();
    }
};