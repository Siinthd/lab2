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


#endif //IP_FILTER_H
