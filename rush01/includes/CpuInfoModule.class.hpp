#ifndef CPUINFOMODULE_CLASS_HPP
# define CPUINFOMODULE_CLASS_HPP

# include "../includes/AModule.class.hpp"

class CpuInfoModule : public AModule
{
	public:
		CpuInfoModule(void);
		CpuInfoModule(CpuInfoModule const & src);
		~CpuInfoModule(void);

		CpuInfoModule const & operator=(CpuInfoModule const & rhs);

		void setCpuModel(void);
		void setCpuNumber(void);

		void display(void);
	
	private:

};

#endif