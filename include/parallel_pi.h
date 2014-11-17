/**
 * @file parallel_pi.h
 * @brief 
 * @author Travis Lane
 * @version 
 * @date 2014-11-16
 */


#ifndef PARALLEL_PI_H
#define PARALLEL_PI_H

/**
 * @brief 
 */
class PICalc {

	public:
		PICalc(uint32_t radius);

		uint64_t GetSquaredDistance(uint32_t x, uint32_t y);

	private:

		/**
		 * @brief 
		 */
		uint64_t squared_radius;

		/**
		 * @brief 
		 */
		uint32_t radius
};

#endif
