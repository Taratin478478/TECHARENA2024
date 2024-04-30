#include <iostream>
#include "solver.h"
#include <vector>
#include <fstream>


int main() {
    std::ifstream in;
    in.open(R"(E:\Projects\TECHARENA2024\open.txt)");
    int NTests;
    in >> NTests;
    int N, M, K, J, L, begin, end, a, b;
    long long score, max_score, total_score = 0;
    std::vector<Interval> reservedRBs;
    std::vector<UserInfo> userInfos;
    for (int i = 0; i < NTests; ++i) {
        if (i == 982) {
            i = 982;
        }
        in >> N >> M >> K >> J >> L;
        for (int j = 0; j < K; ++j) {
            in >> begin >> end;
            reservedRBs.emplace_back(begin, end);
        }
        max_score = 0;
        for (int j = 0; j < N; ++j) {
            in >> a >> b;
            max_score += a;
            userInfos.emplace_back(a, b, j);
        }
        std::vector<Interval> answer = Solver(N, M, K, J, L, reservedRBs, userInfos);
        score = 0;
        for (auto &x: answer) {
            for (auto &y: x.users) {
                score += std::min(x.end - x.start, userInfos[y].rbNeed);
            }
        }
        std::cout << "test " << i << ": " << score << '/' << max_score << std::endl;
        total_score += score;
        reservedRBs.clear();
        userInfos.clear();
    }
    std::cout << "total score: " << total_score << std::endl;
    return 0;
}
