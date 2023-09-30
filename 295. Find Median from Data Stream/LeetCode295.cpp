#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(pqL.empty())
        {
            pqL.push(num);
            return;
        }
        
        if(pqL.size() == pqR.size())
        {
            if(pqR.top() < num)
            {
                pqL.push(pqR.top());
                pqR.pop();
                pqR.push(num);
            }
            else
                pqL.push(num);
        }
        else
        {
            if(num < pqL.top())
            {
                pqR.push(pqL.top());
                pqL.pop();
                pqL.push(num);
            }
            else
                pqR.push(num);
        }
    }
    
    double findMedian() {
        if(pqL.size() == pqR.size())
            return (double)(pqL.top() + pqR.top()) / 2;
        else
            return pqL.top();
    }

private:
    priority_queue<int> pqL;
    priority_queue<int, vector<int>, greater<int>> pqR;
};