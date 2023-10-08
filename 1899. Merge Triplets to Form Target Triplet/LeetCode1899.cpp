#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int start;
        for(start = 0; start < triplets.size(); start++)
        {
            if(triplets[start][0] <= target[0] && triplets[start][1] <= target[1] && triplets[start][2] <= target[2])
                break;
        }

        if(start == triplets.size())
            return false;

        for(int i = start+1; i < triplets.size(); i++)
        {
            int j = max(triplets[i][0], triplets[start][0]), k = max(triplets[i][1], triplets[start][1]), l = max(triplets[i][2], triplets[start][2]);

            if(j <= target[0] && k <= target[1] && l <= target[2])
            {
                triplets[start][0] = j;
                triplets[start][1] = k;
                triplets[start][2] = l;
            }
        }

        return (triplets[start][0] == target[0] && triplets[start][1] == target[1] && triplets[start][2] == target[2]);
    }
};