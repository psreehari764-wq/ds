#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}


struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return newNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}


void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}


int search(struct Node* root, int key) {
    if (root == NULL) return 0;
    if (root->data == key) return 1;
    if (key < root->data) return search(root->left, key);
    else return search(root->right, key);
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);#include <stdio.h>

int parent[20];


int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}


void union_set(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    parent[rootY] = rootX;
}

int main() {
    int n, i, j, u, v, min, ne = 1;
    int cost[20][20], total = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;   
        }
    }

    for (i = 1; i <= n; i++)
        parent[i] = i;

    printf("\nEdges in the Minimum Spanning Tree:\n");

    while (ne < n) {
        min = 999;

        
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        
        if (find(u) != find(v)) {
            printf("%d -> %d  Cost = %d\n", u, v, min);
            total += min;
            union_set(u, v);
            ne++;
        }

        cost[u][v] = cost[v][u] = 999; 
    }

    printf("\nTotal Cost of Minimum Spanning Tree = %d\n", total);

    return 0;
}


    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    int key = 40;
    if (search(root, key))
        printf("%d found in BST\n", key);
    else
        printf("%d not found in BST\n", key);

    return 0;
}
#include <stdio.h>

int parent[20];


int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}


void union_set(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    parent[rootY] = rootX;
}

int main() {
    int n, i, j, u, v, min, ne = 1;
    int cost[20][20], total = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;   
        }
    }

    for (i = 1; i <= n; i++)
        parent[i] = i;

    printf("\nEdges in the Minimum Spanning Tree:\n");

    while (ne < n) {
        min = 999;

        
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        
        if (find(u) != find(v)) {
            printf("%d -> %d  Cost = %d\n", u, v, min);
            total += min;
            union_set(u, v);
            ne++;
        }

        cost[u][v] = cost[v][u] = 999; 
    }

    printf("\nTotal Cost of Minimum Spanning Tree = %d\n", total);

    return 0;
}


