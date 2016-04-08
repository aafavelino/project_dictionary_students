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




int main ( )
{
    DAL< int, std::string  >  myList( 50 ); // Lista de no máximo 50 elementos.

    std::cout << "\n>>> myList: " << myList << std::endl;
try{
    myList.insert(  2, "dado 2" );
    myList.insert(  8, "dado 3" );
    myList.insert( 15, "dado 1" );
}
catch(const std::length_error & e){
	std::cout << ">>> Capturei uma uma exceção";
}
int j = 0;

	std::cout << "\n>>> myList: " << myList << std::endl;

	std::cout << myList.min()<< std::endl;
	std::cout << myList.max()<< std::endl;
	std::cout << myList.predecessor(2,j)<< std::endl;
	std::cout << j<< std::endl;
    std::cout << "\n>>> Normal ending...\n\n";

    return EXIT_SUCCESS;
}

