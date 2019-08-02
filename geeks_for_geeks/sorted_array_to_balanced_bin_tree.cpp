// C++ program to print BST in given range 
#include<bits/stdc++.h> 
using namespace std; 
  
/* A Binary Tree node */
class TNode  
{  
    public: 
    int data;  
    TNode* left;  
    TNode* right;  
};  
  
TNode* newNode(int data);  
  
/* A function that constructs Balanced 
Binary Search Tree from a sorted array */
TNode* sortedArrayToBST(int arr[],  
                        int start, int end)  
{  
  if (start > end) return nullptr;
  if (start == end) return newNode(arr[start]);

  int mid = start + (end - start) / 2;
  TNode* node = newNode(arr[mid]);
  node->left = sortedArrayToBST(arr, start, mid - 1);
  node->right = sortedArrayToBST(arr, mid + 1, end);
  return node;
}  
  
/* Helper function that allocates a new node  
with the given data and NULL left and right  
pointers. */
TNode* newNode(int data)  
{  
    TNode* node = new TNode(); 
    node->data = data;  
    node->left = NULL;  
    node->right = NULL;  
  
    return node;  
}  
  
/* A utility function to print 
preorder traversal of BST */
void preOrder(TNode* node)  
{  
    if (node == NULL)  
        return;  
    cout << node->data << " ";  
    preOrder(node->left);  
    preOrder(node->right);  
}  
  
// Driver Code 
int main()  
{  
    int arr[] = {1, 2, 3, 4, 5, 6, 7};  
    int n = sizeof(arr) / sizeof(arr[0]);  
  
    /* Convert List to BST */
    TNode *root = sortedArrayToBST(arr, 0, n-1);  
    cout << "PreOrder Traversal of constructed BST \n";  
    preOrder(root);  
  
    return 0;  
}  
  
// This code is contributed by rathbhupendra 
