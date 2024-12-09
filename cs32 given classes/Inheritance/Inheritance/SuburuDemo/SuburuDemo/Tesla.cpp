//
//  Tesla.cpp
//  Example
//
//  Created by Howard Stahl on 3/2/16.
//  Copyright © 2016 Howard Stahl. All rights reserved.
//

#include "Tesla.h"
#include <iostream>

namespace cs32 {

    Tesla::Tesla( std::string make, std::string color, double price )
    : Car( "Tesla", make, color, price )
    {
        
    }

    void Tesla::drive( )
    {
        using namespace std;
        cout << "an electric powered tesla zooming around town..." << endl;
    }

}
