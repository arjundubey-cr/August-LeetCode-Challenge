class Solution {
public:
    int titleToNumber(string s) {
        int answer = 0;
        int n = s.length()-1;
        for(int i = n;i>=0;i--)
            answer+=pow(26,n-i)*(s[i]-'A'+1);      
        return answer;
    }
};
