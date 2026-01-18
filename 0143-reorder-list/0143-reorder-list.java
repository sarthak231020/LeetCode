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
    public void reorderList(ListNode head) {
        // The idea here is to reverse the second half then mix one by one.
        if(head == null || head.next == null) 
            return;
        
        ListNode slow = head, fast = head;

        while(fast != null && fast.next != null)
        {
            slow = slow.next;
            fast = fast.next.next;
        }

        // Now reverse the second half.
        ListNode prev = null,curr = slow, nextPtr = slow;
        while(curr != null) 
        {
            nextPtr = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nextPtr;
        }

        // while(prev != null) 
        // {
        //     System.out.print(prev.val + " ");
        //     prev = prev.next;
        // }
        // System.out.println();

        // Prev will be pointing to last node and second half got reversed as well.
        // Now mix these two lists.
        ListNode prevL1 = head,tempL1 = head, tempL2 = prev, nextPtr1, nextPtr2;
        while(tempL1.next != tempL2 && tempL1 != tempL2)
        {
            // System.out.println(tempL1.val + " " + tempL2.val);
            nextPtr1 = tempL1.next;
            nextPtr2 = tempL2.next;
            tempL1.next = tempL2;
            tempL2.next = nextPtr1;
            tempL1 = nextPtr1;
            tempL2 = nextPtr2;
        }

    }

}