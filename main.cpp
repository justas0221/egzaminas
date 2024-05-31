#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <sstream>
#include <vector>
#include <iomanip>
#include <regex>

void counterAndReference(std::stringstream &ss);
void findURL(std::stringstream &ss);

int main()
{
    std::stringstream ss;

    counterAndReference(ss);
    findURL(ss);

    return 0;
}

std::string cleanString(std::string s)
{
    std::string result;

    for(char c : s)
    {
        if (!std::iscntrl(c) && !std::ispunct(c) && !std::isdigit(c) && std::isalnum(c))
        {
            result += c;
        }
    }

    return result;
}

void counterAndReference(std::stringstream &ss)
{
    std::ifstream fd;
    fd.open("input.txt");
    ss << fd.rdbuf();
    fd.close();
    std::string x;
    std::unordered_map<std::string, int> counters;
    std::unordered_map<std::string, std::set<int>> references;


    int lineCount = 1;
    while(getline(ss, x))
    {
        std::istringstream iss(x);
        while(iss >> x)
        {
            std::string cleanedString = cleanString(x);
            if(!cleanedString.empty())
            {
                counters[cleanedString]++;
            }
            references[cleanedString].insert(lineCount);
        }
        lineCount++;
    }
    std::vector<std::pair<std::string, int>> v;

    for(auto &i : counters)
    {
        if(i.second > 1)
            v.push_back(make_pair(i.first, i.second));
    }

    std::sort(v.begin(), v.end(), [](auto &a, auto &b)
    {
        return a.second > b.second;
    });

    std::ofstream fr1("counter.txt");

    for(auto &i:v)
    {
        fr1 << std::left << std::setw(20) << i.first << i.second << std::endl;
    }

    fr1.close();

    std::ofstream fr2("cross-reference.txt");

    for(auto &i : v)
    {
        fr2 << std::left << std::setw(30) << i.first << " ";
        for(auto &j : references[i.first])
        {
            fr2 << j << " ";
        }
        fr2 << std::endl;
    }
    fr2.close();
}

void findURL(std::stringstream &ss)
{
    std::string text = ss.str();

    std::regex url_regex(R"((http|https)://([A-Za-z0-9.-]+)\.([A-Za-z]{2,})(:[0-9]{1,5})?(/.*)?|www\.([A-Za-z0-9.-]+)\.([A-Za-z]{2,})(:[0-9]{1,5})?(/.*)?|([A-Za-z0-9.-]+)\.([A-Za-z]{2,}))");
    std::ofstream fr3 ("url.txt");
    auto words_begin = std::sregex_iterator(text.begin(), text.end(), url_regex);
    auto words_end = std::sregex_iterator();

    std::unordered_map<std::string, bool> map;
    for (auto i = words_begin; i != words_end; ++i)
    {
        std::smatch match = *i;
        std::string url = match.str();
        if(!map[url])
        {
            map[url] = true;
        }
    }
    for(auto &i : map)
    {
        fr3 << i.first << std::endl ;
    }

    fr3.close();
}