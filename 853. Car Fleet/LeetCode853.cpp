#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> storage;
        stack<pair<int, double>> ans;

        for(int i = 0; i < position.size(); i++)
            storage.push_back({position[i], speed[i]});

        sort(storage.begin(), storage.end());

        ans.push(storage[storage.size() - 1]);

        for(int i = storage.size() - 2; i >= 0; i--)
        {
            if(storage[i].second > ans.top().second && (target - storage[i].first) / storage[i].second <= (target - ans.top().first) / ans.top().second)
                continue;
            
            ans.push(storage[i]);
        }

        return ans.size();
    }
};

int main()
{
    vector<int> position, speed;

    int question, val;

    cin >> val;

    while(cin >> question)
        position.push_back(question);

    while(cin >> question)
        speed.push_back(question);

    Solution AnswerFunction;

    cout << AnswerFunction.carFleet(val, position, speed);
}