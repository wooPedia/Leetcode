/*
    [Easy] 21.Merge Two Sorted Lists
    ---------------------------------------------------------------------------------------------------------------------------------------------
    Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

    Example:

    Input: 1->2->4, 1->3->4
    Output: 1->1->2->3->4->4
    ---------------------------------------------------------------------------------------------------------------------------------------------

    - Definition for singly-linked list.
    * struct ListNode {
    *     int val;
    *     ListNode *next;
    *     ListNode(int x) : val(x), next(NULL) {}
    * };


 */
class Solution 
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {

        if (l1 == NULL && l2 == NULL)
            return NULL;
        else if (l1 == NULL)
            return l2;
        else if (l2 == NULL)
            return l1;

        ListNode* firstList = l1;
        ListNode* secondList = l2;
        ListNode* head = new ListNode(0);
        ListNode* curNode = head;
        ListNode* tempList;

        bool bFirst = true;
        while (firstList != NULL && secondList != NULL)
        {
            // ���� ���� ��带 ���ϴ�.
            tempList = (firstList->val > secondList->val) ? secondList : firstList;
            bFirst = (tempList == firstList) ? true : false;

            // ���� ����� next ��忡 �� ��带 �߰��մϴ�.
            curNode->next = new ListNode(tempList->val);
            curNode = curNode->next;

            // �߰��� ���� ���� ��带 ����Ű���� �մϴ�.   
            if (bFirst)
                firstList = firstList->next;
            else
                secondList = secondList->next;
        }

        // ������ ������ ���ս�ŵ�ϴ�.
        tempList = (firstList == NULL) ? secondList : firstList;
        while (tempList != NULL) {
            curNode->next = new ListNode(tempList->val);
            curNode = curNode->next;
            tempList = tempList->next;
        }

        return head->next;
    }
};