#include <iostream>
#include <vector>
#include <algorithm>

struct meeting {
    int start, end, pos;
};

bool comparator(struct meeting m1, struct meeting m2) {
    if (m1.end < m2.end) return true;
    else if (m1.end > m2.end) return false;
    else if (m1.pos < m2.pos) return true;
    return false;
}

std::vector<int> maxMeetings(std::vector<int> start_times, std::vector<int> end_times) {
    int n = start_times.size();
    struct meeting m[n];
    for (int i = 0; i < n; i++) {
        m[i].start = start_times[i];
        m[i].end = end_times[i];
        m[i].pos = i + 1;
    }

    std::sort(m, m + n, comparator);

    std::vector<int> result;
    int limit = m[0].end;
    result.push_back(m[0].pos);

    for (int i = 1; i < n; i++) {
        if (m[i].start > limit) {
            limit = m[i].end;
            result.push_back(m[i].pos);
        }
    }

    return result;
}

int main(int argc, char const* argv[]) {
    std::vector<int> start_times = { 1,3,0,5,8,5 };
    std::vector<int> end_times = { 2,4,5,7,9,9 };

    std::vector<int> res = maxMeetings(start_times, end_times);

    std::cout << "Meetings possible are : " << std::endl;
    for (auto& i : res) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
