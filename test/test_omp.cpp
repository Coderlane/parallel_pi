
#include <iostream>
#include <parallel_pi_omp.h>
#include <cassert>
#include <omp.h>

int 
main() 
{
#ifdef PARALLEL_PI_USE_OMP
	omp_set_num_threads(1);
	double pi = omp_estimate_pi((INT32_MAX - 1) / 2, 10000);
	std::cerr << "omp pi: " << pi << std::endl;
	//assert(pi > 3.14 && pi < 3.15);
#endif
	return 0;
}
