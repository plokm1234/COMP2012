#include "bst.h"

template <typename T>
const T& BST<T>::operator[](int i) const
{
    // This function overloads operator[] whereby when value i is indexed, the (i+1)th smallest value is returned
    
    // Hint: remember to handle out of bound indexing

    int temp1 = i >= 0 ? i % this->totalNodes() : this->totalNodes() - (abs(i) % this->totalNodes());

    int totalNumberOfNodes = this->totalNodes();

    const BST* temp[110] = {nullptr};

    temp[0] = this;

    for(int i = 0 ; i < totalNumberOfNodes; i++){
        for(int j = 0 ; j < totalNumberOfNodes;j++){
            if(temp[j] == nullptr){
                if(!temp[i]->root->left.is_empty() && !temp[i]->root->right.is_empty()){
                    temp[j] = &temp[i]->root->left;
                    temp[j+1] = &temp[i]->root->right;
                    break;
                }else if(!temp[i]->root->left.is_empty() && temp[i]->root->right.is_empty()){
                    temp[j] = &temp[i]->root->left;
                    break;
                }else if(!temp[i]->root->right.is_empty() && temp[i]->root->left.is_empty()){
                    temp[j] = &temp[i]->root->right;
                    break;
                }
            }
        }
    }

    const BST* tempExchange;
    for(int i = 0; i + 1 < totalNumberOfNodes; i++){
        for(int j = i; temp[j] != nullptr; j++){
            if(temp[i]->find_val() > temp[j]->find_val()){
                tempExchange = temp[j];
                temp[j] = nullptr;
                temp[j] = temp[i];
                temp[i] = nullptr;
                temp[i] = tempExchange;
                tempExchange = nullptr;
            }
        }
    }

    return temp[temp1]->find_val();
}

template <typename T>
BST<T> BST<T>::operator+(BST<T>& bst)
{
    // This function overloads operator+, this serves to illustrate when two BSTs merge into one BST
    // or in Virus-Cell-Vaccine scenario, it is when the Virus consumes the Cell
    // When the virus tries to consume the cell, it first needs to check if it has a node with counter value of at least 4.
    // If yes, then the virus will consume the cell, and else the virus does NOT consume and temp object of the virus created is returned from the function.

    // Suppose virus BST is A and cell BST is B. when we do A + B, return a new BST such that it's node values
    // are the same as when you insert all B's nodes from smallest to largest
    // NOTE: You only need to add each value of B once, in another words, you can ignore the counter value associated with the nodes of B

    // Hint: you could consider taking advantage of operator[] if you have implemented it before this!
    BST<T> temp1;

    if(this->getMaxcounter() < 4){
        return *this;

    }else if(this->root!=nullptr){

        int totalNumberOfNodes = this->totalNodes();

        const BST* temp[110] = {nullptr};

        temp[0] = this;

        for(int i = 0 ; i < totalNumberOfNodes; i++){
            for(int j = 0 ; j < totalNumberOfNodes;j++){
                if(temp[j] == nullptr){
                    if(!temp[i]->root->left.is_empty() && !temp[i]->root->right.is_empty()){
                        temp[j] = &temp[i]->root->left;
                        temp[j+1] = &temp[i]->root->right;
                        break;
                    }else if(!temp[i]->root->left.is_empty() && temp[i]->root->right.is_empty()){
                        temp[j] = &temp[i]->root->left;
                        break;
                    }else if(!temp[i]->root->right.is_empty() && temp[i]->root->left.is_empty()){
                        temp[j] = &temp[i]->root->right;
                        break;
                    }
                }
            }
        }

        temp1.operator=(*this);

        for(int i = 0; i < totalNumberOfNodes; i++){
            if(temp[i]->root->counter >=4){
                for(int i = 0; i < bst.totalNodes(); i++){
                    temp1.insert(bst.operator[](i));
                }
            }
        }

        bst.beKilled();

    }
    return temp1;
}

template <typename T>
void BST<T>::operator++(int)
{
    // This function should increment counter value present in ALL nodes of the BST
    if(this->root!=nullptr){
        this->root->counter += 1;
        this->root->left++;
        this->root->right++;
    }
}

template <typename T>
BST<T>& BST<T>::operator=(const BST& bst)
{
    // This function should overload the operator= such that it carries out deepcopy
    if(bst.root!=nullptr){
        this->root = new BSTnode(bst.root->value);
        this->root->counter = bst.root->counter;
        if(!bst.root->right.is_empty())this->root->right.operator=(bst.root->right);
        if(!bst.root->left.is_empty())this->root->left.operator=(bst.root->left);
    }else{
        this->root = nullptr;
    }
    return *this;
}