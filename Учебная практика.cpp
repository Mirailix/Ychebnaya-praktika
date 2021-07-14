#include<iostream>
#include<vector>
using namespace std;
int e = 0, c = 0;//ОБЪЯВЛЕНИЕ ГЛОБАЛЬНЫХ ПЕРЕМЕННЫХ,ЧТОБЫ ПЕРЕХОДИТЬ В СЛЕДУЮЩИЙ ЭЛЕМЕНТ НОВОГО МНОЖЕСТВА(по условию это пересечение и разность)
void Enter_point(vector<pair<int,int> >*arr,int n,int i)
{
	int a, b;//наши будущие координаты точки в пространстве
    cout << "Введите координаты " << i+1 << "-ой точки" << endl;
	cin >> a >> b;
	arr[i].push_back(make_pair(a, b));//добавляем координаты точек во множество(используются материалы аж из 3 лекций)
}
void Print_point(vector<pair<int, int> >* arr,int i)
{
	for (auto el : arr[i])//сам не знаю как работает "el",ведь я имя каждой паре не давал(в теории можно любое имя подставить и будет работать)
		
			cout << "(" << el.first << ";" << el.second << ")" << endl;//просто вывод элементов пары(все что в ковычках для красоты)
		
}
void Per(vector<pair<int, int> >* arr1, vector<pair<int, int> >* arr2, vector<pair<int, int> >* arr,int n)//создаем новое множество точек
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr1[i] == arr2[j])
			{
				arr[e]=arr1[i];//создаем новый элемент в новом множестве 
				e++; break;//брейк для того,чтобы точки не дублировались,а переменная е нужна для перехода в следующий элемент множества
				
			}
		}
	}
}
void Razn(vector<pair<int, int> >* arr1, vector<pair<int, int> >* arr2, vector<pair<int, int> >* arr, int n)
{
	bool k,l;
	for (int i = 0; i < n; i++)
	{
		k = 1;
		l = 1;
		for (int j = 0; j < n; j++)
		{
			if (arr1[i] == arr2[j])
				k = 0;
			//if (arr2[i] == arr1[j])
			//	l = 0; 
		}
		if (k == 1)
		{
			arr[c] = arr1[i];
			c++;
		}
		/*if (l == 1)
		{
			arr[c] = arr2[i];
			c++;
		}*/
	}
}
int main()
{
	setlocale(LC_ALL, "RUS");//хочу русский,потому что английского не знаю
	int n;
	cout << "Введите количество точек во множестве" << endl;
	cin >> n;
	vector<pair<int, int> >* arr1 = new vector<pair<int, int> >[n];//выделение памяти под МАССИВ ВЕКТОРОВ,ЭЛЕМЕНТЫ КОТОРОГО - ПАРЫ ЧИСЕЛ
	vector<pair<int, int> >* arr2 = new vector<pair<int, int> >[n];
	vector<pair<int, int> >* arr3 = new vector<pair<int, int> >[n];
	vector<pair<int, int> >* arr4 = new vector<pair<int, int> >[4*n]; // нужно вдвое больше памяти,потому что если точек 2, то в разности будет целых 4
	cout << "Введите координаты точек первого множества" << endl;
	for (int i = 0; i < n; i++)
	{
		Enter_point(arr1, n, i);                                             //заполнение этих множеств
	}                           
	cout << "Введите координаты точек второго множества" << endl;
	for (int i = 0; i < n; i++)
	{
		Enter_point(arr2, n, i);
	}
	cout << endl;
	Per(arr1, arr2, arr3,n);//вызываем функцию,которая создаст нам множество пересечений
	Razn(arr1, arr2,arr4, n);//функция,которая создаст нам множество разности

	cout << "Пересечение множеств " << endl;
	for(int i=0;i<n;++i)
		Print_point(arr3,i);
	cout << "Разность множеств " << endl;
	for (int i = 0; i < 4*n; ++i)
		Print_point(arr4, i);
	
   


	

}
