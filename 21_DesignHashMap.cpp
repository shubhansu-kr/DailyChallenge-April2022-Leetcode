// https://leetcode.com/problems/design-hashmap/

// Design a HashMap without using any built-in hash table libraries.

// Implement the MyHashMap class:

// MyHashMap() initializes the object with an empty map.
// void put(int key, int value) inserts a (key, value) pair
// into the HashMap. If the key already exists in the map, update
// the corresponding value.
// int get(int key) returns the value to which the specified key
// is mapped, or -1 if this map contains no mapping for the key.
// void remove(key) removes the key and its corresponding value
// if the map contains the mapping for the key.

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int val, key;
    node *next;
    node() : val(0), key(0), next(nullptr) {}
    node(int x, int y) : val(x), key(y), next(nullptr) {}
    node(int x, int y, node *next) : val(x), key(y), next(next) {}
};

class MyHashMap
{
    // ["MyHashMap","put","put","get","get","put","get","remove","get"]
    // [[],[1,1],[2,2],[1],[3],[2,1],[2],[2],[2]]
public:
    node *head;
    int size;
    MyHashMap()
    {
        head = nullptr;
        size = 0;
    }

    void put(int key, int value)
    {
        node *ptr = head, *prev = nullptr;
        while (ptr)
        {
            if (ptr->key >= key)
            {
                break;
            }
            prev = ptr;
            ptr = ptr->next;
        }
        if (ptr != nullptr && ptr->key == key)
        {
            ptr->val = value;
        }
        else
        {
            node *p = new node(value, key, ptr);
            ++size;
            if (prev == nullptr)
            {
                head = p;
            }
            else
            {
                prev->next = p;
            }
        }
    }

    int get(int key)
    {
        node *ptr = head;
        while (ptr)
        {
            if (ptr->key > key)
            {
                return -1;
            }
            if (ptr->key == key)
            {
                return ptr->val;
            }
            ptr = ptr->next;
        }
        return -1;
    }

    void remove(int key)
    {
        node *prev = nullptr, *ptr = head;
        while (ptr != nullptr && ptr->key != key)
        {
            if (ptr->key > key)
            {
                return;
            }
            prev = ptr;
            ptr = ptr->next;
        }
        if (ptr != nullptr)
        {
            if (prev == nullptr)
            {
                head = head->next;
                delete (ptr);
            }
            else
            {
                prev->next = ptr->next;
                delete (ptr);
            }
            --size;
        }
    }
};

int main()
{

    return 0;
}