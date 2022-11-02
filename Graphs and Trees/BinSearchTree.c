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
    if(current == NULL)                        //If Tree is EMPTY
    {
        current = (node*)malloc(sizeof(node));
        current->data = data;
    }
    else                                    //Normal Process Starts
    {
        if(data < current->data)
        {
            return Insert(data, current->left);
        }
        else if(data < current->data)
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

int SearchValue(int key, node *current)
{
    if(key == current->data)
    {
        return 1;
    }
    else if(key > current->data)
    {
        if(current->right != NULL)
            return SearchValue(key, current->right);
        else
            return 0;
    }
    else if(key < current->data)
    {
        if(current->left != NULL)
            return SearchValue(key, current->left);
        else
            return 0;
    }
}
int main()
{
    //node *root = NULL;
    char ch = 'y';
    while(ch == 'y')
    {
        printf("\nWELCOME TO BINARY SEARCH TREE\n");
        printf("TYPE 1 TO INSERT DATA\nTYPE 2 TO SEARCH DATA\n");
        int choice;
        scanf("%d", &choice);
        switch(choice)
        {
            case 1 :
                {
                    printf("Enter Data : ");
                    int data;
                    scanf("%d", &data);
                    Insert(data, root);
                    printf("%d added SUCCESSFULLY\n");
                    break;
                }
            case 2 :
                {
                    printf("Enter Data To Search: ");
                    int data;
                    scanf("%d", &data);
                    if(SearchValue(data, root))
                        printf("Data Found\n");
                    else
                        printf("Data NOT Found\n");
                    break;
                }
            default :
                {
                    printf("INVALID CHOICE\n");
                    break;
                }
        }
        printf("Do You Want To Continue?(y/n)    ");
        scanf("%c", &ch);
        scanf("%c", &ch);
    }

    return 0;
}
