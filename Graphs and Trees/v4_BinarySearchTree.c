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

void InOrder(node* current)
{
    if(current == NULL)
    {
        return;
    }
    else
    {
        PreOrder(current->left);
        printf("%d\t", current->data);
        PreOrder(current->right);
    }
}

void PostOrder(node* current)
{
    if(current == NULL)
    {
        return;
    }
    else
    {
        PreOrder(current->left);
        PreOrder(current->right);
        printf("%d\t", current->data);
    }
}


node* minValueNode(node* nodee)
{
    node* current = nodee;
  
    while (current && current->left != NULL)
        current = current->left;
  
    return current;
}
node* deleteNode(node* current, int key)
{
    // base case
    if (current == NULL)
        return root;
  
    // If the key to be deleted 
    // is smaller than the root's
    // key, then it lies in left subtree
    if (key < current->data)
        root->left = deleteNode(root->left, key);
  
    // If the key to be deleted 
    // is greater than the root's
    // key, then it lies in right subtree
    else if (key > root->data)
        root->right = deleteNode(current->right, key);
  
    // if key is same as root's key, 
    // then This is the node
    // to be deleted
    else {
        // node with only one child or no child
        if (current->left == NULL) {
            node* temp = current->right;
            free(current);
            return temp;
        }
        else if (root->right == NULL) {
            node* temp = current->left;
            free(current);
            return temp;
        }
  
        // node with two children: 
        // Get the inorder successor
        // (smallest in the right subtree)
        node* temp = minValueNode(root->right);
  
        // Copy the inorder 
        // successor's content to this node
        current->data = temp->data;
  
        // Delete the inorder successor
        root->right = deleteNode(current->right, temp->data);
    }
    return current;
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
        printf("TYPE 4 TO SHOW IN-ORDER\n");
        printf("TYPE 5 TO SHOW POST-ORDER\n");
        printf("TYPE 6 TO DELETE A NODE\n");
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
                InOrder(root); break;
            }
            case 5 :
            {
                PostOrder(root); break;
            }
            case 6 :
            {
                printf("Enter Data to DELETE: ");
                int data;
                scanf("%d", &data);
                root = deleteNode(root, data);
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
