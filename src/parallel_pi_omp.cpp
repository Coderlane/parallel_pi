/**
 * @file parallel_pi_omp.cpp
 * @brief 
 * @author Travis Lane
 * @version 
 * @date 2014-11-17
 */

#include <parallel_pi_omp.h>
#include <iostream>

#ifdef PARALLEL_PI_USE_OMP

double
omp_estimate_pi(int32_t radius, uint64_t total_iterations)
{
	uint64_t total_inside = 0;
	const uint64_t squared_radius = (uint64_t) radius * (uint64_t) radius;

	#pragma omp parallel for reduction(+:total_inside)
	for(uint64_t i = 0; i < total_iterations; i++) {
		if(IsRandomInside(radius, squared_radius))
			total_inside++;
	}

	// Figure out what our estimate was.
	return ((double) total_inside / (double) total_iterations) * 4.0;
}

#endif
