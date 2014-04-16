#ifndef ALLEGRO_INITLALIZATION_EXCEPTION_H
#define ALLEGRO_INITLALIZATION_EXCEPTION_H

#include <exception>
#include <string>

using namespace std;

class AllegroInitalizationException: public exception {
	string message;

public:

	AllegroInitalizationException(string message) :
			exception() {
		this->message = message;
	}

	virtual ~AllegroInitalizationException() throw () {
		message = "";
	}

	virtual const char* what() const throw () {
		return message.c_str();
	}
};
#endif
