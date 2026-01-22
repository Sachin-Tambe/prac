#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    int freq;
    struct Node *left, *right;
};

struct Node* newNode(char data, int freq) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

void swap(struct Node** a, struct Node** b) {
    struct Node* t = *a;
    *a = *b;
    *b = t;
}

void heapify(struct Node* arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && arr[left]->freq < arr[smallest]->freq)
        smallest = left;
    
    if (right < n && arr[right]->freq < arr[smallest]->freq)
        smallest = right;
    
    if (smallest != i) {
        swap(&arr[smallest], &arr[i]);
        heapify(arr, n, smallest);
    }
}

struct Node* extractMin(struct Node* arr[], int* n) {
    struct Node* temp = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    heapify(arr, *n, 0);
    return temp;
}

void insertNode(struct Node* arr[], int* n, struct Node* node) {
    (*n)++;
    int i = *n - 1;
    
    while (i && node->freq < arr[(i - 1) / 2]->freq) {
        arr[i] = arr[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    arr[i] = node;
}

void printCodes(struct Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    
    if (!root->left && !root->right) {
        printf("'%c': ", root->data);
        for (int i = 0; i < top; i++)
            printf("%d", arr[i]);
        printf("\n");
    }
}

struct Node* buildHuffmanTree(char data[], int freq[], int size) {
    struct Node* arr[size];
    int n = size;
    
    for (int i = 0; i < size; i++)
        arr[i] = newNode(data[i], freq[i]);
    
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    
    while (n != 1) {
        struct Node* left = extractMin(arr, &n);
        struct Node* right = extractMin(arr, &n);
        struct Node* top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertNode(arr, &n, top);
    }
    
    return extractMin(arr, &n);
}

int main() {
    int n;
    
    printf("Enter number of characters: ");
    scanf("%d", &n);
    
    char data[n];
    int freq[n];
    
    printf("Enter characters and frequencies:\n");
    for (int i = 0; i < n; i++) {
        printf("Character %d: ", i + 1);
        scanf(" %c", &data[i]);
        printf("Frequency: ");
        scanf("%d", &freq[i]);
    }
    
    printf("\nInput Data:\n");
    for (int i = 0; i < n; i++) {
        printf("'%c': %d\n", data[i], freq[i]);
    }
    
    struct Node* root = buildHuffmanTree(data, freq, n);
    
    int arr[100], top = 0;
    printf("\nHuffman Codes:\n");
    printCodes(root, arr, top);
    
    return 0;
}
