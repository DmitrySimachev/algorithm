#include "stdafx.h"
#include <iostream>
using namespace std;
 
struct node {
    int key = 0;
    node *left = NULL, *right = NULL;
};
 
node *createTree(int rootKey) {
    node *root = NULL;
    root = new node;
    root->key = rootKey;
    return root;
}
 
void treeAdd(int key, node* root) {
    node *temp = NULL;
    if (key < root->key) {
        if (root->left != NULL) {
            treeAdd(key, root->left);
        } else {
            root->left = new node;
            root->left->key = key;
            cout << "Left child added successfully!" << endl;
            return;
        }
    }
    else  if(key > root->key) {
        if (root->right != NULL) {
            treeAdd(key, root->right);
        }
        else {
            root->right = new node;
            root->right->key = key;
            cout << "Right child added successfully!" << endl;
            return;
        }
    } else {
        cout << "Leaf already exist!" << endl;
        return;
    }
}
 
void searchNode(int key, node *root) {
    if (key < root->key) {
        cout << root->key << " ->L ";
        searchNode(key, root->left);
    }
    else {
        if (key == root->key) {
            cout << root->key << endl;
            return;
        }
        else {
            cout << root->key << " ->R ";
            searchNode(key, root->right);
        }
    }
}
 
void postOrderTraverse(node *root) {
    if (root == NULL) {
        return;
    }
    postOrderTraverse(root->left);
    postOrderTraverse(root->right);
    cout << root->key << " ";
}
 
int minkey(node *root) {
    node *temproot = NULL;
    temproot = root;
    if (temproot != NULL) {
        while (temproot->left != NULL) {
            temproot = temproot->left;
        }
        return temproot->key;
    }
    else cout << "Tree is empty!";
}
 
void remove(node *root, node *temp,int key) {
    if (key < root->key) {
        temp = root;
        remove(root->left, temp, key);
    }
    else {
        if (key == root->key) {
            if (temp->left == root) {
                if (root->left != NULL) {
                    temp->left = root->left;
                    delete root;
                }
                else if (root->right != NULL) {
                    temp->left = root->right;
                    delete root;
                }
            }
            else {
                if (root->left != NULL) {
                    temp->right = root->left;
                    delete root;
                }
                else if (root->right != NULL) {
                    temp->right = root->right;
                    delete root;
                }
            }
        return;
        }
        else {
            temp = root;
            remove(root->right, temp, key);
        }
    }
}
 
int main()
{
    int key = 0, leaf;
    int i = 0;
    node *Tree = NULL;
 
    cout << "Root of the new tree: "; cin >> key; cout << endl;
    Tree = createTree(key);
 
    do {
        cout << "New leaf: "; cin >> leaf;
        if (leaf != 0){
            treeAdd(leaf, Tree);
        }
        cout << endl;
        i++;
    } while (leaf != 0);
     
    cout << "Searching element by key: "; cin >> key; cout << endl;
    searchNode(key, Tree);
 
    cout << "Make an postorder traverse in Tree: ";
    postOrderTraverse(Tree); cout << endl;
 
    cout << "Searching minimum key value: " << minkey(Tree) << endl;
 
    cout << "Removing node with key value: "; cin >> key;
    remove(Tree, NULL,key);
    cout << endl << "Checking new Tree: ";
    cin >> key;
    searchNode(key, Tree); cout << endl;
 
    return 0;
}

