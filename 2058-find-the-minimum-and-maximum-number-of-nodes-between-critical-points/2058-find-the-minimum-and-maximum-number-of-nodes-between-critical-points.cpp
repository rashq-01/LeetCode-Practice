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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int veryFirstC = -1;
        int prevC = -1;
        int curr = 2;

        int maxDist = INT_MIN;
        int minDist = INT_MAX;

        ListNode* prev = head;
        head = head->next;
        while(head->next){
            //Local Maxima
            if(head->val > prev->val && head->val > head->next->val){
                if(veryFirstC == -1){
                    prevC = curr;
                    veryFirstC = curr;
                }
                else{
                    maxDist = max(maxDist,curr-veryFirstC);
                    minDist = min(minDist,curr-prevC);
                    prevC = curr;
                }

            }

            //Local mini
            if(head->val < prev->val && head->val < head->next->val){
                if(veryFirstC == -1){
                    prevC = curr;
                    veryFirstC = curr;
                }
                else{
                    maxDist = max(maxDist,curr-veryFirstC);
                    minDist = min(minDist,curr-prevC);
                    prevC = curr;
                }

            }
            curr++;
            prev = head;
            head = head->next;
        }



        return {minDist==INT_MAX ? -1 : minDist , maxDist==INT_MIN ? -1 : maxDist};
    }
};