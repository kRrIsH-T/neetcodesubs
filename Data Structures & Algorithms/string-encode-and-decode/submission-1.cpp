class Solution {
public:
    // encode by putting # 
    string encode(vector<string>& strs) {
        string ans;
        for(auto word: strs)
        {
            ans += to_string(word.length()) + "#" + word;
        }
        return ans;
    }

    vector<string> decode(string s) {
        // cout << s << "\n";
        int left = 0;
        vector<string> ans;
        int n = s.size();
        int right = 0;
        while(left < n-1)
        {
            right++;
            if(s[right] == '#')
            {
                int k = stoi(s.substr(left,right-left));
                string dec = s.substr(right+1,k);
                ans.push_back(dec);
                left = right+k+1;
                right = left;
            }
        }
        return ans;
    }
};
