/*
 * RandomUtils.h
 *
 *  Created on: 30-05-2014
 *      Author: tomek
 */

#ifndef RANDOMUTILS_H_
#define RANDOMUTILS_H_

class RandomUtils {
public:
	static int randomInt(int min, int max) {
		return min + (rand() % (int)(max - min + 1));
	}
};

#endif /* RANDOMUTILS_H_ */
