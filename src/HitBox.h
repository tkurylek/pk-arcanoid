#ifndef HITAREA_H_
#define HITAREA_H_

class HitPoints {
	int left;
	int right;
	int bottom;
	int top;

public:
	HitPoints() {
		this->left = 0;
		this->right = 0;
		this->top = 0;
		this->bottom = 0;
	}
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
