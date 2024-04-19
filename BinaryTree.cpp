#include "BinaryTree.hpp"

int main(){
    int n,m;
    std::cin >> n;


    BinaryTree tree;

    for(int i = 1; i <= n; i++){
        std::cin>>m;
        tree.insert(m);
    }
    std::cout<< tree.size()<<" "<<tree.depth()<<" "<<tree.minimum()<<" "<<tree.maksimum()<<std::endl;
    tree.preorder();
    for(int i=1;i<=9;i++){
        
        if(tree.search(i)){
            std::cout<<"Yes"<<std::endl;
        }
        else{
            std::cout<<"No"<<std::endl;
        }
    }
}