#pragma once
#include <boost/noncopyable.hpp>

class CCar;

// Наследование от boost::noncopyable - явный способ запретить копирование и присваивание экземпляров класса
class CDriver : boost::noncopyable
{
public:
    CDriver(CCar & car, std::istream & input, std::ostream & output);

    bool HandleCommand();

private:
    bool Info(std::istream & args);
    bool EngineOn(std::istream & args);
    bool EngineOff(std::istream & args);
    bool SetGear(std::istream & args);
    bool SetSpeed(std::istream & args);

    typedef std::map<std::string, std::function<bool(std::istream & args)>> ActionMap;

    CCar & m_car;
    std::istream & m_input;
    std::ostream & m_output;

    const ActionMap m_actionMap;
};

