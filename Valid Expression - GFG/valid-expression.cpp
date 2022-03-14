// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
bool valid(string str);
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string str;
        getline(cin,str);
        cout<<valid(str)<<endl;
    }
    return 0;
}// } Driver Code Ends


bool is_open_bracket(char b){
    return b=='(' || b=='[' || b=='{';
}

bool is_balanced(char a,char b){
    
    return (a=='(' && b==')')||(a=='[' && b==']')||(a=='{' && b=='}');
    
}

bool is_close_bracket(char b){
    return b==')' || b==']' || b=='}';
}

bool is_odd(int n){
    return n%2;
}

bool is_even(int n){
    return !n%2;
}

bool valid(string s)
{
    // code here
    
    int n = s.size();
    
    if(is_odd(n)) return false;
    
    stack<char> stk;
    
    for(int i = 0;i<n;i++){
        
        if(stk.empty() && is_close_bracket(s[i]))
            return false;
        if(stk.empty())
            stk.push(s[i]);
        else if(is_open_bracket(s[i]))
            stk.push(s[i]);
        else if(is_close_bracket(s[i]) && is_balanced(stk.top(),s[i]))
            stk.pop();
        else 
            stk.push(s[i]);
    }
    return stk.empty();
}