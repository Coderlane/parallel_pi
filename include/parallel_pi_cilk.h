

#ifndef PARALLEL_PI_CILK_H
#define PARALLEL_PI_CILK_H

#include <parallel_pi.h>

double cilk_estimate_pi(int32_t radius, uint64_t total_iterations);

#endif /* PARALLEL_PI_CILK_H */
