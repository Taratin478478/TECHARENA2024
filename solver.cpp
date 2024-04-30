#include <vector>

struct UserInfo {
    int rbNeed;
    int beam;
    int id;
};
struct Interval {
    int start, end;
    std::vector<int> users;
};

std::vector<Interval>
Solver(int N, int M, int K, int J, int L, std::vector<Interval> reservedRBs, std::vector<UserInfo> userInfos) {
    std::vector<Interval> res(J);

    int NRB = M;
    for (auto &x : reservedRBs) {
        NRB -= x.end - x.start;
    }



    return res;
}