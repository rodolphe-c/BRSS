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

#ifndef MOLECULE_HPP
#define MOLECULE_HPP

#include "hopp/container.hpp"

enum class molecule_type{ A, B, C, D, E };

class molecule
{
public:
	molecule_type type;

	hopp::vector3<float> position;
	hopp::vector3<float> velocity;
	hopp::vector3<float> acceleration;

	float mass;

public:
	molecule(molecule_type const type) : type(type),
	position(hopp::vector3<float>(0.f,0.f,0.f)),
	velocity(hopp::vector3<float>(0.1f,0.1f,0.1f)),
	acceleration(hopp::vector3<float>(0.f,0.f,0.f)),
	mass(1.f)
	{}
};

template<class vector3_t, class T = float>
vector3_t mult (vector3_t const & v, T const k)
{
	return vector3_t(v.x * k, v.y * k, v.z * k);
}

template<class vector3_t, class T = float>
auto dot (vector3_t const & v0, vector3_t const & v1) -> decltype(v0.x)
{
	return v0.x * v1.x + v0.y * v1.y + v0.z * v1.z;
}

template<class vector3_t>
auto norm (vector3_t const & v) -> decltype(v.x)
{
	return std::sqrt(dot(v,v));
}

template<class vector3_t>
vector3_t normalize(vector3_t const & v)
{
	return mult(v,(1/norm(v)));
}


#endif // MOLECULE_HPP
