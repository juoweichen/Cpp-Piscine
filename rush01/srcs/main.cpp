#include <unistd.h>

#include "../includes/NcursesDisplay.class.hpp"
#include "../includes/IMonitorDisplay.class.hpp"
#include "../includes/IMonitorModule.class.hpp"
#include "../includes/NameModule.class.hpp"
#include "../includes/OSModule.class.hpp"
#include "../includes/TimeModule.class.hpp"
#include "../includes/CpuUsageModule.class.hpp"
#include "../includes/CpuInfoModule.class.hpp"
#include "../includes/RamModule.class.hpp"
#include "../includes/NetworkModule.class.hpp"

int main(void)
{
	NcursesDisplay ncursesDisplay;
	
	NameModule nameModule;
	OSModule osMoudule;
	TimeModule timeModule;

	CpuInfoModule cpuInfo;
	CpuUsageModule cpu0(0);
	CpuUsageModule cpu1(1);
	CpuUsageModule cpu2(2);
	CpuUsageModule cpu3(3);

	RamModule ram;

	NetworkModule net;

	int ch = 0;		/* for getch */

    do
    {
        ch = getch(); 	//catch keyboard input
        clear();
  
        switch(ch)		//set user input
		{
            case 27:		/* Esc key */
				ncursesDisplay.close();
				break ;
            default:
				break ;
    	}
		//update section
		timeModule.setTimeinfo();
		cpu0.setCpuUsage();
		cpu1.setCpuUsage();
		cpu2.setCpuUsage();
		cpu3.setCpuUsage();
		ram.setMemoryCount();
		net.setPacketIO();

		//display section
		ncursesDisplay.title("Name");
		nameModule.display();
		osMoudule.display();
		timeModule.display();

		ncursesDisplay.title("CPU");
		cpuInfo.display();
		cpu0.display();
		cpu1.display();
		cpu2.display();
		cpu3.display();
		printw("\n");

		ncursesDisplay.title("RAM");
		ram.display();
	
		ncursesDisplay.title("Network");
		net.display();
		
		sleep(1);

	} while (1);

	ncursesDisplay.close();
	return (0);
}