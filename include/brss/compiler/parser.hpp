// Copyright © 2017 Rodolphe Cargnello, rodolphe.cargnello@gmail.com
// Copyright © 2017 Ifthihar Mohamed Raffique, ifthihar1995@gmail.com
// Copyright © 2017 Ayoub Jaa, ayoub.jaa@u-psud.fr

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

#include <iostream>
#include <numeric>


#include "token.hpp"
#include "program.hpp"

namespace brss
{
	int num_type = 1;

	using error_t = std::pair<std::string, std::string>;

	// Test taille de nos expressions
	inline
	void check_size(std::vector<brss::expression_t> const & data, size_t const i)
	{
		if(i >= data.size())
		{
			throw error_t("Parsing:" , "EOF");
		}
	}

	// Test de déclaration molécule
	inline
	void check_molecule(program const & p, std::string const & s, std::vector<brss::expression_t> const & data, size_t const i)
	{
		if (p.molecules.count(s) == 0)
		{
			throw error_t("Parsing l."+ std::to_string(data[i].line) +", c."+std::to_string(data[i].col)+":" , "Molecule type '" + s + "' is not declared.");
		}
	}

	// Test une séquence de Token
	inline
	bool is_sequence (std::vector<brss::token_t> tokens, std::vector<brss::expression_t> const & data, size_t const i)
	{
		for (size_t j = 0; j < tokens.size(); ++j)
		{
			if (i+j >= data.size()) {return false;}
			if(tokens[j] != data[i+j].token)
			{
				return false;
			}
		}
		return true;
	}

	// Déclaration d'un ensemble de molécules
	inline
	void molecule_t_declaration(brss::program & p, std::vector<brss::expression_t> const & data, size_t & i)
	{
		i++;
		check_size(data,i);
		if((data[i]).token == token_t::VAR)
		{
			size_t id = 0;
			std::function<void(brss::program &, size_t &, std::vector<brss::expression_t> const &, int const)> slave;
			slave = [&](brss::program & p, size_t & i, std::vector<brss::expression_t> const & data, int const flag)
			{
				check_size(data,i);
				if( data[i].token == token_t::VAR && flag==1)
				{
					molecule_type tm(id);
					p.molecules.insert(std::pair<std::string, molecule_type>(boost::get<std::string>(data[i].value),tm));
					p.molecules_index.push_back(std::ref(p.molecules[boost::get<std::string>(data[i].value)]));
					i++;
					id++;
					slave(p, i, data, 0);
				}
				else if( data[i].token == token_t::COMMA && flag==0)
				{
					i++;
					slave(p, i, data, 1);
				}
				else if( !(data[i].token == token_t::SEMI && flag==0))
				{
					if (data[i].token == token_t::VAR)
					{
						throw error_t ("Parsing l."+ std::to_string(data[i].line) +", c."+std::to_string(data[i].col)+":" , "All molecule types must be separated with comma.");
					}
					else if (data[i].token == token_t::COMMA)
					{
						throw error_t ("Parsing l."+ std::to_string(data[i].line) +", c."+std::to_string(data[i].col)+":" , "Attend a molecule type after comma.");
					}
					else if (data[i].token == token_t::KEYWORD)
					{
						throw error_t ("Parsing l."+ std::to_string(data[i].line) +", c."+std::to_string(data[i].col)+":" , "The word '" + boost::get<std::string>(data[i].value) +"' is reserved and cannot be used as a molecule type.");
					}
					else
					{
						throw error_t ("Parsing l."+ std::to_string(data[i].line) +", c."+std::to_string(data[i].col)+":" , "TODO");
					}
				}
			};
			slave(p, i, data, 1);
		}
		else
		{
			throw error_t ("Parsing l."+ std::to_string(data[i].line) +", c."+std::to_string(data[i].col)+":" , "Attend a Variable.");
		}
	}

	// Dimension de la Cellule
	inline
	void dimension_cellule(brss::program & p, std::vector<brss::expression_t> const & data, size_t & i)
	{
		i++;
		check_size(data,i);
		if(is_sequence({token_t::INTEGER, token_t::SEMI}, data, i))
		{
			p.dimension = boost::get<size_t>((data[i]).value);
			i++;
		}
		else
		{
			throw error_t ("Parsing l."+ std::to_string(data[i].line) +", c."+std::to_string(data[i].col)+":" , "Attend an Integer.");
		}
	}

