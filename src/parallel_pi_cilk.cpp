/**
 * @file pi_calc.c
 * @brief 
 * @author Travis Lane
 * @version 
 * @date 2014-11-11
 */

#include <parallel_pi_cilk.h>

#ifdef PARALLEL_PI_USE_CILK

double
cilk_estimate_pi(CircleSquare cs, uint64_t total_iterations)
{
	uint64_t total_inside = 0;

	cilk_for(uint64_t i; i < total_iterations; i++) {
		uint32_t x, y;
		x = 0;
		y = 0;
		if(cs.IsInsideCircle(x, y))
			total_inside++;
	}
}

#endif
