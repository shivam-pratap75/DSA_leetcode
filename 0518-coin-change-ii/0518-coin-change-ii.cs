public class Solution
{
    int[,] dp;

    public int Backtrack(int amount, int[] coins, int i)
    {
        if (amount == 0)
            return 1;

        if (amount < 0 || i >= coins.Length)
            return 0;

        if (dp[i, amount] != -1)
            return dp[i, amount];

        // Take
        int take = Backtrack(amount - coins[i], coins, i);

        // Skip
        int skip = Backtrack(amount, coins, i + 1);

        dp[i, amount] = take + skip;

        return dp[i, amount];
    }

    public int Change(int amount, int[] coins)
    {
        dp = new int[coins.Length, amount + 1];

        for (int i = 0; i < coins.Length; i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                dp[i, j] = -1;
            }
        }

        return Backtrack(amount, coins, 0);
    }
}