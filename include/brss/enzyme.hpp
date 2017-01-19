#ifndef ENZYME_HPP
#define ENZYME_HPP

#include <osg/MatrixTransform>

enum class enzyme_type{ A, B };

class enzyme
{
public:
	osg::Matrixf matrix;
	enzyme_type type;

	osg::Vec3f position;
	osg::Vec3f velocity;
	osg::Vec3f acceleration;
	double mass;

public:
	enzyme(enzyme_type const type) : matrix(osg::Matrixf::identity()),
	type(type),
	position(osg::Vec3f(0.f,0.f,0.f)),
	velocity(osg::Vec3f(0.1f,0.1f,0.1f)),
	acceleration(osg::Vec3f(0.f,0.f,0.f)),
	mass(1.0)
	{}
};

#endif // ENZYME_HPP
