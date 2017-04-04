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

#ifndef BRSS_COMPILER_TOKEN_HPP
#define BRSS_COMPILER_TOKEN_HPP

#include <string>
#include <vector>

#include <boost/variant.hpp>
#include <boost/lexical_cast.hpp>

namespace brss
{
	std::vector<std::string> const keywords {{"molecule", "dimension", "taille", "vitesse", "couleur", "rgb", "popinit" }};

	enum class token_t
	{
		KEYWORD,
		VAR,
		INTEGER,
		FLOAT,
		ADD,
		ARROW,
		COMMA,
		SEMI,
		EQUAL,
		LBRACKET,
		RBRACKET,
		LPAR,
		RPAR
	};

	struct expression_t
	{
		token_t token;
		boost::variant<char, float, size_t, std::string> value;
		size_t line;
		size_t col;

		template <class T>
		expression_t(token_t const t, T const & v, size_t const l = 1, size_t const c = 1) :
		token(t), value(v), line(l), col(c)
		{}
	};

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

	std::ostream & operator<<(std::ostream & o, brss::expression_t const & type)
	{
		auto str =  boost::lexical_cast<std::string>(type.value);
		o << "{"+to_string(type.token)+", '" + str + "'}";
		return o;
	}
}

#endif
