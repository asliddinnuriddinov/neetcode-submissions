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
        let second = slow.next
        slow.next = null
        let prev = null
        while(second){
            const next = second.next
            second.next = prev
            prev = second
            second = next
        }
        let headCurr = head

        while(prev){
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
