#include<vector>
#include<iostream>

using namespace std;

class Solution
{
public:
	int maxA(int N) {
		vector<int> dp(N + 1, 0);

		dp[0] = 0;

		for (int i = 1; i <= N; i++)
		{
			// ����A��
			dp[i] = dp[i - 1] + 1;

			// ����C-A��C-C��ϼ�
			for (int j = 2; j < i; j++)
			{
				// ȫѡ+���ƺ���Ļ��ʣ��dp[j-2]��A
				// ճ��j - i����Ļ�ϻ�����(i - j + 1) * dp[j-2]��A
				dp[i] = max(dp[i], dp[j - 2] * (i - j + 1));
			}
		}

		// �����Ļ��ʣ�µ�A�ĸ���
		return dp[N];
	}
};

int main() {
	Solution solution;

	cout << solution.maxA(3) << endl;

	cout << solution.maxA(7) << endl;

	return 0;
}