	// Taille d'un type de molécule
	inline
	void taille(brss::program & p, std::vector<brss::expression_t> const & data, size_t & i, std::vector<error_t> & warnings)
	{
		i++;
		check_size(data,i);
		if(is_sequence(
			{token_t::LPAR, token_t::VAR,
			token_t::RPAR, token_t::EQUAL,
			token_t::INTEGER, token_t::SEMI}, data, i))
		{
			std::string v = boost::get<std::string>((data[i+1]).value);
			check_molecule(p,v, data, i+1);
			auto machin = p.molecules[v];
			machin.taille = boost::get<size_t>((data[i+4]).value);
			if(machin.taille > 10)
			{
				warnings.push_back
				(
					error_t("Warning Parsing l." + std::to_string(data[i+4].line) +", c."+std::to_string(data[i+4].col)+":",
					"Wrong size value, default size value 10.\n")
				);
				machin.taille = 10;
			}
			p.molecules[v] = machin;
			i+=5;
			check_size(data,i);
		}
		else
		{
			throw error_t ("Parsing l."+ std::to_string(data[i].line) +", c."+std::to_string(data[i].col)+":", "Error size declaration");
		}
	}

	// Vitesse d'un type de molécule
	inline
	void velocity(brss::program & p, std::vector<brss::expression_t> const & data, size_t & i, std::vector<error_t> & warnings)
	{
		i++;
		check_size(data,i);

		check_size(data,i);

		if(is_sequence(
			{token_t::LPAR, token_t::VAR,
			token_t::RPAR, token_t::EQUAL,
			token_t::FLOAT, token_t::SEMI}, data, i))
		{
			std::string v = boost::get<std::string>((data[i+1]).value);
			check_molecule(p,v, data, i+1);
			auto machin = p.molecules[v];
			machin.velocity = boost::get<float>((data[i+4]).value);
			if(machin.velocity > 1.f)
			{
				warnings.push_back
				(
					error_t("Warning Parsing l." + std::to_string(data[i+4].line) +", c."+std::to_string(data[i+4].col)+":",
					"Wrong speed value, default speed value 1.")
				);
				machin.velocity = 1.f;
			}
			p.molecules[v] = machin;
			i+=5;
			check_size(data,i);
		}
		else
		{
			throw error_t ("Parsing l."+ std::to_string(data[i].line) +", c."+std::to_string(data[i].col)+":", "Error speed declaration");
		}
	}

	// Population initiale d'un type de molécule
	inline
	void popinit(brss::program & p, std::vector<brss::expression_t> const & data, size_t & i)
	{
		i++;
		check_size(data,i);

		if(is_sequence(
			{token_t::LPAR, token_t::VAR,
			token_t::RPAR, token_t::EQUAL,
			token_t::INTEGER, token_t::SEMI}, data, i))
		{
			std::string v = boost::get<std::string>((data[i+1]).value);
			check_molecule(p,v, data, i+1);
			auto machin = p.molecules[v];
			machin.popinit = boost::get<size_t>((data[i+4]).value);
			p.molecules[v] = machin;
			i+=5;
			check_size(data,i);
		}
		else
		{
			throw error_t ("Parsing l."+ std::to_string(data[i].line) +", c."+std::to_string(data[i].col)+":", "Error popinit declaration");
		}
	}

