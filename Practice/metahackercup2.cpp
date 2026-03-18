#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

bool is_ladder_sufficient(long long ladder_height, int num_platforms, const std::vector<int> &platform_heights)
{
    std::queue<int> q;
    std::vector<bool> visited(num_platforms, false);
    int visited_count = 0;

    for (int i = 0; i < num_platforms; ++i)
    {
        if (platform_heights[i] <= ladder_height)
        {
            q.push(i);
            visited[i] = true;
            visited_count++;
        }
    }

    while (!q.empty())
    {
        int current_platform = q.front();
        q.pop();

        int left_neighbor = current_platform - 1;
        if (left_neighbor >= 0 && !visited[left_neighbor])
        {
            long long height_diff = std::abs((long long)platform_heights[current_platform] - platform_heights[left_neighbor]);
            if (height_diff <= ladder_height)
            {
                visited[left_neighbor] = true;
                q.push(left_neighbor);
                visited_count++;
            }
        }

        int right_neighbor = current_platform + 1;
        if (right_neighbor < num_platforms && !visited[right_neighbor])
        {
            long long height_diff = std::abs((long long)platform_heights[current_platform] - platform_heights[right_neighbor]);
            if (height_diff <= ladder_height)
            {
                visited[right_neighbor] = true;
                q.push(right_neighbor);
                visited_count++;
            }
        }
    }

    return visited_count == num_platforms;
}

void solve_case()
{
    int num_platforms;
    std::cin >> num_platforms;
    std::vector<int> platform_heights(num_platforms);
    for (int i = 0; i < num_platforms; ++i)
    {
        std::cin >> platform_heights[i];
    }

    long long low = 0;
    long long high = 1e9 + 7;
    long long min_height = high;

    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        if (is_ladder_sufficient(mid, num_platforms, platform_heights))
        {
            min_height = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    std::cout << min_height << std::endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int num_test_cases;
    std::cin >> num_test_cases;
    for (int i = 1; i <= num_test_cases; ++i)
    {
        std::cout << "Case #" << i << ": ";
        solve_case();
    }

    return 0;
}