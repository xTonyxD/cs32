//
//  Car.c
//  Car
//
//  Created by Howard Stahl on 3/2/16.
//  Copyright © 2016 Howard Stahl. All rights reserved.
//

#include "Car.h"
#include <iostream>

namespace cs32
{
    
    
    Car::Car( std::string make, std::string model, std::string color, double price )
    : mMake( make ), mModel( model ), mColor( color ), mPrice( price )
    {
        
        
    }
    
    std::string Car::getMake( ) const
    {
        return( mMake );
    }
    
    void Car::setMake( std::string make )
    {
        mMake = make;
    }
    
    std::string Car::getModel( ) const
    {
        return( mModel );
    }
    
    void Car::setModel( std::string model )
    {
        mModel = model;
    }
    
    std::string Car::getColor( ) const
    {
        return( mColor );
    }
    
    void Car::setColor( std::string color )
    {
        mColor = color;
    }
    
    double Car::getPrice( ) const
    {
        return( mPrice );
    }
    
    void Car::setPrice( double price )
    {
        mPrice = price;
    }
    
    void Car::drive( )
    {
        using namespace std;
        cout << "here is Car driving around town..." << endl;
    }
    
}
