#include <stdio.h>
#include <stdlib.h>

typedef struct BinarySearchTree
{
    int data;
    struct BinarySearchTree *left;
    struct BinarySearchTree *right;
} node;

node *root = NULL;

int Insert(int data, node *current)
{
    //node *temp = current;
    if(temp == NULL)                        //If Tree is EMPTY
    {
        current = (node*)malloc(sizeof(node));
        current->data = data;
    }
    else                                    //Normal Process Starts
    {
        if(data < temp->data)
        {
            return Insert(data, current->left);
        }
        else if(data < temp->data)
        {
            return Insert(data, current->right);
        }
        else
        {
            printf("Error: Same data cannot be in tree more than once");
            return;
        }
    }
}
int main()
{
    node *root = NULL;
    switch(choice)
    {
        case 1 : printf
    }
    return 0;
}
