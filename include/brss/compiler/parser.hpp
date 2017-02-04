// Copyright © 2017 Rodolphe Cargnello, rodolphe.cargnello@gmail.com
// Copyright © 2017 Ifthihar Mohamed Raffique, ifthihar1995@gmail.com

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

#ifndef BRSS_COMPILER_PARSER_HPP
#define BRSS_COMPILER_PARSER_HPP

#include <vector>
#include <functional>


#include "hopp/container/vector2.hpp"

#include "token.hpp"
#include "program.hpp"
#include "exception.hpp"

namespace brss
{
	inline
	void molecule_t_declaration(brss::program & p, std::vector<brss::expression_t> const & data, size_t & i)
	{
		i++;
		if (i < data.size())
		{
			if((data[i]).token == token_t::VAR)
			{
				std::function<void(brss::program &, size_t &, std::vector<brss::expression_t> const &, int const)> slave;
				slave = [&slave](brss::program & p, size_t & i, std::vector<brss::expression_t> const & data, int const flag) -> void
				{
					if (i >= data.size())
					{
						throw brss::exception(brss::exception_t::ERROR, hopp::vector2<std::string> ("Parsing:" , "EOF"));
					}
					if( data[i].token == token_t::VAR && flag==1)
					{
						molecule_type tm;
						p.molecules[boost::get<std::string>(data[i].value)] = tm;
						i++;
						slave(p, i, data, 0);
					}
					else if( data[i].token == token_t::COMMA && flag==0)
					{
						brss::molecule_type tm;
						i++;
						slave(p, i, data, 1);
					}
					else if( !(data[i].token == token_t::SEMI && flag==0))
					{
						if (data[i].token == token_t::VAR)
						{
							throw brss::exception(brss::exception_t::ERROR,
								hopp::vector2<std::string> ("Parsing l."+ std::to_string(data[i].line) +", c."+std::to_string(data[i].col)+":" , "All molecule types must be separated with comma."));
						}
						else if (data[i].token == token_t::COMMA)
						{
							throw brss::exception(brss::exception_t::ERROR,
								hopp::vector2<std::string> ("Parsing l."+ std::to_string(data[i].line) +", c."+std::to_string(data[i].col)+":" , "Attend a molecule type after comma."));
						}
						else if (data[i].token == token_t::KEYWORD)
						{
							throw brss::exception(brss::exception_t::ERROR,
								hopp::vector2<std::string> ("Parsing l."+ std::to_string(data[i].line) +", c."+std::to_string(data[i].col)+":" , "The word '" + boost::get<std::string>(data[i].value) +"' is reserved and cannot be used as a molecule type."));
						}
						else
						{
							throw brss::exception(brss::exception_t::ERROR,
								hopp::vector2<std::string> ("Parsing l."+ std::to_string(data[i].line) +", c."+std::to_string(data[i].col)+":" , "TODO"));
						}
					}
				};
				slave(p, i, data, 1);
			}
			else
			{
				throw brss::exception(brss::exception_t::ERROR,
					hopp::vector2<std::string> ("Parsing l."+ std::to_string(data[i].line) +", c."+std::to_string(data[i].col)+":" , "Attend a Variable."));
			}
		}
		else
		{
			throw brss::exception(brss::exception_t::ERROR,
				hopp::vector2<std::string> ("Parsing:" , "EOF"));
		}
	}

	inline
	void parser(std::vector<brss::expression_t> const & data)
	{
		brss::program p;
/*
		for (auto const & d : data)
		{
			std::cout << d << std::endl;
		}
*/

		for (size_t i = 0; i < data.size(); i++)
		{
			if(data[i].token == token_t::KEYWORD)
			{
				//MOLECULE TYPE
				if(boost::get<std::string>((data[i]).value) == brss::keywords[0])
				{
					molecule_t_declaration(p, data, i);
				}
				else
				{
					std::cout<< to_string(data[i].token) <<std::endl;
				}
			}
			else
			{
				std::cout<< to_string(data[i].token) <<std::endl;
			}
		}

		for (std::map<std::string, brss::molecule_type>::iterator it = p.molecules.begin(); it!=p.molecules.end(); ++it)
		{
				std::cout<<it->first<<std::endl;
		}
	}
}

#endif
