#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> records;

    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        records[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        int L = 0, R = records[key].size() - 1, Max = -1;

        while(L <= R)
        {
            int mid = L + (R - L) / 2;

            if(records[key][mid].first <= timestamp)
            {
                Max = max(Max, mid);
                L = mid + 1;
            }
            else
                R = mid - 1;
        }

        return Max == -1 ? "" : records[key][Max].second;
    }
};