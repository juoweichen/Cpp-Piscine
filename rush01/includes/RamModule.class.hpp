#ifndef RAMMODULE_CLASS_HPP
# define RAMMODULE_CLASS_HPP

# include <mach/vm_statistics.h>
# include <mach/mach_types.h>
# include <mach/mach_init.h>
# include <mach/mach_host.h>
# include <sstream>
# include <iomanip>

# include "../includes/AModule.class.hpp"

class RamModule : public AModule
{
	public:
		RamModule(void);
		RamModule(RamModule const & src);
		~RamModule(void);

		RamModule const & operator=(RamModule const & rhs);

		void setMemoryCount(void);
		void display(void);
	private:
};

#endif