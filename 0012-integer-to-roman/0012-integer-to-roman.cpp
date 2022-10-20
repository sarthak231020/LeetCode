class Solution {
public:
    string intToRoman(int num) {
//         map<int,string> mp;
//         mp[1] = "I";
//         mp[4] = "IV";
//         mp[5] = "V";
//         mp[9] = "IX";
//         mp[10] = "X";
//         mp[40] = "XL";
//         mp[50] = "L";
//         mp[90] = "XC";
//         mp[100] = "C";
//         mp[400] = "CD";
//         mp[500] = "D"; 
//         mp[900] = "CM";
//         mp[1000] = "M"; 
        
//         vector<int> v = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        
//         int i = v.size()-1; 
//         string ans = "";
//         while(i >= 0 && num) 
//         {
//             while(num >= v[i]) 
//             {
//                 ans += mp[v[i]];
//                 num -= v[i];
//             }
//             i--;
//         }
        // return ans;
        //Optimized Solution :- 
        //Ind                   0  1   2    3     4    5   6     7      8     9 
        vector<string> ones = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        vector<string> tens = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        vector<string> hnrs = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        vector<string> thds = {"","M","MM","MMM"};
        
        return thds[num/1000]+hnrs[(num%1000)/100]+tens[(num%100)/10]+ones[num%10];
        
        
        
    }
};