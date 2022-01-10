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
    //struct TreeNode *root = NULL;

    return root;
}
//================== code ========================
int* postorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    if(!root)return NULL;
    int *resultArr = (int *)malloc(sizeof(int) * 100);
    struct TreeNode **stack = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * 100);
    int stackSize = 0;
    struct TreeNode *ptr = root;
    struct TreeNode *visited = NULL;
    do{
        while(NULL != ptr){
            *(stack+(stackSize++))=ptr;
            ptr = ptr->left;
        }
        while(NULL == ptr && 0 != stackSize){
            ptr = *(stack + (stackSize-1));
            if(ptr->right == visited || ptr->right == NULL){
                *(resultArr + (*returnSize)++) = ptr->val;
                stackSize--;
                visited = ptr;
                ptr = NULL;
            }else{
                ptr = ptr->right;
            } 
        }
    }while(0 != stackSize);
      free(stack);
    return resultArr;
}
// Answer should be 4 5 2 6 7 3 1


//==============================================

void main()
{
    int returnSize = 0;
    int *array = 0;
    // create tree
    struct TreeNode *root = tree();

    array = postorderTraversal(root, &returnSize);
    printf("\n");
    for (int i = 0; i < returnSize; i++)
    {
        printf(" %d", array[i]);
    }
    printf("\n");
}