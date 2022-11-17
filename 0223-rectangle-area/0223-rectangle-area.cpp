class Solution {
public:
    
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        //TC :- O(1).SC :- O(1)
        int ox1 = max(ax1,bx1);
        int oy1 = max(ay1,by1);
        int ox2 = min(ax2,bx2);
        int oy2 = min(ay2,by2);
        
        int l1 = ax2-ax1;
        int h1 = ay2-ay1;
        int l2 = bx2-bx1;
        int h2 = by2-by1;
        
        int a1 = l1*h1;
        int a2 = l2*h2;
        
        int ol1 = ox2-ox1;
        int oh1 = oy2-oy1;
        if(ol1 >= 0 && oh1 >= 0)  //means overlapping portion is not fake so minus the overlapping area.
        {
            int oa = ol1*oh1;
            if(oa >= 0) 
                return (a1+a2-oa);
        }
        //in case it is not overlapping ol1 or oh1 will come as negative. so we will just return the actual are 
        return (a1+a2);
    }
};