	// Valeur RGB d'un type molécule
	inline
	std::array<int,3> rgb(std::vector<brss::expression_t> const & data, size_t & i, std::vector<error_t> & warnings)
	{
		std::array<int,3> tab = {{0,0,0}};
		i++;
		check_size(data,i);

		if(is_sequence(
			{token_t::LPAR, token_t::INTEGER,
			token_t::COMMA, token_t::INTEGER,
			token_t::COMMA, token_t::INTEGER,
			token_t::RPAR}, data, i))
		{
			tab[0] = int(boost::get<size_t>((data[i+1]).value));
			if(tab[0] > 255)
			{
				warnings.push_back
				(
					error_t("Warning Parsing l." + std::to_string(data[i+1].line) +", c."+std::to_string(data[i+1].col)+":",
					"Wrong color, default color 255.")
				);
				tab[0] = 255;
			}
			tab[1] = int(boost::get<size_t>((data[i+3]).value));
			if(tab[1] > 255)
			{
				warnings.push_back
				(
					error_t("Warning Parsing l." + std::to_string(data[i+3].line) +", c."+std::to_string(data[i+3].col)+":",
					"Wrong color, default color 255.")
				);
				tab[1] = 255;
			}
			tab[2] = int(boost::get<size_t>((data[i+5]).value));
			if(tab[2] > 255)
			{
				warnings.push_back
				(
					error_t("Warning Parsing l." + std::to_string(data[i+5].line) +", c."+std::to_string(data[i+5].col)+":",
					"Wrong color, default color 255.")
				);
				tab[2] = 255;
			}
			i+=6;
			check_size(data,i);
		}
		else
		{
			throw error_t ("Parsing l."+ std::to_string(data[i].line) +", c."+std::to_string(data[i].col)+":", "Error rgb declaration");
		}
		return tab;
	}

	// Déclaration d'une couleur pour un type molécule
	inline
	void couleur(brss::program & p, std::vector<brss::expression_t> const & data, size_t & i, std::vector<error_t> & warnings)
	{
		i++;
		check_size(data,i);

		if(is_sequence(
			{token_t::LPAR, token_t::VAR,
			token_t::RPAR, token_t::EQUAL,
			token_t::KEYWORD}, data, i))
		{
			if(boost::get<std::string>((data[i+4]).value) == brss::keywords[5])
			{
				std::string v = boost::get<std::string>((data[i+1]).value);
				auto machin = p.molecules[v];
				i+=4;
				machin.couleur = rgb(data, i, warnings);
				p.molecules[v] = machin;
				i++;
				check_size(data,i);
				if((data[i]).token != token_t::SEMI)
				{
					throw error_t ("Parsing:" , "Error color declaraction");
				}
			}
			else
			{
				throw error_t ("Parsing:" , "Error color declaraction");
			}
		}
		else
		{
			throw error_t ("Parsing l."+ std::to_string(data[i].line) +", c."+std::to_string(data[i].col)+":", "Error color declaraction");
		}
	}

	// Appels de fonctions pour un type molécule
	inline
	void functions_call(brss::program & p, std::vector<brss::expression_t> const & data, size_t & i, std::vector<error_t> & warnings)
	{
		if(boost::get<std::string>((data[i]).value) == brss::keywords[2])
		{
			taille(p, data, i, warnings);
		}
		else if(boost::get<std::string>((data[i]).value) == brss::keywords[3])
		{

			velocity(p, data, i, warnings);
		}
		else if(boost::get<std::string>((data[i]).value) == brss::keywords[4])
		{
			couleur(p, data, i, warnings);
		}
		else if(boost::get<std::string>((data[i]).value) == brss::keywords[6])
		{
			popinit(p, data, i);
		}
	}

