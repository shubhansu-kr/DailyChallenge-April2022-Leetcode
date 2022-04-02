// https://leetcode.com/problems/valid-palindrome-ii/

// Given a string s, return true if the s can be palindrome after
// deleting at most one character from it.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Wrong solution 
public:
    bool validPalindrome(string s)
    {
        // Let's try to run the code for both half
        bool first = true, second = true;
        int flag = 1;
        int n = s.size();
        for (int i = 0; i <= n / 2; i++)
        {
            if (flag)
            {
                if (s[i] != s[n - i - 1])
                {
                    i--;
                    flag = 0;
                    n--;
                    continue;
                }
            }
            else
            {
                if (s[i] != s[n - i - 1])
                {
                    second = false;
                    break;
                }
            }
        }
        flag = 1;
        for (int i = 0; i <= n / 2; i++)
        {
            if (flag)
            {
                if (s[i] != s[n - i - 1])
                {
                    flag = 0;
                    continue;
                }
            }
            else
            {
                if (s[i + 1] != s[n - i])
                {
                    first = false;
                    break;
                }
            }
        }
        if (first && second)
        {
            return true;
        }
        return false;
    }
};

class Solution
{
    // wrong answer : Since we are only considering the other half to be corrected
    // "deeee"
public:
    bool validPalindrome(string s)
    {
        int flag = 1;
        int n = s.size();
        for (int i = 0; i <= n / 2; i++)
        {
            if (flag)
            {
                if (s[i] != s[n - i - 1])
                {
                    i--;
                    flag = 0;
                    n--;
                    continue;
                }
            }
            else
            {
                if (s[i] != s[n - i - 1])
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{

    return 0;
}