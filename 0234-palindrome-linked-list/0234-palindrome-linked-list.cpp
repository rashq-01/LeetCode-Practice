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
    bool isPalindrome(ListNode* head) {
        int n = 0;
        ListNode* curr = head;
        while(curr){
            n++;
            curr = curr->next;
        }


        curr = head;
        ListNode* prev = nullptr;
        for(int i=0;i<n/2;i++){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        if(n%2==1)curr = curr->next;

        while(prev && curr){
            if(prev->val != curr->val)return false;

            prev = prev->next;
            curr = curr->next;
        }


        return true;

    }
};