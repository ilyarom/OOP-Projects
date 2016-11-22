#include "stdafx.h"
#include "Driver.h"
#include "Car.h"

using namespace std;
using namespace std::placeholders;

CDriver::CDriver(CCar &car, std::istream &input, std::ostream &output)
    : m_car(car)
    , m_input(input)
    , m_output(output)
    , m_actionMap({ {"Info", bind(&CDriver::Info, this, _1)}, 
                    {"EngineOn", bind(&CDriver::EngineOn, this, _1)},
                    {"EngineOff", bind(&CDriver::EngineOff, this, _1)},
                    {"SetGear", bind(&CDriver::SetGear, this, _1)},
                    { "SetSpeed", bind(&CDriver::SetSpeed, this, _1) }
})
{
}

bool CDriver::HandleCommand()
{
    string line;
    getline(m_input, line);
    istringstream strm(line);

    string action;
    strm >> action;

    auto it = m_actionMap.find(action);
    if (it != m_actionMap.end())
    {
        return it->second(strm);
    }
    return false;
}

bool CDriver::EngineOn(std::istream & /*args*/)
{
	if (!m_car.TurnOnEngine())
	{
		m_output << "Engine is already turn on";
	}
    return true;
}

bool CDriver::EngineOff(std::istream & /*args*/)
{
	if (!m_car.TurnOffEngine())
	{
		m_output << "Engine can't turn off";
	}
    return true;
}

bool CDriver::SetGear(std::istream & args)
{
    int gear;
    args >> gear;
    if (!m_car.SetGear(gear))
	{
		m_output << "Engine is switch off or this gear can not be settle\n";
    }
    return true;
}

bool CDriver::SetSpeed(std::istream & args)
{
    int speed;
    args >> speed;
    if (!m_car.SetSpeed(speed))
    {
		m_output << "The car can't accelerate to that speed in this gear";
	}
    return true;
}

bool CDriver::Info(std::istream & /*args*/)
{
	string info = m_car.Info();
	m_output << info;
	return true;
}
