#ifndef IP_H
#define IP_H

#include <vector>
#include <tuple>
#include <istream>

std::vector<std::string> chaifen(const std::string& s, char fengefu);

std::vector<std::tuple<int, int, int, int>> duqu_and_jaingxu_ip(std::istream& is);

std::vector<std::tuple<int, int, int, int>> diyidyValue(
    const std::vector<std::tuple<int, int, int, int>>& ips,
    int value);

std::vector<std::tuple<int, int, int, int>> qianliadyValue(
    const std::vector<std::tuple<int, int, int, int>>& ips,
    int first, int second);

std::vector<std::tuple<int, int, int, int>> renyidyValue(
    const std::vector<std::tuple<int, int, int, int>>& ips,
    int value);

void print_ips(const std::vector<std::tuple<int, int, int, int>>& ips);

#endif
