#include<iostream>
#include<string>
#include<vector>
#include <unordered_set>

using namespace std;

// 前綴、後綴的應用，前綴為前i-1個值的乘積，後綴為i+1到末端的乘積，最後兩者相乘就是答案了。
// 因為除法在程式上的操作較麻煩，因此用前後綴的方法可以避免像我的方法一樣使用除法。

class Solution {
public:
    // vector<int> productExceptSelf(vector<int>& nums) {   簡化寫法
    //     int n = nums.size();
    //     vector<int> result(n, 1);
        
    //     int prefix = 1;
    //     for (int i = 0; i < n; i++) {
    //         result[i] = prefix;
    //         prefix = prefix * nums[i];
    //     }
        
    //     int postfix = 1;
    //     for (int i = n - 1; i >= 0; i--) {
    //         result[i] = result[i] * postfix;
    //         postfix = postfix * nums[i];
    //     }
        
    //     return result;
    // }

    vector<int> prefixProduct(const vector<int>& nums) { //拆分寫法
        int n = nums.size();
        vector<int> prefix(n, 1);
        
        int product = 1;
        for (int i = 0; i < n; i++) {
            prefix[i] = product;
            product *= nums[i];
        }
        
        for(int num : prefix)
            cout << num << " ";
        cout << endl;

        return prefix;
    }

    vector<int> postfixProduct(const vector<int>& nums) {
        int n = nums.size();
        vector<int> postfix(n, 1);
        
        int product = 1;
        for (int i = n - 1; i >= 0; i--) {
            postfix[i] = product;
            product *= nums[i];
        }
        
        for(int num : postfix)
            cout << num << " ";
        cout << endl;

        return postfix;
    }

    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> prefix = prefixProduct(nums);
        vector<int> postfix = postfixProduct(nums);
        vector<int> result(n);
        
        for (int i = 0; i < n; i++) {
            result[i] = prefix[i] * postfix[i];
        }
        
        return result;
    }
};

int main()
{
    vector<int> nums;

    int question;

    while(cin >> question)
        nums.push_back(question);

    Solution AnswerFunction;

    for(int num : AnswerFunction.productExceptSelf(nums))
        cout << num << " ";
}