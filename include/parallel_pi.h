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

using std::int32_t;
using std::uint32_t;
using std::uint64_t;

uint64_t GetSquaredDistance(int32_t x, int32_t y);
bool IsInsideCircle(uint64_t squared_radius, int32_t x, int32_t y);
bool IsRandomInside(int32_t radius, uint64_t squared_radius);

#endif
