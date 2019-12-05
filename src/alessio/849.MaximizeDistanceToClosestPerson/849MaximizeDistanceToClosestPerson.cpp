#include <bits/stdc++.h>

using namespace std;

int maxDistToClosest(vector<int> &seats)
{
    vector<int> temp;

    for (int i = 0; i < seats.size(); i++)
        if (seats[i] == 1)
            temp.push_back(i);

    if (temp.size() == 0)
        return seats.size();

    int maxRes = temp[0];
    for (int i = 0; i < temp.size() - 1; i++)
    {
        int check = temp[i + 1] - temp[i];
        if (check > maxRes)
            maxRes = check;
    }
    int rightMax = seats.size() - temp.back() - 1;
    int leftMax = temp[0];
    int tempMax = max(leftMax, rightMax);

    return max(maxRes / 2, tempMax);
}

int main()
{
    vector<int> seats = {0, 1, 0, 1, 0};
    cout << maxDistToClosest(seats) << endl;

    return 0;
}
