#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include <stdexcept>
#include <iostream>

class BinaryTree {
    
   
private:
    struct Node {
        int key;
        Node* left;
        Node* right;
        Node(int value) : key(value), left(nullptr), right(nullptr) {}
    };
    Node* root;
    int num_elem=0;
    
public:
    BinaryTree() : root(nullptr) {}
    
    Node* insert_pomocniczy(Node* n,int x){
        if(n==nullptr){
            n = new Node(x);
        }
        else if(x < n->key) {
            n->left = insert_pomocniczy(n->left, x);
        }
        else if(x >=  n->key) {
            n->right = insert_pomocniczy(n->right, x);
        }
        return n;
    }

    void insert(int x){
        root = insert_pomocniczy(root, x);
        num_elem++;
    }
    //pomocniczy search rekruencyjny
    Node* search_pomocniczy(Node*n, int x){
        if (n == nullptr || n->key == x) {
            return n;
        }
        if (x < n->key) {
            return search_pomocniczy(n->left, x);
        } 
        else {
            return search_pomocniczy(n->right, x);
        }
    }
    //search rekurencyjny
    bool search(int x) {
        if(root==nullptr){
            throw std::out_of_range("Przeszukujesz puste drzewo");
        }
        Node* result = search_pomocniczy(root, x);
        return (result != nullptr);
    }
    //search iteracyjny
    bool search_iteracyjny(int x) {
        if(root==nullptr){
            throw std::out_of_range("Przeszukujesz puste drzewo");
        }
        Node* n = root;

        while (n != nullptr) {
            if (x == n->key) {
                return true;
            } else if (x < n->key) {
                n = n->left;
            } else {
                n = n->right;
            }
        }

        return false;
    }
    Node* minimum_pomocniczy(Node*n){
        if(n->left == nullptr){
            return n;
        }
        return minimum_pomocniczy(n->left);
    }
    int minimum(){
        if(root==nullptr){
            throw std::out_of_range("Przeszukujesz puste drzewo");
        }
        Node* min = minimum_pomocniczy(root);
        return min->key;
    }
    Node* maksimum_pomocniczy(Node*n){
        if(n->right == nullptr){
            return n;
        }
        return maksimum_pomocniczy(n->right);
    }
    int maksimum(){
        if(root==nullptr){
            throw std::out_of_range("Przeszukujesz puste drzewo");
        }
        Node* maksimum = maksimum_pomocniczy(root);
        return maksimum->key;
    }

    int size(){
        return num_elem;
    }
    int depth_pomocniczy(Node* n){
        if (n == nullptr) {
            return 0;  // Głębokość pustego poddrzewa wynosi 0
        }
        int leftDepth = depth_pomocniczy(n->left);
        int rightDepth = depth_pomocniczy(n->right);

        return 1 + std::max(leftDepth, rightDepth);
    }
    int depth(){
        if(root==nullptr){
            throw std::out_of_range("Przeszukujesz puste drzewo");
        }
        return depth_pomocniczy(root);
    }

    void inorder_pomocniczy(Node* n) {
        if (n != nullptr) {
            inorder_pomocniczy(n->left);
            std::cout << n->key << " ";
            inorder_pomocniczy(n->right);
        }
    }

    void inorder() {
        std::cout << "Porządek inorder: ";
        inorder_pomocniczy(root);
        std::cout << std::endl;
    }
    void preorder_pomocniczy(Node* n) {
        if (n != nullptr) {
            std::cout << n->key << std::endl;
            preorder_pomocniczy(n->left);
            preorder_pomocniczy(n->right);
        }
    }
    void preorder() {
        preorder_pomocniczy(root);
    }

    void postorder_pomocniczy(Node* n) {
        if (n != nullptr) {
            postorder_pomocniczy(n->left);
            postorder_pomocniczy(n->right);
            std::cout << n->key << " ";
        }
    }

    void postorder() {
        std::cout << "Porządek postorder: ";
        postorder_pomocniczy(root);
        std::cout << std::endl;
    }


};
#endif