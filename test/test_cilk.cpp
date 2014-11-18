
#include <parallel_pi_cilk.h>
#include <cassert>
#include <iostream>

int 
main() 
{
	double pi = cilk_estimate_pi((INT32_MAX - 1) / 2, 10000);
	std::cerr << "cilk pi: " << pi << std::endl;
//	assert(pi > 3.14 && pi < 3.15);
	return 0;
}
