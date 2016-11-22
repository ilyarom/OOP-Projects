#include "stdafx.h"
#include "Car.h"

CCar::CCar()
	: m_isStart(false)
	, m_gear(0)
	, m_speed(0)
	, m_dir(0)
{}

bool CCar::IsTurnOnEngine()const
{
    return m_isStart;
}

bool CCar::TurnOnEngine()
{
	if (m_isStart)
	{
		return false;
	}
    m_isStart = true;
    return true;
}

bool CCar::TurnOffEngine()
{
    if (m_isStart && m_gear== 0 && m_speed == 0)
    {
        m_isStart = false;
        return true;
    }
    return false;
}

int CCar::GetGear()const
{
    return m_gear;
}

int CCar::GetSpeed() const
{
	return m_speed;
}

std::string CCar::GetDir()const
{
	std::string dir;

	switch (m_dir)
	{
	case -1:
		dir = "BACK";
	case 0:
		dir = "NONE";
	case 1:
		dir = "FORWARD";
	}

	return dir;
}


// refactor me
bool CCar::SetGear(int gear)
{
    if (!m_isStart && gear != 0)
    {
        return false;
    }
    if (!m_isStart && gear == 0)
    {
        return true;
    }

    if (m_isStart)
    {
	    switch (gear)
        {
        case -1:
            if (m_speed == 0 && (m_gear == 0 || m_gear == 1))
            {
                m_gear = -1;
                return true;
            }
			return false;

        case 0:
            m_gear = 0;
            return true;

        case 1:
            if ((m_gear == -1 && m_speed == 0) || (m_gear == 0 && m_dir == 0 && m_speed >= 0 && m_speed <= 30) || (m_dir == 1 && m_speed >= 0 && m_speed <= 30))
            {
                m_gear = 1;
                return true;
            }
            return false;

        case 2:
			if (m_speed >= 20 && m_speed <= 50)
			{
				m_gear = 2;
				return true;
			}
			return false;

        case 3:
			if (m_speed >= 30 && m_speed <= 60)
			{
				m_gear = 3;
				return true;
			}
			return false;

        case 4:
			if (m_speed >= 40 && m_speed <= 90)
			{
				m_gear = 4;
				return true;
			}
			return false;
        case 5:
			if (m_speed >= 50 && m_speed <= 150)
			{
				m_gear = 5;
				return true;
			}
			return false;
        }
    }
    return false;
}

// refactor me
bool CCar::SetSpeed(int speed)
{
    if (m_isStart)
    {
		switch (m_gear)
		{
		case -1:
			if (speed >= 0 && speed <= 20)
			{
				m_speed = speed;
				m_speed > 0 ? m_dir = -1 : m_dir = 0;
				return true;
			}
			return false;
		case 0:
			if (speed < m_speed)
			{
				m_speed = speed;
				if (m_speed == 0)
				{
					m_dir = 0;
				}
				return true;
			}
			return false;
		case 1:
			if (speed >= 0 && speed <= 30)
			{
				m_speed = speed;
				m_dir = 1;
				return true;
			}
			return false;
		case 2:
			if (speed >= 20 && speed <= 50)
			{
				m_speed = speed;
				m_dir = 1;
				return true;
			}
			return false;
		case 3:
			if (speed >= 30 && speed <= 60)
			{
				m_speed = speed;
				m_dir = 1;
				return true;
			}
			return false;
		case 4:
			if (speed >= 40 && speed <= 90)
			{
				m_speed = speed;
				m_dir = 1;
				return true;
			}
			return false;
		case 5:
			if (speed >= 50 && speed <= 150)
			{
				m_speed = speed;
				m_dir = 1;
				return true;
			}
			return false;
		}
    }
    return false;
}

std::string CCar::Info()
{
	std::string info = (m_isStart)
		? ("Engine is turned on\n + Gear is: " + std::to_string(GetGear()) + "\nSpeed is: " + std::to_string(GetSpeed()) + "\nDir is: " + GetDir())
		: "Engine is turned off\n";


	return info;
}


