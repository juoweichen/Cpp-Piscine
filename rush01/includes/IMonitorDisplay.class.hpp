#ifndef IMONITORDISPLAY_CLASS_HPP
# define IMONITORDISPLAY_CLASS_HPP

# include <ncurses.h>
# include <iostream>

class IMonitorDisplay
{
	public:
		IMonitorDisplay(void);
		IMonitorDisplay(IMonitorDisplay const & src);
		virtual ~IMonitorDisplay(void);
		IMonitorDisplay const & operator=(IMonitorDisplay const & rhs);

		virtual void display(void) = 0;
};

#endif