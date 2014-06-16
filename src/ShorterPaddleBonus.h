#ifndef SHORTERPADDLEBONUS_H_
#define SHORTERPADDLEBONUS_H_
#include "TemporaryBonus.h"
#include "Paddle.h"

/**
 * A bonus that makes paddle shorter.
 */
class ShorterPaddleBonus: public TemporaryBonus {

	const int PADDLE_WIDTH_SUBTRACTION;
	Paddle* paddle;

public:
	ShorterPaddleBonus(Paddle* paddle) :
			TemporaryBonus(),
					PADDLE_WIDTH_SUBTRACTION(50) {

		this->paddle = paddle;
	}

	void activate() {
		paddle->makeShorter(PADDLE_WIDTH_SUBTRACTION);
	}

	void deactivate() {
		paddle->makeWider(PADDLE_WIDTH_SUBTRACTION);
	}
};

#endif /* SHORTERPADDLEBONUS_H_ */
