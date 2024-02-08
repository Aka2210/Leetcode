#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        int storage[n + 1];
        storage[0] = 0;
        storage[1] = 1;

        for(int i = 2; i <= n; i++)
            storage[i] = storage[i - 1] + storage[i - 2]; 
        
        return storage[n];
    }
};