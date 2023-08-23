public:
    int characterReplacement(string s, int k) {
        int ans = 0, L = 0, R = 0;
        char init;

        while(R < s.size())
        {
            int changeChance = k;
            init = s[L];

            while(s[L - 1] == s[L])
                L--;
            
            while(s[R + 1] == s[R])
                R++;

            while(changeChance >= 2)
            {
                if(L > 0 && s[L - 1] != s[L])
                    changeChance--;

                if(R < s.size() - 1 && s[R + 1] != s[R])
                    changeChance--;

                if(L > 0)
                    L--;
                if(R < s.size() - 1)
                    R++;
            }

            cout << L << " " << R << " " << changeChance << endl;

            if(changeChance > 0 && s[L - 1] != s[L] && s[R + 1] != s[R])
                ans = max(ans, max(R - LeftJudge(s, L, changeChance, init) + 1, RightJudge(s, R, changeChance, init) - L + 1));
            else if(changeChance > 0 && s[L - 1] != s[L])
                ans = max(ans, R - LeftJudge(s, L, changeChance, init) + 1);
            else if(changeChance > 0 && s[R - 1] != s[R])
                ans = max(ans, RightJudge(s, R, changeChance, init) - L + 1);
            else if(changeChance == 0)
                ans = max(ans, R - L + 1);

            R++;
            L = R;
        }

        return ans;
    }

private:
    int LeftJudge(string s, int L, int changeChance, char init)
    {
        while(L > 0 && (changeChance > 0 || s[L - 1] == init))
        {
            if(s[L - 1] != init)
                changeChance--;

            L--;
        }

        return L;
    }

    int RightJudge(string s, int R, int changeChance, char init)
    {
        while(R < s.size() - 1 && (changeChance > 0 || s[R + 1] == init))
        {
            if(s[R + 1] != init)
                changeChance--;

            R++;
        }

        return R;
    }