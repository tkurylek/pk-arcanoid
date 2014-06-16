#ifndef TEMPORARYBONUS_H_
#define TEMPORARYBONUS_H_

#include "Bonus.h"
#include <time.h>

class TemporaryBonus: public Bonus {

	const int DEACTIVATION_TIME;
	double startTime;

public:

	TemporaryBonus() :
			DEACTIVATION_TIME(5), startTime((unsigned int) -1) {
	}

	/**
	 * Dezaktywuje bonus. Metoda wywołana po przekroczeniu
	 * czasu dezaktywacji.
	 */
	virtual void deactivate() = 0;

	virtual void draw(BITMAP *buffer) {
		Bonus::draw(buffer);
		deactivateAfterDeactivationTime();
	}

	virtual void collision() {
		if (getVisible()) {
			// zarejestruj czas, w którym bonus został aktywowany
			startTime = clock();
		}
		Bonus::collision();
	}

private:
	void deactivateAfterDeactivationTime() {
		if (getActiveTime() > DEACTIVATION_TIME) {
			deactivate();
			startTime = (unsigned int) -1;
		}
	}

	double inline getActiveTime() {
		return (clock() - startTime) / CLOCKS_PER_SEC;
	}
};

#endif /* TEMPORARYBONUS_H_ */
