class Solution {
public:
    long long sumOfDigits(long long n) 
    {
        int sum = 0;
        while(n) 
        {
            sum += (n%10);
            n = n/10;
        }
        
        return sum;
    }
    
    long long makeIntegerBeautiful(long long n, int target) {
        long long base = 1,temp = n;
        
        while(sumOfDigits(temp) > target) 
        {
            temp = temp/10 + 1; //467->47->5
            base = base*10;     //467(1 initially)->470(10)->500(100)
        }
        
        return temp*base-n;
    }
};