	// Déclaration d'une réaction
	inline
	void gestion_reactions(brss::program & p, std::vector<brss::expression_t> const & data, size_t & i)
	{
		reaction r;
		std::string str = boost::get<std::string>((data[i]).value);
		check_molecule(p,str, data, i);
		r.left_molecules.push_back(p.molecules[str].id);
		i++;
		check_size(data,i);

		// A -> B + C [X];
		if(is_sequence(
			{token_t::ARROW, token_t::VAR,
			token_t::ADD, token_t::VAR,
			token_t::LBRACKET, token_t::FLOAT,
			token_t::RBRACKET, token_t::SEMI},data, i))
		{
			str = boost::get<std::string>((data[i+1]).value);
			check_molecule(p,str, data, i+1);
			r.right_molecules.push_back(p.molecules[str].id);

			str = boost::get<std::string>((data[i+3]).value);
			check_molecule(p,str, data, i+3);
			r.right_molecules.push_back(p.molecules[str].id);

			r.proba = (boost::get<float>((data[i+5]).value));
			p.reactions_matrix[r.left_molecules[0]][r.left_molecules[0]].push_back(r);
			i+=7;
		}
		// A -> B [X];
		else if(is_sequence(
			{token_t::ARROW, token_t::VAR,
			token_t::LBRACKET, token_t::FLOAT,
			token_t::RBRACKET, token_t::SEMI},data, i))
		{
			str = boost::get<std::string>((data[i+1]).value);
			check_molecule(p, str, data, i+1);
			r.right_molecules.push_back(p.molecules[str].id);

			r.proba = (boost::get<float>((data[i+3]).value));
			p.reactions_matrix[r.left_molecules[0]][r.left_molecules[0]].push_back(r);

			i+=5;
		}
		// A + B -> C [X];
		else if(is_sequence(
			{token_t::ADD, token_t::VAR,
			token_t::ARROW, token_t::VAR,
			token_t::LBRACKET, token_t::FLOAT,
			token_t::RBRACKET, token_t::SEMI},data, i))
		{
			str = boost::get<std::string>((data[i+1]).value);
			check_molecule(p,str, data, i+1);
			r.left_molecules.push_back(p.molecules[str].id);

			str = boost::get<std::string>((data[i+3]).value);
			check_molecule(p,str, data, i+3);
			r.right_molecules.push_back(p.molecules[str].id);

			r.proba = (boost::get<float>((data[i+5]).value));
			p.reactions_matrix[r.left_molecules[0]][r.left_molecules[1]].push_back(r);
			p.reactions_matrix[r.left_molecules[1]][r.left_molecules[0]].push_back(r);

			i+=7;
		}
		// A + B -> C + D [X];
		else if(is_sequence(
			{token_t::ADD, token_t::VAR,
			token_t::ARROW, token_t::VAR,
			token_t::ADD, token_t::VAR,
			token_t::LBRACKET, token_t::FLOAT,
			token_t::RBRACKET, token_t::SEMI},data, i))
		{
			str = boost::get<std::string>((data[i+1]).value);
			check_molecule(p,str, data, i+1);
			r.left_molecules.push_back(p.molecules[str].id);

			str = boost::get<std::string>((data[i+3]).value);
			check_molecule(p,str, data, i+3);
			r.right_molecules.push_back(p.molecules[str].id);

			str = boost::get<std::string>((data[i+5]).value);
			check_molecule(p,str, data, i+5);
			r.right_molecules.push_back(p.molecules[str].id);

			r.proba = (boost::get<float>((data[i+7]).value));
			p.reactions_matrix[r.left_molecules[0]][r.left_molecules[1]].push_back(r);
			p.reactions_matrix[r.left_molecules[1]][r.left_molecules[0]].push_back(r);

			i+=9;
		}
		p.reactions.push_back(r);
	}

	// Algorithme principal de parsing du programme
	inline
	brss::program parser(std::vector<brss::expression_t> const & data, std::vector<error_t> & warnings)
	{
		brss::program p;

		// Création du programme
		for (size_t i = 0; i < data.size(); i++)
		{
			if(data[i].token == token_t::KEYWORD)
			{
				//MOLECULE TYPE
				if(boost::get<std::string>((data[i]).value) == brss::keywords[0])
				{
					molecule_t_declaration(p, data, i);
				}
				//DIMENSION
				else if (boost::get<std::string>((data[i]).value) == brss::keywords[1])
				{
					dimension_cellule(p, data, i);
				}
				//Functions
				else
				{
					functions_call(p, data, i, warnings);
				}
			}
			else if(data[i].token == token_t::VAR)
			{
				gestion_reactions(p, data, i);
			}
		}

		// Test de couleurs différentes pour un type de molécule
		for(size_t i = 0; i <  p.molecules_index.size(); ++i)
		{
			for(size_t j = i+1; j <  p.molecules_index.size(); ++j)
			{
				if( p.molecules_index[i].get().couleur == p.molecules_index[j].get().couleur)
				{
					warnings.push_back(error_t("Warning Parsing:", "Same color for " + std::to_string(i) + " and " + std::to_string(j) + "."));
				}
			}
		}

		// Test de dépassement de la probabilité sur une même formule
		for(auto const & m1 : p.molecules_index)
		{
			for(auto const & m2 : p.molecules_index)
			{
				auto v = p.reactions_matrix[m1.get().id][m2.get().id];
				float val = std::accumulate(v.cbegin(), v.cend(), 0.f, [](float const cpt, reaction const & r){ return r.proba+cpt;});
				if (val > 1.f)
				{
					throw error_t ("Parsing:", "Invalid probability for " + std::to_string(m1.get().id) + " (" + std::to_string(val) + ").");
				}
			}
		}

		return p;
	}
}

#endif
