

#ifndef PARALLEL_PI_CILK_H
#define PARALLEL_PI_CILK_H

#ifdef PARALLEL_PI_USE_CILK

#include <parallel_pi.h>
#include <cilk/cilk.h>
#include <cilk/reducer_opadd.h>

double cilk_estimate_pi(CircleSquare cs, uint64_t total_iterations);

#endif /* PARALLEL_PI_USE_CILK */

#endif /* PARALLEL_PI_CILK_H */
