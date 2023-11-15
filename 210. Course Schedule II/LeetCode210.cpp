#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        bool visited[numCourses];
        unordered_map<int, vector<int>> records;
        int count[numCourses];
        vector<int> result;
        queue<int> q;

        for(int i = 0; i < numCourses; i++)
        {
            count[i] = 0;
            visited[i] = false;
        }

        for(int i = 0; i < prerequisites.size(); i++)
        {
            count[prerequisites[i][0]]++; //紀錄有多少課程指向此課程，代表此課程有多少先修
            records[prerequisites[i][1]].push_back(prerequisites[i][0]); //建立graphs各節點的關聯
        }

        for(int i = 0; i < numCourses; i++)
        {
            if(count[i] == 0) //偵測root(若無節點指向該課程則代表此為root)
            {
                q.push(i);
                visited[i] = true; 
            }
        }

        while(!q.empty())
        {
            int n = q.size();
            for(int i = 0; i < n; i++)
            {
                result.push_back(q.front());
                for(int j = 0; j < records[q.front()].size(); j++)
                {
                    int now = records[q.front()][j];
                    if(visited[now] == true) //若拜訪了已經拜訪過的節點代表形成循環，有課程永遠無法完成，因此直接return
                        return {};
                    count[now]--; //代表完成一個此課程的先修
                    if(count[now] == 0) //若每個先修都完成，則可以完成此課程
                    {
                        q.push(now);
                        visited[now] = true;
                    }
                }
                q.pop();
            }
        }

        if(result.size() == numCourses)
            return result;
        else
            return {};
    }
};