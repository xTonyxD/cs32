//
//  Suburu.hpp
//  Example
//
//  Created by Howard Stahl on 3/2/16.
//  Copyright © 2016 Howard Stahl. All rights reserved.
//

#ifndef SUBURU_H
#define SUBURU_H
#include <string>
#include "Car.h"

namespace cs32
{
    

class Suburu : public Car
{
public:
    Suburu( std::string make, std::string color, double price );
    
    virtual void drive( );
private:
    
};

}

#endif
