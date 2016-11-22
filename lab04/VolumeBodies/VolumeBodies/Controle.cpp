#include "stdafx.h"
#include "Controle.h"

using namespace std;
using namespace std::placeholders;

CControle::CControle(vector<shared_ptr<CBody>> &bodies, istream &input, ostream &output)
	: m_bodies(bodies)
	, m_input(input)
	, m_output(output)
	, m_actionMap({
		{ "Sphere", bind(&CControle::CreateSphere, this, _1) },
		{ "Parallelepiped", bind(&CControle::CreateParallelepiped, this, _1) },
		{ "Cone", bind(&CControle::CreateCone, this, _1) },
		{ "FindLargestWeightBody", bind(&CControle::FindLargestWeightBody, this, _1) },
		{ "Cylinder", bind(&CControle::CreateCylinder, this, _1) },
		{ "FindSmallestWeightBodyInWater", bind(&CControle::FindSmallestWeightBodyInWater, this, _1) },
		{ "PrintBodies", bind(&CControle::PrintBodies, this, _1) },
		{ "Help", bind(&CControle::Help, this, _1) }
})
{
}

bool CControle::HandleCommand()
{
    string commandLine;
    if (!getline(m_input, commandLine))
        return true;
    istringstream strm(commandLine);

    string action;
    strm >> action;

    auto it = m_actionMap.find(action);
    if (it != m_actionMap.end())
    {
        return !(it -> second(strm));
    }
	m_output << "Unknown command\n";
    return false;
}

bool CControle::CreateSphere(istream &args)
{
    double density;
    double radius;

    if (!(args >> density) || !(args >> radius) || args.fail())
    {
		m_output << "Error. Expected: <density> <radius>\n";
        return EXIT_FAILURE;
    }
	if (radius == -1)
	{
		m_output << "Error. The values are be greater than 0\n";
		return EXIT_FAILURE;
	}
    shared_ptr<CBody> sphere(new CSphere(density, radius));
    m_bodies.push_back(sphere);

    return EXIT_SUCCESS;
}

bool CControle::CreateParallelepiped(istream &args)
{
	double density;
    double width;
    double height;
    double depth;

    if (!(args >> density) || !(args >> width) || !(args >> height) || !(args >> depth) || args.fail())
    {
        m_output << "Error. Expected: <density> <width> <height> <depth>\n";
        return EXIT_FAILURE;
    }
	if (width == -1 || height == -1 || depth == -1)
	{
		m_output << "Error. The values are be greater than 0\n";
		return EXIT_FAILURE;
	}
    shared_ptr<CBody> parallelepiped(new CParallelepiped(density, width, height, depth));
    m_bodies.push_back(parallelepiped);

    return EXIT_SUCCESS;
}

bool CControle::CreateCone(istream &args)
{
    double density;
    double radius;
    double height;

    if (!(args >> density) || !(args >> radius) || !(args >> height) || args.fail())
    {
		m_output << "Error. Expected: <density> <radius> <height>\n";
        return EXIT_FAILURE;
    }
	if (radius == -1 || height == -1)
	{
		m_output << "Error. The values are be greater than 0\n";
		return EXIT_FAILURE;
	}
    shared_ptr<CBody> cone(new CCone(density, radius, height));
    m_bodies.push_back(cone);

    return EXIT_SUCCESS;
}

bool CControle::CreateCylinder(istream &args)
{
    double density;
    double radius;
    double height;

    if (!(args >> density) || !(args >> radius) || !(args >> height) || args.fail())
    {
		m_output << "Error. Expected: <density> <radius> <height>\n";
        return EXIT_FAILURE;
    }
	if (radius == -1 || height == -1)
	{
		m_output << "Error. The values are be greater than 0\n";
		return EXIT_FAILURE;
	}
    shared_ptr<CBody> cylinder(new CCylinder(density, radius, height));
    m_bodies.push_back(cylinder);

    return EXIT_SUCCESS;
}

bool CControle::PrintBodies(istream &args)
{
	if (m_bodies.empty())
	{
		m_output << "Error. Bodies are not exist\n";
		return EXIT_FAILURE;
	}
	for (auto &body : m_bodies)
	{
		m_output << body->ToString();
	}
	return EXIT_SUCCESS;
}

bool CControle::FindLargestWeightBody(istream &args)
{
    if (m_bodies.empty())
    {
		m_output << "Error. Bodies are not exist\n";
		return EXIT_FAILURE;
    }
	else
	{
		auto maxWeight = [](shared_ptr<CBody> const &first, shared_ptr<CBody> const &second)
		{
			return first->GetMass() < second->GetMass();
		};
		m_output << "Body with max weight is " << (*max_element(m_bodies.begin(), m_bodies.end(), maxWeight))->ToString();
		return EXIT_SUCCESS;
	}
}

bool CControle::FindSmallestWeightBodyInWater(istream &args)
{
	if (m_bodies.empty())
	{
		m_output << "Error. Bodies are not exist\n";
		return EXIT_FAILURE;
	}
	else
	{
		auto minWeight = [](shared_ptr<CBody> const &first, shared_ptr<CBody> const &second)
		{
			const double WATER_DENSITY = 1000;
			const double GRAVITATIONAL_ACCELERATION = 9.8f;
			return ((first->GetDensity() - WATER_DENSITY) * GRAVITATIONAL_ACCELERATION * first->GetVolume()) <
				((second->GetDensity() - WATER_DENSITY) * GRAVITATIONAL_ACCELERATION * second->GetVolume());
		};
		m_output << "Body with smallest weight in water is " << (*min_element(m_bodies.begin(), m_bodies.end(), minWeight))->ToString();
		return EXIT_SUCCESS;
	}
}

double CControle::GetWeight(shared_ptr<CBody> &body, const double &waterDensity, const double &gravitationalAcceleration)
{
    return (body->GetDensity() - waterDensity) * gravitationalAcceleration * body->GetVolume();
}

bool CControle::Help(istream &args)
{
	m_output << "Welcome to system of Volume Bodies.\nInstructions for use:\nEnter the figure and its parameters separated by spaces (Example: Sphere 5 5)\nAdditional commands:\n -FindLargestWeightBody\n - FindSmallestWeightBodyInWater\n - PrintBodies\n Good luck!\n";
	return EXIT_SUCCESS;
}