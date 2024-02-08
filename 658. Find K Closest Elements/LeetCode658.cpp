#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size(), MAX = abs(arr[0] - x);
        vector<int> result;
        queue<int> q;
        q.push(arr[0]);
        k--;

        for(int i = 1; i < n; i++)
        {
            int curr = abs(arr[i] - x);
            if(curr < MAX && k == 0)
            {
                q.pop();
                q.push(arr[i]);
                MAX = q.front() - x >= 0 ? q.front() - x : x - q.front();
            }
            else if(k > 0)
            {
                k--;
                q.push(arr[i]);
            }  
        }

        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }
        sort(result.begin(), result.end());
        return result;
    }
};