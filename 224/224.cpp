class Solution {
public:
    int calculate(string s) {
        stack<int> values;
        
        int result = 0;
        int sign = 1;
        
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ' ') continue;
            
            if(isdigit(s[i])) {
                int val = 0;
                
                while(i < s.length() && isdigit(s[i])) {
                    val = val * 10 + (s[i] - '0');
                    i++;
                }
                
                result+= (val * sign);
                i--;
            }
            else if(s[i] == '+') sign = 1;
            else if(s[i] == '-') sign = -1;
            else if(s[i] == '(') {
                
                values.push(result);
                values.push(sign);
                
                result = 0;
                sign = 1;
            }
            else {
                
                result *= values.top();
                values.pop();
                result += values.top();
                values.pop();
            }
        }
        
        return result;
    }
};
