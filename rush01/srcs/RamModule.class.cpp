#include "../includes/RamModule.class.hpp"

RamModule::RamModule(void)
{
	this->setMemoryCount();
}

RamModule::RamModule(RamModule const & src)
{
	*this = src;
}

RamModule::~RamModule(void)
{

}

RamModule const & RamModule::operator=(RamModule const & rhs)
{
	(void)rhs;
	return *this;
}

void RamModule::setMemoryCount(void)
{
	vm_size_t page_size;
    mach_port_t mach_port;
    mach_msg_type_number_t count;
    vm_statistics64_data_t vm_stats;

	std::string longLongStr;
	std::ostringstream streamObj;

	mach_port = mach_host_self();
    count = sizeof(vm_stats) / sizeof(natural_t);
    if (KERN_SUCCESS == host_page_size(mach_port, &page_size) &&
		KERN_SUCCESS == host_statistics64(	mach_port, 
											HOST_VM_INFO,
											(host_info64_t)&vm_stats,
											&count))
	{
		//Free memory
		streamObj.str("");
		streamObj.clear();
		streamObj << std::fixed;
		streamObj << std::setprecision(2);
		streamObj << (static_cast<float>(vm_stats.free_count) * static_cast<float>(page_size)) / 1000000000;
		longLongStr = streamObj.str();
		this->_moduleMap["Free Memory"] = longLongStr;
		//Active memory
		streamObj.str("");
		streamObj.clear();
		streamObj << std::fixed;
		streamObj << std::setprecision(2);
		streamObj << (static_cast<float>(vm_stats.active_count) * static_cast<float>(page_size)) / 1000000000;
		longLongStr = streamObj.str();
		this->_moduleMap["Active Memory"] = longLongStr;
		//Inactive memory
		streamObj.str("");
		streamObj.clear();
		streamObj << std::fixed;
		streamObj << std::setprecision(2);
		streamObj << (static_cast<float>(vm_stats.inactive_count) * static_cast<float>(page_size)) / 1000000000;
		longLongStr = streamObj.str();
		this->_moduleMap["Inactive Memory"] = longLongStr;
		//Wired memory
		streamObj.str("");
		streamObj.clear();
		streamObj << std::fixed;
		streamObj << std::setprecision(2);
		streamObj << (static_cast<float>(vm_stats.wire_count) * static_cast<float>(page_size)) / 1000000000;
		longLongStr = streamObj.str();
		this->_moduleMap["Wired Memory"] = longLongStr;
		//Total Used = active + inactive + wired
		streamObj.str("");
		streamObj.clear();
		streamObj << std::fixed;
		streamObj << std::setprecision(2);
		streamObj << ((static_cast<float>(vm_stats.active_count) +
                    	static_cast<float>(vm_stats.inactive_count) +
                        static_cast<float>(vm_stats.wire_count)) *  (int64_t)page_size) / 1000000000;
		longLongStr = streamObj.str();
		this->_moduleMap["Total Used Memory"] = longLongStr;
		
	}
}

void RamModule::display(void)
{
	char memtype[3] = "GB";
	printw("%s: %s %s\n", "Free Memory", this->_moduleMap["Free Memory"].c_str(), memtype);
	printw("%s: %s %s\n", "Active Memory", this->_moduleMap["Active Memory"].c_str(), memtype);
	printw("%s: %s %s\n", "Inactive Memory", this->_moduleMap["Inactive Memory"].c_str(), memtype);
	printw("%s: %s %s\n", "Wired Memory", this->_moduleMap["Wired Memory"].c_str(), memtype);
	printw("\n%s: %s %s\n\n", "Total Used Memory", this->_moduleMap["Total Used Memory"].c_str(), memtype);
}