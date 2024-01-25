#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
	ULListStr * list = new ULListStr();
    	for(int count = 0; count < 4; ++count){
            list->push_back("test");
            std::cout << list->get(0) << std::endl;
            list->pop_front();
            std::cout << list->size() << std::endl;
            std::cout << list->empty() << std::endl;

        }
	
    // list->push_back("1");
    // list->push_back("2");
    // list->push_back("3");
    // list->push_back("4");
    // list->push_back("5");
    // list->push_back("6");
    // list->push_back("7");
    // list->push_back("8");
    // list->push_back("9");
    // list->push_back("10");
    // list->push_back("11");
    // // list->push_back("a");
    // // list->push_back("a");
    // // list->push_back("a");
    // // list->push_back("a");
    // // list->push_back("a");
    // // list->push_back("a");
    // // list->push_back("a");
    // // list->push_back("a");
    // // list->push_back("a");
    // // list->push_back("a");
    // // list->push_back("a");
    // // std::cout << list->get(5) << std::endl;
    // std::cout << list->get(10) << std::endl;
    // std::cout << list->get(10) << std::endl;
    // std::cout << list->size() << std::endl;
    // // std::cout << list->empty() << std::endl;
    // list ->clear();
    // std::cout << list->size() << std::endl;
    // std::cout << list->empty() << std::endl;


    // list->pop_back();
    // list->pop_front();
    // list->push_back("Num 1");
    // list->push_back("Num 2");
    // std::cout << list->front() << std::endl;
    // list->push_back("Num 3");
    // std::cout << list->front() << std::endl;
    // list->push_front("Num 4");
    // list->push_front("Num 5");
    // std::cout << list->back() << std::endl;
    // std::cout << list->front() << std::endl;
    // std::cout << "Size " << list->size() << std::endl;
    // list->pop_front();
    // list->pop_back();
    // std::cout << "Size " << list->size() << std::endl;
    // list->push_back("Num 6");
    // list->push_back("Num 7");

    // std::cout << list->size() << std::endl;
    // std::cout << list->get(0) << std::endl;
    // std::cout << list->get(2) << std::endl;

}
