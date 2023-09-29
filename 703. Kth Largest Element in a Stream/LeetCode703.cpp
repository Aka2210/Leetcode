#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        kLargest = k;

        for(int i = 0; i < nums.size(); i++)
            pq.push(nums[i]);
        
        while(pq.size() > k)
            pq.pop();
    }
    
    int add(int val) {
        pq.push(val);

        while(pq.size() > kLargest)
            pq.pop();

        return pq.top();
    }

private:
    int kLargest;
    priority_queue<int, vector<int>, greater<int>> pq;
};