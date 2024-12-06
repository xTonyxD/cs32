//
//  Trie.cpp
//  DNADatabase
//

#include "Trie.h"

#include <iostream>

namespace cs32
{

// the constructor
Trie::Trie( )
{
    // build the root node
    // we are not referring to the data in the root node at all
    // instead, we are using the root node to hang all the other nodes off of it
    mRoot = new TrieNode();
}

// the destructor
Trie::~Trie()
{
    // delete the root
    // but be careful
    // trying to delete a nullptr value will crash
    if (mRoot != nullptr)
        delete( mRoot );
}

// TODO
// insert a new word into this Trie
// each letter should get broken into its own TrieNode
// the ending TrieNode should be marked with an EndOfWord value that is true
void Trie::insert( std::string word )
{
    TrieNode* node = mRoot;
    std::string::iterator i;
    for (i = word.begin(); i != word.end(); i++) {
        if (i != word.end() && node->dataExists(*i)) { //char alr in the tree
            node = node->find(*i)->second;

        }
        else {
            TrieNode* temp = new TrieNode();
            node->setMapNode((*i), temp);
            node = temp;
        }
    }

    node->setEndOfWord();
}

// TODO
// determine if this word is already in this Trie
// each letter should be found in nextNodeMap value of a TrieNode hanging off the root of this Trie
// and in addition the last letter should be marked with an EndOfWord value that is true
bool Trie::contains( std::string word ) const
{
    TrieNode* node = mRoot;
    std::string::iterator i;
    for (i = word.begin(); i != word.end(); i++) {
        if (!(node->dataExists(*i))) { //next char not found in children
            return false;
        }
        else { //default
            node = node->find(*i)->second;
        }
    }
    if (node->isEndOfWord()) { //word found; alr end of word; already checked for data existence in the forloop
        return true;
    }
    return false;
}

// TODO
// determine if this partial word is already in this Trie
// each letter should be found in nextNodeMap value of a TrieNode hanging off the root of this Trie
bool Trie::prefixExists( std::string prefix ) const
{
    TrieNode* node = mRoot;
    std::string::iterator i;
    for (i = prefix.begin(); i != prefix.end(); i++) {
        if (!(node->dataExists(*i))) { //next char not found in children
            return false;
        }
        else { //default
            node = node->find(*i)->second;
        }
    }
    if (node->dataExists(*i)) { //word found; alr end of word
        return true;
    }

    return false;
}

// stringify this Trie and all of its TrieNodes
std::string Trie::to_string() const
{
    std::string s;
    if (mRoot != nullptr)
    {
        s = mRoot->to_string();
    }
    return( s );
}

// TODO
// how many nodes in this Trie have an EndOfWord value that is true
int  Trie::howManyWords() const
{
    return mRoot->howManyWords();
}



// TODO
// how many nodes in this Trie have an EndOfWord value that is false
int  Trie::howManyNonWords() const
{
    return mRoot->howManyNonWords();
}

// TODO
// what is the size of this Trie
// how many nodes are there in this Trie?
int  Trie::size() const
{
    return mRoot->size();
}

// TODO
// what is the height of this Trie
// how far away is the further away leaf in this Trie?
int  Trie::height() const
{
    return mRoot->height();
}

}
