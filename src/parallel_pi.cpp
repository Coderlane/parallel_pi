/**
 * @file parallel_pi.cpp
 * @brief
 * @author Travis Lane
 * @version 
 * @date 2014-11-16
 */

#include <parallel_pi.h>

#include <cassert>
#include <cstdlib>

#include <iostream>
#include <random>

/**
 * @brief 
 *
 * @param x
 * @param y
 *
 * @return 
 */
uint64_t 
GetSquaredDistance(int32_t x, int32_t y)
{
	uint64_t dx, dy;
	dx = llabs(x);
	dy = llabs(y);
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
IsInsideCircle(uint64_t squared_radius, int32_t x, int32_t y)
{
	return (GetSquaredDistance(x, y) < squared_radius);
}

/**
 * @brief 
 *
 * @param radius
 * @param squared_radius
 *
 * @return 
 */
bool 
IsRandomInside(int32_t radius, uint64_t squared_radius)
{
	int32_t x, y;
	//std::random_device rd;
  std::mt19937 gen;//(rd());
	std::uniform_int_distribution<int32_t> dist(-radius, radius);
	x = dist(gen);
	y = dist(gen);
	//std::cerr << x << "," << y << std::endl;
	return IsInsideCircle(squared_radius, x, y);
}

