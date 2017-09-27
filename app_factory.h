#ifndef APP_FACTORY_H
#define APP_FACTORY_H


#include "Appointment.h"

class AppFactory {
public:
	Appointment load(const char* temp);
};

#endif
