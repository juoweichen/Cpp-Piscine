#include "../includes/TimeModule.class.hpp"

TimeModule::TimeModule(void)
{
	this->setTimeinfo();
}

TimeModule::TimeModule(TimeModule const & src)
{
	*this = src;
}

TimeModule::~TimeModule(void)
{

}

TimeModule const & TimeModule::operator=(TimeModule const & rhs)
{
	(void)rhs;
	return *this;
}

void TimeModule::setTimeinfo(void)
{
	const time_t now = time(0);
	char* dt = ctime(&now);
	
	this->_moduleMap["Date Time"] = dt;
}