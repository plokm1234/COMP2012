#include <iostream>
using namespace std;
#include "bst.h"
#include "tree_functions.cpp"
#include "operator_overloading.cpp"

int main(){
    int testCase = 1;
    cout << "Please enter the test case number: ";
    cin >> testCase;
    cout << endl;

    cout << "============================================" << endl;
    cout << "Showing the output for test case " << testCase << ":" << endl;

    if (testCase==1){
        int virus_sequence[] = {1,4,2,6};
        BST<int> virus_tree;
        for (int i = 0; i<4; i++){
            virus_tree.insert(virus_sequence[i]);
        }
        cout<<endl;
        cout<<"Step 1: Tree output after adding nodes with values: 1, 4, 2, 6"<<endl;
        cout<<endl;
        virus_tree.print();
        cout<<endl;
        cout<<"Step 2: Tree output after adding nodes with values: 1, 4"<<endl;
        cout<<endl;
        int virus_sequence2[] = {1,4};
        for (int i = 0; i<2; i++){
            virus_tree.insert(virus_sequence2[i]);
        }
        virus_tree.print();
        cout<<endl;

    }
    else if (testCase==2){
        // Testing getMaxHeight function
        int virus_sequence[] = {6,17,19,15,2,16,13,3,10,7,9};
        // int virus_sequence[100];
        //  for(int i=0;i<110;i++){
        //     virus_sequence[i]=rand()%100;
        // }
        BST<int> virus_tree;
        for (int i = 0; i<11; i++){
            virus_tree.insert(virus_sequence[i]);
        }
        int virus_sequence2[] = {11};
        BST<int> virus_tree2;
        for (int i = 0; i<1; i++){
            virus_tree2.insert(virus_sequence2[i]);
        }
        // BST<int> virus_tree_copy;
        // virus_tree_copy.insert(2);
        // cout<<"Maximum height of the tree: "<<virus_tree_copy.getMaxHeight()<<endl;
        virus_tree.print();
        // cout<<virus_tree2.getMaxHeight();
        BST<int> virus_tree_copy = virus_tree;
        // virus_tree_copy++;
        // virus_tree_copy++;
        // virus_tree_copy++;
        // virus_tree_copy++;
        // // virus_tree_copy.print();
        BST<int> virus_tree_copy2 = virus_tree_copy.operator+(virus_tree2);
        // virus_tree_copy2.print();
        cout<<"Maximum height of the tree: "<<virus_tree.getMaxHeight()<<endl;
        cout<<"Minimum value of the tree: "<<virus_tree.operator[](-1)<<endl;
        // cout<<"Minimum value of the tree: "<<virus_tree.operator[](1)<<endl;
        // cout<<"Minimum value of the tree: "<<virus_tree.operator[](2)<<endl;
        // cout<<"Minimum value of the tree: "<<virus_tree.operator[](3)<<endl;
        // virus_tree.mutate();
    }
    else if (testCase==3){
        // Testing getMaxCounter function
        // int virus_sequence[] = {5,3,6,1,2,7,4,5,5,6};
        int virus_sequence[100];
         for(int i=0;i<100;i++){
            virus_sequence[i]=rand()%100;
        }
        BST<int> virus_tree;
        for (int i = 0; i<100; i++){
            virus_tree.insert(virus_sequence[i]);
        }
        virus_tree.print();
        cout<<"Maximum counter present in the tree: "<<virus_tree.getMaxcounter()<<endl;
    }
    else if (testCase==4){
        // Testing totalNodes function
        int virus_sequence[] = {1,2,2,3,3,3,4,5,5,6};
        BST<int> virus_tree;
        for (int i = 0; i<10; i++){
            virus_tree.insert(virus_sequence[i]);
        }
        virus_tree.print();
        cout<<"Total number of nodes in the tree: "<<virus_tree.totalNodes()<<endl;
    }
    else if (testCase==5){
        // Testing breakbond function
        int virus_sequence[] = {4,2,5,3,1,4,3,3,2,9};
        BST<int> virus_tree;
        for (int i = 0; i<10; i++){
            virus_tree.insert(virus_sequence[i]);
        }
        virus_tree.print();
        cout<<"Breaking bond with strength 2"<<endl;

        // Vaccine of strength 2 in action
        virus_tree.breakbond(2);
        virus_tree.print();
    }
    cout << "============================================" << endl << endl;
    return 0;
}
