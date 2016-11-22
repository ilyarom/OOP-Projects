#include "stdafx.h"
#include "../car/Car.h"


struct CarFixture
{
    CCar car;
};

BOOST_FIXTURE_TEST_SUITE(Car, CarFixture)

    BOOST_AUTO_TEST_CASE(engine_switched_off)
    {
        BOOST_CHECK(!car.IsTurnOnEngine());
    }

	BOOST_AUTO_TEST_SUITE(engine_switch_off)

		BOOST_AUTO_TEST_CASE(engine_switch_on_when_it_switch_off)
		{
			BOOST_CHECK(car.TurnOnEngine());
		}

		BOOST_AUTO_TEST_CASE(can_not_engine_switch_off)
		{
			BOOST_CHECK(!car.TurnOffEngine());
		}	

		BOOST_AUTO_TEST_CASE(default_gear_is_neutral)
		{
			BOOST_CHECK_EQUAL(car.GetGear(), 0);
		}

		BOOST_AUTO_TEST_CASE(default_speed_is_zero)
		{
			BOOST_CHECK_EQUAL(car.GetSpeed(), 0);
		}

		BOOST_AUTO_TEST_CASE(can_set_neutral_gear_when_it_switched_off)
		{
			BOOST_CHECK(car.SetGear(0));
		}

		BOOST_AUTO_TEST_CASE(cant_not_set_back_gear_when_engine_switched_off)
		{
			BOOST_CHECK(!car.SetGear(-1));
		}

		BOOST_AUTO_TEST_CASE(can_not_set_speed_when_engine_switched_off)
		{
			BOOST_CHECK(!car.SetSpeed(10));
		}

	BOOST_AUTO_TEST_SUITE_END()

    struct carSwitchedOn : CarFixture
    {
        carSwitchedOn()
        {
            car.TurnOnEngine();
        }
    };
    BOOST_FIXTURE_TEST_SUITE(engine_switched_on, carSwitchedOn)

		BOOST_AUTO_TEST_SUITE(get_functions)
		    BOOST_AUTO_TEST_CASE(should_be_neutral_when_engine_started)
			{
			    BOOST_CHECK_EQUAL(car.GetGear(), 0);
		    }

			BOOST_AUTO_TEST_CASE(should_be_zero_when_engine_started)
			{
				BOOST_CHECK_EQUAL(car.GetSpeed(), 0);
			}
		BOOST_AUTO_TEST_SUITE_END()


		BOOST_AUTO_TEST_SUITE(set_functions)
			BOOST_AUTO_TEST_SUITE(set_gear_function)


				BOOST_AUTO_TEST_CASE(set_gears_when_engine_started)
				{
					BOOST_CHECK(car.SetGear(1) && !car.SetGear(5) && car.SetGear(-1) && !car.SetGear(99));
				}

				BOOST_AUTO_TEST_CASE(can_set_second_gear_with_meet_speed)
				{
					car.SetGear(1);
					car.SetSpeed(20);
					BOOST_CHECK(car.SetGear(2));
				}

				BOOST_AUTO_TEST_CASE(can_not_set_second_gear_with_unmeet_speed)
				{
					car.SetGear(1);
					car.SetSpeed(10);
					BOOST_CHECK(!car.SetGear(2));
				}

				BOOST_AUTO_TEST_CASE(can_set_back_gear_when_setted_first_gear)
				{
					car.SetGear(1);
					car.SetSpeed(0);
					BOOST_CHECK(car.SetGear(-1));
				}

				BOOST_AUTO_TEST_CASE(can_not_set_back_gear_when_current_gear_is_second)
				{
					car.SetGear(1);
					car.SetSpeed(20);
					car.SetGear(2);
					BOOST_CHECK(!car.SetGear(-1));
				}

				BOOST_AUTO_TEST_CASE(can_not_set_first_gear_when_car_moves_back)
				{
					car.SetGear(-1);
					car.SetSpeed(10);
					BOOST_CHECK(!car.SetGear(1));
				}

			BOOST_AUTO_TEST_SUITE_END()

			BOOST_AUTO_TEST_SUITE(set_speed_function)

				BOOST_AUTO_TEST_CASE(can_set_meet_speed_in_first_gear)
				{
					car.SetGear(1);
					BOOST_CHECK(car.SetSpeed(20));
				}

				BOOST_AUTO_TEST_CASE(can_not_set_unmeet_speed_in_first_gear)
				{
					car.SetGear(1);
					BOOST_CHECK(!car.SetSpeed(80));
				}

				BOOST_AUTO_TEST_CASE(can_set_meet_speed_in_back_gear)
				{
					car.SetGear(-1);
					BOOST_CHECK(car.SetSpeed(20));
				}

				BOOST_AUTO_TEST_CASE(can_not_set_unmeet_speed_in_back_gear)
				{
					car.SetGear(-1);
					BOOST_CHECK(!car.SetSpeed(80));
				}

				BOOST_AUTO_TEST_CASE(can_not_set_speed_in_neutral_gear)
				{
					BOOST_CHECK(!car.SetSpeed(15));
				}

				BOOST_AUTO_TEST_CASE(can_set_smaller_speed_in_neutral_gear)
				{
					car.SetGear(1);
					car.SetSpeed(30);
					car.SetGear(0);
					BOOST_CHECK(car.SetSpeed(5));
				}

			BOOST_AUTO_TEST_SUITE_END()

		BOOST_AUTO_TEST_SUITE_END()

		BOOST_AUTO_TEST_SUITE(start_and_stop_engine)

			BOOST_AUTO_TEST_CASE(engine_can_not_be_switched_on)
			{
				BOOST_CHECK(!car.TurnOnEngine());
			}

			BOOST_AUTO_TEST_CASE(engine_can_be_switched_off)
			{
				BOOST_CHECK(car.TurnOffEngine());
			}

			BOOST_AUTO_TEST_CASE(engine_can_not_switched_off_in_first_gear)
			{
				car.SetGear(1);
				BOOST_CHECK(!car.TurnOffEngine());
			}

			BOOST_AUTO_TEST_CASE(engine_can_not_switched_off_in_neutral_gear_and_speed)
			{
				car.SetGear(1);
				car.SetSpeed(20);
				car.SetGear(0);
				BOOST_CHECK(!car.TurnOffEngine());
			}

		BOOST_AUTO_TEST_SUITE_END()
		
    BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
