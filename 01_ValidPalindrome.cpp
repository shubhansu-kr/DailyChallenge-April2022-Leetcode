// https://leetcode.com/problems/valid-palindrome-ii/

// Given a string s, return true if the s can be palindrome after
// deleting at most one character from it.

#include <bits/stdc++.h>
using namespace std;

class Solution1
{
public:
    bool palindrome(string s)
    {
        int i, j;
        for (i = 0, j = s.size(); i < j; ++i, --j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
        }
        return true;
    }

    bool validPalindrome(string s)
    {
        int i, j;
        for (i = 0, j = s.size() - 1; i < j; ++i, --j)
        {
            if (s[i] != s[j])
            {
                // Check if j can be deleted or i can be deleted to make the string
                // palindrome

                // delete i - Pass i+1 as index and j-i as len
                string subi = s.substr(i + 1, j - i);

                // delete j - pass i as index and j-1 as len
                string subj = s.substr(i, j - i);

                if (palindrome(subi) || palindrome(subj))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};

class Solution
{
    // Two pointer approach :
public:
    bool validPalindrome(string s)
    {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--)
            if (s[i] != s[j])
            {
                int i1 = i, j1 = j - 1, i2 = i + 1, j2 = j;
                while (i1 < j1 && s[i1] == s[j1])
                {
                    i1++;
                    j1--;
                };
                while (i2 < j2 && s[i2] == s[j2])
                {
                    i2++;
                    j2--;
                };
                return i1 >= j1 || i2 >= j2;
            }
        return true;
    }
};

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