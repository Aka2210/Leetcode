vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> record, result;
        vector<int> ans;
        int max = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            record[nums[i]] += 1;

            if(record[nums[i]] > max)
                max = record[i];
        }

        for(auto it = record.begin(); it != record.end(); it++)
            result[it->second] = it->first;
        
        for(int i = max; k > 0; i--)
        {
            if(result[i] != 0)
                k--;
                
            ans.push_back(result[i]);
        }
    }