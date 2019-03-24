#include "../includes/IMonitorModule.class.hpp"

IMonitorModule::IMonitorModule(void)
{

}

IMonitorModule::IMonitorModule(IMonitorModule const & src)
{
	*this = src;
}

IMonitorModule::~IMonitorModule(void)
{

}

IMonitorModule const & IMonitorModule::operator=(IMonitorModule const & rhs)
{
	(void)rhs;
	return *this;
}
