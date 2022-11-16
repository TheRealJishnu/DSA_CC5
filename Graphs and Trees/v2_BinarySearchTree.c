#include <stdio.h>
#include <stdlib.h>

typedef struct BinarySearchTree
{
    int data;
    struct BinarySearchTree *left;
    struct BinarySearchTree *right;
} node;

node *root = NULL;

node* Insert(int data, node *current)
{
    //node *temp = current;
    if(current == NULL)                        //If Tree is EMPTY
    {
        current = (node*)malloc(sizeof(node));
        current->data = data;
        return current;
    }
    else                                    //Normal Process Starts
    {
        if(data < current->data)
        {
            current->left = Insert(data, current->left);
        }
        else if(data > current->data)                                       //Same as above
        {
            current->right = Insert(data, current->right);
        }
    }
    return current;
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

void PreOrder(node* current)
{
    if(current == NULL)
    {
        return;
    }
    else
    {
        printf("%d\t", current->data);
        PreOrder(current->left);
        PreOrder(current->right);
    }
}

int Delete_A_Node(node* current, int data)
{
    if(current->data == data)
    {
        if(current->right == NULL && current->left == NULL)
        {
            int ret = current->data;
            free(current);
            current = NULL;
            return ret;
        }

    }
    else if (current == NULL)
    {
        
    }
    
    else if(data > current->data)
    {
        return Delete_A_Node(current->right, data);
    }
    else if(data < current->data)
    {
        return Delete_A_Node(current->right, data);
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
        printf("TYPE 3 TO SHOW PRE-ORDER\n");
        int choice;
        scanf("%d", &choice);
        switch(choice)
        {
            case 1 :
            {
                printf("Enter Data : ");
                int data;
                scanf("%d", &data);
                root = Insert(data, root);
                printf("%d added SUCCESSFULLY\n", data);
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
            case 3 :
            {
                PreOrder(root); break;
            }
            case 4 :
            {
                printf("Enter Data to DELETE: ");
                int data;
                scanf("%d", &data);
                root = Delete_A_Node(root, data);
                printf("%d DELETED SUCCESSFULLY\n", data);
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