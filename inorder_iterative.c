#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Create a new node
 */
struct TreeNode *newNode(int key)
{
    struct TreeNode *t = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    t->val = key;
    t->left = t->right = NULL;
    return t;
}

/*
Our b-tree

                   1
                /     \
            2            3
         /    \        /    \
       4        5     6       7
*/

struct TreeNode *tree()
{

    struct TreeNode *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    //  struct TreeNode *root = NULL;

    return root;
}
//================== code ========================

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0; 
    
    if(!root) return NULL; 
    
    int* output = malloc(sizeof(int)*100);
    struct TreeNode** stack = malloc(sizeof(struct TreeNode*)*100);
    int stackSize = 0; 
    struct TreeNode* ptr = root; 
    
    /* When the stack is empty, stackSize is 0. 
     * When we have traversed all the nodes, ptr would be NULL. 
     * When both conditions were meet, exit. */ 
    while(stackSize > 0 || ptr){
        /* Traverse to the leftest node in the subtree, push all nodes we traversed. */ 
        if (ptr){
            stack[stackSize++] = ptr;
            ptr = ptr -> left;
        }
        /* Once we reached the leftest node in the subtree, 
         * pop a node and copy its value. Then traverse to its right node. */ 
        else{
            ptr = stack[--stackSize];
            output[(*returnSize)++] = ptr -> val; 
            ptr = ptr -> right;
        }
    }
    
    free(stack);        // Don't forget to free space. 
    return output; 
}



//==============================================

void main()
{
    int returnSize = 0;
    int *array = 0;
    // create tree
    struct TreeNode *root = tree();

    array = inorderTraversal(root, &returnSize);
    printf("\n");
    for (int i = 0; i < returnSize; i++)
    {
        printf(" %d", array[i]);
    }
    printf("\n");
}