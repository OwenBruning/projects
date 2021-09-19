/***************************************************************************************
*    NOTE: several modifications have been made to this file in order to ensure that it works with this project.
*    NOTE: the file SplayTree.h was created by Mark Allen Weiss, and has been properly cited below.
*    Title: SplayTree.h
*    Author: Weiss, Mark Allen
*    Date: 2014
*    Code version: 1.0
*    Availability: http://users.cs.fiu.edu/~weiss/dsaa_c++4/code/SplayTree.h
***************************************************************************************/

#ifndef SPLAY_TREE_H
#define SPLAY_TREE_H

#include "StationData.h"
#include <iostream>     
using namespace std;

// SplayTree class
//
// CONSTRUCTION: with no parameters
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x
// bool contains( x )     --> Return true if x is present
// StationData findMin( )  --> Return smallest item
// StationData findMax( )  --> Return largest item
// bool isEmpty( )        --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order
// ******************ERRORS********************************
// Throws UnderflowException as warranted


class SplayTree
{
  public:
    int depth;
    SplayTree( )
    {
        nullNode = new BinaryNode;
        nullNode->left = nullNode->right = nullNode;
        root = nullNode;
    }

    SplayTree( const SplayTree & rhs )
    {
        nullNode = new BinaryNode;
        nullNode->left = nullNode->right = nullNode;
        root = clone( rhs.root );
    }

    SplayTree( SplayTree && rhs ) : root{ rhs.root }, nullNode{ rhs.nullNode }
    {
        rhs.root = nullptr;
        rhs.nullNode = nullptr;
    }
    
    ~SplayTree( )
    {
        makeEmpty( );
        delete nullNode;
    }

    
    /**
     * Deep copy.
     */
    SplayTree & operator=( const SplayTree & rhs )
    {
        SplayTree copy = rhs;
        std::swap( *this, copy );
        return *this;
    }
        
    /**
     * Move.
     */
    SplayTree & operator=( SplayTree && rhs )
    {
        std::swap( root, rhs.root );
        std::swap( nullNode, rhs.nullNode );
        
        return *this;
    }
    
    /**
     * Find the smallest item in the tree.
     * Not the most efficient implementation (uses two passes), but has correct
     *     amortized behavior.
     * A good alternative is to first call find with parameter
     *     smaller than any item in the tree, then call findMin.
     * Return the smallest item or throw UnderflowException if empty.
     */
    const StationData & findMin( )
    {
        BinaryNode *ptr = root;

        while( ptr->left != nullNode )
            ptr = ptr->left;

        splay( ptr->element, root, depth );
        return ptr->element;
    }

    /**
     * Find the largest item in the tree.
     * Not the most efficient implementation (uses two passes), but has correct
     *     amortized behavior.
     * A good alternative is to first call find with parameter
     *     larger than any item in the tree, then call findMax.
     * Return the largest item or throw UnderflowException if empty.
     */
    const StationData & findMax( )
    {
        BinaryNode *ptr = root;

        while( ptr->right != nullNode )
            ptr = ptr->right;

        splay( ptr->element, root, depth );
        return ptr->element;
    }


    bool contains( const StationData & x, int &depth )
    {
        if( isEmpty( ) )
            return false;
        splay( x, root, depth );
        return root->element == x;
    }

    bool isEmpty( ) const
    {
        return root == nullNode;
    }

    void printTree( ) const
    {
        if( isEmpty( ) )
            cout << "Empty tree" << endl;
        else
            printTree( root );
    }

    void makeEmpty( )
    {
    /******************************
     * Comment this out, because it is prone to excessive
     * recursion on degenerate trees. Use alternate algorithm.
        
        reclaimMemory( root );
        root = nullNode;
     *******************************/
        while( !isEmpty( ) )
        {
            findMax( );        // Splay max item to root
            remove( root->element );
        }
    }

