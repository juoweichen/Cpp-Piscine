#include "../includes/NameModule.class.hpp"

NameModule::NameModule(void)
{
	this->setHostName();
	this->setUserName();
}

NameModule::NameModule(NameModule const & src)
{
	*this = src;
}

NameModule::~NameModule(void)
{

}

NameModule const & NameModule::operator=(NameModule const & rhs)
{
	(void)rhs;
	return *this;
}

void NameModule::setHostName(void)
{
	char buffer[100] = {0};
    size_t bufLen = 100;

	sysctlbyname("kern.hostname", &buffer, &bufLen, NULL, 0);
	this->_moduleMap["Host Name"] = buffer;
}

void NameModule::setUserName(void)
{
	this->_moduleMap["User Name"] = std::getenv("USER");
}
