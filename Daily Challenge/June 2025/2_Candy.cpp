class Solution {
public:
  int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> downPoints;
    for (int i = 1; i + 1 < n; ++i) {
      if (ratings[i] <= ratings[i - 1] and ratings[i] <= ratings[i + 1]) {
        downPoints.push_back(i);
      }
    }

    vector<int> candies(n, -1);
    auto setLeft = [&] (int index) {
      while (index >= 0) {
        if (ratings[index] > ratings[index + 1]) {
          candies[index] = max(candies[index], candies[index + 1] + 1);
        } else if (ratings[index] == ratings[index + 1]) {
          candies[index] = max(candies[index], 1);
        } else {
          break;
        }
        --index;
      }
    };

    auto setRight = [&] (int index) {
      while (index < n) {
        if (ratings[index] > ratings[index - 1]) {
          candies[index] = max(candies[index], candies[index - 1] + 1);
        } else if (ratings[index] == ratings[index - 1]) {
          candies[index] = max(candies[index], 1);
        } else {
          break;
        }
        ++index;
      }
    };

    for (int point : downPoints) {
      candies[point] = 1;
      setLeft(point - 1);
      setRight(point + 1);
    }

    if (candies[0] == -1 and candies[n - 1] == -1) {
      if (ratings[0] < ratings[n - 1]) {
        candies[0] = 1;
        setRight(1);
        if (candies[n - 1] == -1) {
          candies[n - 1] = 1;
          setLeft(n - 2);
        }
      } else {
        candies[n - 1] = 1;
        setLeft(n - 2);
        if (candies[0] == -1) {
          candies[0] = 1;
          setRight(1);
        }
      }
    } else if (candies[0] == -1) {
      candies[0] = 1;
      setRight(1);
    } else if (candies[n - 1] == -1) {
      candies[n - 1] = 1;
      setLeft(n - 2);
    }

    int totalCandies = 0;
    for (int candy : candies) {
      totalCandies += candy;
    }

    return totalCandies;
  }
};