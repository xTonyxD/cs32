//
//  DNADatabase.cpp
//  DNADatabase
//

#include "DNADatabase.h"
#include <iostream>

namespace cs32
{

DNADatabase::DNADatabase()
{
    
}

// TODO
bool DNADatabase::findSequence( std::string sequence ) const
{
    return mTrie.contains(sequence);
}

// TODO
bool DNADatabase::addSequence( std::string sequence )
{
    if (!isValid(sequence)) return false;

    int size = mTrie.size();
    mTrie.insert(sequence);

    return(mTrie.size() > size);
}

// TODO
bool DNADatabase::isValid( std::string sequence ) const
{
    
    std::string::iterator i;
    for (i = sequence.begin(); i != sequence.end(); i++) {
        //std::cout << *i << typeid(*i).name() << ((*i) == 'A') << std::endl;
        if (*i != 'A' && *i != 'T' && *i != 'G' && *i != 'C') {
            return false;
        }
    }

    return true;
}

// TODO
int  DNADatabase::size() const
{
    return mTrie.size();
}

// TODO
int  DNADatabase::height() const
{
    return mTrie.height();
}

// TODO
int  DNADatabase::countAllGs() const
{


    int h = mTrie.height();
    int ct = 0;
    std::string temp = "";

    //init temp to string of g's at max possible lenght
    for (int i = 0; i < h; i++) {
        temp = temp + "G";
    }
    //std::cout << temp << std::endl;

    while (temp.length() > 0) {
        if (mTrie.contains(temp)) ct++;
        temp.pop_back();
    }

    return ct;
}

}
