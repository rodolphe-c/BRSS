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
			brss::parser(brss::lex(args[1]));
		}
		catch (brss::exception const & e)
		{
			if (e.value.first == brss::exception_t::ERROR)
			{
				std::cerr << "\033[31mERROR " << e.value.second.x << "\033[0m " << e.value.second.y << std::endl;
			}
			else
			{
				std::cerr << "\033[33mWARNING " << e.value.second.x << "\033[0m " << e.value.second.y << std::endl;
			}
			exit(2);
		}
	}

	return 0;
}
