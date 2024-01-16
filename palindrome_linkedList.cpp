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
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return true;
        }
        stack<int> st;
        ListNode *temp = head;

        while (temp != NULL)
        {
            int x = temp->val;
            st.push(x);
            temp = temp->next;
        }
        temp = head;
        while (temp != NULL)
        {
            if (st.top() != temp->val)
            {
                return false;
            }
            st.pop();
            temp = temp->next;
        }
        return true;
    }
};