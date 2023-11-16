#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        arr[0] = 1;
        for(int i = 1; i < arr.size(); i++)
        {
            if(arr[i] - arr[i - 1] == 0) continue;
            else arr[i] = arr[i - 1] + 1;
        }

        return arr.back();
    }
};