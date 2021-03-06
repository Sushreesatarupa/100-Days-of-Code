// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

void inorder(Node *root)
{
    if (root == NULL)return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);    
}

int rightLeafSum(Node* root);

/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     // inorder(root);
     // cout<<endl;
     cout<<rightLeafSum(root)<<endl;
  }
  return 0;
}// } Driver Code Ends
/*Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
*/
// function should return the sum of all 
// right leaf nodes

void findSum(Node *r,int *sum,char LorR){
    if(r==NULL)
        return;
    findSum(r->left,sum,'l');
    findSum(r->right,sum,'r');
    if(r->left==NULL and r->right==NULL and LorR=='r')
        *sum=*sum+r->data;
}

int rightLeafSum(Node* root)
{
    int sum=0;
    findSum(root,&sum,'n');
    return sum;
}