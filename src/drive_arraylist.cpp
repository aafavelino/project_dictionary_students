/*
 * Test aaplication for the Dictionary with Array Lits or DAL.
 *
 * Try to test as many DAL's methods in varying situations
 * as possible.
 *
 * */
#include <iostream>
#include <sstream>
#include <cmath>
#include <functional>
#include <stdexcept>  

#include "dal.h"



class MyKeyComparator {
public:
int operator()( int lhs, int rhs ) const {
    if( lhs < rhs ) 
        return -1;
    else if ( lhs == rhs ) 
        return 0;
    else 
        return 1; // lhs > rhs 
}
};

int main ( ) {
std::string remover;
DAL< int, std::string, MyKeyComparator > myList( 50 );

//DSAL< int, std::string, MyKeyComparator > myList( 50 );

cout << ">>> Inserindo {2015003129, \"Jack\"}" << endl; myList.insert( 1, "Jack" );

cout << ">>> Inserindo {2014065190, \"John\"}" << endl; myList.insert( 2, "John" );

    std::cout << "\n>>> myList: " << myList << std::endl;
    auto j(0);
    
    std::cout << myList.min()<< std::endl;
    std::cout << myList.max()<< std::endl;
    std::cout << myList.predecessor(2,j)<< std::endl;
    std::cout << myList.sucessor(1,j)<< std::endl;
    std::cout << myList.remove(2,remover)<< std::endl;
    std::cout << "\n>>> myList: " << myList << std::endl;



    std::cout << "\n>>> Normal ending...\n\n";

    return EXIT_SUCCESS;
}

