vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> records;
        unordered_map<int, vector<int>> ans;
        vector<int> result;
        int Max = 0;

        for(int num : nums)
            records[num]++;

        for(int num : nums)
        {
            if(ans.find(records[num]) == ans.end())
            {
                ans[records[num]].push_back(num);
                Max = max(records[num], Max);
            }
        }

        for(int i = Max; k > 0; i--)
        {
            if(ans.count(i))
            {
                for(int num : ans[i])
                    result.push_back(num);
                k -= ans[i].size();
            }
        }

        return result;
    }