// 542. 01 Matrix

class Solution
{
public:
	vector<vector<int> > mem;
	int delta[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	int m, n;

	vector<vector<int> > updateMatrix(vector<vector<int> > &mat)
	{
		vector<vector<int> > res;

		m = mat.size();
		n = mat[0].size();

		for (int i = 0; i < m; i++)
		{
			mem.push_back(vector<int>(n, 1e5));
		}

		queue<pair<int, int> > q; // {{i,j},cost}
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (mat[i][j] == 0)
				{
					mem[i][j] = 0;
					q.push({i, j});
				}
			}
		}

		int depth = 0;
		while (q.size())
		{
			int s = q.size();
			for (int k = 0; k < s; k++)
			{
				auto [i, j] = q.front();
				q.pop();
				for (int l = 0; l < 4; l++)
				{
					int ni = i + delta[l][0];
					int nj = j + delta[l][1];

					if (0 <= ni && ni < m &&
						0 <= nj && nj < n && (depth + 1) < mem[ni][nj])
					{
						mem[ni][nj] = depth + 1;
						q.push({ni, nj});
					}
				}
			}
			depth++;
		}

		return mem;
	}
};