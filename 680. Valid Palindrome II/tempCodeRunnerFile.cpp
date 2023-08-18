    string s1 = s.substr(L, R-1), s2 = s.substr(L+1, R);

            for(L = 0, R = s.size() - 1;L < R; L++, R--)
            {
                if(s1[L] != s1[R] || s2[L] != s2[R])
                    return false;
            }