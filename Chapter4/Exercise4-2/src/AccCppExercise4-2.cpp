//============================================================================
// Name        : AccCppExercise4-2.cpp
// Author      : Mario Gonzalez
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <iomanip>


int square(int x) {
	return x*x;
}

int main() {

	for (int i = 1; i < 101; ++i) {
	  std::cout << "Input: " << std::setw(4) << i << " Value: " << std::setw(6) <<(i * i) << std::endl;
   }
	return 0;
}


