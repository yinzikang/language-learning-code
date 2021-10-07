
/*矩阵类*/
/*姓名：尹子康*/
/*学号：2017302097*/
/*日期：2020.3.8*/

#include "iostream"
using namespace std;
using std::endl;
using std::cout;
const double EPS = 1e-10;

template <typename T>
class matrix
{
public:
	matrix(int rows, int cols);//建立一个，rows行cols列，值全为value的矩阵
	matrix(int n);//建立一个n行n列的单位矩阵
	~matrix();
	static matrix& inv(matrix);//求矩阵的逆矩阵
	friend matrix operator + <T> (const matrix&, const matrix&);//矩阵相加
	friend matrix operator - <T> (const matrix&, const matrix&);//矩阵相减
	friend matrix operator * <T> (const matrix&, const matrix&);//矩阵相乘
	friend matrix operator / <T> (const matrix&, const matrix&);//矩阵相除
	friend matrix operator + <T> (const matrix&, T);//矩阵加数
	friend matrix operator - <T> (const matrix&, T);//矩阵减数
	friend matrix operator * <T> (const matrix&, T);//矩阵乘数
	friend matrix operator / <T> (const matrix&, T);//矩阵除数
	T max() const;//最大值
	T min() const;//最小值
	T avg() const;//平均值

	matrix sub_matrix(const matrix& base_matrix, int row_start, int col_start, int row_end, int col_end);//拆分得到行、列、子矩阵
	matrix resize(const matrix& base_matrix, char a_or_d, char r_or_c, int pos);//添加或删去一行或列,a:add,d:delete,r:row,c:col,pos:position
	bool find(const matrix& base_matrix, char r_or_c, int pos, int tar);//某一行或某一列查找元素，r:row,c:col,pos:position,tar:target
	void show() const;//矩阵显示

private:
	int rows_num, cols_num;
	T** p;
	void initialize();//矩阵初始化
};









template <typename T>
void matrix<T>::initialize()
{
	p = new T* [rows_num];//分配rows_num个指针
	for (int i = 0; i < rows_num; i++)
	{
		p[i] = new T[cols_num];//为p[i]进行动态内存分配，大小为cols
	}
}

template <typename T>
matrix<T>::matrix(int rows, int cols)
{
	if (rows < 0 || cols < 0)
		std::cout << "error input" << endl;
	rows_num = rows;
	cols_num = cols;
	initialize();
	for (int i = 0; i < rows_num; i++)
		for (int j = 0; j < cols_num; j++)
			p[i][j] = 0;
}

template <typename T>
matrix<T>::matrix(int n)
{
	if (n < 0)
		std::cout << "error input" << endl;
	rows_num = n;
	cols_num = n;
	initialize();
	for (int i = 0; i < rows_num; i++)
		for (int j = 0; j < cols_num; j++)
		{
			if (i != j)
				p[i][j] = 0;
			else
				p[i][j] = 1;
		}
}

template <typename T>
matrix<T>::~matrix()
{
	/*for (int i = 0; i < rows_num; ++i)
		delete[] p[i];
	delete[] p;*/
}

template <typename T>
matrix<T>& matrix<T>::inv(matrix A)
{
	if (A.rows_num != A.cols_num)
		std::cout << "row should equal to col" << std::endl;
	T temp;

	//先将矩阵A保存到A_B
	matrix A_B = matrix(A.rows_num, A.cols_num);
	A_B = A;
	matrix B(A.cols_num);

	//将过小的值全部取0
	for (int i = 0; i < A.rows_num; i++)
		for (int j = 0; j < A.cols_num; j++)
			if (abs(A.p[i][j]) <= EPS)
				A.p[i][j] = 0;

	//将对角线元素全部非0
	for (int i = 0; i < A.rows_num; i++)
		if (abs(A.p[i][i]) <= EPS)
		{
			bool flag = false;
			for (int j = 0; (j < A.rows_num) && (!flag); j++)
				if ((abs(A.p[i][j]) > EPS) && (abs(A.p[j][i]) > EPS))
				{
					flag = true;
					for (int k = 0; k < A.cols_num; k++)
					{
						temp = A.p[i][k];
						A.p[i][k] = A.p[j][k];
						A.p[j][k] = temp;

						temp = B.p[i][k];
						B.p[i][k] = B.p[j][k];
						B.p[j][k] = temp;
					}
				}
			if (!flag)
				std::cout << "逆矩阵不存在\n";
		}

	//将矩阵A转换为上三角矩阵
	T temp_rate;
	for (int i = 0; i < A.rows_num; i++)
		for (int j = i + 1; j < A.rows_num; j++)
		{
			temp_rate = A.p[j][i] / A.p[i][i];
			for (int k = 0; k < A.cols_num; k++)
			{
				A.p[j][k] -= A.p[i][k] * temp_rate;
				B.p[j][k] -= B.p[i][k] * temp_rate;
			}
			A.p[j][i] = 0;
		}

	////检测是否存在逆矩阵
	//for (int i = 0, row_sum = 0, col_sum = 0; i < A.rows_num; i++)
	//{
	//	for (int j = 0; j < A.rows_num; j++)
	//	{
	//		row_sum += A.p[i][j];
	//		col_sum += A.p[j][i];
	//	}
	//	if (row_sum == 0 || col_sum == 0)
	//	{
	//		cout << "inv_matrix do not exist" << endl;
	//		return A;
	//	}
	//	row_sum = 0;
	//	col_sum = 0;
	//}


	//对角元素单位化
	for (int i = 0; i < A.rows_num; i++)
	{
		temp = A.p[i][i];
		for (int j = 0; j < A.cols_num; j++) {
			A.p[i][j] /= temp;
			B.p[i][j] /= temp;
		}
	}

	//将A变为单位矩阵
	for (int i = A.rows_num - 1; i >= 1; i--)
		for (int j = i - 1; j >= 0; j--) {
			temp = A.p[j][i];
			for (int k = 0; k < A.cols_num; k++)
			{
				A.p[j][k] -= A.p[i][k] * temp;
				B.p[j][k] -= B.p[i][k] * temp;
			}
		}

	A = A_B;//还原A
	return B;//返回该矩阵的逆矩阵
}

