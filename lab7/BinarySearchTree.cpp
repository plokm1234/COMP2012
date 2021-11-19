//
// Created by ck on 2021/11/5.
//

#include <iostream>

#include "BinarySearchTree.h"
using namespace std;

BinarySearchTree::BinarySearchTree(int id)
    : id(id), leftSubTree(nullptr), rightSubTree(nullptr) {}

BinarySearchTree::BinarySearchTree(const BinarySearchTree& other): id(other.id)
{
    // TODO: Clone the two subtrees accordingly.

    if(other.leftSubTree != nullptr){
        this->leftSubTree = new BinarySearchTree(*other.leftSubTree);
    }
    
    if(other.rightSubTree != nullptr){
        this->rightSubTree = new BinarySearchTree(*other.rightSubTree);
    }
}

BinarySearchTree::~BinarySearchTree()
{
    // TODO: release the resources occupied by the two subtrees if any.

    if(this->leftSubTree != nullptr){
        delete this->leftSubTree;
    }
    if(this->rightSubTree != nullptr){
        delete this->rightSubTree;
    }
}

void BinarySearchTree::add(int newId)
{
    // TODO: Insert the newId to the current tree.
    // You need to create a new node for the newId and attach it to the correct place.
    // Do nothing if the id is already in the tree.

    if(newId > this->id){
       if(this->rightSubTree == nullptr){
           this->rightSubTree = new BinarySearchTree(newId);
        }else{
            this->rightSubTree->add(newId);
        }
    }else if(newId < this->id){
       if(this->leftSubTree == nullptr){
           this->leftSubTree = new BinarySearchTree(newId);
        }else{
            this->leftSubTree->add(newId);
        }
    }
}

bool BinarySearchTree::hasId(int idToFind) const
{
    // TODO: Check whether the given id is in the tree.
    // You need to determinate whether to seach the left subtree or right subtree.

    if(idToFind > this->id){
        return this->rightSubTree != nullptr ? this->rightSubTree->hasId(idToFind) : false;
    }

    if(idToFind < this->id){
        return this->leftSubTree != nullptr ? this->leftSubTree->hasId(idToFind) : false;
    }

    return true;
}

int BinarySearchTree::height() const
{
    // TODO: Calculate the height of the tree.
    // Tree like this has height 0:
    //    O
    //
    // Trees like these have height 1:
    //    O        O       O
    //  /  \        \     /
    // O    O        O   O
    
    if(this->leftSubTree == nullptr && this->rightSubTree == nullptr){
        return 0;
    }else{
        int countLeft = 0;
        int countRight = 0;

        if(this->leftSubTree != nullptr){
            countLeft = this->leftSubTree->height();
        }
        if(this->rightSubTree != nullptr){
            countRight = this->rightSubTree->height();
        }
        return countLeft < countRight ? countRight + 1: countLeft + 1; 
    }
}

void BinarySearchTree::printDFSPrefix() const
{
    std::cout << id << " ";
    if (leftSubTree != nullptr)
        leftSubTree->printDFSPrefix();

    if (rightSubTree != nullptr)
        rightSubTree->printDFSPrefix();
}

void BinarySearchTree::printDFSInfix() const
{
    if (leftSubTree != nullptr)
        leftSubTree->printDFSInfix();
    std::cout << id << " ";
    if (rightSubTree != nullptr)
        rightSubTree->printDFSInfix();
}
