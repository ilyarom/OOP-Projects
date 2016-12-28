#include "stdafx.h"
#include "../lab6/StringList.h"

using namespace std;

struct EmptyStringList
{
	CStringList list;
};

BOOST_FIXTURE_TEST_SUITE(String_list, EmptyStringList)
	BOOST_AUTO_TEST_CASE(empty_list)
	{
		BOOST_CHECK_EQUAL(list.GetSize(), 0);
		BOOST_CHECK(list.isEmpty());
		BOOST_REQUIRE_THROW(list.Delete(list.begin()), runtime_error);
		BOOST_REQUIRE_NO_THROW(list.Insert("hello", list.begin()));
		BOOST_REQUIRE_NO_THROW(list.Clear());
		BOOST_REQUIRE_THROW(list.GetBackElement(), out_of_range);
		BOOST_REQUIRE_THROW(list.GetFrontElement(), out_of_range);
	}

	BOOST_AUTO_TEST_SUITE(after_appending_a_string)
		BOOST_AUTO_TEST_CASE(increases_its_size_by_1)
		{
			auto oldSize = list.GetSize();
			list.AppendBack("hello");
			BOOST_CHECK_EQUAL(list.GetSize(), oldSize + 1);
			list.AppendBack("hello");
			BOOST_CHECK_EQUAL(list.GetSize(), oldSize + 2);
		}
		BOOST_AUTO_TEST_CASE(makes_it_accessible_via_GetBackElement_method)
		{
			list.AppendBack("hello");
			BOOST_CHECK_EQUAL(list.GetBackElement(), "hello");
			list.AppendBack("goodbye");
			BOOST_CHECK_EQUAL(list.GetBackElement(), "goodbye");
		}
		BOOST_AUTO_TEST_CASE(makes_it_accessible_via_iterator_to_first_element)
		{
			list.AppendBack("hello");
			auto it = list.begin();
			BOOST_CHECK_EQUAL(addressof(*it), addressof(list.GetBackElement()));
		}
		BOOST_AUTO_TEST_CASE(makes_it_accessible_via_iterator_to_last_element)
		{
			list.AppendBack("goodbye");
			auto it = list.begin();
			BOOST_CHECK_EQUAL(addressof(*it), addressof(list.GetBackElement()));
		}
	BOOST_AUTO_TEST_SUITE_END()
	BOOST_AUTO_TEST_SUITE(after_appending_a_string_to_front)
		BOOST_AUTO_TEST_CASE(increases_its_size_by_1)
		{
			auto oldSize = list.GetSize();
			list.AppendFront("hello");
			BOOST_CHECK_EQUAL(list.GetSize(), oldSize + 1);
			list.AppendFront("hello");
			BOOST_CHECK_EQUAL(list.GetSize(), oldSize + 2);
		}
		BOOST_AUTO_TEST_CASE(makes_it_accessible_via_GetFrontElement_method)
		{
			list.AppendFront("hello");
			BOOST_CHECK_EQUAL(list.GetFrontElement(), "hello");
			list.AppendFront("goodbye");
			BOOST_CHECK_EQUAL(list.GetFrontElement(), "goodbye");
		}
		BOOST_AUTO_TEST_CASE(makes_it_accessible_via_iterator_to_first_element)
		{
			list.AppendFront("hello");
			auto it = list.begin();
			BOOST_CHECK_EQUAL(addressof(*it), addressof(list.GetFrontElement()));
		}
	BOOST_AUTO_TEST_SUITE_END()
	BOOST_AUTO_TEST_SUITE(iterator)
		BOOST_AUTO_TEST_CASE(can_be_increnenting)
		{
			list.AppendBack("first");
			list.AppendBack("second");
			auto iter = list.begin();
			BOOST_CHECK_EQUAL(*iter, "first");
			++iter;
			BOOST_CHECK_EQUAL(*iter, "second");
		}
	BOOST_AUTO_TEST_SUITE_END()
		

	struct FilledStringList
	{
		CStringList list;
		FilledStringList()
		{
			list.AppendBack("first");
			list.AppendBack("second");
			list.AppendBack("third");
		}
		std::vector<std::string> exemplaryString = { "first", "second", "third" };
	};
	BOOST_FIXTURE_TEST_SUITE(filled_string_list, FilledStringList)
		BOOST_AUTO_TEST_CASE(can_go_though_list)
		{
			size_t index = 0;
			for (auto iter = list.begin(); iter != list.end(); ++iter)
			{
				BOOST_CHECK(*iter == exemplaryString[index]);
				++index;
			}
		}
		BOOST_AUTO_TEST_CASE(can_go_through_list_with_reverse_iterators)
		{
			size_t index = list.GetSize() - 1;
			for (auto iter = list.rbegin(); iter != list.rend(); --iter)
			{
				BOOST_CHECK(*iter == exemplaryString[index]);
				--index;
			}
		}
		BOOST_AUTO_TEST_CASE(can_get_front_element)
		{
			BOOST_CHECK_EQUAL(list.GetFrontElement(), "first");
			list.Insert("second", list.begin());
			BOOST_CHECK_EQUAL(list.GetFrontElement(), "second");
		}
		BOOST_AUTO_TEST_CASE(can_get_back_element)
		{
			BOOST_CHECK_EQUAL(list.GetBackElement(), "third");
			list.Insert("fourth", list.end());
			BOOST_CHECK_EQUAL(list.GetBackElement(), "fourth");
		}
		BOOST_AUTO_TEST_CASE(can_get_size_of_list)
		{
			auto size = list.GetSize();
			list.Insert("fourth", list.end());
			BOOST_CHECK_EQUAL(list.GetSize(), size + 1);
		}
		BOOST_AUTO_TEST_CASE(can_insert_element)
		{
			list.Insert("super-first", list.begin());
			BOOST_CHECK_EQUAL(*list.begin(), "super-first");

			auto it = ++list.begin();
			list.Insert("half", it);
			BOOST_CHECK_EQUAL(*(++list.begin()), "half");

			list.Insert("fourth", list.end());


			it = --(++(++(list.begin())));
			list.Insert("quarter", it);
			BOOST_CHECK_EQUAL(*(--(++(++(list.begin())))), "quarter");


			std::vector<std::string> exemplaryStrings = { "super-first", "quarter" ,"half" , "first", "second", "third", "fourth"};
			size_t i = 0;
			for (auto str : list)
			{
				BOOST_CHECK_EQUAL(str, exemplaryStrings[i]);
				i++;
			}
		}

		BOOST_AUTO_TEST_CASE(can_delete_element)
		{
			auto it = --(++(++list.begin()));
			list.Delete(it);
			BOOST_CHECK_EQUAL(*list.begin(), "first");
			BOOST_CHECK_EQUAL(*++list.begin(), "third");

			list.Delete(list.begin());
			BOOST_CHECK_EQUAL(*list.begin(), "third");

			list.Delete(list.end());
			BOOST_CHECK(list.isEmpty());
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()