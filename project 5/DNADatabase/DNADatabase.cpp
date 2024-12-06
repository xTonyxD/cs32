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
        std::cout << *i << typeid(*i).name() << ((*i) == 'A') << std::endl;
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
    int result = -1;
    return( result );
}

}
