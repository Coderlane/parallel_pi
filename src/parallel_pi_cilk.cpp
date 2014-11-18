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
#include <cilk/cilk_api.h>
#include <cilk/reducer_opadd.h>
#include <ctime>

	double
cilk_estimate_pi(int32_t radius, uint64_t total_iterations)
{
	const uint64_t squared_radius = (uint64_t) radius * (uint64_t) radius;
	cilk::reducer_opadd<uint64_t> total_inside(0);

	cilk_for(uint64_t i = 0; i < total_iterations; i++) {
		int32_t x, y;
		std::mt19937 gen(__cilkrts_get_pedigree());
		std::uniform_int_distribution<int32_t> dist(-radius, radius);
		x = dist(gen);
		y = dist(gen);
		if(IsInsideCircle(squared_radius, x, y))
			total_inside++;
	}
	// Figure out what our estimate was.
	return ((double) total_inside.get_value() / (double) total_iterations) * 4.0;
}

#endif
