class Solution {
public:
    
    bool isPrime(int n) 
    {
        if(n == 1)
            return false;
        for(int i=2;i<=sqrt(n);i++) 
        {
            if(n%i == 0)
                return false;
        }   
        return true;
    }
    bool isUgly(int n) {
        // n = abs(n);
        // cout<<" NEXT "<<n<<endl; 
        if(n <= 0) 
            return false;
        while(n) 
        {
            // cout<<n<<endl;
            if(n%2 == 0)
                n = n/2;
            else if(n%3 == 0)
                n = n/3;
            else if(n%5 == 0) 
                n = n/5;
            else 
                break;
        }
        // cout<<n<<endl;
        if(n == 1) 
            return true;
        return false;
    }
};