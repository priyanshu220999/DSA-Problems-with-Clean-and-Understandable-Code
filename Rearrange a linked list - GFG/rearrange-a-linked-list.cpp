// { Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};



 // } Driver Code Ends
/* Node structure

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution
{
    bool is_even(int n){
        return !(n%2);
    }
    
    public:
    void rearrangeEvenOdd(Node *head)
    {
       // Your Code here
       
       if(!head || !head->next || !head->next->next){
           return;
       }
       
       Node *last = head;
       int size = 1;
       while(last->next){
           size++;
           last = last->next;
       }
       
       Node *ptr_prev = nullptr,*ptr = head;
       int i = 1;
       
       while(ptr->next && i<=size){
           
           if(is_even(i)){
                ptr_prev->next = ptr->next;
                ptr->next = NULL;
                last->next = ptr;
                last = last->next;
                ptr = ptr_prev->next;
            }
            else{
                ptr_prev = ptr;
                ptr = ptr->next;
            }
            i++;
       }
    }
};


// { Driver Code Starts.

/* Driver program to test above function*/
int main()
{
    int T,i,n,l;

    cin>>T;

    while(T--)
    {
        struct Node *head = NULL;
        struct Node *temp = head;
        cin>>n;
        for(i=1; i<=n; i++)
        {
            cin>>l;

            if (head == NULL)
            {   
                head = temp = new Node(l); 
                
            }
            else
            {  temp->next = new Node(l);
               temp = temp->next;
            }
        }
        Solution ob;
        ob.rearrangeEvenOdd(head);
        while(head != NULL)
        {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
    return 0;
}
  // } Driver Code Ends