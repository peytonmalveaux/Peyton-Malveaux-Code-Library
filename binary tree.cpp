// binary tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

typedef struct Node {
    int key;
    Node *left, * right;

}Node;

Node* createNode(char data) {
    Node* node = (Node*)malloc(sizeof(struct Node));
    node->key = data;
    node->right = node->left = NULL;
    return node;
}

int countNodes(Node* root) {
    if (root == NULL) 
        return(0);
    return(1 + countNodes(root->left) + countNodes(root->right));
    
}

bool checkCompletion(Node* root, int i, int numberNodes) {
    if (root == NULL)
        return true;
    if (i >= numberNodes)
        return false;

    return(checkCompletion(root->left, 2 * i + 1, numberNodes) && checkCompletion(root->right, 2 * i + 2, numberNodes));
}




int main()
{
    Node* root = createNode(1);
   
    root->left = createNode(2);
    root->right = createNode(3);
   
    root->left->right = createNode(5);
   

    //use a addNode(...) function to add more nodes quickly
    
    int nodeCount = 0;
    int k = 0;

    if (checkCompletion(root, k, nodeCount))
        cout << "the tree is complete";
    else
        cout << "the tree is not complete";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
