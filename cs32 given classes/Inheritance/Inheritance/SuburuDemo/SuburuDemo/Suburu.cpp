//
//  Suburu.cpp
//  Example
//
//  Created by Howard Stahl on 3/2/16.
//  Copyright © 2016 Howard Stahl. All rights reserved.
//

#include "Suburu.h"
#include <iostream>

namespace cs32 {

    Suburu::Suburu( std::string make, std::string color, double price )
    : Car( "Suburu", make, color, price )
    {
        
    }

    void Suburu::drive( )
    {
        using namespace std;
        cout << "a gas-powered suburu is driving around..." << endl;
    }

}
