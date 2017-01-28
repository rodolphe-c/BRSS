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

#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>


namespace brss
{
	constexpr size_t version_major() { return 0; }
	constexpr size_t version_minor() { return 0; }
	constexpr size_t version_patch() { return 0; }

	inline std::string version() { return std::to_string(version_major())+"."+std::to_string(version_minor())+"."+std::to_string(version_patch()); }
	inline std::string codename() { return "Let's start simulation !"; }
}

#endif
