string delLetter(string s){
        stack<char> v;
        for(int i=0; i<s.size(); i++){
            char c = s[i];
            if(c!='#'){
                v.push(c);
            }else if(!v.empty()){
                v.pop();
            }
        }
        string res = "";
        while(!v.empty()){
            res.push_back(v.top());
            v.pop();
        }
        return res;
    }
    bool backspaceCompare(string s, string t) {
        string ss = delLetter(s);
        // cout<<ss[0]<<ss[1]<<endl;
        string tt = delLetter(t);
        // cout<<tt[0]<<tt[1]<<endl;
        return !ss.compare(tt);
    }
