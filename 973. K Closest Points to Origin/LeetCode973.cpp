#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<math.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, CustomCompare> pq;
        vector<vector<int>> result;

        for(int i = 0; i < points.size(); i++)
            pq.push(make_pair(points[i][0] * points[i][0] + points[i][1] * points[i][1], i));

        for(int i = 0; i < k; i++)
        {
            result.push_back(points[pq.top().second]);
            pq.pop();
        }

        return result;
    }
private:
    struct CustomCompare {
        bool operator()(pair<int, int> a, pair<int, int> b) const {
            return a.first > b.first;
        }
    };
};