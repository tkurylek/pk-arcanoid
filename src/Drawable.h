#ifndef DRAWABLE_H_
#define DRAWABLE_H_

class Drawable {
public:
	virtual void draw(BITMAP *buffer) = 0;

	virtual ~Drawable() {
	}
};

#endif /* DRAWABLE_H_ */
