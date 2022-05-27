class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* p=head, *ff=head, *ss=head;
        for(int i=1;i<k;i++)
            p=p->next;
        ff= p;
        while(p->next)
        {
            p=p->next;
            ss=ss->next;
        }
        swap(ff->val,ss->val);
        return head;
    }
};