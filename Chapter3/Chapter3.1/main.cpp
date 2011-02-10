#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

int main (int argc, char * const argv[]) 
{
    // insert code here...
	std::cout << "Please enter your first name: " << std::endl;
	std::string name;
	std::cin >> name;
    std::cout << "Hello " << name << "!" << std::endl;
	
	std::cout << "Please enter your midterm and final exam grades: ";
	double midterm, final;
	std::cin >> midterm >> final;
	
	// Ask for the homework grades
	std::cout <<	"Enter all your homework grades, "
					"followed by end-of-file: ";
	
	// The number and sum of the grades read so far
	int count = 0;
	double sum = 0;
	
	// A variable into which to read
	double x;
	
	while(std::cin >> x) {
		++count;
		sum += x;
	}
	
	// Write the result
	std::streamsize prec = std::cout.precision();
	std::cout	<< "Your final grade is " << std::setprecision(3)
				<< 0.2 * midterm + 0.4 * final + 0.4 * sum/count
				<< std::setprecision(prec) << std::endl;
    return 0;
}
