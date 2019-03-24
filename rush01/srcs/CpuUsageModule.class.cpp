#include "../includes/CpuUsageModule.class.hpp"

CpuUsageModule::CpuUsageModule(void) : _core(0)
{
	
}

CpuUsageModule::CpuUsageModule(CpuUsageModule const & src)
{
	*this = src;
}

CpuUsageModule::CpuUsageModule(unsigned int core) : _core(core)
{
	this->setCpuUsage();
}

CpuUsageModule::~CpuUsageModule(void)
{

}

CpuUsageModule const & CpuUsageModule::operator=(CpuUsageModule const & rhs)
{
	(void)rhs;
	return *this;
}

void CpuUsageModule::setCpuUsage(void)
{
	std::string cpuLabel = "CPU ";
	char cpuNum;
	std::string floatStr;
	std::ostringstream streamObj;
	
	this->_usage = this->getUsage();
	streamObj << std::fixed;
	streamObj << std::setprecision(2);
	streamObj << this->_usage;
	floatStr = streamObj.str();
	cpuNum = this->_core + '0';
	cpuLabel.append(1, cpuNum);

	this->_moduleMap[cpuLabel] = floatStr;
}

float CpuUsageModule::getUsage()
{
	Ticks t = updatedTicks(this->_core);
	unsigned long long int used = t.used() - prev.used();
	unsigned long long int total = t.total() - prev.total();
	
	prev = t;
	return (float)used / (float)total * 100.0f;
}

CpuUsageModule::Ticks CpuUsageModule::updatedTicks(unsigned int core) 
{
	unsigned int cpu_count;
	processor_cpu_load_info_t cpu_load;
	mach_msg_type_number_t cpu_msg_count;

	int rc =  host_processor_info(
			mach_host_self( ),
			PROCESSOR_CPU_LOAD_INFO,
			&cpu_count,
			(processor_info_array_t *) &cpu_load,
			&cpu_msg_count);

	if (rc != 0) {
		printf("Error: failed to scan processor info (rc=%d)\n", rc);
		exit(1);
	}

	if (cpu_count <= core) {
		printf("Error: invalid core number: %d\n", core);
		exit(1);
	}
	unsigned long long int usertime = cpu_load[core].cpu_ticks[CPU_STATE_USER];
	unsigned long long int nicetime = cpu_load[core].cpu_ticks[CPU_STATE_NICE];
	unsigned long long int systemtime = cpu_load[core].cpu_ticks[CPU_STATE_SYSTEM];
	unsigned long long int idletime = cpu_load[core].cpu_ticks[CPU_STATE_IDLE];

	Ticks t = {usertime, nicetime, systemtime, idletime};
	return t;
}

void CpuUsageModule::display(void)
{
	std::map<std::string, std::string>::iterator it;

	for (it = this->_moduleMap.begin(); it != this->_moduleMap.end(); it++)
		printw("%s: %s%%\t", it->first.c_str(), it->second.c_str());
	
	float usageBar = this->_usage * 0.4;

	init_pair(1, COLOR_GREEN, COLOR_GREEN);
	init_pair(2, COLOR_RED, COLOR_RED);
	if (this->_usage > 75.0f)
		attron(COLOR_PAIR(2));
	else
		attron(COLOR_PAIR(1));
	for (int i = 0; i < static_cast<int>(usageBar); i++)
		printw("|");
	printw("\n\n");
	attroff(COLOR_PAIR(1));
	attroff(COLOR_PAIR(2));
}