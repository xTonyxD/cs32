#include "Person.h"

namespace cs32
{


// Person Constructors
Person::Person( ) : mName( "" ), mGender( Gender::PREFERNOTTOANSWER )
{
    myMother = nullptr;
    myFather = nullptr;
}

Person::Person( std::string name, Gender gender ) : mName( name ), mGender( gender )
{
    myMother = nullptr;
    myFather = nullptr;
}

// Trivial Person getters
const std::string& Person::getName()   const
{
    return( mName );
}

Gender             Person::getGender() const
{
    return( mGender );
}

// TODO Who is your mother?
void           Person::setMother( Person * p )
{
    this->myMother = p;

}

// TODO Who is your father?
void           Person::setFather( Person * p )
{
    this->myFather = p;

}

// TODO Who is your mother?
Person*        Person::getMother() const
{
    return(myMother);
}

// TODO Who is your father?
Person*        Person::getFather() const
{
    return(myFather);
}

// TODO who are your siblings - brothers or sisters?
void           Person::addSibling( Person * p )
{
    this->mySiblings.insert(p);
}

// TODO who are your grandparents - grandfather or grandmother?
void           Person::addGrandparent( Person * p )
{
    if(p != nullptr) this->myGrandparents.insert(p);
}

// TODO who are your children - sons or daughters?
void           Person::addChild( Person * p )
{
    if(p != nullptr) this->myOffspring.insert(p);
}

// Required Relationship Functions
// TODO return all your defined brothers
std::set<Person*> Person::brothers( )
{
    std::set<Person*> bruh;
    for (auto p : mySiblings){
        if (p -> getGender() == Gender::MAN){
            bruh.insert(p);
        }
    }
    return(bruh);
}

// TODO return all your defined children - sons and daughters
std::set<Person*> Person::children()
{
    std::set< Person* > bruh = std::set<Person*>(this->myOffspring);
    return(bruh);
}

// TODO return all your defined daughters
std::set<Person*> Person::daughters()
{
    std::set<Person*> bruh;
    for (auto p : myOffspring) {
        if (p->getGender() == Gender::WOMAN) {
            bruh.insert(p);
        }
    }
    return(bruh);
}

// TODO return all your defined grandfathers
std::set<Person*> Person::grandfathers( )
{
    std::set<Person*> bruh;
    for (auto p : myGrandparents) {
        if (p->getGender() == Gender::MAN) {
            bruh.insert(p);
        }
    }
    return(bruh);
}

// TODO return all your defined grandmothers
std::set<Person*> Person::grandmothers()
{
    std::set<Person*> bruh;
    for (auto p : myGrandparents) {
        if (p->getGender() == Gender::WOMAN) {
            bruh.insert(p);
        }
    }
    return(bruh);
}

// TODO return all your defined grandparents - grandfathers and grandmothers
std::set<Person*> Person::grandparents()
{
    std::set< Person* > bruh = std::set<Person*>(this->myGrandparents);
    return(bruh);
}

// TODO return all your defined parents - father and mother
std::set<Person*> Person::parents( )
{
    std::set< Person* > bruh;
    if (this->myMother != nullptr) bruh.insert(this->myMother);
    if (this->myFather != nullptr) bruh.insert(this->myFather);

    return(bruh);
}

// TODO return all your defined siblings - brothers and sisters
std::set<Person*> Person::siblings()
{
    std::set< Person* > bruh = std::set<Person*>(this->mySiblings);
    return(bruh);
}

// TODO return all your defined sisters
std::set<Person*> Person::sisters( )
{
    std::set<Person*> bruh;
    for (auto p : mySiblings) {
        if (p->getGender() == Gender::WOMAN) {
            bruh.insert(p);
        }
    }
    return(bruh);
}

// TODO return all your defined sons
std::set<Person*> Person::sons()
{
    std::set<Person*> bruh;
    for (auto p : myOffspring) {
        if (p->getGender() == Gender::MAN) {
            bruh.insert(p);
        }
    }
    return(bruh);
}

}
