#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* left;
    struct Node* right;
    int data;
};

struct Node* createTree() {
    struct Node* root = NULL;
    int data;

    printf("Enter data (or -1 to return): ");
    scanf("%d", &data);

    if (data == -1) return NULL;

    root = (struct Node*)malloc(sizeof(struct Node));
    root->data = data;

    printf("Enter left for %d:\n", data);
    root->left = createTree();

    printf("Enter right for %d:\n", data);
    root->right = createTree();

    return root;
}

void inOrder(struct Node* root) {
    if (root == NULL) return;

    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void preOrder(struct Node* root) {
    if (root == NULL) return;

    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(struct Node* root) {
    if (root == NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

int main() {
    struct Node* root = createTree();

    printf("Inorder Traversal: ");
    inOrder(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preOrder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postOrder(root);
    printf("\n");

    // Free allocated memory
    // Not implemented in this code, you should handle memory deallocation appropriately.

    return 0;
}
