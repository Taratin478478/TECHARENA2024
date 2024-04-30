#ifndef TECHARENA2024_SOLVER_H
#define TECHARENA2024_SOLVER_H

#endif //TECHARENA2024_SOLVER_H

#include <vector>

struct UserInfo {
    int rbNeed;
    int beam;
    int id;

    UserInfo(int rbNeed = 0, int beam = 0, int id = 0): rbNeed{rbNeed}, beam{beam}, id{id} {}
};

struct Interval {
    int start, end;
    std::vector<int> users;

    Interval(int start = 0, int end = 0): start{start}, end{end} {}
};

struct Gap {
    int start{}, end{}, size{};
    Gap(int start = 0, int end = 0, int size = 0): start{start}, end{end}, size{size} {}
};

std::vector<Interval>
Solver(int N, int M, int K, int J, int L, std::vector<Interval> reservedRBs, std::vector<UserInfo> userInfos);