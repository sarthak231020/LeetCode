class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size()-1;
        int m = b.size()-1;
        
        string ans = "";
        
        int carry = 0;
        while((n != -1) && (m != -1))
        {
            // cout<<int(a[n])<<" "<<int(b[m])<<" "<<carry<<endl;
            int res = (int(a[n]-'0') + int(b[m]-'0') + carry)%2;
            carry = (int(a[n]-'0') + int(b[m]-'0') + carry)/2;
            ans = ans + to_string(res);
            n--;
            m--;
        }
        while(n != -1) 
        {
            int res = (int(a[n]-'0') + carry)%2;
            carry = (int(a[n]-'0') + carry)/2;
            ans = ans + to_string(res) ;
            n--;
        }
        while(m != -1) 
        {
            int res = (int(b[m]-'0') + carry)%2;
            carry = (int(b[m]-'0') + carry)/2;
            ans = ans + to_string(res);
            m--;
        }
        
        if(carry) 
            ans = ans + to_string(carry);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};