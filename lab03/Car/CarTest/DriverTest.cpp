#include "stdafx.h"
#include "../Car/Driver.h"
#include "../Car/Car.h"
#include <sstream>
#include <boost/optional.hpp>

using namespace std;
using boost::optional;
using boost::none;

// «ависимости RemoteControl-а вынесены в родительскую структуру,
// чтобы гарантировать их создание до конструировани€ самого remote-контрола
struct CDriverDependencies
{
	CCar car;
	stringstream input;
	stringstream output;
};

struct DriverFixture : CDriverDependencies
{
	CDriver remoteControl;

	DriverFixture()
		: remoteControl(car, input, output)
	{
	}

	// ¬спомогательна€ функци€ дл€ проверки работы команды command
	// ќна принимает ожидаемый номер канала expectedChannel и expectedOutput
	void VerifyCommandHandling(const string& command, const string& expectedOutput)
	{
		// ѕредварительно очищаем содержимое выходного потока
		output = stringstream();
		input = stringstream();
		BOOST_CHECK(input << command);
		BOOST_CHECK(remoteControl.HandleCommand());
		BOOST_CHECK(input.eof());
		BOOST_CHECK_EQUAL(output.str(), expectedOutput);
	}
};

BOOST_FIXTURE_TEST_SUITE(Car_controller, DriverFixture)

	BOOST_AUTO_TEST_CASE(can_handle_EngineOn_command)
	{
		VerifyCommandHandling("EngineOn", "");
	}

	BOOST_AUTO_TEST_CASE(can_turn_off_car_which_is_on)
	{
		car.TurnOnEngine();
		VerifyCommandHandling("EngineOff", "");
	}


	BOOST_AUTO_TEST_CASE(can_print_Info_command_when_car_turn_on)
	{
		car.TurnOnEngine();
		car.SetGear(1);
		car.SetSpeed(20);
		VerifyCommandHandling("Info", "Engine is turned on\n + Gear is: 1\nSpeed is: 20\nDir is: FORWARD");
	}

	BOOST_AUTO_TEST_CASE(can_print_Info_command_when_car_turn_off)
	{
		VerifyCommandHandling("Info", "Engine is turned off\n");
	}


BOOST_AUTO_TEST_SUITE_END()