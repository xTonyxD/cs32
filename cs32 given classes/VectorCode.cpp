//
//  Created by Howard Stahl on 11/8/23.
//

#include <iostream>
#include <string>
#include <vector>

enum class MENU { ADD, SIZE, CAPACITY, PRINT, QUIT };

MENU menu()
{
    using namespace std;
    MENU m = MENU::QUIT;
    string s;
    cout << "---> (A)dd (S)ize (C)apacity (P)rint (Q)uit: ";
    cin  >> s;
    switch( s.at( 0 ) )
    {
        case 'A':
        case 'a':
            m = MENU::ADD;
            break;
        case 'S':
        case 's':
            m = MENU::SIZE;
            break;
        case 'C':
        case 'c':
            m = MENU::CAPACITY;
            break;
        case 'P':
        case 'p':
            m = MENU::PRINT;
            break;
        case 'Q':
        case 'q':
            m = MENU::QUIT;
            break;
        default:
            m = menu();
            break;
    }
    return( m );
}


int main()
{
    using namespace std;
    std::vector< int > v;
    int value;
    MENU m = MENU::QUIT;
    do
    {
        m = menu();
        
        switch( m )
        {
            case MENU::ADD:
                cin >> value;
                v.push_back( value );
                break;
            case MENU::SIZE:
                cout << "v's size = " << v.size() << endl;
                break;
            case MENU::CAPACITY:
                cout << "v's capacity = " << v.capacity() << endl;
                break;
            case MENU::PRINT:
                for (value = 0; value < v.size(); value++)
                    cout << "v[ " << value << " ] = " << v[ value ] << endl;
                break;
            case MENU::QUIT:
                break;
        }
    } while (m != MENU::QUIT);
    
    return 0;
}
