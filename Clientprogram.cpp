// Kevin Mattappally and Davis Fairchild
// LINKEDBINARYTREE
// 3-05-18
// Clientprogram.cpp
// dropoff using kmattappally

#include <iostream>
#include <fstream>
#include "BinaryTree.h"
#include "Exception.h"
#include "TreeNode.h"

using namespace std;

// Open the file to be read from in the main program
// pre: infile is not open to a file
// post: infile can be used to read from a file
// usage: openInputFile(infile);
void openInputFile(ifstream& infile);

// Helps to insert a full tree of height two into
// the binary tree.
// pre: infile has been opened for reading, mytree is
// an empty Binarytree
// post: mytree has been assigned to a full binary tree
// usage: insertTreeOne(infile, mytree);
void insertTreeOne(ifstream& infile, BinaryTree& mytree);

// Helps to insert a complete tree of height three into
// the binary tree.
// pre: infile has been opened for reading, mytree is
// an empty Binarytree
// post: mytree has been assigned to a full binary tree
// usage: insertTreeTwo(infile, mytree);
void insertTreeTwo(ifstream& infile, BinaryTree& mytree);

// helps to output the BinaryTree as a sideways tree
// pre: mytree is assigned to a typical binary tree
// post: the Binary Tree is printed out to the
// console to look like an actual binary tree
// usage: doPrettyDisplay(mytree);
void doPrettyDisplay(BinaryTree& mytree);

// helps to traverse an entire tree using
// preorder, inorder, and postorder traversal methods
// pre: mytree is assigned to a typical binary tree
// post: mytree has been printed in preorder, inorder
// and postorder traversals
// usage: doTraversals(mytree);
void doTraversals(BinaryTree& mytree);

// prints out the exception message
// pre: except is assigned to an exception
// post: an exception notice is printed out
// usage: PrintExceptionMessage(except);
void PrintExceptionMessage(const Exception& except);

int main()
{
    BinaryTree treeOne;
    BinaryTree treeTwo;
    ifstream infile;
    
    openInputFile(infile);
    insertTreeOne(infile, treeOne);
    cout << "Full tree of height 2" << endl << endl;
    doPrettyDisplay(treeOne);
    doTraversals(treeOne);
    insertTreeTwo(infile, treeTwo);
    cout << "Complete tree of height 3" << endl << endl;
    doPrettyDisplay(treeTwo);
    doTraversals(treeTwo);
    
    return 0;
}

void openInputFile(ifstream& infile)
{
    infile.open("Input.dat");
    if(infile.fail())
    {
        cout << "ERROR IN OPENING 'Input.dat'" ;
        exit(1);
    }
}

void insertTreeOne(ifstream& infile, BinaryTree& mytree)
{
    try
    {
        mytree.makeTreeOne(infile);
    }
    catch (Exception except)
    {
        PrintExceptionMessage(except);
    }
}

void insertTreeTwo(ifstream& infile, BinaryTree& mytree)
{
    try
    {
        mytree.makeTreeTwo(infile);
    }
    catch (Exception except)
    {
        PrintExceptionMessage(except);
    }
}

void doPrettyDisplay(BinaryTree& mytree)
{
    mytree.prettyDisplay();
    cout << endl;
}

void doTraversals(BinaryTree& mytree)
{
    cout << "Preorder Traversal: " << endl;
    mytree.preorderTraverse();
    cout << endl;
    cout << "Inorder Traversal: " << endl;
    mytree.inorderTraverse();
    cout << endl;
    cout << "Postorder Traversal: " << endl;
    mytree.postorderTraverse();
    cout << endl;
}

void PrintExceptionMessage(const Exception& except)
{
    cout << endl << endl;
    cout << except.What();
    cout << endl << endl;
}

