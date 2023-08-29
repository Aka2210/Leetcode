#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums){            
            int ans;            
            int fp, sp;            
            int sum;            
            fp = 0;            
            sp = 1;            
            sum = nums[0];            
            ans = nums.size() + 1;            
            while(fp != sp){                
                if(sum >= target){                    
                    ans = min(sp - fp, ans);                    
                    sum = sum - nums[fp];                    
                    fp++;                    
                }
                else{                        
                    if(sp < nums.size()){                         
                        sum = sum + nums[sp];
                        sp++;                            
                    }
                    else{                            
                        fp++;                            
                    }                    
                }                  
            }      

            if(ans == nums.size() + 1)
                ans = 0;  
            return ans;
        }    
};

int main()
{
    vector<int> nums;

    int question, val;

    cin >> val;

    while(cin >> question)
        nums.push_back(question);

    Solution AnswerFunction;

    cout << AnswerFunction.minSubArrayLen(val, nums);
}