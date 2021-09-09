
#define BOOST_TEST_MODULE FilterTest
#include <boost/test/unit_test.hpp>

#include "ip_filter.h"
#include <iterator>


std::vector<std::vector<int>> input  {{186,125,174,10},
					{113,182,239,185},
					{106,67,36,120},
					{189,100,88,211},
					{184,170,35,121},
					{181,215,20,38},
					{185,3,147,64},
					{187,64,27,167},
					{73,55,95,93},
					{45,32,140,209},
					{37,110,213,11},
					{177,32,68,231},
					{203,192,225,115},
					{189,181,251,184},
					{82,199,206,151},
					{73,224,202,251},
					{75,90,211,217},
					{173,211,75,55},
					{115,221,10,154},
					{190,39,83,68},
					{112,124,39,77},
					{5,189,200,175},
					{181,169,25,33},
					{202,166,194,217}};



BOOST_AUTO_TEST_CASE(filter1)
{
std::sort(input.begin(), input.end(), std::greater<std::vector<int>>());

std::vector<std::vector<int>> values = filter(input,73);

std::vector<std::vector<int>> expected {{73,224,202,251},
	    				{73,55,95,93}};
	    				
BOOST_TEST(values == expected);
}

BOOST_AUTO_TEST_CASE(filter2)
{

std::sort(input.begin(), input.end(), std::greater<std::vector<int>>());
std::vector<std::vector<int>> values = filter(input,181,215);
std::vector<std::vector<int>> expected {{181,215,20,38}};

BOOST_TEST(values == expected);

}

BOOST_AUTO_TEST_CASE(filterany)
{
std::sort(input.begin(), input.end(), std::greater<std::vector<int>>());
std::vector<std::vector<int>> values = filter_any(input,173);
std::vector<std::vector<int>> expected {{173,211,75,55}};

BOOST_TEST(values == expected);


}


