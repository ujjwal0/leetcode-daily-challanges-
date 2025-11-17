bool kLengthApart(vector<int> &nums, int k)
{
    int a = -1;
    int diff = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            if (a == -1)
            {
                a = i;
                diff = 0;
            }
            else if (diff < k)
                return false;
            else
            {
                diff = 0;
                a = i;
            }
        }
        else
        {
            diff++;
        }
    }
    return true;
}