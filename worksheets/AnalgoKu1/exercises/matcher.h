#ifndef MATCHER_H
#define MATCHER_H

#include <map>
#include <queue>
#include <vector>

class Matcher {
public:
  typedef std::vector<std::string> PrefList;
  typedef std::map<std::string, PrefList> PrefMap;
  typedef std::map<std::string, std::string> Couples;

  Matcher(const PrefMap &_male, const PrefMap &_female)
      : male(_male), female(_female) {}
  Couples getMatch();

private:
  PrefMap male;
  PrefMap female;

  bool prefers(const PrefList &, const std::string &, const std::string &);
};

bool Matcher::prefers(const PrefList &prefList, const std::string &firstPref,
                      const std::string &secondPref) {
  for (const std::string &pref : prefList) {
    if (pref == firstPref)
      return true;
    if (pref == secondPref)
      return false;
  }
  return false;
}

Matcher::Couples Matcher::getMatch() {
  std::queue<std::string> bachelors;
  Couples engaged;

  for (const auto &malePref : male) {
    bachelors.push(malePref.first);
  }

  while (!bachelors.empty()) {
    const std::string &suitor = bachelors.front();
    const PrefList &prefList = male[suitor];

    for (const std::string &pref : prefList) {
      const std::string &bride = pref;

      if (engaged.find(bride) == engaged.end()) {
        engaged[bride] = suitor;
        break;
      }

      const std::string &groom = engaged[bride];

      if (prefers(female[bride], suitor, groom)) {
        bachelors.push(groom);
        engaged[bride] = suitor;
        break;
      }
    }
    bachelors.pop();
  }
  return engaged;
}

#endif