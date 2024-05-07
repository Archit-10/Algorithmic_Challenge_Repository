#include <iostream>
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
    void helper(ListNode *head, int &carry)
    {
        if (!head)
            return;
        helper(head->next, carry);
        int product = head->val * 2 + carry;
        head->val = product % 10;
        carry = product / 10;
    }
    ListNode *doubleIt(ListNode *head)
    {
        int carry = 0;
        helper(head, carry);
        if (carry)
        {

            ListNode *newNode = new ListNode(carry);
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
};