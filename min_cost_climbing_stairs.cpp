class Solution 
{
    public:
        int minCostClimbingStairs(vector<int>& cost) 
        {
            int minCost = 999;
            int stairCost[cost.size()];
            for (int i = cost.size() - 1; i >= 0; i--)
            {
                if ( i + 2 >= cost.size() || i + 1 >= cost.size() )
                {
                    stairCost[i] = cost[i];
                }
                else
                    stairCost[i] = cost[i] + min( stairCost[i + 1], stairCost[i + 2] );
                //cout << "stairCost[" << i << "]: " << stairCost[i] << endl;
            }

            return min( stairCost[0], stairCost[1] );
        }
};
