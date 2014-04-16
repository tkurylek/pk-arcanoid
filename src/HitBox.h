/*
 * HitArea.h
 *
 *  Created on: 06-04-2014
 *      Author: tomek
 */

#ifndef HITAREA_H_
#define HITAREA_H_

class HitPoints {
	int left;
	int right;
	int bottom;
	int top;
public:
	HitPoints(int left, int right, int top, int bottom) {
		this->left = left;
		this->right = right;
		this->top = top;
		this->bottom = bottom;
	}
	int getLeft() {
		return left;
	}
	int getRight() {
		return right;
	}
	int getTop() {
		return top;
	}
	int getBottom() {
		return bottom;
	}
};

#endif /* HITAREA_H_ */