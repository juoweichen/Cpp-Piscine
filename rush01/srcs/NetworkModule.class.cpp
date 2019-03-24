# include "../includes/NetworkModule.class.hpp"

NetworkModule::NetworkModule(void)
{
	this->setPacketIO();
}

NetworkModule::NetworkModule(NetworkModule const & src)
{
	*this = src;
}

NetworkModule::~NetworkModule(void)
{

}

NetworkModule const & NetworkModule::operator=(NetworkModule const & rhs)
{
	(void)rhs;
	return *this;
}

void NetworkModule::setPacketIO(void)
{
	int		mib[] = { CTL_NET, PF_ROUTE, 0, 0, NET_RT_IFLIST, 0 };
    char	*buf;
    size_t	len = 1024;

	sysctl(mib, 6, NULL, &len, NULL, 0);
    buf = new char[len];
    sysctl(mib, 6, buf, &len, NULL, 0);

	char *lim = buf + len;
    char *next = NULL;

    u_int64_t totalIPacket = 0;
    u_int64_t totalOPacket = 0;
	for (next = buf; next < lim; )
    {
        struct if_msghdr *ifm = reinterpret_cast<struct if_msghdr*>(next);
        next += ifm->ifm_msglen;

        if (ifm->ifm_type == RTM_IFINFO)
        {
            totalIPacket += ifm->ifm_data.ifi_ipackets;
            totalOPacket += ifm->ifm_data.ifi_opackets;
        }
    }
	this->_moduleMap["Packet in"] = std::to_string((totalIPacket));
	this->_moduleMap["Packet out"] = std::to_string((totalOPacket));
	this->_moduleMap["Packet in/sec"] = std::to_string((totalIPacket - _prevIPacket));
	this->_moduleMap["Packet out/sec"] = std::to_string((totalOPacket - _prevOPacket));
	_prevIPacket = totalIPacket;
    _prevOPacket = totalOPacket;
}

void NetworkModule::display(void)
{
	printw("%s: %s\n", "Packet in", this->_moduleMap["Packet in"].c_str());
	printw("%s: %s\n\n", "Packet out", this->_moduleMap["Packet out"].c_str());
	printw("%s: %s\n", "Packet in/sec", this->_moduleMap["Packet in/sec"].c_str());
	printw("%s: %s\n", "Packet out/sec", this->_moduleMap["Packet out/sec"].c_str());
}