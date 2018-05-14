/******************************************
* Класс Матриц, созданный через векторы   *
*                                         *
*-Недоделана функуия решения СЛУ по Гаусу *
*-Нет разбиения на файл .h и .cpp         *
******************************************/

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

namespace szabiyako
{
	static const char FULLVERSION_STRING[] = "0.9.9.8";
	template <typename T> class Matrix
	{
	private:
		int m, n, epsilon;
		std::vector <std::vector <T> > inside;
	public:
		Matrix()
		{
			m = 0;
			n = 0;
			epsilon = 2;
			std::cout << "Введите размер матрицы:\n";
			std::cin >> m;
			std::cout << "x\n";
			std::cin >> n;
			while ((m < 1) || (n < 1))
			{
				std::cout << "Введите КОРРЕКТНЫЙ размер матрицы:\n";
				std::cin >> m;
				std::cout << "x\n";
				std::cin >> n;
			}
			std::cout << "\nЗаполните матрицу:";
			for (int i = 0; i < m; i++)
			{
				inside.push_back(std::vector<T>(n));
				for (int j = 0; j < n; j++)
				{
					std::cout << "\nЭлемент " << i + 1 << 'x' << j + 1 << ":";
					std::cin >> inside[i][j];
				}
			}
		}
		Matrix(int Epsilon)
		{
			m = 0;
			n = 0;
			epsilon = Epsilon;
			std::cout << "Введите размер матрицы:\n";
			std::cin >> m;
			std::cout << "x\n";
			std::cin >> n;
			while ((m < 1) || (n < 1))
			{
				std::cout << "Введите КОРРЕКТНЫЙ размер матрицы:\n";
				std::cin >> m;
				std::cout << "x\n";
				std::cin >> n;
			}
			std::cout << "\nЗаполните матрицу:";
			for (int i = 0; i < m; i++)
			{
				inside.push_back(std::vector<T>(n));
				for (int j = 0; j < n; j++)
				{
					std::cout << "\nЭлемент " << i + 1 << 'x' << j + 1 << ":";
					std::cin >> inside[i][j];
				}
			}
		}
		Matrix(int NumberOfLines, int NumberOfColumns)
		{
			epsilon = 2;
			m = NumberOfLines;
			n = NumberOfColumns;
			for (int i = 0; i < m; i++)
			{
				inside.push_back(std::vector<T>(n));
				for (int j = 0; j < n; j++)
				{
					inside[i][j] = NULL;
				}
			}
		}
		Matrix(int NumberOfLines, int NumberOfColumns, int Epsilon)
		{
			epsilon = Epsilon;
			m = NumberOfLines;
			n = NumberOfColumns;
			for (int i = 0; i < m; i++)
			{
				inside.push_back(std::vector<T>(n));
				for (int j = 0; j < n; j++)
				{
					inside[i][j] = NULL;
				}
			}
		}
		void G_show()
		{
			std::cout << '\n';
			std::vector<int> l(n);
			int k = -1, R;
			long int dot = 1;
			for (int i = 1; i <= epsilon; i++)dot *= 10;
			for (int i = 0; i < n; i++)l[i] = 0;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (inside[j][i] == (int)inside[j][i])
					{
						if ((inside[j][i] >= 0) && (std::abs(inside[j][i]) >= std::abs(l[i]))) l[i] = (int)inside[j][i];
						else if ((inside[j][i] < 0) && (inside[j][i] <= (-l[i] / 10))) l[i] = std::abs((int)inside[j][i]) * 10;
					}
					else if (inside[j][i] != (int)inside[j][i])
					{
						if ((int)inside[j][i] == 0)
						{
							if ((inside[j][i] > 0) && ((std::abs(l[i]) < std::abs(dot * 100 - 1)))) l[i] = dot * 100 - 1;
							else if ((inside[j][i] < 0) && ((std::abs(l[i]) < std::abs(dot * 1000 - 1)))) l[i] = dot * 1000 - 1;
						}
						else
						{
							if ((int)inside[j][i] > 0 && ((std::abs(l[i]) < std::abs(inside[j][i] * dot * 10)))) l[i] = (int)(inside[j][i] * dot * 10);
							else if ((inside[j][i] < 0) && ((std::abs(l[i]) < std::abs(std::abs(inside[j][i]) * dot * 100)))) l[i] = (int)(std::abs(inside[j][i]) * dot * 100);
						}
					}
				}
			}
			for (int i = 0; i < n; i++)
			{
				if (l[i] > 0) k = 0;
				else k = 1;
				while (l[i] != 0)
				{
					k += 1;
					l[i] /= 10;
				}
				l[i] = k;
			}
			//l[i] теперь длина с точкой и знаком (если они есть)
			for (int i = 0; i < m; i++)
			{
				std::cout << '|';
				for (int j = 0; j < n; j++)
				{
					if (inside[i][j] == (int)inside[i][j]) std::cout << inside[i][j];
					else if ((inside[i][j] > 0) && (std::abs((int)(inside[i][j] * dot - (int)inside[i][j] * dot)) >= 10))std::cout << (int)inside[i][j] << '.' << std::abs((int)(inside[i][j] * dot - (int)inside[i][j] * dot));
					else if ((inside[i][j] > 0) && (std::abs((int)(inside[i][j] * dot - (int)inside[i][j] * dot)) < 10))std::cout << (int)inside[i][j] << ".0" << std::abs((int)(inside[i][j] * dot - (int)inside[i][j] * dot));
					else if ((inside[i][j] < 0) && (std::abs((int)(inside[i][j] * dot - (int)inside[i][j] * dot)) >= 10)) std::cout << '-' << std::abs((int)inside[i][j]) << '.' << std::abs((int)(inside[i][j] * dot - (int)inside[i][j] * dot));
					else if ((inside[i][j] < 0) && (std::abs((int)(inside[i][j] * dot - (int)inside[i][j] * dot)) < 10)) std::cout << '-' << std::abs((int)inside[i][j]) << ".0" << std::abs((int)(inside[i][j] * dot - (int)inside[i][j] * dot));
					R = (int)inside[i][j];
					if (R >= 0) k = 0;
					else k = 1;
					if (R != 0)
					{
						if (inside[i][j] != (int)inside[i][j]) k += epsilon + 1;
						while (R != 0)
						{
							k += 1;
							R /= 10;
						}
					}
					else if (inside[i][j] != (int)inside[i][j])
					{
						if (inside[i][j] > 0)k += epsilon + 2;
						else k += epsilon + 3;
					}
					else k = 1;
					if (j != n - 1)for (int q = 0; q < (l[j] - k + 1); q++)std::cout << ' ';
					else for (int q = 0; q < (l[j] - k); q++)std::cout << ' ';
				}
				std::cout << '|';
				std::cout << '\n';
			}
		}
		void G_boolShow()
		{
			std::vector<int> l(n);
			for (int i = 0; i < n; i++)l[i] = 0;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if ((inside[j][i] == 0) && (l[i] != 1)) l[i] = 1;
				}
			}
			for (int i = 0; i < m; i++)
			{
				std::cout << '|';
				for (int j = 0; j < n; j++)
				{
					if ((inside[i][j] != 0) && (l[j] == 0)) std::cout << "true";
					else if ((inside[i][j] != 0) && (l[j] != 0)) std::cout << "true ";
					else std::cout << "false";
					if (j != n - 1) std::cout << ' ';
				}
				std::cout << '|';
				std::cout << '\n';
			}
		}
		void changeEpsilon(int NewEpsilon)
		{
			epsilon = NewEpsilon;
		}
		void G_changeElement()
		{
			int a, b;
			T c;
			G_show();
			std::cout << "\nВведите номер строки элемента:";
			std::cin >> a;
			if ((a - 1 < m) && (a > 0))
			{
				std::cout << "Введите номер столбца элемента:";
				std::cin >> b;
				if ((b - 1 < n) && (b > 0))
				{
					std::cout << "Введите новое значение элемента:";
					std::cin >> c;
					inside[a - 1][b - 1] = c;
					G_show();
				}
				else std::cout << "\nОшибка, выход за границы матрицы\n";
			}
			else std::cout << "\nОшибка, выход за границы матрицы\n";
		}
		void G_rewrite()
		{
			std::cout << "\nВведите размер матрицы:\n";
			std::cin >> m;
			std::cout << "x\n";
			std::cin >> n;
			while ((m < 1) || (n < 1))
			{
				std::cout << "Введите КОРРЕКТНЫЙ размер матрицы:\n";
				std::cin >> m;
				std::cout << "x\n";
				std::cin >> n;
			}
			std::cout << "\nЗаполните матрицу:";
			inside.clear();
			for (int i = 0; i < m; i++)
			{
				inside.push_back(std::vector<T>(n));
				for (int j = 0; j < n; j++)
				{
					std::cout << "\nЭлемент " << i + 1 << 'x' << j + 1 << ":";
					std::cin >> inside[i][j];
				}
			}
		}
		T get(int NumberOfLine, int NumberOfColumn)
		{
			if ((NumberOfLine - 1 < m) && (NumberOfLine > 0))
				if ((NumberOfColumn - 1 < n) && (NumberOfColumn > 0))
					return inside[NumberOfLine - 1][NumberOfColumn - 1];
				else return NULL;
			else return NULL;
		}
		T getFromZero(int NumberOfLine, int NumberOfColumn)
		{
			if ((NumberOfLine < m) && (NumberOfLine >= 0))
				if ((NumberOfColumn < n) && (NumberOfColumn >= 0))
					return inside[NumberOfLine][NumberOfColumn];
				else return NULL;
			else return NULL;
		}
		void set(int NumberOfLine, int NumberOfColumn, T element)
		{
			inside[NumberOfLine - 1][NumberOfColumn - 1] = element;
		}
		void setFromZero(int NumberOfLine, int NumberOfColumn, T element)
		{
			inside[NumberOfLine][NumberOfColumn] = element;
		}
		int returnM()
		{
			return m;
		}
		int returnN()
		{
			return n;
		}
		int returnEpsilon()
		{
			return epsilon;
		}
		long double det()
		{
			long double S = 0.0, a;
			int k;
			if (m == n)
			{
				if (n > 3)
				{
					std::vector <std::vector <double> > d;
					for (int i = 0; i < n; i++)
					{
						d.push_back(std::vector<double>(n));
						for (int j = 0; j < n; j++)
						{
							d[i][j] = inside[i][j];
						}
					}
					S = 1.0;
					for (int q = 0; q < n - 1; q++)
					{
						if (d[q][q] == 0)
						{
							std::vector <double> h(n);
							for (int i = 0; i < n; i++) h[i] = d[q][i];
							S *= -1;
							for (int i = 0; i < n; i++)
							{
								d[q][i] = d[q + 1][i];
								d[q + 1][i] = h[i];
							}
						}
						for (int i = q + 1; i < n; i++)
						{
							a = d[i][q] / d[q][q];
							for (int j = q; j < n; j++)
							{
								d[i][j] -= d[q][j] * a;
								if (std::abs(d[i][j]) < 0.00000000001)d[i][j] = 0;
							}
						}
					}
					for (int i = 0; i < n; i++)
					{
						S *= d[i][i];
						if (S == 0) return 0;
					}
				}
				else if (n == 3)
				{
					for (int i = 0; i < n; i++)
					{
						a = 1.0;
						for (int j = 0; j < n; j++)
						{
							if (j + i >= n) k = j + i - n;
							else k = j + i;
							a *= inside[j][k];
						}
						S += a;
					}
					for (int i = 0; i < n; i++)
					{
						a = 1.0;
						for (int j = 0; j < n; j++)
						{
							if (j + i >= n) k = 2 * n - j - i - 1;
							else k = n - j - i - 1;
							a *= inside[j][k];
						}
						S -= a;
					}
				}
				else if (n == 2)
				{
					S = inside[0][0] * inside[1][1] - inside[0][1] * inside[1][0];
				}
				else if (n == 1) S = inside[0][0];
				else return -1.2345;
				return S;
			}
			else return -1.2345;

		}
		void transp()
		{
			int p = m;
			std::vector <std::vector <T> > t;
			for (int i = 0; i < m; i++)
			{
				t.push_back(std::vector<T>(n));
				for (int j = 0; j < n; j++)
				{
					t[i][j] = inside[i][j];
				}
			}
			m = n;
			n = p;
			inside.clear();
			for (int i = 0; i < m; i++)
			{
				inside.push_back(std::vector<T>(n));
				for (int j = 0; j < n; j++)
				{
					inside[i][j] = t[j][i];
				}
			}
		}
		void G_showTransp()
		{
			transp();
			G_show();
			transp();
		}
		Matrix returnTransp()
		{
			Matrix <T> M(n, m);
			M.G_show();
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					M.setFromZero(i, j, inside[j][i]);
				}
			}
			return M;
		}
		void G_debug()
		{
			std::cout << "\n Исходная матрица:";
			G_show();
			std::cout << "\n M=" << returnM();
			std::cout << "\n N=" << returnN();
			if (m == n)std::cout << "\n\n Определитель = " << det();
			else std::cout << "\n\n Определитель найти нельзя так как число строк и столбцов не совпадает";
			std::cout << "\n\n В виде boolean:\n";
			G_boolShow();
			std::cout << "\n В транспонированном виде:";
			G_showTransp();
			/*std::cout << "\n Решённая методом Жордана-Гаусса:";
			Matrix <T> s(1,1);
			s.G_rewrite();
			G_gaus(s);
			*/
		}
		void G_gaus(Matrix <T> s)
		{
			if ((s.returnM() == m) && s.returnN() == 1)
			{
				double a, buff;
				int o;
				Matrix <T> answer(m, n, epsilon);
				std::vector <std::vector <double> > d;
				for (int i = 0; i < m; i++)
				{
					d.push_back(std::vector<double>(n));
					for (int j = 0; j < n; j++)
					{
						d[i][j] = inside[i][j];
					}
				}
				if (m >= n)
				{
					o = n;
					for (int q = 0; q < o - 1; q++)
					{
						if (d[q][q] == 0)
						{
							std::vector <double> h(n);
							for (int i = 0; i < n; i++) h[i] = d[q][i];
							buff = s.getFromZero(q, 0);
							for (int i = 0; i < n; i++)
							{
								d[q][i] = d[q + 1][i];
								d[q + 1][i] = h[i];
							}
							s.setFromZero(q, 0, s.getFromZero(q + 1, 0));
							s.setFromZero(q + 1, 0, buff);
						}
						for (int i = q + 1; i < m; i++)
						{
							a = d[i][q] / d[q][q];
							for (int j = q; j < n; j++)
							{
								d[i][j] -= d[q][j] * a;
								if (std::abs(d[i][j]) < 0.00000000001)d[i][j] = 0;
							}
							s.setFromZero(i, 0, (s.getFromZero(i, 0) - s.getFromZero(q, 0)*a));
						}

					}
					//Тестовый вывод
					for (int i = 0; i < m; i++)
					{
						for (int j = 0; j < n; j++)
						{
							answer.setFromZero(i, j, d[i][j]);
						}
					}
					answer.G_show();
					//debug!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
					s.G_show();
					//Тестовый вывод
					for (int i = 0; i < m; i++)
					{
						for (int j = 0; j < n; j++)
						{
							if (std::abs(d[i][j]) == 0) d[i][j] = 0;
							answer.setFromZero(i, j, d[i][j]);
						}
					}
					answer.G_show();
					//debug!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
					s.G_show();
					for (int i = 0; i < m; i++)
					{
						for (int j = 0; j < n; j++)
						{
							if (i == j)a = d[i][j];
							if (d[i][j] != 0) d[i][j] /= a;
							answer.setFromZero(i, j, d[i][j]);
						}
						s.setFromZero(i, 0, (s.getFromZero(i, 0) / a));
					}
					answer.G_show();
					//debug!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!ПРОБЛЕМА ЗДЕСЬ(+ после else тоже надо поменять!!!)
					s.G_show();
					for (int q = o - 1; q > 0; q--)
					{
						for (int i = m - 1; i >= 0; i--)
						{
							for (int j = 0; j < n; j++)
							{
								if (i != j)
								{
									///still problem here
									s.setFromZero(i, 0, (s.getFromZero(i, 0) - s.getFromZero(q, 0) * d[q][j] * d[i][j]));
									d[i][j] = d[i][j] - d[q][j] * d[i][j];
								}
							}
							//Тестовый вывод123                           )
							for (int i = 0; i < m; i++)
							{
								for (int j = 0; j < n; j++)
								{
									if (std::abs(d[i][j]) == 0) d[i][j] = 0;
									answer.setFromZero(i, j, d[i][j]);
								}
							}
							answer.G_show();
							//debug!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!123     )
							//debug!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
							s.G_show();
						}
					}
					//Вывод
					for (int i = 0; i < m; i++)
					{
						for (int j = 0; j < n; j++)
						{
							answer.setFromZero(i, j, d[i][j]);
						}
					}
				}
				else
				{
					o = m;
					for (int q = 0; q < o - 1; q++)
					{
						if (d[q][q] == 0)
						{
							std::vector <double> h(n);
							for (int i = 0; i < n; i++) h[i] = d[q][i];
							buff = s.getFromZero(q, 0);
							for (int i = 0; i < n; i++)
							{
								d[q][i] = d[q + 1][i];
								d[q + 1][i] = h[i];
							}
							s.setFromZero(q, 0, s.getFromZero(q + 1, 0));
							s.setFromZero(q + 1, 0, buff);
						}
						for (int i = q + 1; i < m; i++)
						{
							a = d[i][q] / d[q][q];
							for (int j = q; j < n; j++)
							{
								d[i][j] -= d[q][j] * a;
								if (std::abs(d[i][j]) < 0.00000000001)d[i][j] = 0;
							}
							s.setFromZero(i, 0, (s.getFromZero(i, 0) - s.getFromZero(q, 0)*a));
						}

					}
					//Тестовый вывод
					for (int i = 0; i < m; i++)
					{
						for (int j = 0; j < n; j++)
						{
							answer.setFromZero(i, j, d[i][j]);
						}
					}
					answer.G_show();
					//Тестовый вывод
					for (int i = 0; i < m; i++)
					{
						for (int j = 0; j < n; j++)
						{
							if (std::abs(d[i][j]) == 0) d[i][j] = 0;
							answer.setFromZero(i, j, d[i][j]);
						}
					}
					answer.G_show();
					for (int i = 0; i < m; i++)
					{
						for (int j = 0; j < n; j++)
						{
							if (i == j)a = d[i][j];
							if (d[i][j] != 0) d[i][j] /= a;
							answer.setFromZero(i, j, d[i][j]);
						}
						s.setFromZero(i, 0, (s.getFromZero(i, 0) / a));
					}
					answer.G_show();
					for (int q = m - 1; q > 0; q--)
					{
						for (int i = q - 1; i >= 0; i--)
						{
							for (int j = 0; j < n; j++)
							{
								if (i != j)
								{
									///still problem here
									s.setFromZero(i, 0, (s.getFromZero(i, 0) - s.getFromZero(q, 0) * d[q][j] * d[i][j]));
									d[i][j] = d[i][j] - d[q][j] * d[i][j];
								}
							}
							//s.setFromZero(i, 0, (s.getFromZero(i, 0) - s.getFromZero(q, 0)*s.getFromZero(i, 0)));
						}
					}
					//Вывод
					for (int i = 0; i < m; i++)
					{
						for (int j = 0; j < n; j++)
						{
							answer.setFromZero(i, j, d[i][j]);
						}
					}
				}
				std::cout << "\nМатрица неизвестных:";
				answer.G_show();
				std::cout << "\nМатрица свободных членов:";
				for (int i = 0; i < m; i++)if (std::abs(s.getFromZero(i, 0)) == 0) s.setFromZero(i, 0, 0);
				s.G_show();
			}
			else std::cout << "\nОшибка! матрица свободных членов не совпадает по размерам с матрицей неизвестных";
		}
	};

	Matrix <double> operator+ (Matrix <double> &a, Matrix <double> &b)
	{
		int m, n, e;
		if (a.returnM() > b.returnM()) m = a.returnM();
		else m = b.returnM();
		if (a.returnN() > b.returnN()) n = a.returnN();
		else n = b.returnN();
		if (a.returnEpsilon() > b.returnEpsilon()) e = b.returnEpsilon();
		else e = a.returnM();
		Matrix <double> c(m, n, e);
		for (int i = 0; i < a.returnM(); i++)
			for (int j = 0; j < a.returnN(); j++)
				c.setFromZero(i, j, a.getFromZero(i, j));

		for (int i = 0; i < b.returnM(); i++)
			for (int j = 0; j < b.returnN(); j++)
				c.setFromZero(i, j, (c.getFromZero(i, j) + b.getFromZero(i, j)));

		return c;
	}

	Matrix <double> operator+ (Matrix <double> a, Matrix <double> b)
	{
		int m, n, e;
		if (a.returnM() > b.returnM()) m = a.returnM();
		else m = b.returnM();
		if (a.returnN() > b.returnN()) n = a.returnN();
		else n = b.returnN();
		if (a.returnEpsilon() > b.returnEpsilon()) e = b.returnEpsilon();
		else e = a.returnM();
		Matrix <double> c(m, n, e);
		for (int i = 0; i < a.returnM(); i++)
			for (int j = 0; j < a.returnN(); j++)
				c.setFromZero(i, j, a.getFromZero(i, j));

		for (int i = 0; i < b.returnM(); i++)
			for (int j = 0; j < b.returnN(); j++)
				c.setFromZero(i, j, (c.getFromZero(i, j) + b.getFromZero(i, j)));

		return c;
	}

	Matrix <double> operator- (Matrix <double> &a, Matrix <double> &b)
	{
		int m, n, e;
		if (a.returnM() > b.returnM()) m = a.returnM();
		else m = b.returnM();
		if (a.returnN() > b.returnN()) n = a.returnN();
		else n = b.returnN();
		if (a.returnEpsilon() > b.returnEpsilon()) e = b.returnEpsilon();
		else e = a.returnM();
		Matrix <double> c(m, n, e);
		for (int i = 0; i < a.returnM(); i++)
			for (int j = 0; j < a.returnN(); j++)
				c.setFromZero(i, j, a.getFromZero(i, j));

		for (int i = 0; i < b.returnM(); i++)
			for (int j = 0; j < b.returnN(); j++)
				c.setFromZero(i, j, (c.getFromZero(i, j) - b.getFromZero(i, j)));

		return c;
	}

	void G_infoMatrix()
	{
		std::cout << "MatrixVersion " << FULLVERSION_STRING << '\n';
	}
}

#endif
