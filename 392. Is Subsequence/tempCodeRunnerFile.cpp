bool isSubsequence(string s, string t) {
        if(s == "")
            return true;
            
        int Position = 0;

        for(char ch : t)
        {
            if(s[Position] == ch)
                Position++;
        }

        if(Position >= s.size())
            return true;
        else
            return false;
    }