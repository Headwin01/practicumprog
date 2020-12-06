#include <iostream> 
#include <map> 
#include <algorithm>
#include <vector>
using namespace std;

// Function to print all distinct palindrome sub-strings of s 
void palindromeSubStrs(string s)
{
    map<string, int> m;
    int n = s.size();

    // table for storing results (2 rows for odd- 
    // and even-length palindromes 
    int** R = new int* [2];
    
    for (size_t i = 0; i < 2; i++)
    {
        R[i] = new int[n + 1];
    }

    // Find all sub-string palindromes from the given input 
    // string insert 'guards' to iterate easily over s 
    s = "@" + s + "#";

    for (int j = 0; j <= 1; j++)
    {
        int rp = 0;   // length of 'palindrome radius' 
        R[j][0] = 0;

        int i = 1;
        while (i <= n)
        {
            //  Attempt to expand palindrome centered at i 
            while (s[i - rp - 1] == s[i + j + rp])
                rp++;  // Incrementing the length of palindromic 
                       // radius as and when we find vaid palindrome 

            // Assigning the found palindromic length to odd/even 
            // length array 
            R[j][i] = rp;
            int k = 1;
            while ((R[j][i - k] != rp - k) && (k < rp))
            {
                R[j][i + k] = min(R[j][i - k], rp - k);
                k++;
            }
            rp = max(rp - k, 0);
            i += k;
        }
    }

    // remove 'guards' 
    s = s.substr(1, n);

    // Put all obtained palindromes in a hash map to 
    // find only distinct palindromess 
    m[string(1, s[0])] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 1; j++)
            for (int rp = R[j][i]; rp > 0; rp--)
                m[s.substr(i - rp - 1, 2 * rp + j)] = 1;
        m[string(1, s[i])] = 1;
    }

    //printing all distinct palindromes from hash map 
    cout << "Below are " << m.size() - 1
        << " palindrome sub-strings";
    map<string, int>::iterator ii;
    for (ii = m.begin(); ii != m.end(); ++ii)
        cout << (*ii).first << endl;
}
// palindrome
bool isPalindrome(string str)
{
    int len = str.length();

    // compare each character from starting
    // with its corresponding character from last
    for (int i = 0; i < len / 2; i++)
        if (str[i] != str[len - i - 1])
            return false;

    return true;
}

// Function to check if a palindrome pair exists
bool checkPalindromePair(vector<string> vect)
{
    // Consider each pair one by one
    for (int i = 0; i < vect.size() - 1; i++)
    {
        for (int j = i + 1; j < vect.size(); j++)
        {
            string check_str;

            // concatenate both strings
            check_str = vect[i] + vect[j];

            // check if the concatenated string is
            // palindrome
            if (isPalindrome(check_str))
                return true;

            // check for other combination of the two strings
            check_str = vect[j] + vect[i];
            if (isPalindrome(check_str))
                return true;
        }
    }
    return false;
}


// Driver program 
int main()
{
    palindromeSubStrs("abaaa");
    cout << endl;
    vector <string> vect = { "geekf", "geeks", "or",
                            "keeg", "abc", "bc" };


    checkPalindromePair(vect) ? cout << "Yes" :
        cout << "No";
    return 0;
}