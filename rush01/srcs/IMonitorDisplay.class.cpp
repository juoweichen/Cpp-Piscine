#include "../includes/IMonitorDisplay.class.hpp"

IMonitorDisplay::IMonitorDisplay(void)
{

}

IMonitorDisplay::IMonitorDisplay(IMonitorDisplay const & src)
{
	*this = src;
}

IMonitorDisplay::~IMonitorDisplay(void)
{

}

IMonitorDisplay const & IMonitorDisplay::operator=(IMonitorDisplay const & rhs)
{
	(void)rhs;
	return *this;
}