template <typename T>
matrix<T> operator+(const matrix<T>& m, const matrix<T>& n)
{
	matrix<T> a(m.rows_num, m.cols_num);
	for (int i = 0; i < a.rows_num; i++)
		for (int j = 0; j < a.cols_num; j++)
			a.p[i][j] = m.p[i][j] + n.p[i][j];
	return a;
}

template <typename T>
matrix<T> operator-(const matrix<T>& m, const matrix<T>& n)
{
	matrix<T> a(m.rows_num, m.cols_num);
	for (int i = 0; i < a.rows_num; i++)
		for (int j = 0; j < a.cols_num; j++)
			a.p[i][j] = m.p[i][j] - n.p[i][j];
	return a;
}

template <typename T>
matrix<T> operator*(const matrix<T>& m, const matrix<T>& n)
{
	matrix<T> a(m.rows_num, n.cols_num);
	T  sum = 0;
	for (int i = 0; i < a.rows_num; i++)
		for (int j = 0; j < a.cols_num; j++)
		{
			for (int k = 0; k < m.cols_num; k++)
				sum += m.p[i][k] * n.p[k][j];
			a.p[i][j] = sum;
			sum = 0;
		}
	return a;
}

template <typename T>
matrix<T> operator/(const matrix<T>& m, const matrix<T>& n)
{
	matrix<T> a(m.rows_num, m.cols_num);
	a = m * n.inv(n);
	return a;
}

template <typename T>
matrix<T> operator+(const matrix<T>& m, T num)
{
	matrix<T> a(m.rows_num, m.cols_num);
	for (int i = 0; i < a.rows_num; i++)
		for (int j = 0; j < a.cols_num; j++)
			a.p[i][j] = m.p[i][j] + num;
	return a;
}

template <typename T>
matrix<T> operator-(const matrix<T>& m, T num)
{
	matrix<T> a(m.rows_num, m.cols_num);
	for (int i = 0; i < a.rows_num; i++)
		for (int j = 0; j < a.cols_num; j++)
			a.p[i][j] = m.p[i][j] - num;
	return a;
}

template <typename T>
matrix<T> operator*(const matrix<T>& m, T num)
{
	matrix<T> a(m.rows_num, m.cols_num);
	for (int i = 0; i < a.rows_num; i++)
		for (int j = 0; j < a.cols_num; j++)
			a.p[i][j] = m.p[i][j] * num;
	return a;
}

template <typename T>
matrix<T> operator/(const matrix<T>& m, T num)
{
	matrix<T> a(m.rows_num, m.cols_num);
	for (int i = 0; i < a.rows_num; i++)
		for (int j = 0; j < a.cols_num; j++)
			a.p[i][j] = m.p[i][j] / num;
	return a;
}

template <typename T>
T matrix<T>::max() const
{
	int max_row = 0, max_col = 0;
	for (int i = 0; i < rows_num; i++)
	{
		for (int j = 0; j < cols_num; j++)
		{
			if (p[max_row][max_col] < p[i][j])
			{
				max_row = i;
				max_col = j;
			}
		}
	}
	cout << "最大值位置为第" << max_row + 1 << "行第" << max_col + 1 << "列" << endl;
	cout << "其值为" << p[max_col][max_col] << endl;
	return p[max_col][max_col];
}

