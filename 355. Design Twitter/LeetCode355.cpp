#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class user{
public:
    vector<pair<int, int>> Post;
    unordered_set<int> followee;

    void post(int time, int tweetId)
    {
        Post.push_back(make_pair(time, tweetId));
    }

    void follow(int followeeId) 
    {
        followee.insert(followeeId);
    }
};

class Twitter {
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        if(records.find(userId) == records.end())
            records[userId] = new user();
        
        records[userId]->post(time, tweetId);
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int, int>> News;
        vector<int> result;

        if(records.find(userId) == records.end())
            return result;
        
        News.insert(News.end(), records[userId]->Post.begin(), records[userId]->Post.end());

        for(auto it = records[userId]->followee.begin(); it != records[userId]->followee.end(); it++)
            News.insert(News.end(), records[(*it)]->Post.begin(), records[(*it)]->Post.end());
        
        priority_queue<pair<int, int>> pq(News.begin(), News.end());

        while(!pq.empty() && result.size() < 10)
        {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
    
    void follow(int followerId, int followeeId) {
        if(records.find(followerId) == records.end())
            records[followerId] = new user();

        if(records.find(followeeId) == records.end())
            records[followeeId] = new user();
            
        records[followerId]->follow(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        records[followerId]->followee.erase(followeeId);
    }

private:
    int time;
    unordered_map<int, user*> records;
};