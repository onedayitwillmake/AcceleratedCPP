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
	if(hw.size() ==0)
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
	// Ask for and read the students name
	std::cout << "Please enter your first name: ";
	std::string name;

	std::cin >> name;
	std::cout << "Hello, " << name << "!" << std::endl;

	// ask for and read the midterm and final grades
	std::cout << "Please enter your midterm and final exam grades: ";
	double midterm, final;
	std::cin >> midterm >> final;

	// ask for the homework grades
	std::cout <<	"Enter all your homework grades, "
				    " followed by end-of-file: ";

	std::vector<double> homework;
	read_hw(std::cin, homework);

	try {
		double final_grade = grade(midterm, final, homework);
		std::streamsize	prec = std::cout.precision();
        std::cout <<	 "Your final grade is " << std::setprecision( 3 ) << final_grade << std::setprecision(prec) << std::endl;
	} catch ( std::domain_error ) {
		std::cout <<	"You must enter your grades. "
					    "Please try again. " << std::endl;
		return 1;
	}

	return 0;
}