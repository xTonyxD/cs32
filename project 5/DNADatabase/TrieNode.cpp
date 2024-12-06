//
//  TrieNode.cpp
//  DNADatabase
//

#include "TrieNode.h"
#include <iostream>
using namespace std;


namespace cs32
{

// constructor
TrieNode::TrieNode() : mEndOfWord(false)
{
    
}

// destructor
TrieNode::~TrieNode()
{
    // delete all of the new'ed children nodes of this node
    std::map< char, TrieNode* >::const_iterator iter = nextNodeMap.begin();
    while (iter != nextNodeMap.end())
    {
        TrieNode * node = iter->second;
        // delete this node
        // but be careful
        // trying to delete a nullptr value will crash
        if (node != nullptr)
        {
            delete( node );
        }
        ++iter;
    }
}

// return a map iterator for the desired character parameter
std::map< char, TrieNode * >::const_iterator TrieNode::find( char c ) const
{
    // Check if this char has a node created for it already
    std::map< char, TrieNode* >::const_iterator iter = nextNodeMap.find(c);
    return( iter );
}

// TODO
// is the character parameter already present in the nextNodeMap of this node?
bool TrieNode::dataExists( char c ) const
{
    return (this->nextNodeMap.find(c) != this->nextNodeMap.end()); //if it IS end of map char, means not found
}

// TODO
// set the character parameter into the nextNodeMap of this node
void TrieNode::setMapNode( char c, TrieNode * node )
{
    
    this->nextNodeMap.insert({ c,node });
    
    //cout << "setMapNode " << c << endl;
    //this->printmap();
}

void TrieNode::printmap() const {
    std::map<char, TrieNode*>::const_iterator i;
    cout << "printing nextNodeMap" << endl;
    for (i = nextNodeMap.begin(); i != nextNodeMap.end(); i++) {
        cout << i->first << endl;
    }
    cout << "done printing" << endl;
}

// TODO
// is this TrieNode the end of a word?
bool TrieNode::isEndOfWord() const
{
    return /*this->nextNodeMap.size() == 0 && */mEndOfWord;
}

// TODO
// set this TrieNode to be the end of a word
void TrieNode::setEndOfWord()
{
    this->mEndOfWord = true;
}

// TODO
// including this node, how many nodes of this TrieNode have an EndOfWord value that is true
int  TrieNode::howManyWords() const
{
    int ct = 0;
    std::map<char, TrieNode*>::const_iterator i;
    for (i = nextNodeMap.begin(); i != nextNodeMap.end(); i++) {
        //if (i->second->isEndOfWord()) ct++;
        ct += i->second->howManyWords();
    }

    if (this->isEndOfWord()) ct++;
    
    return ct;
}

// TODO
// including this node, how many nodes in this TrieNode have an EndOfWord value that is false
int  TrieNode::howManyNonWords() const
{
    int ct = 0;
    std::map<char, TrieNode*>::const_iterator i;
    for (i = nextNodeMap.begin(); i != nextNodeMap.end(); i++) {
        //if (!(i->second->isEndOfWord())) ct++;
        ct += i->second->howManyNonWords();
    }

    if (!(this->isEndOfWord())) ct++;

    return ct++;
}

// TODO
// what is the size of this TrieNode
// how many nodes are there in this TrieNode?
int  TrieNode::size() const
{
    // how many TrieNodes are found in this TrieNode plus all of its mapnodes?
    // remember one for itself
    int ct = 1;
    std::map<char, TrieNode*>::const_iterator i;
    for (i = nextNodeMap.begin(); i != nextNodeMap.end(); i++) {
        //cout << i->second->to_string();
        ct += i->second->size() - 1;
    }

    return ct + this->nextNodeMap.size();
}

// TODO
// what is the height of this TrieNode
// how far away is the furthest away leaf in this TrieNode?
int  TrieNode::height() const
{
    if (/*this->isEndOfWord() || */this->nextNodeMap.size() == 0) {
        //cout << "premature" << endl;
        //this->printmap();
        return 0;
    }
    int max = 0; 
    int tempMax = 0;
    std::map<char, TrieNode*>::const_iterator i;

    //end condition built in here; if leaf node, nextNodeMap.begin() shoudl return nextNodeMap.end(); for loop exits and height(leafnode) returns 1
    for (i = nextNodeMap.begin(); i != nextNodeMap.end(); i++) { 
        tempMax = i->second->height();
        cout << i->first << ", max: " << max << ", tempmax: " << tempMax << endl;
        if (tempMax > max) max = tempMax;
    }
    cout << max + 1<< ", getting out" << endl;
    return max + 1; //1 for itself
}
// stringify this TrieNode and all of its children nodes
std::string TrieNode::to_string() const
{
    return(to_string(0, ' '));
}

// stringify this TrieNode and all of its children nodes
std::string TrieNode::to_string(int indentLevel, char theData) const
{
    std::string s;
    for (int i = 0; i < indentLevel; i++)
    {
        s += " ";
    }
    s += "thedata --> ";
    s += theData;
    s += "\tend  --> ";
    if (mEndOfWord)
    {
        s += "true";
    }
    else
    {
        s += "false";
    }
    s += "\n";

    std::map< char, TrieNode* >::const_iterator iter = nextNodeMap.begin();
    while (iter != nextNodeMap.end())
    {
        TrieNode* node = iter->second;
        char c = iter->first;
        s += node->to_string(indentLevel + INDENTATION, c);
        ++iter;
    }

    return(s);
}

}
