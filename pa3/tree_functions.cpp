#include <iostream>
#include "bst.h"
using namespace std;

template <typename T>          
bool BST<T>::breakbond(const T& x)
{
    // This function should find the first bond that exceeds the value of x, break it and return
    // If no such bond exists, then simply return
    // When implementing, take note of the following:
    // 1. Search from the leftmost branch and iteratively move to the rightmost branch (similar to how we search from smallest value in normal BST search)
    // 2. But take note! that this is trying to find the 'bond' which is the absolute value of the difference in value instead of the value itself!
    // 3. Upon finding the first bond that is greater than the function parameter value x, break the bond and return. Careful: Only break the first bond that meets this criteria
    // 4. breakbond function should return true when a bond has been broken otherwise return false
    
    // Hint: You could consider taking advantage of the boolean returned for recursive call

    if(this->root != nullptr){
        if(this->root->left.root != nullptr){
            if(this->root->value - this->root->left.root->value <= x){
                this->root->left.breakbond(x);
            }else{
                this->root->left.beKilled();
                return true;
            }
        }
        if(this->root->right.root != nullptr){
            if(this->root->right.root->value - this->root->value <= x){
                this->root->right.breakbond(x);
            }else{
                this->root->right.beKilled();
                return true;
            }
        }
    
    }
    return false;
}

template <typename T>
BST<T>::BST(const BST<T>& bst)
{
    // This function should perform deep-copy of one BST to another
    this->operator=(bst);
}

template <typename T>
int BST<T>::getMaxcounter() const
{
    // This function should find the maximum counter value of all the nodes present in BST
    if(this->root == nullptr){
        return 0;
    }else{
        int left = 0, right = 0, temp = this->root->counter;

        left = this->root->left.getMaxcounter();
        right = this->root->right.getMaxcounter();
        return left > temp ? temp = left: right > temp ? temp = right : temp = temp;
    }
}

template <typename T>
int BST<T>::getMaxHeight() const{
    // This function should return the maximum height of the BST
    if(this->root == nullptr){
        return 0;
    }else{
        int left = 0, right = 0;

        left = this->root->left.getMaxHeight();
        right = this->root->right.getMaxHeight();
        return left > right ? left + 1: right + 1;
    }
}

template <typename T>          
void BST<T>::insert(const T& x)
{
    // This function inserts the given value into the BST
    // If the value to be inserted already exists in the BST, remember to handle the counter!
    if(this->root != nullptr){
        if(x == this->root->value){
           this->root->counter++;
        }

       if(x < this->root->value){
           if(this->root->left.root != nullptr){
                if(this->root->left.root->value == x){
                    this->root->left.root->counter++;
                }else{
                    this->root->left.insert(x);
                }
           }else{
               this->root->left.root = new BSTnode(x);
           }
       }

        if(x > this->root->value){
           if(this->root->right.root != nullptr){
                if(this->root->right.root->value == x){
                    this->root->right.root->counter++;
                }else{
                    this->root->right.insert(x);
                }
           }else{
               this->root->right.root = new BSTnode(x);
           }
       }

    }else{
        this->root = new BSTnode(x);
    }
                 
}

template <typename T>
void BST<T>::mutate()
{
    // This function aims to mutate the virus such that it minimizes bond length while maintaining all the nodes
    // Write a function that reorders the nodes of the BST such that the bond length is minimized
    // This reordering can only occur if the height of the tree is at least 3. If less than 3, then do nothing.

    // NOTE: In the process of mutating, the virus BST loses information of its nodes' counter values.
    //       In another words, you do not need to worry about preserving the counter value when reordering the nodes!

    // Hint: 
    // 1. You could consider using operator[] if you have implemented it prior to this
    // 2. Suppose we have two nodes A and B. The bond length (difference between value of A and B) is minimal when
    //    there are no other nodes with value in between A and B. Hope this helps~
    if(this->getMaxHeight() >= 3){
        T virus_sequence[this->totalNodes()];
        
        for(int i = 0; i < this->totalNodes(); i++){
            virus_sequence[i] = this->operator[](i);
        }

        this->beKilled();

        for(int i = 0; i < (sizeof(virus_sequence)/sizeof(*virus_sequence)); i++){
            this->insert(virus_sequence[i]);
        }
    }
}

template <typename T>
int BST<T>::totalNodes() const{

    // This function should return the total number of nodes present in the BST
    if(this->root == nullptr){
        return 0;
    }else{
        int left = 0, right = 0;

        left = this->root->left.totalNodes();
        right = this->root->right.totalNodes();
        return left + right + 1;
    }
}
