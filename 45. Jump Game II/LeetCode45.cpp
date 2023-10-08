#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<math.h>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int stop = nums[0], preStop = 0, result = 0;

        if(nums.size() == 1)
            return 0;
        else if(stop + 1 >= nums.size())
            return 1;

        for(int i = 0; i < stop + 1; i++)
        {
            if(nums[i] + i > stop)
            {
                if(i > preStop)
                {
                    result++;
                    preStop = stop;
                }

                stop = nums[i] + i;

                if(stop+1 >= nums.size())
                    break;
            }
        }

        return result + 1;
    }
};