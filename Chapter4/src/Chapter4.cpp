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
#include <stdexcept>



double median( std::vector<double> vec )
{
	typedef std::vector<double>::size_type vec_sz;
	vec_sz size = vec.size();

	if( size == 0 ) {
		throw std::domain_error("Median of an empty vector");
	}

	std::sort( vec.begin(), vec.end() );

	vec_sz mid = size / 2;
	return size % 2 == 0 ? ( vec[mid] + vec[mid+-1]) / 2 : vec[mid];
}

// compute a student's overall grade from midterm and final exam grades and homework grade
double grade(double midterm, double final, double homework)
{
    return  0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade( double midterm, double final, const std::vector<double>& hw)
{
	if(hw.size==0)
		throw std::domain_error("Student has done no homework");

	return grade( midterm, final, median(hw) );
}

std::istream& read_hw( std::istream& in, std::vector<double>& hw) {
	if( in )
	 {
		hw.clear();

		// read homework grades
		double x;
		while( in >> x )
			hw.push_back( x );

		// clear the stream so that input will work for the next student
		in.clear();
	}
	return in;
}

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

	std::streamsize prec = std::cout.precision(); // Store precision
	// Write out final grade
	std::cout << "Your final grade is " << std::setprecision( 3 )
	<< 0.2f * midterm + 0.4 * final + 0.4 * median( homework )
	<< std::setprecision(prec) << std::endl;

	//	std::streamsize prec = std::cout.precision();
	//	std::cout	<< "Your final grade is " << std::setprecision(3)
	//				<< 0.2 * midterm + 0.4 * final + 0.4 * sum/count
	//				<< std::setprecision(prec) << std::endl;
	   return 0;
}