#include <vector>
#include <algorithm>

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
Solver(int N, int M, int K, int J, int L, std::vector<Interval> reservedRBs, std::vector<UserInfo> userInfos) {
    std::vector<Interval> answer;
    std::vector<Gap> gaps;
    int left = 0, right;
    for (auto &x : reservedRBs) {
        right = x.start;
        gaps.emplace_back(left, right, right - left);
        left = x.end;
    }
    gaps.emplace_back(left, M, M - left);
    int delta = 20;
    bool can_place, placed;
    auto userInfosSorted{userInfos};
    std::sort(userInfosSorted.begin(), userInfosSorted.end(), [](auto &a, auto &b) {return a.rbNeed > b.rbNeed;});
    for (auto &u: userInfosSorted) {
        placed = false;
        for (auto &interval: answer) {
            int int_size = interval.end - interval.start;
            if (interval.users.size() < L && u.rbNeed <= int_size) {
                can_place = true;
                for (auto id: interval.users) {
                    if (u.beam == userInfos[id].beam) {
                        can_place = false;
                        break;
                    }
                }
                if (can_place) {
                    interval.users.push_back(u.id);
                    placed = true;
                    break;
                }
            }
        }
        if (!placed && answer.size() != J) {
            std::sort(gaps.begin(), gaps.end(), [](auto &a, auto &b){return a.size > b.size;});
            int new_int_size = std::min(u.rbNeed, gaps[0].size);
            Interval new_int{gaps[0].start, gaps[0].start + new_int_size};
            new_int.users.push_back(u.id);
            answer.push_back(new_int);
            gaps[0].start += new_int_size;
            gaps[0].size -= new_int_size;
        } //891000
        /*
        if (!placed && answer.size() != J) {
            std::sort(gaps.begin(), gaps.end(), [](auto &a, auto &b){return a.size > b.size;});
            auto it = gaps.begin();
            while (it != gaps.end() && it->size >= u.rbNeed) {
                ++it;
            }
            if (it != gaps.begin()) {
                --it;
            }
            int new_int_size = std::min(u.rbNeed, it->size);
            Interval new_int{it->start, it->start + new_int_size};
            new_int.users.push_back(u.id);
            answer.push_back(new_int);
            it->start += new_int_size;
            it->size -= new_int_size;
        }
         */ //890972
    }
    return answer;
}

