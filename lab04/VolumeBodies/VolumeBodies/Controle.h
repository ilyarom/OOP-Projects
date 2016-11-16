#pragma once
#include "stdafx.h"
#include <boost/noncopyable.hpp>
#include "Body.h"
#include "Sphere.h"
#include "Parallelepiped.h"
#include "Cone.h"
#include "Cylinder.h"

class CBody;

using namespace std;

class CControle : boost::noncopyable
{
public:
    CControle(vector<shared_ptr<CBody>> &bodies, istream &input, ostream &output);
    bool HandleCommand();

    bool PrintBodies(istream &args);
    bool FindLargestWeightBody(istream &args);
	bool FindSmallestWeightBodyInWater(istream &args);

private:
    bool CreateSphere(istream &rgs);
    bool CreateParallelepiped(istream &args);
    bool CreateCone(istream &args);
    bool CreateCylinder(istream &args);
    double GetWeight(shared_ptr<CBody> &body, const double &WATER_DENSITY, const double &GRAVITY_CONST);
	bool Help(istream &args);

    typedef map<string, function<bool(istream & args)>> ActionMap;

    vector<shared_ptr<CBody>> &m_bodies;
    istream &m_input;
    ostream &m_output;

    const ActionMap m_actionMap;
};

