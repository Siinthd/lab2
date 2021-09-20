#ifndef IP_FILTER_H
#define	IP_FILTER_H

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
////////
#include <fstream>
#include <algorithm>


using pool = std::vector<std::vector<int>>;

std::ostream& operator<<(std::ostream& os, const pool& data);

std::vector<std::string> split(const std::string &str, char d);

pool filter(const pool& ip_pool,int first);
pool filter(const pool& ip_pool, int first,int second);
pool filter_any(const pool& ip_pool, int value);

template<typename... Args>
pool filter_strong(const pool& ip_pool,const Args&... args) {

    pool out;

    int xobj[sizeof...(args)] = {args ...};
	for (const auto& ip : ip_pool)
	{
		if (ip[0] == xobj[0] && ip[1] == xobj[1] && ip[2] == xobj[2])
			out.push_back(ip);
	}
	return out;

}


#endif //IP_FILTER_H
