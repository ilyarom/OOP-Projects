#pragma once

enum Direction
{
	BACKWARD,
	FORWARD,
	STOP
};

class CCar
{
public:
	CCar::CCar();
	CCar::~CCar() = default;
    bool IsTurnOnEngine()const;
    bool TurnOnEngine();
    bool TurnOffEngine();
	int GetSpeed()const;
	int GetGear()const;
	std::string GetDir()const;
    bool SetGear(int gear);
    bool SetSpeed(int speed);
	std::string Info();
private:
	bool m_isStart;
    int m_gear;
    int m_dir;
    int m_speed;
};

