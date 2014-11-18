
#include <iostream>
#include <parallel_pi_omp.h>
#include <cassert>

int 
main() 
{
	double pi = omp_estimate_pi((INT32_MAX - 1) / 2, 1000000);
	std::cerr << "pi: " << pi << std::endl;
	assert(pi > 3.14 && pi < 3.15);
	return 0;
}
