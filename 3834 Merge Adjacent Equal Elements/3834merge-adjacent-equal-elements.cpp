class Solution
{
public:
    vector<long long> mergeAdjacent(vector<int> &nums)
    {
        vector<long long> Ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (Ans.empty() || Ans.back() != nums[i])
                Ans.push_back(nums[i]);

            else{
                long long num = nums[i];
                while (!Ans.empty() && Ans.back() == num){
                    num += Ans.back();
                    Ans.pop_back();
                }
                Ans.push_back(num);
            }
        }

        return Ans;
    }
};