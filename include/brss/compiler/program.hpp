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

#ifndef BRSS_COMPILER_PROGRAM_HPP
#define BRSS_COMPILER_PROGRAM_HPP

#include <map>
#include <vector>
#include <functional>

#include "molecule_type.hpp"
#include "reaction.hpp"

namespace brss
{
	struct program
	{
		std::map<std::string, molecule_type> molecules;
		std::vector<std::reference_wrapper<molecule_type>> molecules_index;
		size_t dimension;

		std::array<std::array<std::vector<reaction>, 100>, 100> reactions_matrix;
		std::vector<reaction> reactions;
	};
}

#endif
