//
//  Tesla.h
//  Example
//
//  Created by Howard Stahl on 3/2/16.
//  Copyright © 2016 Howard Stahl. All rights reserved.
//

#ifndef TESLA_H
#define TESLA_H
#include <string>
#include "Car.h"

namespace cs32
{
    

class Tesla : public Car
{
public:
    Tesla( std::string make, std::string color, double price );
    
    virtual void drive( );
private:
    
};

}

#endif