template <typename T>
T matrix<T>::min() const
{
	int min_row = 0, min_col = 0;
	for (int i = 0; i < rows_num; i++)
	{
		for (int j = 0; j < cols_num; j++)
		{
			if (p[min_row][min_col] > p[i][j])
			{
				min_row = i;
				min_col = j;
			}
		}
	}
	cout << "最小值位置为第" << min_row + 1 << "行第" << min_col + 1 << "列" << endl;
	cout << "其值为" << p[min_row][min_col] << endl;
	return p[min_row][min_col];
}

template <typename T>
T matrix<T>::avg() const
{
	double sum = 0, avg = 0, deta = 0;
	int avg_row = 0, avg_col = 0;
	for (int i = 0; i < rows_num; i++)
	{
		for (int j = 0; j < cols_num; j++)
		{
			sum += p[i][j];
		}
	}
	avg = sum / rows_num / cols_num;
	deta = abs(p[0][0] - avg);
	for (int i = 0; i < rows_num; i++)
	{
		for (int j = 0; j < cols_num; j++)
		{
			if (deta > abs(p[i][j] - avg))
			{
				avg_row = i;
				avg_col = j;
			}

		}
	}
	cout << "平均值为" << avg << endl;
	cout << "大小离平均值最近值位置为第" << avg_row + 1 << "行第" << avg_col + 1 << "列" << endl;
	cout << "其值为" << p[avg_row][avg_col] << endl;
	return avg;
}

template <typename T>
void matrix<T>::show() const
{
	for (int i = 0; i < rows_num; i++)
	{
		for (int j = 0; j < cols_num; j++)
		{
			cout << p[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

template <typename T>
matrix<T> matrix<T>::sub_matrix(const matrix& m, int row_start, int col_start, int row_end, int col_end)
{
	matrix sub(row_end - row_start + 1, row_end - col_start + 1);
	for (int i = 0; i < sub.rows_num; i++)
	{
		for (int j = 0; j < sub.cols_num; j++)
		{
			sub.p[i][j] = m.p[row_start + i][col_start + j];
		}
	}
	return sub;
}

template <typename T>
matrix<T> matrix<T>::resize(const matrix& m, char a_or_d, char r_or_c, int pos)
{
	pos--;
	if (a_or_d == 'a')
	{
		if (r_or_c == 'r')
		{
			matrix sub(m.rows_num + 1, m.cols_num);
			for (int i = 0; i < pos; i++)
			{
				for (int j = 0; j < sub.cols_num; j++)
					sub.p[i][j] = m.p[i][j];
			}
			for (int j = 0; j < sub.cols_num; j++)
				sub.p[pos][j] = 0;
			for (int i = pos + 1; i < sub.rows_num; i++)
			{
				for (int j = 0; j < sub.cols_num; j++)
					sub.p[i][j] = m.p[i - 1][j];
			}
			return sub;
		}
		if (r_or_c == 'c')
		{
			matrix sub(m.rows_num, m.cols_num + 1);
			for (int i = 0; i < rows_num; i++)
			{
				for (int j = 0; j < pos; j++)
					sub.p[i][j] = m.p[i][j];
				sub.p[i][pos] = 0;
				for (int j = pos + 1; j < sub.cols_num; j++)
					sub.p[i][j] = m.p[i][j - 1];
			}
			return sub;
		}
	}

	if (a_or_d == 'd')
	{
		if (r_or_c == 'r')
		{
			matrix sub(m.rows_num - 1, m.cols_num);
			for (int i = 0; i < pos; i++)
			{
				for (int j = 0; j < sub.cols_num; j++)
					sub.p[i][j] = m.p[i][j];
			}
			for (int i = pos; i < sub.rows_num; i++)
			{
				for (int j = 0; j < sub.cols_num; j++)
					sub.p[i][j] = m.p[i + 1][j];
			}
			return sub;
		}
		if (r_or_c == 'c')
		{
			matrix sub(m.rows_num, m.cols_num - 1);
			for (int i = 0; i < rows_num; i++)
			{
				for (int j = 0; j < pos; j++)
					sub.p[i][j] = m.p[i][j];
				for (int j = pos; j < sub.cols_num; j++)
					sub.p[i][j] = m.p[i][j + 1];
			}
			return sub;
		}
	}
}

template <typename T>
bool matrix<T>::find(const matrix<T>& m, char r_or_c, int pos, int tar)
{
	pos--;
	if (r_or_c == 'r')
	{
		for (int j = 0; j < m.cols_num; j++)
		{
			if (tar == m.p[pos][j])
			{
				cout << "在" << pos + 1 << "," << j << "处发现" << tar << endl;
				return true;
			}
			else
			{
				cout << "未发现目标" << endl;
				return false;
			}
		}
	}
	if (r_or_c == 'c')
	{
		for (int i = 0; i < m.cols_num; i++)
		{
			if (tar == m.p[i][pos])
			{
				cout << "在" << i << "," << pos + 1 << "处发现" << tar << endl;
				return true;
			}
			else
			{
				cout << "未发现目标" << endl;
				return false;
			}
		}
	}
}
