#include "../includes/AModule.class.hpp"

AModule::AModule(void)
{

}

AModule::AModule(AModule const & src)
{
	*this = src;
}

AModule::~AModule(void)
{

}

AModule const & AModule::operator=(AModule const & rhs)
{
	(void)rhs;
	return *this;
}

void AModule::display(void)
{
	std::map<std::string, std::string>::iterator it;

	for (it = this->_moduleMap.begin(); it != this->_moduleMap.end(); it++)
		printw("%s: %s\n", it->first.c_str(), it->second.c_str());
}

std::string AModule::getFromMap(std::string label)
{
	return this->_moduleMap[label];
}

void AModule::updateMap(std::string label, std::string output)
{
	this->_moduleMap[label] = output;
}
