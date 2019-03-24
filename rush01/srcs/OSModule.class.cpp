#include "../includes/OSModule.class.hpp"

OSModule::OSModule(void)
{
	this->setOSinfo();
}

OSModule::OSModule(OSModule const & src)
{
	*this = src;
}

OSModule::~OSModule(void)
{

}

OSModule const & OSModule::operator=(OSModule const & rhs)
{
	(void)rhs;
	return *this;
}

void OSModule::setOSinfo(void)
{
    char buffer[100] = {0};
    size_t bufLen = 100;
	std::string result;

    sysctlbyname("kern.ostype", &buffer, &bufLen, NULL, 0);
	result = buffer;
	memset(buffer, 0, bufLen);
	sysctlbyname("kern.osrelease", &buffer, &bufLen, NULL, 0);
	result.append(" ");
	result.append(buffer);
	
	this->_moduleMap["OS info"] = result;
}

