#include "Squad.hpp"

Squad::Squad( void ): _nb_unit(0), _mlist(NULL) {}

Squad::Squad( Squad const & src )
{
	t_mlist	*tmp;
	t_mlist	*tmp2;

	tmp = this->_mlist;
	tmp2 = src._mlist;
	this->_mlist = NULL;
	while (tmp2)
	{
		if (this->_mlist == NULL)
		{
			this->_mlist = new(t_mlist);
			this->_mlist->instance = tmp2->instance;
			this->_mlist->next = NULL;
		}
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new(t_mlist);
			tmp->next->instance = tmp2->instance;
			tmp->next->next = NULL;
		}
		tmp2 = tmp2->next;
	}
	this->_nb_unit = src._nb_unit;
}

Squad::~Squad( void )
{
	t_mlist	*tmp;

	while (this->_mlist)
	{
		tmp = this->_mlist;
		delete this->_mlist->instance;
		this->_mlist = tmp->next;
		delete tmp;
	}
}

int		Squad::getCount( void ) const
{
	return this->_nb_unit;
}

int		Squad::push( ISpaceMarine* sm )
{
	t_mlist	*tmp;

	if (sm == NULL) // nothing, so no adding, just return current nb_unit
		return (this->_nb_unit);
	if (this->_mlist == NULL) // head
	{
		this->_mlist = new(t_mlist);
		this->_mlist->instance = sm;
		this->_mlist->next = NULL;
	}
	else
	{
		tmp = this->_mlist;
		while (tmp->next)
		{
			if (tmp->instance == sm)
				return (this->_nb_unit);
			tmp = tmp->next;
		}
		tmp->next = new(t_mlist);
		tmp->next->instance = sm;
		tmp->next->next = NULL;
	}
	this->_nb_unit++;
	return (this->_nb_unit);
}

ISpaceMarine*	Squad::getUnit( int index ) const
{
	t_mlist	*tmp;

	tmp = this->_mlist;
	while (index != 0 && tmp)
	{
		tmp = tmp->next;
		index--;
	}
	return (tmp->instance);
}

Squad&  Squad::operator=(Squad const & rhs)
{
    t_mlist  *tmp;

    tmp = this->_mlist;
    while (tmp)
		delete tmp->instance;
    if (this != &rhs)
		this->_nb_unit = rhs._nb_unit;

	t_mlist	*tmp2;

	tmp = this->_mlist;
	tmp2 = rhs._mlist;
	this->_mlist = NULL;
	while (tmp2)
	{
		if (this->_mlist == NULL) // head
		{
			this->_mlist = new(t_mlist);
			this->_mlist->instance = tmp2->instance;
			this->_mlist->next = NULL;
		}
		else
		{
			tmp = this->_mlist;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new(t_mlist);
			tmp->next->instance = tmp2->instance;
			tmp->next->next = NULL;
		}
		tmp2 = tmp2->next;
	}
    return *this;
}