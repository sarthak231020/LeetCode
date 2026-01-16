/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {

    public ListNode brutSol(ListNode list1,ListNode list2) 
    {
        // System.out.println("HERE");
        ListNode ansList = new ListNode(), ans = ansList;
        ListNode temp1 = list1, temp2 = list2;

        while(temp1 != null && temp2 != null) 
        {
            if(temp1.val <= temp2.val) 
            {
                ansList.next = new ListNode(temp1.val);
                temp1 = temp1.next;
            }
            else
            {
                ansList.next = new ListNode(temp2.val);
                temp2 = temp2.next;
            }
            ansList = ansList.next; 
        }

        while(temp1 != null) 
        {
            ansList.next = new ListNode(temp1.val);
            ansList = ansList.next;
            temp1 = temp1.next;
        }

        while(temp2 != null) 
        {
            ansList.next = new ListNode(temp2.val);
            ansList = ansList.next;
            temp2 = temp2.next;
        }

        ansList.next = null;
        return ans.next;
    }

    public ListNode optimal(ListNode list1,ListNode list2) 
    {
        ListNode temp1 = list1, temp2 = list2, ans = new ListNode(), ansTemp = ans;

        while(temp1 != null && temp2 != null) 
        {
            if(temp1.val <= temp2.val) 
            {
                ansTemp.next = temp1;
                ansTemp = temp1; 
                temp1 = temp1.next;
            }
            else
            {
                ansTemp.next = temp2;
                ansTemp = temp2; 
                temp2 = temp2.next;
            }
        }

        if(temp1 != null) 
            ansTemp.next = temp1;
        if(temp2 != null)
            ansTemp.next = temp2;

        return ans.next; 
    }

    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        // return brutSol(list1,list2);
        return optimal(list1,list2); 
    }
}