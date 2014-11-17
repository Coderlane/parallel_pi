/**
 * @file parallel_pi.cpp
 * @brief :
 * @author Travis Lane
 * @version 
 * @date 2014-11-16
 */


#include <parallel_pi.h>

/**
 * @brief 
 *
 * @param new_radius
 */
PICalc::PICalc(int32_t new_radius)
{
	radius = new_radius;
	squared_radius = (uint64_t) radius * (uint64_t) radius;
}

/**
 * @brief 
 *
 * @param x
 * @param y
 *
 * @return 
 */
uint64_t 
PICalc::GetSquaredDistance(int32_t x, int32_t y)
{
	uint64_t dx, dy;
	dx = llabs(radius - x1);
	dy = llabs(radius - y1);
	return (dx * dx) + (dy * dy);

}

