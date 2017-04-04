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

#ifndef BRSS_COMPILER_REACTION_HPP
#define BRSS_COMPILER_REACTION_HPP

#include <vector>
#include <iostream>
#include <string>

namespace brss
{

	class reaction
	{
	public :
		std::vector<size_t> left_molecules;
		std::vector<size_t> right_molecules;
		float proba;

		reaction()
		{}
	};

	std::ostream& operator<<(std::ostream& os, reaction const & obj)
	{
		std::string tmp;

		if(obj.left_molecules.size() == 1)
		{
			tmp+= std::to_string(obj.left_molecules.at(0)) + " ";
		}
		else
		{
			tmp+= std::to_string(obj.left_molecules.at(0)) + "+" + std::to_string(obj.left_molecules.at(1)) + " ";
		}


		tmp+= "-> ";

		if(obj.right_molecules.size() == 1)
		{
			tmp+= std::to_string(obj.right_molecules.at(0)) + " ";
		}
		else
		{
			tmp+= std::to_string(obj.right_molecules.at(0)) + "+" + std::to_string(obj.right_molecules.at(1));
		}

		tmp+=" ["+ std::to_string(obj.proba) + "]";

		os << tmp;
		return os;
	}
	
}

#endif
