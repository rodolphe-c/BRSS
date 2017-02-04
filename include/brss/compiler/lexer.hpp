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

#ifndef BRSS_COMPILER_LEXER_HPP
#define BRSS_COMPILER_LEXER_HPP

#include <fstream>
#include <vector>
#include <map>

#include "exception.hpp"

namespace brss
{
	inline
	std::vector<brss::expression_t> lex(std::string const & filename)
	{
		std::ifstream file(filename);
		if (!file.good())
		{
			throw brss::exception(brss::exception_t::ERROR, hopp::vector2<std::string> ("File stream:", "The file '" + filename + "' cannot be opened."));
		}

		std::vector<brss::expression_t> types;

		short state = 1;
		unsigned line = 1;
		unsigned col = 0;

		std::string tmp;
		std::string error;

		while (file.good())
		{
			char c = char(file.peek());
			if (!file.good()) {file.close(); break;}
			switch (state)
			{
				case 1:
				{
					if (c == ',') {types.push_back(expression_t(token_t::COMMA, ',', line, col)); file.get();}
					else if (c == ';') {types.push_back(expression_t(token_t::SEMI, ';', line, col)); file.get();}
					else if (c == '(') {types.push_back(expression_t(token_t::LPAR, '(', line, col)); file.get();}
					else if (c == ')') {types.push_back(expression_t(token_t::RPAR, ')', line, col)); file.get();}
					else if (c == '=') {types.push_back(expression_t(token_t::EQUAL, '=', line, col)); file.get();}
					else if (c == '+') {types.push_back(expression_t(token_t::ADD, '+', line, col)); file.get();}
					else if (c == '[') {types.push_back(expression_t(token_t::LBRACKET, '[', line, col)); file.get();}
					else if (c == ']') {types.push_back(expression_t(token_t::RBRACKET, ']', line, col)); file.get();}
					else if (c == ' ') {file.get();}
					else if (c == '\t') {file.get();}
					else if (c == '\n') {line++; col=0; file.get();}
					else if (c == '-') {state = 2; file.get();}
					else if (c == '/') {state = 3; file.get();}
					else if(std::isalpha(c)){state = 5; tmp = c; file.get();}
					else if(std::isdigit(c)){state = 6; tmp = c; file.get();}
					else
					{
						error = "Invalid char ("+std::to_string(c)+").";
						throw brss::exception(brss::exception_t::ERROR, hopp::vector2<std::string> ("Lex l." + std::to_string(line) + ", c." + std::to_string(col)+":", error));
					}
					col++;
					continue;
				}
				case 2:
				{
					if(c == '>')
					{
						col++;
						types.push_back(expression_t(token_t::ARROW, "->", line, col-1));
						state = 1;
					}
					else {error = "Invalid char ("+std::to_string(c)+"). Need a '>'";state = -1;}
					file.get();
					continue;
				}
				case 3:
				{
					if(c == '/'){state = 4;}
					else {error = "Invalid char ("+std::to_string(c)+"). Need a '/'";state = -1;}
					file.get();
					continue;
				}
				case 4:
				{
					while(char(file.peek())!= '\n')
					{
						c = char(file.get());
					}
					state = 1;
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

					if(std::find (brss::keywords.cbegin(), brss::keywords.cend(), tmp) == brss::keywords.cend())
					{
						types.push_back(expression_t(token_t::VAR, tmp, line, col - tmp.size()));
					}
					else
					{
						types.push_back(expression_t(token_t::KEYWORD, tmp, line, col - tmp.size()));
					}
					state = 1;

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
					if (char(file.peek()) == '.') {tmp+='.'; state = 7; col++; file.get();}
					else
					{
						types.push_back(expression_t(token_t::INTEGER, std::stoi(tmp), line, col - tmp.size()));
						state = 1;
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
						types.push_back(expression_t(token_t::FLOAT, std::stof(tmp), line, col - tmp.size()));
						state = 1;
					}
					else
					{
						error = "Invalid char ("+std::to_string(c)+"). Need a digit after '.'.";
						throw brss::exception(brss::exception_t::ERROR, hopp::vector2<std::string> ("Lex l." + std::to_string(line) + ", c." + std::to_string(col)+":", error));
					}
					continue;
				}
				default:
				{
					throw brss::exception(brss::exception_t::ERROR, hopp::vector2<std::string> ("Lex l." + std::to_string(line) + ", c." + std::to_string(col)+":", error));
				}
			}
		}
		return types;
	}
}

#endif
