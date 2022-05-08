class Solution {
public:
    unordered_map <int, int> steps;
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        if (steps.find(n) != steps.end()){
            return steps.at(n);
        }

        int result = climbStairs(n - 1) + climbStairs(n - 2);
        steps.insert({n , result});

        return result;

    }
};
