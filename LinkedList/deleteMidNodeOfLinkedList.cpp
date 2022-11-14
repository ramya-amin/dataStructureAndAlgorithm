/**
* Q. Delete the Middle Node of a Linked List
You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.

https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/

 By: Ramya Amin 
 Date: 14/Nov/2022
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
    ListNode* deleteMiddle(ListNode* head) {
        /*

            Lets consider using slow/fast pointer method 
            slowPointer would be at the middle element when fast reached the end of the linked list 

            Maintain another pointer to the previous element of mid element 

            preElement->next = midElement->next 

            delete midElement 

            return preElment

        */


        
        if(!head || !head->next ) return NULL; // if there is only one node in the given LL or no node then return NULL
        
        //If the given list has more than 1 elements then do find the mid element and then delete it by modifying 
        //its previous element's next field 

        ListNode* prevNode = NULL;  //to maintain previous element; starting with NULL as that way it would be 1 step previous to midNode 
        ListNode* midNode = head;
        ListNode* fastNode = head;
        while(fastNode && fastNode->next ){
            prevNode = midNode;
            midNode = midNode->next;
            fastNode = fastNode -> next -> next;

        }
        

        prevNode->next = midNode->next;
        delete midNode;

        return head;

    }
};