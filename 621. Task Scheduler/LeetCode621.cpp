#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        queue<pair<int, int>> wait;
        vector<int> counts(26, 0);

        for(int i = 0; i < tasks.size(); i++)
            counts[tasks[i] - 'A']++;
        
        for(int i = 0; i < 26; i++)
        {
            if(counts[i] != 0)
                pq.push(counts[i]);
        }

        int time;
        for(time = 0; !pq.empty() || !wait.empty(); time++)
        {
            if(!wait.empty())
            {
                if(wait.front().second == time)
                {
                    pq.push(wait.front().first);
                    wait.pop();
                }
            }

            if(!pq.empty())
            {
                if(pq.top() > 1)
                    wait.push(make_pair(pq.top() - 1, time + n + 1));
                pq.pop();
            }
        }

        return time;
    }
};