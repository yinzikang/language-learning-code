
/*������*/
/*���������ӿ�*/
/*ѧ�ţ�2017302097*/
/*���ڣ�2020.3.8*/

#include "iostream"
using namespace std;
using std::endl;
using std::cout;
const double EPS = 1e-10;

template <typename T>
class matrix
{
public:
	matrix(int rows, int cols);//����һ����rows��cols�У�ֵȫΪvalue�ľ���
	matrix(int n);//����һ��n��n�еĵ�λ����
	~matrix();
	static matrix& inv(matrix);//�����������
	friend matrix operator + <T> (const matrix&, const matrix&);//�������
	friend matrix operator - <T> (const matrix&, const matrix&);//�������
	friend matrix operator * <T> (const matrix&, const matrix&);//�������
	friend matrix operator / <T> (const matrix&, const matrix&);//�������
	friend matrix operator + <T> (const matrix&, T);//�������
	friend matrix operator - <T> (const matrix&, T);//�������
	friend matrix operator * <T> (const matrix&, T);//�������
	friend matrix operator / <T> (const matrix&, T);//�������
	T max() const;//���ֵ
	T min() const;//��Сֵ
	T avg() const;//ƽ��ֵ

	matrix sub_matrix(const matrix& base_matrix, int row_start, int col_start, int row_end, int col_end);//��ֵõ��С��С��Ӿ���
	matrix resize(const matrix& base_matrix, char a_or_d, char r_or_c, int pos);//��ӻ�ɾȥһ�л���,a:add,d:delete,r:row,c:col,pos:position
	bool find(const matrix& base_matrix, char r_or_c, int pos, int tar);//ĳһ�л�ĳһ�в���Ԫ�أ�r:row,c:col,pos:position,tar:target
	void show() const;//������ʾ

private:
	int rows_num, cols_num;
	T** p;
	void initialize();//�����ʼ��
};









template <typename T>
void matrix<T>::initialize()
{
	p = new T* [rows_num];//����rows_num��ָ��
	for (int i = 0; i < rows_num; i++)
	{
		p[i] = new T[cols_num];//Ϊp[i]���ж�̬�ڴ���䣬��СΪcols
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

	//�Ƚ�����A���浽A_B
	matrix A_B = matrix(A.rows_num, A.cols_num);
	A_B = A;
	matrix B(A.cols_num);

	//����С��ֵȫ��ȡ0
	for (int i = 0; i < A.rows_num; i++)
		for (int j = 0; j < A.cols_num; j++)
			if (abs(A.p[i][j]) <= EPS)
				A.p[i][j] = 0;

	//���Խ���Ԫ��ȫ����0
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
				std::cout << "����󲻴���\n";
		}

	//������Aת��Ϊ�����Ǿ���
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

	////����Ƿ���������
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


	//�Խ�Ԫ�ص�λ��
	for (int i = 0; i < A.rows_num; i++)
	{
		temp = A.p[i][i];
		for (int j = 0; j < A.cols_num; j++) {
			A.p[i][j] /= temp;
			B.p[i][j] /= temp;
		}
	}

	//��A��Ϊ��λ����
	for (int i = A.rows_num - 1; i >= 1; i--)
		for (int j = i - 1; j >= 0; j--) {
			temp = A.p[j][i];
			for (int k = 0; k < A.cols_num; k++)
			{
				A.p[j][k] -= A.p[i][k] * temp;
				B.p[j][k] -= B.p[i][k] * temp;
			}
		}

	A = A_B;//��ԭA
	return B;//���ظþ���������
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
	cout << "���ֵλ��Ϊ��" << max_row + 1 << "�е�" << max_col + 1 << "��" << endl;
	cout << "��ֵΪ" << p[max_col][max_col] << endl;
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
	cout << "��Сֵλ��Ϊ��" << min_row + 1 << "�е�" << min_col + 1 << "��" << endl;
	cout << "��ֵΪ" << p[min_row][min_col] << endl;
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
	cout << "ƽ��ֵΪ" << avg << endl;
	cout << "��С��ƽ��ֵ���ֵλ��Ϊ��" << avg_row + 1 << "�е�" << avg_col + 1 << "��" << endl;
	cout << "��ֵΪ" << p[avg_row][avg_col] << endl;
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
				cout << "��" << pos + 1 << "," << j << "������" << tar << endl;
				return true;
			}
			else
			{
				cout << "δ����Ŀ��" << endl;
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
				cout << "��" << i << "," << pos + 1 << "������" << tar << endl;
				return true;
			}
			else
			{
				cout << "δ����Ŀ��" << endl;
				return false;
			}
		}
	}
}