    void insert( const StationData & x )
    {
        static BinaryNode *newNode = nullptr;

        if( newNode == nullptr )
            newNode = new BinaryNode;
        newNode->element = x;

        if( root == nullNode )
        {
            newNode->left = newNode->right = nullNode;
            root = newNode;
        }
        else
        {
            splay( x, root, depth );
            if( x < root->element )
            {
                newNode->left = root->left;
                newNode->right = root;
                root->left = nullNode;
                root = newNode;
            }
            else
            if( root->element < x )
            {
                newNode->right = root->right;
                newNode->left = root;
                root->right = nullNode;
                root = newNode;
            }
            else
                return;
        }
        newNode = nullptr;   // So next insert will call new
    }

    void remove( const StationData & x )
    {
            // If x is found, it will be splayed to the root by contains
        if( !contains( x, depth ) )
            return;   // Item not found; do nothing

        BinaryNode *newTree;

        if( root->left == nullNode )
            newTree = root->right;
        else
        {
            // Find the maximum in the left subtree
            // Splay it to the root; and then attach right child
            newTree = root->left;
            splay( x, newTree, depth );
            newTree->right = root->right;
        }
        delete root;
        root = newTree;
    }

private:
    struct BinaryNode
    {
        StationData  element;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode( ) : left{ nullptr }, right{ nullptr } { }
        
        BinaryNode( const StationData & theElement, BinaryNode *lt, BinaryNode *rt )
            : element{ theElement }, left{ lt }, right{ rt } { }       
    };
    
    BinaryNode *root;
    BinaryNode *nullNode;


    /**
     * Internal method to reclaim internal nodes in subtree t.
     * WARNING: This is prone to running out of stack space.
     */
    void reclaimMemory( BinaryNode * t )
    {
        if( t != t->left )
        {
            reclaimMemory( t->left );
            reclaimMemory( t->right );
            delete t;
        }
    }
    
    /**
     * Internal method to print a subtree t in sorted order.
     * WARNING: This is prone to running out of stack space.
     */
   void printTree( BinaryNode *t ) const
    {
        if( t != t->left )
        {
            printTree( t->left );
            cout << t->element;
            cout << endl;
            printTree( t->right );
        }
    }

    /**
     * Internal method to clone subtree.
     * WARNING: This is prone to running out of stack space.
     */
    BinaryNode * clone( BinaryNode * t ) const
    {
        if( t == t->left )  // Cannot test against nullNode!!!
            return nullNode;
        else
            return new BinaryNode{ t->element, clone( t->left ), clone( t->right ) };
    }

        // Tree manipulations
    void rotateWithLeftChild( BinaryNode * & k2 )
    {
        BinaryNode *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2 = k1;
    }

    void rotateWithRightChild( BinaryNode * & k1 )
    {
        BinaryNode *k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1 = k2;
    }

    /**
     * Internal method to perform a top-down splay.
     * The last accessed node becomes the new root.
     * This method may be overridden to use a different
     * splaying algorithm, however, the splay tree code
     * depends on the accessed item going to the root.
     * x is the target item to splay around.
     * t is the root of the subtree to splay.
     */
    void splay( const StationData & x, BinaryNode * & t, int &depth )
    { depth = 0;
        BinaryNode *leftTreeMax, *rightTreeMin;
        static BinaryNode header;

        header.left = header.right = nullNode;
        leftTreeMax = rightTreeMin = &header;

        nullNode->element = x;   // Guarantee a match

        for( ; ; )
            if( x < t->element )
            { depth++;
                if( x < t->left->element )
                    rotateWithLeftChild( t );
                if( t->left == nullNode )
                    break;
                // Link Right
                rightTreeMin->left = t;
                rightTreeMin = t;
                t = t->left;
            }
            else if( t->element < x )
            {
                if( t->right->element < x )
                    rotateWithRightChild( t );
                if( t->right == nullNode )
                    break;
                // Link Left
                leftTreeMax->right = t;
                leftTreeMax = t;
                t = t->right;
            }
            else
                break;

        leftTreeMax->right = t->left;
        rightTreeMin->left = t->right;
        t->left = header.right;
        t->right = header.left;
    }
};

#endif

