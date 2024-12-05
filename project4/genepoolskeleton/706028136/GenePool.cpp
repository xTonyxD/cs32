#include "GenePool.h"
#include "Person.h"
#include "TSVFile.h"
#include <string>
#include <iostream>
//using namespace std;


namespace cs32
{

GenePool::GenePool() : isLoaded( false )
{
    
}

// has this GenePool been loaded with data?
bool GenePool::loaded() const
{
    return( isLoaded );
}

// clear this GenePool of all its data
void GenePool::clear()
{
    if (loaded())
    {
        while (!people.empty())
        {
            Person * p = people.back();
            people.pop_back();
            delete( p );
        }
    }
    isLoaded = false;
}

// read the TSVFile, inflate the database and return the number of records read
int GenePool::load( const std::string& filePath )
{
    isLoaded = true;
    TSVFile file( this );
    int recordCount = file.readFile( filePath );
    if (recordCount == 0)
    {
        isLoaded = false;
        // i suppose you could throw an exception to communicate no records read...
    }
    // once everyone is loaded individually, then establish the additional relationships
    //      namely siblings, grandparents and children
    findEveryonesSiblings();
    findEveryonesGrandparents();
    findEveryonesChildren();
    return( recordCount );
}

// TODO establish every person's grandparents - grandfathers and grandmothers - in the database,
//      if they are known
void   GenePool::findEveryonesGrandparents() const
{
    //using namespace std;
    Person* mother;
    Person* father;
    for (std::vector<Person*>::const_iterator i = people.begin(); i != people.end(); i++)
    {
        //cout << (*i)->getName() << ":: ";
        mother = (*i)->getMother();
        father = (*i)->getFather();
        if (mother != nullptr) {
            //cout << ((*i)->getFather()->getFather() != nullptr);

            if (mother->getMother() != nullptr) (*i)->addGrandparent(mother->getMother());
            if (mother->getFather() != nullptr) (*i)->addGrandparent(mother->getFather());
        }
        if (father != nullptr) {
            //if ((*i)->getFather()->getFather() != nullptr)
            //    cout << (*i)->getFather()->getFather()->getName() << endl;

            if (father->getMother() != nullptr)(*i)->addGrandparent(father->getMother());
            if (father->getFather() != nullptr) (*i)->addGrandparent(father->getFather());
        }

    }

}

// TODO establish every person's siblings - brothers and sisters - in the database,
//      if they are known
void GenePool::findEveryonesSiblings() const
{
    std::set<Person*> siblings;
    for (std::vector<Person*>::const_iterator i = people.begin(); i != people.end(); i++)
    {
        siblings = (*i)->siblings();
        for (std::vector<Person*>::const_iterator j = people.begin(); j != people.end(); j++)
        {
            int numSharedParents = 0;
            
            if (siblings.find((*j)) == siblings.end() && (*i)->getName() != (*j)->getName()) {
                //cerr << "nsp" << numSharedParents;
                //cerr << (*i)->getName() << ((*i)->getMother() == nullptr) << ((*j)->getMother() == nullptr);
                numSharedParents = 0;
                if ((*i)->getMother() != nullptr && (*j)->getMother() != nullptr){
                    if ((*i)->getMother()->getName() == (*j)->getMother()->getName()) {
                        //if ((*j)->getMother() != nullptr && (*i)->getMother() != nullptr) cerr << "mothers" << (*i)->getMother()->getName() << ", " << (*j)->getMother()->getName(); //mothers match
                        //cerr << (*i)->getName() << ((*i)->getMother() == nullptr) << ((*j)->getMother() == nullptr);
                        numSharedParents++;
                    }
                }
                if ((*i)->getFather() != nullptr && (*j)->getFather() != nullptr) {
                    if (((*i)->getFather()->getName() == (*j)->getFather()->getName())) {
                        //if ((*j)->getFather() != nullptr && (*i)->getFather() != nullptr) {
                        //    cerr << "fathers" << (*i)->getFather()->getName() << ", " << (*j)->getFather()->getName();
                        //}//fathers match
                        //cerr << (nullptr == (*i)->getFather()) << (nullptr == (*j)->getFather()); //print which father is null
                        numSharedParents++;
                    }
                }
                

                if (numSharedParents > 0) {
                    //cerr << "nsp" << numSharedParents << endl;
                    (*i)->addSibling((*j));
                }
            }
        }
    }
}

// TODO establish every person's children - sons and daughters - in the database,
//      if they are known
void GenePool::findEveryonesChildren() const
{
    for (std::vector<Person*>::const_iterator i = people.begin(); i != people.end(); i++)
    {
        for (std::vector<Person*>::const_iterator j = people.begin(); j != people.end(); j++)
        {
            if ((*j)->getMother() != nullptr) {
                if ((*j)->getMother()->getName() == (*i)->getName()) {
                    (*i)->addChild((*j));
                }
                if ((*j)->getFather()->getName() == (*i)->getName()) {
                    (*i)->addChild((*j));
                }
            }
            
        }
    }

}

// TODO this operation gets called over and over, once per line of data in the tsv data file
//      from the map parameter, this operation should create a new Person and add it to the 
//      people vector
void GenePool::tsvData(std::map< std::string, std::string > row)
{
    //using namespace std;
    Person* p = find(row.at("field0"));
    Person* temp = this->find(row.at("field2"));
    if (p == nullptr) {//doesntexists
        p = new Person(row.at("field0"), toGender(row.at("field1")));
        people.push_back(p);
        //cerr << "new" << endl;
        //cerr << people.size() << endl;
        //cerr << "." << people[people.size() - 1]->getName() << "."<< endl;
    }
    
    //deal with mother
    if (temp == nullptr && row.at("field2") != "???") {
        Person* mother = new Person(row.at("field2"), Gender::WOMAN);
        people.push_back(mother);
        
        p->setMother(mother);
    } else if (row.at("field2") != "???"){
        p->setMother(temp);
    }
    temp = this->find(row.at("field3"));
    //deal with fatger
    if (temp == nullptr && row.at("field3") != "???") {
        Person* father = new Person(row.at("field3"), Gender::MAN);
        people.push_back(father);
        p->setFather(father);
    }
    else if (row.at("field3") != "???") {
        p->setFather(temp);
    }

    
}

// Converts a string (like "man") into one of the Gender enumerated values (like Gender::MAN)
Gender GenePool::toGender( std::string value ) const
{
    Gender result( Gender::PREFERNOTTOANSWER );
    if (value == "man")
    {
        result = Gender::MAN;
    }
    else if (value == "woman" )
    {
        result = Gender::WOMAN;
    }
    else if (value == "nonbinary" )
    {
        result = Gender::NONBINARY;
    }
    return( result );
}

// Clean it up
GenePool::~GenePool()
{
    while (!people.empty())
    {
        Person * p = people.back();
        people.pop_back();
        delete( p );
    }
}

// Returns a set with all the people in the database, if the database has been loaded with data
std::set<cs32::Person*> GenePool::everyone() const
{
    std::set< Person * > set;
    if (loaded())
    {
        //cerr << "dafs" << endl;
        for( std::vector< Person * >::const_iterator iter = people.begin(); iter != people.end(); iter++)
        {
            Person * p = *iter;
            set.insert( p );
        }
    }
    return( set );
}

// Find a person in the database by name, if the database has been loaded with data
// Return nullptr if there is no such person
cs32::Person* GenePool::find(const std::string& name) const
{
    Person * result = nullptr;
    if (loaded())
    {
        for( std::vector< Person * >::const_iterator iter = people.begin(); iter != people.end(); iter++)
        {
            Person * p = *iter;
            if (p->getName() == name)
            {
                result = p;
                break;
            }
        }
    }
    return( result );
}

}
