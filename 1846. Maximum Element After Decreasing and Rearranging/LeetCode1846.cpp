#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>

using namespace std;
//若陣列長度不大，此算法即可
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

//陣列長度大算法如下:
/*
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        unordered_map<int, int> ValRecords;

        for(int i = 0; i < arr.size(); i++)
        {
            if(arr[i] <= arr.size())
                ValRecords[arr[i]]++;
            else
                ValRecords[arr.size()]++;
        }

        int result = 1, offset = 0, Val = 1;
        for(int i = 0; i < arr.size(); i++, Val++)
        {     
            while(ValRecords[Val] != 0)
            {
                ValRecords[Val]--;
                if(result < Val)
                    result++;
                i++;
            }

            i--;
        }

        return result;
    }
};
*/