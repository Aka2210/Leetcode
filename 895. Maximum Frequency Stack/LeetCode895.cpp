#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include <algorithm>

using namespace std;

class FreqStack {
public:
    stack<pair<int, int>> deck;
    unordered_map<int, int> records, judge;
    int Max = 1;

    FreqStack() {
        
    }
    
    void push(int val) { 
        records[val]++;
        judge[records[val]]++;
        Max = max(records[val], Max);
        deck.push({val, records[val]});
    }
    
    int pop() {
        vector<pair<int, int>> tempRecords;
        while(deck.top().second != Max)
        {
            tempRecords.push_back({deck.top().first, deck.top().second});
            deck.pop();
        }

        int ans = deck.top().first;
        deck.pop();
        records[ans]--;
        judge[Max]--;
        if(judge[Max] == 0)
            Max--;

        for(int i = tempRecords.size() - 1; i >= 0 ; i--)
            deck.push(tempRecords[i]);

        return ans;
    }
};