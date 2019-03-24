#ifndef AMODULE_CLASS_HPP
# define AMODULE_CLASS_HPP

# include <sys/sysctl.h>

# include "../includes/IMonitorModule.class.hpp"
# include "../includes/IMonitorDisplay.class.hpp"

class AModule : public IMonitorDisplay, public IMonitorModule
{
	public:
		AModule(void);
		AModule(AModule const & src);
		virtual ~AModule(void);

		AModule const & operator=(AModule const & rhs);

		void display(void);

		std::string getFromMap(std::string label);
		void updateMap(std::string label, std::string output);
		
};

#endif