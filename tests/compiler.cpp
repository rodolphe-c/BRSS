// Copyright © 2017 Rodolphe Cargnello, rodolphe.cargnello@gmail.com

// This file is part of BRSS.

// BRSS is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// BRSS is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU Affero General Public License for more details.
// You should have received a copy of the GNU Affero General Public License
// along with BRSS. If not, see <http://www.gnu.org/licenses/>

#include "brss/compiler.hpp"


template <class T>
std::ostream & operator<<(std::ostream & out, std::vector<T> const & v)
{
	out << "{ ";
	for (auto const & n : v)
	{
		out << n << "; ";
	}
	out << "}";
	return out;
}


int main(int argc, char** argv)
{
	std::vector<std::string> args (argv, argv+argc);

	if(argc <=1)
	{
		std::cerr << "\033[31mError:\033[0m Too few arguments, you need to give a brss file as parameter." << std::endl;
		exit(1);
	}
	else
	{
		try
		{
			std::vector<brss::error_t> warnings;
			auto p = brss::parser(brss::lex(args[1]), warnings);

			for (auto const & w : warnings)
			{
				std::cout << "\033[1;33m" << w.first << "\033[0m " <<  w.second;
			}

			for(std::map<std::string, brss::molecule_type>::iterator it = p.molecules.begin(); it != p.molecules.end(); ++it)
			{
				std::cout << it->first << " : " << it->second << "\n";
			}

			for (auto m : p.reactions)
			{
				std::cout << m << std::endl;
			}
		}
		catch (std::pair<std::string, std::string> const & e)
		{
			std::cerr << "\033[1;31mERROR " << e.first << "\033[0m " << e.second << std::endl;
			exit(2);
		}
	}

	return 0;
}
