#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource: public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const & cpy);
		virtual ~MateriaSource(void);
		MateriaSource &	operator=(MateriaSource const & rhs);

		virtual void		learnMateria(AMateria* m);
		virtual AMateria*	createMateria(std::string const & type);

	private:

		AMateria*		_mat[4];
};

#endif