#include <iostream>
#include "matcher.h"

const std::vector<std::vector<std::string>> rawMaleData = {
  {"Victor",  "Bertha", "Amy", "Diane", "Erika", "Clare"},
  {"Wyatt",   "Diane", "Bertha", "Amy", "Clare", "Erika"},
  {"Xavier",  "Bertha", "Erika", "Clare", "Diane", "Amy"},
  {"Yancey",  "Amy", "Diane", "Clare", "Bertha", "Erika"},
  {"Zeus",    "Bertha", "Diane", "Amy", "Erika", "Clare"}
};
 
const std::vector<std::vector<std::string>> rawFemaleData = {
  {"Amy",     "Zeus", "Victor", "Wyatt", "Yancey", "Xavier"},
  {"Bertha",  "Xavier", "Wyatt", "Yancey", "Victor", "Zeus"},
  {"Clare",   "Wyatt", "Xavier", "Yancey", "Zeus", "Victor"},
  {"Diane",   "Victor", "Zeus", "Yancey", "Xavier", "Wyatt"},
  {"Erika",   "Yancey", "Wyatt", "Zeus", "Xavier", "Victor"}
};

int main(int argc, char const *argv[]) {
  Matcher::PrefMap malePref;
  Matcher::PrefMap femalePref;

  for(size_t i = 0; i < rawMaleData.size(); ++i) {
    for (size_t j = 1; j < rawMaleData[i].size(); ++j) {
      malePref[rawMaleData[i][0]].push_back(rawMaleData[i][j]);
      femalePref[rawFemaleData[i][0]].push_back(rawMaleData[i][j]);
    }
  }

  Matcher matcher(malePref, femalePref);

  for(const auto &match : matcher.getMatch()) {
    std::cout << match.first << "\t-\t" << match.second << '\n';
  }

  return 0;
}
