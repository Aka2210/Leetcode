#include<iostream>
#include<vector>
#include<deque>
#include <algorithm>

using namespace std;

class MinStack {
public:
    vector<int> records;
    deque<int> Min;

    MinStack() {
        
    }
    
    void push(int val) {
        records.push_back(val);

        if(records.size() == 1)
            Min.push_back(records.size() - 1);
        else if(val < records[Min.back()])
            Min.push_back(records.size() - 1);
    }
    
    void pop() {
        if(records.size() - 1 == Min.back())
            Min.pop_back();

        records.pop_back();
    }
    
    int top() {
        return records[records.size() - 1];
    }
    
    int getMin() {
        return records[Min.back()];
    }
};