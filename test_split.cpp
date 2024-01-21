/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>

int main(int argc, char* argv[])
{
    // int x[10] = {0, 1, 5, 10, 23, 24, 25, 26, 28, 100};
    // int x[1] = {1};
    // int x[10] = {0, 2, 4, 10, 24, 26, 28, 30, 36, 100};
    int x[10] = {0, 1, 5, 10, 23, 24, 25, 26, 28, 100};
    Node* list = new Node(x[0], nullptr);
    Node* curr = list;
    for (int i = 1; i < 10; i++){
        curr->next = new Node(x[i], nullptr);
        curr = curr -> next;
    }
	Node* odds = nullptr;
	Node* evens = nullptr;
    curr = list;
    while (curr){
        std::cout << curr->value << std::endl;
        curr = curr -> next;
    }

    std::cout << "Now Odds" << std::endl;
    split(list, odds, evens);
    
    curr = odds;
    while (curr){
        std::cout << curr->value << std::endl;
        Node* temp = curr;
        curr = curr -> next;
        delete temp;
    }

    std::cout << "Now Evens" << std::endl;
    curr = evens;
    while (curr){
        std::cout << curr->value << std::endl;
        Node* temp = curr;
        curr = curr -> next;
        delete temp;
        }


}
