/**
 * @file pi_calc.c
 * @brief 
 * @author Travis Lane
 * @version 
 * @date 2014-11-11
 */

#ifdef PARALLEL_PI_USE_CILK

#include <parallel_pi_cilk.h>
#include <cilk/cilk.h>
#include <cilk/reducer_opadd.h>

double
cilk_estimate_pi(int32_t radius, uint64_t total_iterations)
{
	const uint64_t squared_radius = (uint64_t) radius * (uint64_t) radius;
	cilk::reducer_opadd<uint64_t> total_inside(0);

	cilk_for(uint64_t i = 0; i < total_iterations; i++) {
		if(IsRandomInside(radius, squared_radius))
			total_inside++;
	}
	// Figure out what our estimate was.
	return ((double) total_inside.get_value() / (double) total_iterations) * 4.0;
}

#endif
