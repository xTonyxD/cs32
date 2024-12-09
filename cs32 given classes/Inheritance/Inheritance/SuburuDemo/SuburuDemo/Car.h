//
//  Car.hpp
//  Example
//
//  Created by Howard Stahl on 3/2/16.
//  Copyright © 2016 Howard Stahl. All rights reserved.
//

#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>

namespace cs32
{
    
    
    class Car
    {
    public:
        Car( std::string make, std::string model, std::string color, double price );
        
        std::string getMake( ) const;
        void setMake( std::string make );
        std::string getModel( ) const;
        void setModel( std::string model );
        std::string getColor( ) const;
        void setColor( std::string color );
        double getPrice( ) const;
        void setPrice( double price );
        
        virtual void drive( );
    private:
        std::string mMake, mModel, mColor;
        double      mPrice;
    };
    
    
}

#endif 
