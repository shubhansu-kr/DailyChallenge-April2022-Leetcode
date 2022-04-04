// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

// You are given the head of a linked list, and an integer k.

// Return the head of the linked list after swapping the values
// of the kth node from the beginning and the kth node from the
// end (the list is 1-indexed).

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        // April 2022 - Daily challenge (Already solved this question before)
        ListNode *ptr = head;
        int i = 1;
        ListNode *first = NULL;
        ListNode *second = NULL;
        while (ptr != NULL)
        {
            if (second)
            {
                second = second->next;
            }
            if (i == k)
            {
                first = ptr;
                second = head;
            }
            ptr = ptr->next;
            i++;
        }
        swap(first->val, second->val);
        return head;
    }
};

int main()
{

    return 0;
}