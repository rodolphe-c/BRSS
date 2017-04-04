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

#ifndef BRSS_SIMULATOR_MOLECULE_HPP
#define BRSS_SIMULATOR_MOLECULE_HPP

class molecule
{
private :
	static size_t next_id;

public:
	size_t type;
	size_t id;
	float velocity;

public:
	molecule(size_t const ident, size_t const type, float const v) : type(type),
	id(ident),
	velocity(v)
	{}
};

#endif // MOLECULE_HPP
