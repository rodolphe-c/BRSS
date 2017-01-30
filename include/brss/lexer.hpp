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

#ifndef BRSS_LEXER_HPP
#define BRSS_LEXER_HPP

#include <string>
#include <cctype>
#include <vector>

#include <boost/variant.hpp>
#include <boost/lexical_cast.hpp>

#include "hopp/container/vector2.hpp"

namespace brss
{
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

	struct type_t
	{
		token_t token;
		boost::variant<char, float, int, std::string> value;
		template <class T>
		type_t(token_t const t, T const & v) : token(t), value(v)
		{}
	};

	template <class T = std::string const>
	inline
	std::vector<type_t> lex(std::string const & filename)
	{
		std::vector<std::string const> const definitions {{"molecule", "dimension", "taille", "vitesse", "couleur", "rgb", "popinit" }};

		std::ifstream file(filename);
		if (!file.good())
		{
			throw hopp::vector2<std::string> ("File error:", "The file '" + filename + "' can't be opened.");
		}
		std::vector<type_t> types;
		int etape = 1;

		size_t line = 1;
		size_t col = 0;

		std::string tmp;
		std::string error;

		while (file.good())
		{
			char c = char(file.peek());
			if (!file.good()) {file.close(); break;}
			switch (etape)
			{
				case 1:
				{
					if (c == ',') {types.push_back(type_t(token_t::COMMA, ',')); file.get();}
					else if (c == ';') {types.push_back(type_t(token_t::SEMI, ';')); file.get();}
					else if (c == '(') {types.push_back(type_t(token_t::LPAR, '(')); file.get();}
					else if (c == ')') {types.push_back(type_t(token_t::RPAR, ')')); file.get();}
					else if (c == '=') {types.push_back(type_t(token_t::EQUAL, '=')); file.get();}
					else if (c == '+') {types.push_back(type_t(token_t::ADD, '+')); file.get();}
					else if (c == '[') {types.push_back(type_t(token_t::LBRACKET, '[')); file.get();}
					else if (c == ']') {types.push_back(type_t(token_t::RBRACKET, ']')); file.get();}
					else if (c == ' ') {file.get();}
					else if (c == '\t') {file.get();}
					else if (c == '\n') {line++; col=0; file.get();}
					else if (c == '-') {etape = 2; file.get();}
					else if (c == '/') {etape = 3; file.get();}
					else if(std::isalpha(c)){etape = 5; tmp = c; file.get();}
					else if(std::isdigit(c)){etape = 6; tmp = c; file.get();}
					else
					{
						error = "Invalid char ("+std::to_string(c)+").";
						throw hopp::vector2<std::string> ("Lexical error l." + std::to_string(line) + ", c." + std::to_string(col)+":", error);
					}
					col++;
					continue;
				}
				case 2:
				{
					if(c == '>')
					{
						col++;
						types.push_back(type_t(token_t::ARROW, "->"));
						etape = 1;
					}
					else {error = "Invalid char ("+std::to_string(c)+"). Need a '>'";etape = -1;}
					file.get();
					continue;
				}
				case 3:
				{
					if(c == '/'){etape = 4;}
					else {error = "Invalid char ("+std::to_string(c)+"). Need a '/'";etape = -1;}
					file.get();
					continue;
				}
				case 4:
				{
					while(char(file.peek())!= '\n')
					{
						c = char(file.get());
					}
					etape = 1;
					continue;
				}
				case 5:
				{
					while((std::isalpha(char(file.peek())) || std::isdigit(char(file.peek()))))
					{
						col++;
						c = char(file.get());
						tmp += c;
					}

					if(std::find (definitions.cbegin(), definitions.cend(), tmp) == definitions.cend())
					{
						types.push_back(type_t(token_t::VAR, tmp));
					}
					else
					{
						types.push_back(type_t(token_t::KEYWORD, tmp));
					}
					etape = 1;

					continue;
				}
				case 6:
				{
					while(std::isdigit(char(file.peek())))
					{
						col++;
						c = char(file.get());
						tmp += c;
					}
					if (char(file.peek()) == '.') {tmp+='.'; etape = 7; col++; file.get();}
					else
					{
						types.push_back(type_t(token_t::INTEGER, std::stoi(tmp)));
						etape = 1;
					}
					continue;
				}
				case 7:
				{
					if (std::isdigit(char(file.peek())))
					{
						while(std::isdigit(char(file.peek())))
						{
							col++;
							c = char(file.get());
							tmp += c;
						}
						types.push_back(type_t(token_t::FLOAT, std::stof(tmp)));
						etape = 1;
					}
					else
					{
						error = "Invalid char ("+std::to_string(c)+"). Need a digit after '.'.";
						throw hopp::vector2<std::string> ("Lexical error l." + std::to_string(line) + ", c." + std::to_string(col)+":", error);
					}
					continue;
				}
				default:
				{
					throw hopp::vector2<std::string> ("Lexical error l." + std::to_string(line) + ", c." + std::to_string(col)+":", error);
				}
			}
		}
		return types;
	}
}

#endif
