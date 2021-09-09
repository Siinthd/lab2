#include "ip_filter.h"
// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]

std::ostream& operator<<(std::ostream& os, const pool& data)
{

	for (auto ip = data.cbegin(); ip != data.cend(); ++ip)
	{
		for (auto ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
		{
			if (ip_part != ip->cbegin())
			{
				os << ".";
			}
			os << *ip_part;
		}
		os << std::endl;
	}
	return os;
}

std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

pool filter(const pool& ip_pool,int first)
{
	pool out;

		for (const auto& ip: ip_pool)
		{
			if(ip[0] == first)
				out.push_back(ip);
		}
	return out;
}

pool filter(const pool& ip_pool, int first,int second)
{
	pool out;

	for (const auto& ip : ip_pool)
	{
		if (ip[0] == first && ip[1] == second)
			out.push_back(ip);
	}
	return out;
}

pool filter_any(const pool& ip_pool, int value)
{
	pool out;

	for (const auto& ip : ip_pool)
	{
		auto result = std::find(begin(ip), end(ip), value);
		if(result != std::end(ip))
			out.push_back(ip);


	}
	return out;
}

