#ifndef WIDERPADDLEBONUS_H_
#define WIDERPADDLEBONUS_H_

#include "Bonus.h"
#include "Paddle.h"

/**
 * A bonus that makes paddle wider.
 */
class WiderPaddleBonus: public Bonus {

	const int PADDLE_WIDTH_SUBTRACTION;
	Paddle* paddle;

public:
	WiderPaddleBonus(Paddle* paddle) :
			Bonus(),
					PADDLE_WIDTH_SUBTRACTION(50) {

		this->paddle = paddle;
	}

	void activate() {
		paddle->makeWider(PADDLE_WIDTH_SUBTRACTION);
	}
};

#endif /* WIDERPADDLEBONUS_H_ */
