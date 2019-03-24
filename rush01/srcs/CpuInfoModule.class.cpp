#include "../includes/CpuInfoModule.class.hpp"

CpuInfoModule::CpuInfoModule(void)
{
	this->setCpuModel();
	this->setCpuNumber();
}

CpuInfoModule::CpuInfoModule(CpuInfoModule const & src)
{
	*this = src;
}

CpuInfoModule::~CpuInfoModule(void)
{

}

CpuInfoModule const & CpuInfoModule::operator=(CpuInfoModule const & rhs)
{
	(void)rhs;
	return *this;
}

void CpuInfoModule::setCpuModel(void)
{
	char buffer[100] = {0};
    size_t bufLen = 100;

	sysctlbyname("machdep.cpu.brand_string", &buffer, &bufLen, NULL, 0);
	this->_moduleMap["Cpu Model"] = buffer;
}

void CpuInfoModule::setCpuNumber(void)
{
	this->_moduleMap["CPU Core Number"] = "4";
}

void CpuInfoModule::display(void)
{
	printw("CPU Model: %s\n", this->_moduleMap["Cpu Model"].c_str());
	printw("CPU Core Number: %s\n\n", this->_moduleMap["CPU Core Number"].c_str());	
}