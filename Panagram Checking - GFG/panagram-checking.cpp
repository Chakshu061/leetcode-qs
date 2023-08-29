//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string &str) {
        // your code here
        
        vector<bool> mark(26, false);
        // For indexing in mark[]
        int index;
        // Traverse all characters
        for (int i = 0; i < str.length(); i++) {
            // If uppercase character, subtract 'A'
            // to find index.
            if ('A' <= str[i] && str[i] <= 'Z')
                index = str[i] - 'A';
            // If lowercase character, subtract 'a'
            // to find index.
            else if ('a' <= str[i] && str[i] <= 'z')
                index = str[i] - 'a';
            // If this character is other than english
            // lowercase and uppercase characters.
            else
                continue;
            mark[index] = true;
        }
     
        // Return false if any character is unmarked
        for (int i = 0; i <= 25; i++)
            if (mark[i] == false)
                return (false);
        // If all characters were present
        return (true);
    }

};

//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string str;
        getline(cin, str);
        Solution obj;
        if (obj.checkPangram(str) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}

// } Driver Code Ends