/**
 * @file parallel_pi.h
 * @brief 
 * @author Travis Lane
 * @version 
 * @date 2014-11-16
 */


#ifndef PARALLEL_PI_H
#define PARALLEL_PI_H

#include <cstdint>
#include <cstdlib>

using std::int32_t;
using std::uint32_t;
using std::uint64_t;

/**
 * @brief 
 */
class CircleSquare {

	public:
		/**
		 * @brief The input radius. 
		 */
		const uint32_t radius;

		/**
		 * @brief Double the input radius. 
		 * Used for IsInsideSquare.
		 */
		const uint32_t diameter;

		/**
		 * @brief The input radius squared.
		 * Used for IsInsideCircle.
		 */
		const uint64_t squared_radius;

		CircleSquare(uint32_t radius);

		bool IsInsideCircle(uint32_t x, uint32_t y);
		bool IsInsideSquare(uint32_t x, uint32_t y);

	private:
		uint64_t GetSquaredDistance(uint32_t x, uint32_t y);
};
#endif
