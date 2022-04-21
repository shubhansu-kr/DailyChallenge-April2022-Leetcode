// https://leetcode.com/problems/design-hashset/

#include <bits/stdc++.h>
using namespace std;

// Design a HashSet without using any built-in hash table libraries.

// Implement MyHashSet class:

// void add(key) Inserts the value key into the HashSet.
// bool contains(key) Returns whether the value key exists in
// the HashSet or not.
// void remove(key) Removes the value key in the HashSet. If key
// does not exist in the HashSet, do nothing.

struct node
{
    int val;
    node *next;
    node() : val(0), next(nullptr) {}
    node(int x) : val(x), next(nullptr) {}
    node(int x, node *next) : val(x), next(next) {}
};

class MyHashSet
{
    int count;
    node *head;

public:
    MyHashSet()
    {
        head = nullptr;
        count = 0;
    }

    void add(int key)
    {
        node *p = new node(key);
        if (count)
        {
            node *ptr = head;
            node *prev = head;
            while (ptr && ptr->val < key)
            {
                prev = ptr;
                ptr = ptr->next;
            }
            if (ptr == nullptr)
            {
                prev->next = p;
                return;
            }
            if (ptr->val != key)
            {
                ++count;
                if (ptr == head)
                {
                    p->next = ptr;
                    head = p;
                }
                else
                {
                    prev->next = p;
                    p->next = ptr;
                }
            }
        }
        else
        {
            head = p;
            ++count;
        }
    }

    void remove(int key)
    {
        // if count is zero -> set is empty -> no operation needed.
        if (count == 0)
        {
            return;
        }
        node *prev = head;
        node *ptr = head;
        while (ptr && ptr->val != key)
        {
            prev = ptr;
            ptr = ptr->next;
        }
        // If ptr is nullptr -> key does not exist -> no operation needed
        if (ptr)
        {
            --count;
            if (count == 0)
            {
                delete (head);
                head = nullptr;
                return;
            }
            prev->next = ptr->next;
            delete ptr;
        }
    }

    bool contains(int key)
    {
        node *ptr = head;
        while (ptr)
        {
            if (ptr->val == key)
            {
                return true;
            }
            ptr = ptr->next;
        }
        return false;
    }
};

int main()
{

    return 0;
}