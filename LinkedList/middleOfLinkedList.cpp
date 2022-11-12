/*
876. Middle of the Linked List
https://leetcode.com/problems/middle-of-the-linked-list/description/
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

Example 1:


Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        // Fast and slow moving pointers approach
        // one pointer moves by and another moves by 2 steps
        // when the fast pointer meets NULL pointer(even) or if its next is NULL(odd no. elements), slow pointer would be pointing at the mid element 

        ListNode* oneStepNode = head;
        ListNode* twoSstepNode = head;

        while(twoSstepNode != NULL && twoSstepNode->next != NULL){
            oneStepNode = oneStepNode ->next;
            twoSstepNode = twoSstepNode->next->next;
            }

        return oneStepNode;
        
    }
};
