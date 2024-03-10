class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int sum = 0;
        int n = nums.size();
        int max = 0;
        vector<int> indices;

        // find maximum
        // we need to find the maximum number in the nums vector so that we may skip through
        // sums that would be impossible to add to our target in order to save time.
        // example: target is 19999, 1 + 10000 could not add to 19999, so we may skip i = 1.
        for ( int i = 0; i < n; i++ )
        {
            if ( nums[i] > max )
                max = nums[i];
        }

        cout << "max: " << max << endl;

        for ( int i = 0; i < n; i++ )
        {
            if ( nums[i] < (target - max) && max < target )
                continue;
            for ( int j = i + 1; j < n; j++ )
            {
                cout << nums[i] << " + " << nums[j] << " = " << nums[i] + nums[j] << endl;
                if ( nums[i] + nums[j] == target )
                {
                    indices.push_back(i);
                    indices.push_back(j);
                    return indices;
                }
            }
        }
        return indices;
    }
};
