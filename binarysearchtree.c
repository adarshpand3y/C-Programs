#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left, *right;
};

struct node *newNode(int item) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// Insert a new node in BST
struct node *insert(struct node *node, int key) {
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return newNode(key);
    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    /* return the (unchanged) node pointer */
    return node;
}

struct node *minValueNode(struct node *node) {
    struct node *current = node;
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

struct node *deleteNode(struct node *root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Driver Code
int main() {
    struct node *root = NULL;
    int choice, value;
    while (1) {
        printf("1: Print the BST in inorder.\n");
        printf("2. Insert a node in BST.\n");
        printf("3. Delete a node in BST.\n");
        printf("4. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            inorder(root);
            printf("\n");
            break;
        case 2:
            printf("Enter the value to add: ");
            scanf("%d", &value);
            root = insert(root, value);
            printf("%d added successfully to the tree.\n"); break;
        case 3:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            root = deleteNode(root, value);
            printf("%d deleted successfully from the tree.\n"); break;
        case 4:
            printf("Program ended successfully.\n"); return 0;
        default:
            printf("Wrong Choice.\n"); return 0;
        }
    }
}