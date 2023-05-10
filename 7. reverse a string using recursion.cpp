    void solve(vector<char>&s, int start, int end)
    {

        //base case
        if(start>=end)
        {
            return;
        }

        swap(s[start],s[end]);

        //recursive call
        solve(s,start+1,end-1);
        
    }

    void reverseString(vector<char>& s) {
        int start = 0;
        int end = s.size()-1;
       solve(s,start,end);

    }
