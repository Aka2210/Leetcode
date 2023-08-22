int lengthOfLongestSubstring(string s) {
        int L = 0, R = 1, ans = 0;
        unordered_set<char> records;
        
        records.insert(s[L]);
        
        while(R < s.size())
        {
            if(!records.count(s[R]))
                records.insert(s[R]);
            else
            {
                L = R;
                records.clear();
                records.insert(s[L]);
            }

            R++;
            ans = max(ans, R - L);
        }

        return ans;
    }