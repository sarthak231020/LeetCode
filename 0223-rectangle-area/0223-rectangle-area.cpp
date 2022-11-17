class Solution {
public:
    int calc(int p1,int p2) 
    {
        return p2-p1;
    }
    
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        cout<<"NEXT"<<endl;
        int ox1 = max(ax1,bx1);
        int oy1 = max(ay1,by1);
        int ox2 = min(ax2,bx2);
        int oy2 = min(ay2,by2);
        
        int l1 = calc(ax1,ax2);
        int h1 = calc(ay1,ay2);
        int l2 = calc(bx1,bx2);
        int h2 = calc(by1,by2);
        cout<<l1<<" "<<l2<<" "<<h1<<" "<<h2<<endl;
        int a1 = l1*h1;
        int a2 = l2*h2;
        
        // if((ax1 <= bx1 && bx1 <= ax2 && ay1 <= by1 && by1 <= ay2) || (ax1 <= bx2 && bx2 <= ax2 && ay1 <= by2 && by2 <= ay2) || (bx1 <= ax1 && ax1 <= bx2 && by1 <= ay1 && ay1 <= by2) || (bx1 <= ax2 && ax2 <= bx2 && by1 <= ay2 && ay2 <= by2))
        // {
            int ol1 = calc(ox1,ox2);
            int oh1 = calc(oy1,oy2);
            if(ol1 >= 0 && oh1 >= 0) 
            {
            int oa = ol1*oh1;
            if(oa >= 0) 
                return (a1+a2-oa);
            }
        // }
        return (a1+a2);
            
    }
};