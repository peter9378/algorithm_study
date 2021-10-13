/**
 * Definition for singly-linked list.
 * class ListNode(_x: Int = 0, _next: ListNode = null) {
 *   var next: ListNode = _next
 *   var x: Int = _x
 * }
 */
object Solution {
    def mergeTwoLists(l1: ListNode, l2: ListNode): ListNode = (l1, l2) match {
        case (l1, null) => l1
        case (null, l2) => l2
        case (l1, l2) if (l1.x <= l2.x) => {
            l1.next = mergeTwoLists(l1.next, l2)
            l1
        }
        case (l1, l2) if (l1.x > l2.x) => {
            l2.next = mergeTwoLists(l1, l2.next)
            l2
        }
    }
}
