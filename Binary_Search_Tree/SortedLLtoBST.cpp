//https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
//PC

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head){
            return NULL;
        }
        if(!head->next){
            return new TreeNode(head->val);
        }
        ListNode* temp = NULL;
        ListNode* slow=head;
        ListNode* fast = head;
        while(fast!=NULL and fast->next!=NULL){
            temp=slow;
            slow=slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL;
        TreeNode* root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        return root;
    }
};