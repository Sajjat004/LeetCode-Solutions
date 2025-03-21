class Solution {
public:
  vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
    unordered_set<string> suppliesSet(supplies.begin(), supplies.end());

    queue<int> recipesQueue;
    for (int i = 0; i < recipes.size(); ++i) {
      recipesQueue.push(i);
    }

    vector<string> createdRecipes;

    while (true) {
      int recipesQueueSize = recipesQueue.size();
      bool canCreateAtLeastOneRecipe = false;

      while (recipesQueueSize--) {
        int recipeIndex = recipesQueue.front();
        recipesQueue.pop();

        bool canCreateRecipe = true;
        for (auto& ingredient : ingredients[recipeIndex]) {
          if (suppliesSet.find(ingredient) == suppliesSet.end()) {
            canCreateRecipe = false;
            break;
          }
        }

        if (canCreateRecipe) {
          createdRecipes.push_back(recipes[recipeIndex]);
          suppliesSet.insert(recipes[recipeIndex]);
          canCreateAtLeastOneRecipe = true;
        } else {
          recipesQueue.push(recipeIndex);
        }
      }

      if (!canCreateAtLeastOneRecipe) {
        break;
      }
    }

    return createdRecipes;
  }
};