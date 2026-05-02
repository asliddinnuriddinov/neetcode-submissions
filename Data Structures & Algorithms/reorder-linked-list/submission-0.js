/**
 * Definition for singly-linked list.
 * class ListNode {
 *     constructor(val = 0, next = null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */

class Solution {
    /**
     * @param {ListNode} head
     * @return {void}
     */
    reorderList(head) {
        let slow = head
        let fast = head.next

        while(fast && fast.next){
            slow = slow.next
            fast = fast.next.next
        }

        let prev = null
        while(slow){
            const next = slow.next
            slow.next = prev
            prev = slow
            slow = next
        }
        let headCurr = head

        while(prev && headCurr){
            const headNext = headCurr.next
            const prevNext = prev.next
            headCurr.next = prev
            prev.next = headNext
            headCurr = headNext
            prev = prevNext
        }
        return head
    }
}
