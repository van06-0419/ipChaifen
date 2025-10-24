#include "ipChaifen.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <tuple>
#include <algorithm>

std::vector<std::string> chaifen(const std::string& s, char fengefu) {
    std::vector<std::string> words;
    // Вектор для хранения всех подстрок после разделения
    std::string word;
    // Временная переменная для хранения одной подстроки
    std::istringstream zifuchuanliu(s);
    // Создаём поток ввода из строки, чтобы считывать части по разделителю

    while (std::getline(zifuchuanliu, word, fengefu)) {
        words.push_back(word);
    }

    return words;
}


std::vector<std::tuple<int, int, int, int>> duqu_and_jaingxu_ip(std::istream& is) {
    std::vector<std::tuple<int, int, int, int>> ips;
    std::string line;

    while (std::getline(is, line)) {
        size_t tabdeweizhi = line.find('\t');

        std::string ip_str;
        if (tabdeweizhi != std::string::npos) {
            ip_str = line.substr(0, tabdeweizhi);
        }
        else ip_str = line;

        std::vector<std::string> cfhderesult = chaifen(ip_str, '.');
        if (cfhderesult.size() != 4) continue;

        try {
            int b1 = std::stoi(cfhderesult[0]);
            int b2 = std::stoi(cfhderesult[1]);
            int b3 = std::stoi(cfhderesult[2]);
            int b4 = std::stoi(cfhderesult[3]);

            if (b1 >= 0 && b1 <= 255 && b2 >= 0 && b2 <= 255 &&
                b3 >= 0 && b3 <= 255 && b4 >= 0 && b4 <= 255)
                ips.emplace_back(b1, b2, b3, b4);
        }
        catch (...) {
            continue;
            }
    }

    std::sort(ips.begin(), ips.end(),
        [](const std::tuple<int, int, int, int>& a,
            const std::tuple<int, int, int, int>& b) {
                return a > b;
        }
        );
    return ips;
}

std::vector<std::tuple<int, int, int, int>> diyidyValue(
    const std::vector<std::tuple<int, int, int, int>>& ips,
    int value) {
    std::vector<std::tuple<int,int,int,int>> diyifuhederesult;
    std::copy_if(ips.begin(), ips.end(), std::back_inserter(diyifuhederesult),
        [value](const std::tuple<int, int, int, int>& ip) {
            return std::get<0>(ip) == value;
        }
    );
    return diyifuhederesult;
}

std::vector<std::tuple<int, int, int, int>> qianliadyValue(
    const std::vector<std::tuple<int, int, int, int>>& ips,
    int first, int second) {
    std::vector<std::tuple<int, int, int, int>> qianliafuhederesult;
    std::copy_if(ips.begin(), ips.end(), std::back_inserter(qianliafuhederesult),
        [first,second](const std::tuple<int, int, int, int>& ip) {
            return std::get<0>(ip) == first && std::get<1>(ip) == second;
        }
    );
    return qianliafuhederesult;
}

std::vector<std::tuple<int, int, int, int>> renyidyValue(
    const std::vector<std::tuple<int, int, int, int>>& ips,
    int value) {
    std::vector<std::tuple<int, int, int, int>> renyifuhederesult;
    std::copy_if(ips.begin(), ips.end(), std::back_inserter(renyifuhederesult),
        [value](const std::tuple<int, int, int, int>& ip) {
            return std::get<0>(ip) == value || std::get<1>(ip) == value ||
                    std::get<2>(ip) == value || std::get<3>(ip) == value;
        }
    );
    return renyifuhederesult;
}

void print_ips(const std::vector<std::tuple<int, int, int, int>>& ips) {
    for (size_t i = 0; i < ips.size(); i++) {
        std::tuple<int, int, int, int> ip = ips[i];

        std::cout 
            << std::get<0>(ip) << "."
            << std::get<1>(ip) << "."
            << std::get<2>(ip) << "." 
            << std::get<3>(ip) << "\n";
    }
}
