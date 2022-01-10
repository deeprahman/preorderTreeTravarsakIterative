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
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    if(!root)return NULL;
    int *resultArr = (int *)malloc(sizeof(int) * 100);
    struct TreeNode **stack = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * 100);
    int stackSize = 0;
    struct TreeNode *ptr = root;
    while(stackSize > 0 || ptr){
        if(ptr){
            *(resultArr + (*returnSize)++) = ptr->val;
            if(ptr->right){
                *(stack + stackSize++) = ptr->right;
            }
            ptr = ptr->left;
        }else{
            ptr = *(stack + (--stackSize));
            //--stackSize;
        }
    }
    free(stack);
    return resultArr;
}


//==============================================

void main()
{
    int returnSize = 0;
    int *array = 0;
    // create tree
    struct TreeNode *root = tree();

    array = preorderTraversal(root, &returnSize);
    printf("\n");
    for (int i = 0; i < returnSize; i++)
    {
        printf(" %d", array[i]);
    }
    printf("\n");
}