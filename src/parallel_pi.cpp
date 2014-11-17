/**
 * @file parallel_pi.cpp
 * @brief
 * @author Travis Lane
 * @version 
 * @date 2014-11-16
 */


#include <parallel_pi.h>
#include <cassert>

/**
 * @brief 
 *
 * @param new_radius
 */
CircleSquare::CircleSquare(uint32_t new_radius) : 
	radius(new_radius), diameter(new_radius * 2),
	squared_radius(new_radius * new_radius) 
{
	assert(new_radius < INT32_MAX);
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
CircleSquare::GetSquaredDistance(uint32_t x, uint32_t y)
{
	uint64_t dx, dy;
	dx = llabs(radius - x);
	dy = llabs(radius - y);
	return (dx * dx) + (dy * dy);
}

/**
 * @brief 
 *
 * @param x
 * @param y
 *
 * @return 
 */
bool 
CircleSquare::IsInsideCircle(uint32_t x, uint32_t y)
{
	return (GetSquaredDistance(x, y) < squared_radius);
}

/**
 * @brief 
 *
 * @param x
 * @param y
 *
 * @return 
 */
bool
CircleSquare::IsInsideSquare(uint32_t x, uint32_t y)
{
	return (x < diameter && y < diameter);
}
