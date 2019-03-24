#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		this->_mat[i] = NULL;
	}
}
MateriaSource::MateriaSource(MateriaSource const & cpy)
{
	*this = cpy;
}

MateriaSource::~MateriaSource(void)
{
	// delete [] this->_mat;
}

MateriaSource &	MateriaSource::operator=(MateriaSource const & rhs)
{
	this->_mat[0] = rhs._mat[0];
	this->_mat[1] = rhs._mat[1];
	this->_mat[2] = rhs._mat[2];
	this->_mat[3] = rhs._mat[3];
	return *this;
}

void			MateriaSource::learnMateria(AMateria* m)
{
	int	learn;

	learn = 0;
	for (int i = 0; i < 4; i++)
	{
		if (learn == 0 && this->_mat[i] == NULL)
		{
			this->_mat[i] = m;
			learn++;
		}
	}
	if (learn == 0)
		std::cout << "MateriaSource memory full" << std::endl;
}

AMateria*		MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_mat[i] != NULL && this->_mat[i]->getType() == type)
		{
			AMateria *cpy;

			cpy = this->_mat[i]->clone();
			return (cpy);
		}
	}
	std::cout << "MateriaSource not found." << std::endl;
	return NULL;
}