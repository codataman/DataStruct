#include<vector>
#include<iostream>

using namespace std;

class Solution
{
public:
	int maxCoins(vector<int>& nums) {

		int n = nums.size();

		// �����µ�����,�������ڵ�0��i + 1
		vector<int> points(n + 2, 1);

		for (int i = 1; i <= n; i++)
		{
			points[i] = nums[i - 1];
		}


		// ���嶯̬�滮������
		// dp[i][j]�ĺ����Ǵ���(i, j)��Χ��������Ի��Ӳ�ҵ��������
		vector<vector<int>>dp(n + 2, vector<int>(n + 2, 0));

		// ��i�������Ͻ�����ټ���
		for (int i = n; i >= 0; i--)
		{
			// ��j�����ҽ��б���
			for (int j = i + 1; j < n + 2; j++)
			{
				// ״̬ת��,������Ƶ�k������ʱ,�����Ӳ������
				for (int k = i + 1; k < j; k++)
				{
					dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + points[i] * points[k] * points[j]);
				}
			}
		}

		return dp[0][n + 1];
	}
};

int test_maxCoins() {

	vector<int> nums{3, 1, 5, 8};

	Solution solution;

	cout << solution.maxCoins(nums) << endl;

	return 0;
}