/**
 * @file pi_calc.c
 * @brief 
 * @author Travis Lane
 * @version 
 * @date 2014-11-11
 */

#include <pi_calc.h>
#include <assert.h>
#include <stdlib.h>

#define RADIUS (RAND_MAX - 1) / 2

const uint64_t squared_radius = (uint64_t) RADIUS * (uint64_t) RADIUS;
const int32_t center_x = RADIUS;
const int32_t center_y = RADIUS;

/**
 * @brief Estimates pi.
 *
 * @param pc The pc to estimate.
 *
 * @return The estimate.
 */
long double 
pi_calc_estimate(struct pi_calc_t *pc)
{
	return ((long double) pc->pc_total_inside / (long double) pc->pc_total) * 4.0;
}

/**
 * @brief Runs the iterations, in parallel if necessary.
 *
 * @param pc The pi calc to run.
 */
void 
pi_calc_run(struct pi_calc_t *pc)
{	
	uint64_t total_inside = 0;
	uint64_t thread_total = pc->pc_total / pc->pc_num_threads;

	//#pragma omp parallel for reduction(+:total_inside) num_threads(pc->pc_num_threads)
	#pragma cilk grainsize = (4 / pc->pc_num_threads)
	cilk_for(uint16_t i = 0; i < pc->pc_num_threads; i++) {
		total_inside += pi_calc_thread_run(pc->pc_seeds[i], thread_total);
	}
	
	pc->pc_total_inside = total_inside;
}

/**
 * @brief Runs an individual thread.
 *
 * @param seed The initial seed.
 * @param total The total iterations the thread should run.
 *
 * @return The number of hits inside.
 */
uint64_t 
pi_calc_thread_run(unsigned int seed, uint64_t total)
{
	uint64_t inside = 0;
	for(uint32_t i = 0; i < total; i++) {
		int32_t x, y;
		uint64_t squared_dist;
		// reduce the total size to 0 - RAND_MAX - 1
		x = rand_r(&(seed)) % RAND_MAX;
		y = rand_r(&(seed)) % RAND_MAX;
		squared_dist = calculate_squared_distance(center_x, center_y, x, y);
		if(squared_dist < squared_radius) {
			inside++;
		}
	}
	return inside;
}

/**
 * @brief Calculates a squared distance.
 * Squared so we can avoid sqrt()
 *
 * @param x1
 * @param y1
 * @param x2
 * @param y2
 *
 * @return The squared distance.
 */
uint64_t
calculate_squared_distance(int32_t x1, int32_t y1, int32_t x2, int32_t y2)
{
	uint64_t dx, dy;
	dx = llabs(x2 - x1);
	dy = llabs(y2 - y1);
	return (dx * dx) + (dy * dy);
}
