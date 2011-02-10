/**
 Accelerated CPP
 Chapter 3.2
 2/10/11
**/
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

int main (int argc, char * const argv[]) 
{
    // insert code here...
	std::cout << "Please enter your first name: " << std::endl;
	std::string name;
	std::cin >> name;
    std::cout << "Hello " << name << "!" << std::endl;
	
	std::cout << "Please enter yo ur midterm and final exam grades: ";
	double midterm, final;
	std::cin >> midterm >> final;
	
	// Ask for the homework grades
	std::cout <<	"Enter all your homework grades, "
					"followed by end-of-file: ";
	
	// Store values in a vector
	// A variable into which to read
	double x;
	std::vector<double> homework;
	 
	while(std::cin >> x) {
		homework.push_back(x);
	}
	
	// Write the result
	typedef std::vector<double>::size_type vecSize;
	vecSize size = homework.size();
	
	// check for zero element vector
	if( size == 0 ) {
		std::cout << "You must enter your grades. Please try again." << std::endl;
		return 1;
	}
	
	// Sort
	sort( homework.begin(), homework.end() );
	
	// Find middle
	vecSize mid = size / 2;
	double median;
	median = size % 2 == 0 ? (homework[mid] + homework[mid-1]) / 2 : homework[mid];
	
	std::streamsize prec = std::cout.precision(); // Store precision
	// Write out final grade
	std::cout << "Your final grade is " << std::setprecision( 3 )
	<< 0.2f * midterm + 0.4 * final + 0.4 * median
	<< std::setprecision(prec) << std::endl;
		
//	std::streamsize prec = std::cout.precision();
//	std::cout	<< "Your final grade is " << std::setprecision(3)
//				<< 0.2 * midterm + 0.4 * final + 0.4 * sum/count
//				<< std::setprecision(prec) << std::endl;
    return 0;
}
