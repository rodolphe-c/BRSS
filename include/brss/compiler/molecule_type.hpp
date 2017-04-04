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

#ifndef BRSS_COMPILER_MOLECULE_TYPE_HPP
#define BRSS_COMPILER_MOLECULE_TYPE_HPP

#include <random>
#include <array>
#include <cstdlib>
#include <iostream>

namespace brss
{
	class molecule_type
	{
	public :
		size_t id;
		size_t taille;
		size_t popinit;
		float velocity;

		std::array<int,3> couleur;
		molecule_type(size_t const ident) : id(ident)
		{
			std::random_device rd;  //Will be used to obtain a seed for the random number engine
			std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
			std::uniform_int_distribution<int> dis(0, 255);

			int r = dis(gen);
			int g = dis(gen);
			int b = dis(gen);

			couleur = {{r,g,b}};
			taille = 0;
			popinit = 0;
			velocity = 0;
		}

		molecule_type()
		{
			id = 0;

			couleur = {{0,0,0}};
			taille = 0;
			popinit = 0;
			velocity = 0;
		}
	};

	std::ostream& operator<<(std::ostream& os, molecule_type const & obj)
	{
		std::string tmp = "{ID: " + std::to_string(obj.id)
							+ ", taille: " + std::to_string(obj.taille)
							+ ", popinit: " + std::to_string(obj.popinit)
							+ ", vitesse: " + std::to_string(obj.velocity)
							+ ", couleur("+ std::to_string(obj.couleur[0]) + ", " + std::to_string(obj.couleur[1]) + ", "+ std::to_string(obj.couleur[2]) + ")}";
		os << tmp;
		return os;
	}
}

#endif
