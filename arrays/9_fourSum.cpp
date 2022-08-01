#include<iostream>
#include<vector>
#include<algorithm>

std::vector<std::vector<int>> fourSum(std::vector<int>& num, int target) {
    std::vector<std::vector<int> > res;

    if (num.empty())
        return res;
    int n = num.size();
    std::sort(num.begin(), num.end());

    for (int i = 0; i < n; i++) {

        int target_3 = target - num[i];

        for (int j = i + 1; j < n; j++) {

            int target_2 = target_3 - num[j];

            int front = j + 1;
            int back = n - 1;

            while (front < back) {

                int two_sum = num[front] + num[back];

                if (two_sum < target_2) front++;

                else if (two_sum > target_2) back--;

                else {

                    std::vector<int> quadruplet(4, 0);
                    quadruplet[0] = num[i];
                    quadruplet[1] = num[j];
                    quadruplet[2] = num[front];
                    quadruplet[3] = num[back];
                    res.push_back(quadruplet);

                    // Processing the duplicates of number 3
                    while (front < back && num[front] == quadruplet[2]) ++front;

                    // Processing the duplicates of number 4
                    while (front < back && num[back] == quadruplet[3]) --back;

                }
            }

            while (j + 1 < n && num[j + 1] == num[j]) ++j;
        }

        while (i + 1 < n && num[i + 1] == num[i]) ++i;

    }

    return res;
}


int main() {

    std::vector<int> v{ 1,0,-1,0,-2,2 };

    std::vector<std::vector<int>> sum = fourSum(v, 0);
    std::cout << "The unique quadruplets are" << std::endl;
    for (int i = 0; i < sum.size(); i++) {
        for (int j = 0; j < sum[i].size(); j++)
            std::cout << sum[i][j] << " ";
        std::cout << std::endl;
    }
}


