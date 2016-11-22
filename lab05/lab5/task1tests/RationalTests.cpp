// task1tests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../task1/Rational.h"

BOOST_AUTO_TEST_CASE(Test_Greates_Common_Denominator)
{
	BOOST_CHECK_EQUAL(GCD(2, 3), 1u);
	BOOST_CHECK_EQUAL(GCD(3, 2), 1u);
	BOOST_CHECK_EQUAL(GCD(12, 8), 4u);
	BOOST_CHECK_EQUAL(GCD(8, 12), 4u);
	BOOST_CHECK_EQUAL(GCD(0, 2), 2u);
	BOOST_CHECK_EQUAL(GCD(2, 0), 2u);
	BOOST_CHECK_EQUAL(GCD(0, 0), 1u);
}



/*
  Рациональное число:
	равно нулю по умолчанию (0/1)
	может быть созданно из целого в формате (n / 1)
	может быть задано с указанием числителя и знаменателя
	хранится в нормализованном виде
	*/

void VerifyRational(const CRational & r, int expectedNumerator, int expectedDenominator)
{
	BOOST_CHECK_EQUAL(r.GetNumerator(), expectedNumerator);
	BOOST_CHECK_EQUAL(r.GetDenominator(), expectedDenominator);
}

BOOST_AUTO_TEST_SUITE(Rational_number)
	BOOST_AUTO_TEST_CASE(is_0_by_default)
	{
		VerifyRational(CRational(), 0, 1);
	}
	BOOST_AUTO_TEST_CASE(can_be_constructed_from_whole)
	{
		VerifyRational(CRational(10), 10, 1);
		VerifyRational(CRational(-10), -10, 1);
		VerifyRational(CRational(0), 0, 1);
	}
	BOOST_AUTO_TEST_CASE(can_be_constructed_with_numerator_and_denominator)
	{
		VerifyRational(CRational(5, 2), 5, 2);
		VerifyRational(CRational(-5, 2), -5, 2);
		VerifyRational(CRational(5, -2), -5, 2);
		VerifyRational(CRational(-5, -2), 5, 2);
	}
	BOOST_AUTO_TEST_CASE(is_normalized_after_construction)
	{
		VerifyRational(CRational(6, 8), 3, 4);
		VerifyRational(CRational(6, -8), -3, 4);
		VerifyRational(CRational(-6, 8), -3, 4);
		VerifyRational(CRational(-6, -8), 3, 4);
		VerifyRational(CRational(-10, 20), -1, 2);
	}
	BOOST_AUTO_TEST_CASE(cant_have_zero_denominator)
	{
		BOOST_REQUIRE_THROW(CRational(1, 0), std::invalid_argument);
	}

	BOOST_AUTO_TEST_SUITE(Convert_to_double)

		BOOST_AUTO_TEST_CASE(can_convert_to_double)
		{
			CRational r(7, 10);
			BOOST_CHECK_CLOSE_FRACTION(r.ToDouble(), 0.7, 0.1);
		}

		BOOST_AUTO_TEST_CASE(can_convert_to_double_round)
		{
			CRational r(1, 3);
			BOOST_CHECK_CLOSE_FRACTION(r.ToDouble(), 0.33, 0.1);
		}

		BOOST_AUTO_TEST_CASE(can_convert_to_double_negative)
		{
			CRational r(-7, 10);
			BOOST_CHECK_CLOSE_FRACTION(r.ToDouble(), -0.7, 0.1);
		}

	BOOST_AUTO_TEST_SUITE_END()
	
	BOOST_AUTO_TEST_SUITE(unary_operators)
		BOOST_AUTO_TEST_CASE(unary_plus_can_return_current_rational_positive)
		{
			CRational r1(1, 4);
			CRational r2 = +r1;
			VerifyRational(r2, 1, 4);
		}
		BOOST_AUTO_TEST_CASE(unary_plus_can_return_current_rational_negative)
		{
			CRational r1(-1, 4);
			CRational r2 = +r1;
			VerifyRational(r2, -1, 4);
		}

		BOOST_AUTO_TEST_CASE(unary_minus_can_return_opposite_number_positive)
		{
			CRational r1(1, 4);
			CRational r2 = -r1;
			VerifyRational(r2, -1, 4);
		}
		BOOST_AUTO_TEST_CASE(unary_minus_can_return_opposite_number_negative)
		{
			CRational r1(-1, 4);
			CRational r2 = -r1;
			VerifyRational(r2, 1, 4);
		}

		BOOST_AUTO_TEST_CASE(unary_minus_can_return_current_rational_when_it_used_2_times)
		{
			CRational r1(1, 4);
			CRational r2 = -r1;
			CRational r3 = -r2;
			VerifyRational(r3, 1, 4);
		}

	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(binary_plus)
		BOOST_AUTO_TEST_CASE(can_summarize_two_rational)
		{
			const CRational r1(1, 3);
			const CRational r2(1, 3);
			CRational result = r1 + r2;
			VerifyRational(result, 2, 3);
		}

		BOOST_AUTO_TEST_CASE(can_summarize_two_rational_with_different_denominator)
		{
			const CRational r1(1, 3);
			const CRational r2(2, 6);
			CRational result = r1 + r2;
			VerifyRational(result, 2, 3);
		}

		BOOST_AUTO_TEST_CASE(can_subtract_numbers_with_plus_operator)
		{
			const CRational r1(1, 3);
			const CRational r2(-1, 6);
			CRational result = r1 + r2;
			VerifyRational(result, 1, 6);
		}

		BOOST_AUTO_TEST_CASE(can_summarize_rational_and_whole)
		{
			const int i = 1;
			const CRational r(1, 3);
			CRational result = r + i;
			VerifyRational(result, 4, 3);
		}

		BOOST_AUTO_TEST_CASE(can_summarize_rational_and_negative_whole)
		{
			const int i = -1;
			const CRational r(4, 3);
			CRational result = r + i;
			VerifyRational(result, 1, 3);
		}

		BOOST_AUTO_TEST_CASE(can_summarize_negative_rational_and_whole)
		{
			const int i = 1;
			const CRational r(-1, 3);
			CRational result = r + i;
			VerifyRational(result, 2, 3);
		}

		BOOST_AUTO_TEST_CASE(can_summarize_whole_and_rational)
		{
			const int i = 1;
			const CRational r(1, 3);
			CRational result = i + r;
			VerifyRational(result, 4, 3);
		}

		BOOST_AUTO_TEST_CASE(can_summarize_negative_whole_and_rational)
		{
			const int i = -1;
			const CRational r(1, 3);
			CRational result = i + r;
			VerifyRational(result, -2, 3);
		}

		BOOST_AUTO_TEST_CASE(can_summarize_whole_and_negative_rational)
		{
			const int i = 1;
			const CRational r(-1, 3);
			CRational result = i + r;
			VerifyRational(result, 2, 3);
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(binary_minus)
		BOOST_AUTO_TEST_CASE(can_subtract_two_rational)
		{
			const CRational r1(2, 3);
			const CRational r2(1, 3);
			CRational result = r1 - r2;
			VerifyRational(result, 1, 3);
		}

		BOOST_AUTO_TEST_CASE(can_subtract_two_rational_with_different_denominator)
		{
			const CRational r1(2, 3);
			const CRational r2(3, 6);
			CRational result = r1 - r2;
			VerifyRational(result, 1, 6);
		}

		BOOST_AUTO_TEST_CASE(can_summarize_numbers_with_subtract_operator)
		{
			const CRational r1(1, 3);
			const CRational r2(-3, 6);
			CRational result = r1 - r2;
			VerifyRational(result, 5, 6);
		}

		BOOST_AUTO_TEST_CASE(can_subtract_rational_and_whole)
		{
			const int i = 1;
			const CRational r(4, 3);
			CRational result = r - i;
			VerifyRational(result, 1, 3);
		}

		BOOST_AUTO_TEST_CASE(can_subtract_rational_and_negative_whole)
		{
			const int i = -1;
			const CRational r(4, 3);
			CRational result = r - i;
			VerifyRational(result, 7, 3);
		}

		BOOST_AUTO_TEST_CASE(can_subtract_negative_rational_and_whole)
		{
			const int i = 1;
			const CRational r(-1, 3);
			CRational result = r - i;
			VerifyRational(result, -4, 3);
		}

		BOOST_AUTO_TEST_CASE(can_subtract_whole_and_rational)
		{
			const int i = 1;
			const CRational r(1, 3);
			CRational result = i - r;
			VerifyRational(result, 2, 3);
		}

		BOOST_AUTO_TEST_CASE(can_subtract_negative_whole_and_rational)
		{
			const int i = -1;
			const CRational r(1, 3);
			CRational result = i - r;
			VerifyRational(result, -4, 3);
		}

		BOOST_AUTO_TEST_CASE(can_subtract_whole_and_negative_rational)
		{
			const int i = 1;
			const CRational r(-1, 3);
			CRational result = i - r;
			VerifyRational(result, 4, 3);
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(increase)
		BOOST_AUTO_TEST_CASE(can_increase_two_rational)
		{
			CRational r1(1, 3);
			const CRational r2(1, 3);
			r1 += r2;
			VerifyRational(r1, 2, 3);
		}

		BOOST_AUTO_TEST_CASE(can_increase_two_rational_with_different_denominator)
		{
			CRational r1(2, 3);
			const CRational r2(3, 6);
			r1 += r2;
			VerifyRational(r1, 7, 6);
		}

		BOOST_AUTO_TEST_CASE(can_reduce_numbers_with_increase_operator)
		{
			CRational r1(1, 3);
			const CRational r2(-3, 6);
			r1 += r2;
			VerifyRational(r1, -1, 6);
		}

		BOOST_AUTO_TEST_CASE(can_increase_rational_and_whole)
		{
			const int i = 1;
			CRational r(1, 3);
			r += i;
			VerifyRational(r, 4, 3);
		}

		BOOST_AUTO_TEST_CASE(can_increase_rational_and_negative_whole)
		{
			const int i = -1;
			CRational r(4, 3);
			r += i;
			VerifyRational(r, 1, 3);
		}

		BOOST_AUTO_TEST_CASE(can_increase_negative_rational_and_whole)
		{
			const int i = 1;
			CRational r(-1, 3);
			r += i;
			VerifyRational(r, 2, 3);
		}

	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(decrease)
		BOOST_AUTO_TEST_CASE(can_decrease_two_rational)
		{
			CRational r1(2, 3);
			const CRational r2(1, 3);
			r1 -= r2;
			VerifyRational(r1, 1, 3);
		}

		BOOST_AUTO_TEST_CASE(can_decrease_two_rational_with_different_denominator)
		{
			CRational r1(2, 3);
			const CRational r2(3, 6);
			r1 -= r2;
			VerifyRational(r1, 1, 6);
		}

		BOOST_AUTO_TEST_CASE(can_increase_numbers_with_decrease_operator)
		{
			CRational r1(1, 3);
			const CRational r2(-3, 6);
			r1 -= r2;
			VerifyRational(r1, 5, 6);
		}

		BOOST_AUTO_TEST_CASE(can_decrease_rational_and_whole)
		{
			const int i = 1;
			CRational r(4, 3);
			r -= i;
			VerifyRational(r, 1, 3);
		}

		BOOST_AUTO_TEST_CASE(can_decrease_rational_and_negative_whole)
		{
			const int i = -1;
			CRational r(1, 3);
			r -= i;
			VerifyRational(r, 4, 3);
		}

		BOOST_AUTO_TEST_CASE(can_decrease_negative_rational_and_whole)
		{
			const int i = 1;
			CRational r(-1, 3);
			r -= i;
			VerifyRational(r, -4, 3);
		}

	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(multiplication)
		BOOST_AUTO_TEST_CASE(can_multiplicate_two_rational)
		{
			const CRational r1(2, 3);
			const CRational r2(1, 3);
			CRational result = r1 * r2;
			VerifyRational(result, 2, 9);
		}

		BOOST_AUTO_TEST_CASE(can_multiplicate_two_rational_negative)
		{
			const CRational r1(-2, 3);
			const CRational r2(1, 3);
			CRational result = r1 * r2;
			VerifyRational(result, -2, 9);
		}

		BOOST_AUTO_TEST_CASE(can_multiplicate_rational_and_whole)
		{
			const int i = 2;
			const CRational r(1, 3);
			CRational result = r * i;
			VerifyRational(result, 2, 3);
		}

		BOOST_AUTO_TEST_CASE(can_multiplicate_rational_and_negative_whole)
		{
			const int i = -2;
			const CRational r(1, 3);
			CRational result = r * i;
			VerifyRational(result, -2, 3);
		}

		BOOST_AUTO_TEST_CASE(can_multiplicate_negative_rational_and_whole)
		{
			const int i = 2;
			const CRational r(-1, 3);
			CRational result = r * i;
			VerifyRational(result, -2, 3);
		}

		BOOST_AUTO_TEST_CASE(can_multiplicate_whole_and_rational)
		{
			const int i = 2;
			const CRational r(1, 3);
			CRational result = i * r;
			VerifyRational(result, 2, 3);
		}

		BOOST_AUTO_TEST_CASE(can_multiplicate_negative_whole_and_rational)
		{
			const int i = -2;
			const CRational r(1, 3);
			CRational result = i * r;
			VerifyRational(result, -2, 3);
		}

		BOOST_AUTO_TEST_CASE(can_multiplicate_whole_and_negative_rational)
		{
			const int i = 2;
			const CRational r(-1, 3);
			CRational result = i * r;
			VerifyRational(result, -2, 3);
		}

	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(division)
		BOOST_AUTO_TEST_CASE(can_divide_two_rational)
		{
			const CRational r1(1, 3);
			const CRational r2(2, 3);
			CRational result = r1 / r2;
			VerifyRational(result, 1, 2);
		}

		BOOST_AUTO_TEST_CASE(can_divide_two_rational_negative)
		{
			const CRational r1(-2, 3);
			const CRational r2(1, 3);
			CRational result = r1 / r2;
			VerifyRational(result, -2, 1);
		}

		BOOST_AUTO_TEST_CASE(can_divide_rational_and_whole)
		{
			const int i = 2;
			const CRational r(1, 3);
			CRational result = r / i;
			VerifyRational(result, 1, 6);
		}

		BOOST_AUTO_TEST_CASE(can_divide_rational_and_negative_whole)
		{
			const int i = -2;
			const CRational r(1, 3);
			CRational result = r / i;
			VerifyRational(result, -1, 6);
		}

		BOOST_AUTO_TEST_CASE(can_divide_negative_rational_and_whole)
		{
			const int i = 2;
			const CRational r(-1, 3);
			CRational result = r / i;
			VerifyRational(result, -1, 6);
		}

		BOOST_AUTO_TEST_CASE(can_divide_whole_and_rational)
		{
			const int i = 2;
			const CRational r(1, 3);
			CRational result = i / r;
			VerifyRational(result, 6, 1);
		}

		BOOST_AUTO_TEST_CASE(can_divide_negative_whole_and_rational)
		{
			const int i = -2;
			const CRational r(1, 3);
			CRational result = i / r;
			VerifyRational(result, -6, 1);
		}

		BOOST_AUTO_TEST_CASE(can_divide_whole_and_negative_rational)
		{
			const int i = 2;
			const CRational r(-1, 3);
			CRational result = i / r;
			VerifyRational(result, -6, 1);
		}
		BOOST_AUTO_TEST_CASE(can_not_divide_for_zero)
		{
			const int i = 0;
			const CRational r(-1, 3);
			BOOST_REQUIRE_THROW((r / i), std::invalid_argument);
		}

	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(augmenting)
		BOOST_AUTO_TEST_CASE(can_augment_two_rational)
		{
			CRational r1(2, 3);
			const CRational r2(1, 3);
			r1 *= r2;
			VerifyRational(r1, 2, 9);
		}

		BOOST_AUTO_TEST_CASE(can_augment_two_rational_negative)
		{
			CRational r1(-2, 3);
			const CRational r2(1, 3);
			r1 *= r2;
			VerifyRational(r1, -2, 9);
		}

		BOOST_AUTO_TEST_CASE(can_augment_rational_and_whole)
		{
			const int i = 2;
			CRational r(1, 3);
			r *= i;
			VerifyRational(r, 2, 3);
		}

		BOOST_AUTO_TEST_CASE(can_augment_rational_and_negative_whole)
		{
			const int i = -2;
			CRational r(1, 3);
			r *= i;
			VerifyRational(r, -2, 3);
		}

		BOOST_AUTO_TEST_CASE(can_augment_negative_rational_and_whole)
		{
			const int i = 2;
			CRational r(-1, 3);
			r *= i;
			VerifyRational(r, -2, 3);
		}

	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(sharing)
		BOOST_AUTO_TEST_CASE(can_share_two_rational)
		{
			CRational r1(2, 3);
			const CRational r2(1, 3);
			r1 /= r2;
			VerifyRational(r1, 2, 1);
		}

		BOOST_AUTO_TEST_CASE(can_share_two_rational_negative)
		{
			CRational r1(-2, 3);
			const CRational r2(1, 3);
			r1 /= r2;
			VerifyRational(r1, -2, 1);
		}

		BOOST_AUTO_TEST_CASE(can_share_rational_and_whole)
		{
			const int i = 2;
			CRational r(1, 3);
			r /= i;
			VerifyRational(r, 1, 6);
		}

		BOOST_AUTO_TEST_CASE(can_share_rational_and_negative_whole)
		{
			const int i = -2;
			CRational r(1, 3);
			r /= i;
			VerifyRational(r, -1, 6);
		}

		BOOST_AUTO_TEST_CASE(can_share_negative_rational_and_whole)
		{
			const int i = 2;
			CRational r(-1, 3);
			r /= i;
			VerifyRational(r, -1, 6);
		}

		BOOST_AUTO_TEST_CASE(can_share_with_zero_denominator_)
		{
			const int i = 0;
			CRational r(-1, 3);
			BOOST_REQUIRE_THROW((r /= i), std::invalid_argument);
		}

	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(equivalence)
		BOOST_AUTO_TEST_CASE(can_check_equal_rations)
		{
			const CRational r(4, 1);
			BOOST_CHECK(r == r);
		}

		BOOST_AUTO_TEST_CASE(can_not_check_equal_rations)
		{
			const CRational r1(4, 1);
			const CRational r2(3, 1);
			BOOST_CHECK(!(r1 == r2));
		}

		BOOST_AUTO_TEST_CASE(can_check_equivalence_with_not_equal_operator)
		{
			const CRational r(-4, -1);
			BOOST_CHECK(!(r != r));
		}

		BOOST_AUTO_TEST_CASE(can_check_not_a_equivalence_with_not_equal_operator)
		{
			const CRational r1(4, 1);
			const CRational r2(3, 1);
			BOOST_CHECK(r1 != r2);
		}

		BOOST_AUTO_TEST_CASE(can_check_equal_of_rational_and_whole)
		{
			int i = 4;
			const CRational r(8, 2);
			BOOST_CHECK(r == i);
		}

		BOOST_AUTO_TEST_CASE(can_not_equal_of_rational_and_whole_negative)
		{
			int i = -4;
			const CRational r(8, 2);
			BOOST_CHECK(r != i);
		}

		BOOST_AUTO_TEST_CASE(is_equal_of_rational_and_whole_negative)
		{
			int i = -4;
			const CRational r(-8, 2);
			BOOST_CHECK(r == i);
		}

		BOOST_AUTO_TEST_CASE(can_not_equal_of_whole_and_rational)
		{
			int i = -4;
			const CRational r(8, 2);
			BOOST_CHECK(i != r);
		}

		BOOST_AUTO_TEST_CASE(is_equal_of_whole_negative_and_rational)
		{
			int i = -4;
			const CRational r(-8, 2);
			BOOST_CHECK(i == r);
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(inequivalence)
		BOOST_AUTO_TEST_CASE(can_check_is_smaller)
		{
			const CRational r1(4, 1);
			const CRational r2(5, 1);
			BOOST_CHECK(r1 < r2);
		}

		BOOST_AUTO_TEST_CASE(can_check_is_not_smaller)
		{
			const CRational r1(4, 1);
			const CRational r2(3, 1);
			BOOST_CHECK(!(r1 < r2));
		}

		BOOST_AUTO_TEST_CASE(can_check_is_larger)
		{
			const CRational r1(5, 1);
			const CRational r2(4, 1);
			BOOST_CHECK(r1 > r2);
		}

		BOOST_AUTO_TEST_CASE(can_check_is_not_larger)
		{
			const CRational r1(-4, 1);
			const CRational r2(-3, 1);
			BOOST_CHECK(!(r1 > r2));
		}

		BOOST_AUTO_TEST_CASE(can_check_is_smaller_with_double_sign)
		{
			const CRational r1(-5, 1);
			const CRational r2(-4, 1);
			BOOST_CHECK(r1 <= r2);
		}

		BOOST_AUTO_TEST_CASE(can_check_is_not_smaller_with_double_sign)
		{
			const CRational r1(4, 1);
			const CRational r2(3, 1);
			BOOST_CHECK(!(r1 <= r2));
		}

		BOOST_AUTO_TEST_CASE(can_check_is_larger_with_double_sign)
		{
			const CRational r1(5, 1);
			const CRational r2(4, 1);
			BOOST_CHECK(r1 >= r2);
		}

		BOOST_AUTO_TEST_CASE(can_check_is_not_larger_with_double_sign)
		{
			const CRational r1(3, 1);
			const CRational r2(4, 1);
			BOOST_CHECK(!(r1 >= r2));
		}

		BOOST_AUTO_TEST_CASE(can_check_with_equal_larger_sign)
		{
			const CRational r1(3, 1);
			const CRational r2(3, 1);
			BOOST_CHECK(r1 >= r2);
		}

		BOOST_AUTO_TEST_CASE(can_check_with_equal_smaller_sign)
		{
			const CRational r1(-2, 1);
			const CRational r2(-2, 1);
			BOOST_CHECK(r1 >= r2);
		}
	

		BOOST_AUTO_TEST_CASE(can_check_is_smaller_rational_whole)
		{
			const CRational r(4, 1);
			const int i = 8;
			BOOST_CHECK(r < i);
		}

		BOOST_AUTO_TEST_CASE(can_check_is_not_smaller_rational_whole)
		{
			const CRational r(4, 1);
			const int i = 2;
			BOOST_CHECK(!(r < i));
		}

		BOOST_AUTO_TEST_CASE(can_check_is_larger_rational_whole)
		{
			const CRational r(4, 1);
			const int i = 2;
			BOOST_CHECK(r > i);
		}

		BOOST_AUTO_TEST_CASE(can_check_is_not_larger_rational_whole)
		{
			const CRational r(4, 1);
			const int i = 8;
			BOOST_CHECK(!(r > i));
		}

		BOOST_AUTO_TEST_CASE(can_check_is_smaller_with_double_sign_rational_whole)
		{
			const CRational r(4, 1);
			const int i = 8;
			BOOST_CHECK(r <= i);
		}

		BOOST_AUTO_TEST_CASE(can_check_is_not_smaller_with_double_sign_rational_whole)
		{
			const CRational r(4, 1);
			const int i = 2;
			BOOST_CHECK(!(r <= i));
		}

		BOOST_AUTO_TEST_CASE(can_check_is_larger_with_double_sign_rational_whole)
		{
			const CRational r(4, 1);
			const int i = 2;
			BOOST_CHECK(r >= i);
		}

		BOOST_AUTO_TEST_CASE(can_check_is_not_larger_with_double_sign_rational_whole)
		{
			const CRational r(4, 1);
			const int i = 8;
			BOOST_CHECK(!(r >= i));
		}

		BOOST_AUTO_TEST_CASE(can_check_with_equal_larger_sign_rational_whole)
		{
			const CRational r(4, 1);
			const int i = 4;
			BOOST_CHECK(r >= i);
		}

		BOOST_AUTO_TEST_CASE(can_check_with_equal_smaller_sign_rational_whole)
		{
			const CRational r(4, 1);
			const int i = 4;
			BOOST_CHECK(r >= i);
		}

		BOOST_AUTO_TEST_CASE(can_check_is_smaller_whole_rational)
		{
			const CRational r(4, 1);
			const int i = 2;
			BOOST_CHECK(i < r);
		}

		BOOST_AUTO_TEST_CASE(can_check_is_not_smaller_whole_rational)
		{
			const CRational r(4, 1);
			const int i = 8;
			BOOST_CHECK(!(i < r));
		}

		BOOST_AUTO_TEST_CASE(can_check_is_larger_whole_rational)
		{
			const CRational r(4, 1);
			const int i = 8;
			BOOST_CHECK(i > r);
		}

		BOOST_AUTO_TEST_CASE(can_check_is_not_larger_whole_rational)
		{
			const CRational r(4, 1);
			const int i = 2;
			BOOST_CHECK(!(i > r));
		}

		BOOST_AUTO_TEST_CASE(can_check_is_smaller_with_double_sign_whole_rational)
		{
			const CRational r(4, 1);
			const int i = 2;
			BOOST_CHECK(i <= r);
		}

		BOOST_AUTO_TEST_CASE(can_check_is_not_smaller_with_double_sign_whole_rational)
		{
			const CRational r(4, 1);
			const int i = 8;
			BOOST_CHECK(!(i <= r));
		}

		BOOST_AUTO_TEST_CASE(can_check_is_larger_with_double_sign_whole_rational)
		{
			const CRational r(4, 1);
			const int i = 8;
			BOOST_CHECK(i >= r);
		}

		BOOST_AUTO_TEST_CASE(can_check_is_not_larger_with_double_sign_whole_rational)
		{
			const CRational r(4, 1);
			const int i = 2;
			BOOST_CHECK(!(i >= r));
		}

		BOOST_AUTO_TEST_CASE(can_check_with_equal_larger_sign_whole_rational)
		{
			const CRational r(4, 1);
			const int i = 4;
			BOOST_CHECK(i >= r);
		}

		BOOST_AUTO_TEST_CASE(can_check_with_equal_smaller_sign_whole_rational)
		{
			const CRational r(4, 1);
			const int i = 4;
			BOOST_CHECK(i >= r);
		}
	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()



//////////////////////////////////////////////////////////////////////////
// TODO: 1. Реализовать метод ToDouble() согласно заданию
// Возвращает отношение числителя и знаменателя в виде числа double
// Пример использования:
//	CRational r(3, 5)
//	cout << r.ToDouble(); // Должно вывести 0.6
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 2. Реализовать унарный + и унарный -
// Указание: см. материалы к лекции
// Пример использования:
//	const CRational r1(3, 5);
//	CRational r2 = -r1; // r2 должно стать -3/5
//	assert(r2.GetNumerator(), -3);
//	assert(r2.GetDenominator(), 5);
//	CRational r3 = +r2; // r3 также равно -3/5
//	assert(r3.GetNumerator(), -3);
//	assert(r3.GetDenominator(), 5);
// Унарный минус возвращает раицональное число без знака
// Унарный плюс возвращает рациональное число, равное текущему
// Реализация не должна допускать операции вроде:
//  -someRational = someOtherRational;
//	+someRational = someOtherRational;
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 3. Реализовать бинарный +
// Возвращает результат сложения двух рациональных чисел, 
//	рационального числа с целым, целого числа с рациональным.
//	(1/2) + (1/6) = (2/3)
//	(1/2) + 1     = (3/2)
//	1 + (1/2)     = (3/2)
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 4. Реализовать бинарный -
// Возвращает разность двух рациональных чисел, 
//	рационального числа и целого, либо целого числа и рационального:
//	(1/2) - (1/6) = (1/3)
//	(1/2) - 1     = (-1/2)
//	1 - (1/2)     = (1/2)
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 5. Реализовать оператор +=
// Выполняет увеличение рационального числа на величину второго рационального,
//	либо целого числа:
//	(1/2) += (1/6)  → (2/3)
//	(1/2) += 1      → (3/2)
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 6. Реализовать оператор -=
// Выполняет уменьшение рационального числа на величину второго рационального либо целого числа :
// (1/2) -= (1/6)  → (1/3)
// (1/2) -= 1      → (-1/2)
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 7. Реализовать оператор *
// Возвращает результат произведения рациональных чисел, 
//	рационального и целого, либо целого и рационального :
//	(1/2) * (2/3) = (1/3)
//	(1/2) * (-3)  = (-3/2)
//	7 * (2/3)     = (14/3)
//////////////////////////////////////////////////////////////////////////





//////////////////////////////////////////////////////////////////////////
// TODO: 8. Реализовать оператор /
// Возвращает частное двух рациональных чисел, 
//	рационального и целого, целого и рационального :
//	(1/2) ⁄ (2/3) = (3/4)
//	(1/2) ⁄ 5     = (1/10)
//	7 ⁄ (2/3)     = (21/2)
//////////////////////////////////////////////////////////////////////////





//////////////////////////////////////////////////////////////////////////
// TODO: 9. Реализовать оператор *=
// Умножает значение первого рационального числа на другое рациональное, 
//	либо целое:
//	(1/2) *= (2/3) → (1/3)
//	(1/2) *= 3     → (3/2)
//////////////////////////////////////////////////////////////////////////





//////////////////////////////////////////////////////////////////////////
// TODO: 10. Реализовать оператор /=
// Делит первое рациональное число на другое рациональное, 
//	либо целое:
//	(1/2) /= (2/3) → (3/4)
//	(3/4) /= (3/8) → (2/1)
//	(1/2) /= 3     → (1/6)
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 11. Реализовать операторы == и !=
// Проверяют равенство (и неравенство) двух рациональных чисел, 
//	целого и рационального, рационального и целого:
//	(1/2) == (1/2) → true
//	(4/1) == 4     → true
//	3 == (3/1)     → true
//	(1/2) != (2/3) → true
//	(1/2) != 7     → true
//	3 != (2/3)     → true
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 12. Реализовать операторы <, >, <=, >=
// Сравнивают два рациональных числа, рациональное с целым, 
//	целое с рациональным:
//	(1/2) >= (1/3) → true
//	(1/2) <= (1/3) → false
//	(3/1) > 2      → true
//	(1/2) < 7      → true
//	3 <= (7/2)     → true
//	3 >= (8/2)     → false
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 13. Реализовать оператор вывода рационального числа в выходной поток 
//	std::ostream в формате <числитель>/<знаменатель>, 
//	например: 7/15
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 14. Реализовать оператор ввода рационального числа из входного потока 
//	std::istream в формате <числитель>/<знаменатель>, 
//	например: 7/15
//////////////////////////////////////////////////////////////////////////

