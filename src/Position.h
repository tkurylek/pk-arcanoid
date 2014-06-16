#ifndef POSITION_H_
#define POSITION_H_

class Position {
public:
	double x;
	double y;
	Position(int x, int y) {
		this->x = x;
		this->y = y;
	}
	Position(double x, double y) {
		this->x = x;
		this->y = y;
	}
};

#endif /* POSITION_H_ */
