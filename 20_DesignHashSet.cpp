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
private:
    int prime;
    vector<list<int>> table;

    int hash(int key)
    {
        return key % prime;
    }

    list<int>::iterator search(int key)
    {
        int h = hash(key);
        return find(table[h].begin(), table[h].end(), key);
    }

public:
    MyHashSet() : prime(10007), table(prime) {}

    void add(int key)
    {
        int h = hash(key);
        if (!contains(key))
            table[h].push_back(key);
    }

    void remove(int key)
    {
        int h = hash(key);
        auto it = search(key);
        if (it != table[h].end())
            table[h].erase(it);
    }

    bool contains(int key)
    {
        int h = hash(key);
        return search(key) != table[h].end();
    }
};

class MyHashSet
{
private:
    // Troll solution
    vector<bool> table;

public:
    MyHashSet() : table(1e6 + 1, false) {}

    void add(int key)
    {
        table[key] = true;
    }

    void remove(int key)
    {
        table[key] = false;
    }

    bool contains(int key)
    {
        return table[key];
    }
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