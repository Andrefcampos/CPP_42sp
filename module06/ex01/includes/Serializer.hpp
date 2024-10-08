
#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include "Data.hpp"

# define BLUE_GREEN	"\033[32;44m"
# define MAG_YE		"\033[33;45m"
# define RED     	"\033[1;31m"
# define GREEN   	"\033[1;32m"
# define YELLOW 	"\033[1;33m"
# define BLUE    	"\033[1;34m"
# define MAGENTA    "\033[1;35m"
# define CYAN    	"\033[1;36m"
# define WHITE    	"\033[1;37m"
# define ORANGE		"\033[0;38;5;166m"
# define GRAY		"\033[38;5;244m"
# define DFT   		"\033[0m"

class	Serializer {

private:
	Serializer(void);
	~Serializer(void);
	Serializer(Serializer const &param);

	Serializer	&operator=(Serializer const &param);

public:
	static uintptr_t	serialize(Data *data);
	static Data			*deserialize(uintptr_t raw);
};

#endif
