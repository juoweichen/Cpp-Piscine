#ifndef CPUUSAGEMODULE_CLASS_HPP
# define CPUUSAGEMODULE_CLASS_HPP

# include <mach/mach_host.h>
# include <mach/processor_info.h>
# include <sstream>
# include <iomanip>
# include "../includes/AModule.class.hpp"

class CpuUsageModule : public AModule
{
	public:
		CpuUsageModule(void);
		CpuUsageModule(CpuUsageModule const & src);
		CpuUsageModule(unsigned int core);
		~CpuUsageModule(void);

		CpuUsageModule const & operator=(CpuUsageModule const & rhs);

		void setCpuUsage(void);
		void display(void);

	private:
		struct Ticks {
			unsigned long long int usertime;
			unsigned long long int nicetime;
			unsigned long long int systemtime;
			unsigned long long int idletime;

			unsigned long long int used() { return usertime + nicetime + systemtime; }
			unsigned long long int total() { return usertime + nicetime + systemtime + idletime; }
		} prev;
		float getUsage();
		Ticks updatedTicks(unsigned int core);

		unsigned int _core;
		float _usage;
};

#endif