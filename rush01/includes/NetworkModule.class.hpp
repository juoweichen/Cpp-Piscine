#ifndef NETWORKMODULE_CLASS_HPP
# define NETWORKMODULE_CLASS_HPP

#include <sys/sysctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <net/route.h>

# include "../includes/AModule.class.hpp"

class NetworkModule : public AModule
{
	public:
		NetworkModule(void);
		NetworkModule(NetworkModule const & src);
		~NetworkModule(void);
		NetworkModule const & operator=(NetworkModule const & rhs);

		void setPacketIO(void);
		void display(void);

	private:
		u_int64_t _prevIPacket;
		u_int64_t _prevOPacket;
};

#endif