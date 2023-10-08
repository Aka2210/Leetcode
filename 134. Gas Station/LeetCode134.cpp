#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<math.h>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0, GasChange = 0, n = gas.size(), result = 0;

        for(int i = 0; i < n; i++)
        {
            int sumConsume = gas[i] - cost[i];

            sum += sumConsume;
            GasChange += sumConsume;

            if(GasChange < 0)
            {
                result = i+1;
                GasChange = 0;
            }
        }

        return sum >= 0 ? result : -1;
    }
};