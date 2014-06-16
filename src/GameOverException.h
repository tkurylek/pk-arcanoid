#ifndef GAMEOVEREXCEPTION_H_
#define GAMEOVEREXCEPTION_H_
#include <exception>
#include <string>

using namespace std;

class GameOverException: public exception {
	string message;

public:

	GameOverException(string message) :
			exception() {
		this->message = message;
	}

	virtual ~GameOverException() throw () {
		message = "";
	}

	virtual const char* what() const throw () {
		return message.c_str();
	}
};
#endif /* GAMEOVEREXCEPTION_H_ */
