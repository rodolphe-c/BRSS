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

#include <iostream>
#include <fstream>

#include "brss/lexer.hpp"

std::string to_string(brss::token_t const t);

std::ostream & operator<<(std::ostream & o, brss::type_t const & type);

int main(int argc, char** argv)
{
	std::vector<std::string> args (argv, argv+argc);

	if(argc <=1)
	{
		std::cerr << "\033[31mError 1:\033[0m Too few arguments, you need to give a brss file as parameter." << std::endl;
		exit(1);
	}
	else
	{
		try
		{
			if(isalpha('/')) { std::cout << "OK\n";}
			auto tokens = brss::lex(args[1]);

			for (auto const & t : tokens)
			{
				std::cout << t << std::endl;
			}

		}
		catch (hopp::vector2<std::string> const & e)
		{
			std::cerr << "\033[31m" << e.x << "\033[0m " << e.y << std::endl;
			exit(2);
		}
	}
	return 0;
}

std::string to_string(brss::token_t const t)
{
	if (t == brss::token_t::KEYWORD){ return "KEYWORD";}
	else if (t == brss::token_t::VAR) {return "VAR";}
	else if (t == brss::token_t::INTEGER) {return "INTEGER";}
	else if (t == brss::token_t::FLOAT) {return "FLOAT";}
	else if (t == brss::token_t::ADD) {return "ADD";}
	else if (t == brss::token_t::ARROW) {return "ARROW";}
	else if (t == brss::token_t::COMMA) {return "COMMA";}
	else if (t == brss::token_t::SEMI) {return "SEMI";}
	else if (t == brss::token_t::EQUAL) {return "EQUAL";}
	else if (t == brss::token_t::LBRACKET) {return "LBRACKET";}
	else if (t == brss::token_t::RBRACKET) {return "RBRACKET";}
	else if (t == brss::token_t::LPAR) {return "LPAR";}
	else if (t == brss::token_t::RPAR) {return "RPAR";}
	else {return "UNKNOWN";}
}

std::ostream & operator<<(std::ostream & o, brss::type_t const & type)
{
	auto str =  boost::lexical_cast<std::string>(type.value);
	o << "{"+to_string(type.token)+", '" + str + "'}";
	return o;
}
