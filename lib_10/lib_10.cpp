//Итераторы. Стандартные алгоритмы. Предикаты.
#include"H.h"
//Вывод пары в поток
ostream& operator<<(ostream& os, pair<string, int> ms)
{
	cout << ms.first << "=" << ms.second << endl;
	return os;
};
//Вывод "контейнера" строки в поток
ostream& operator<<(ostream& os, string ms)
{

	ostream_iterator<char> oss(cout);
	copy(ms.begin(), ms.end(), oss);
	stop
		return os;
};
//Вывод "точки" в поток
ostream& operator<<(ostream& os, const Point &ms)
{
	cout << ms.x << " " << ms.y;
	return os;
}
//Итератор вывода в поток любого контейнера
/*
Не будет работать т.к. в "std"  нету перегруженного оператора = для pair-----(os(поток) = pair)----Просто перегрузить "<< pair" и не париться.
*/
//template<typename T> void c_output(T ms)
//{
//
//	//ostream_iterator<pair<string, int>> os(cout);
//	//ostream_iterator<pair<basic_string<char, char_traits<char>, allocator<char>> const, int>> os(cout);
//	copy(ms.begin(), ms.end(), os);
//};

//Сортировка строк по алфавиту
struct sotr_ABC
{
	char c;
	sotr_ABC(char l) :c(l) {};
	bool operator()(string a) const
	{
		return (a[0] == c);
	}
};
//Итератор вывода в поток по условию
template<typename T> void c_output_if(T ms)
{
	set<char> sChar;
	typename T::iterator it = ms.begin();
	while (it != ms.end())
	{//Формирую set заглавных букв
		sChar.insert((*it)[0]);
		++it;
	}
	stop
		set<char>::iterator itt = sChar.begin();
	ostream_iterator<string> os(cout, "\n");
	while (itt != sChar.end())
	{
		it = ms.begin();
		copy_if(it, ms.end(), os, sotr_ABC(*itt));
		++itt;
	}
	stop
};
//Вывод на консоль любого объекта
template<typename T> void Print(T ms)
{
	cout << ms << endl;
}
//Присваивает точке новые координаты не методом класса
template<typename T, int a, int b> void New_coordinat(T &ms)
{
	int i = 0;
	//int i = (rand()/1000);
	ms.x = a + i;
	//i = (rand()/1000);
	ms.y = b + i;
};
//Проверяет наличие точки в заданных координатах
template<int n = 0, int m = 0>bool coord(Point ms)
{
	if ((ms.x > n) && (ms.x < m) && (ms.y > n) && (ms.y < m)) { return true; }
	return false;
}
//Располагает прямоугольники по удалению центра от начала координат(не заморачивался, и условно принял Point за центр прямоугольника, дабы не пересчитывать)
bool sort_coord(const Point &ms, const Point &ms2)
{
	return ((ms.x + ms.y) < (ms2.x + ms2.y));
}
//Переводит из верхнего регистра в нижнии символ
char transformation_register(char a)
{
	a = a + 32;
	return a;
};
//Переводит строку из верхнего регистра в нижнии
string transformation_register2(string a)
{
	string::iterator it = a.begin();
	transform(it, a.end(), it, transformation_register);
	return a;
};
//Предикат Pair на чётность
bool Pred(pair<string, int> a)
{
	return (a.second % 2);
};
//Предикат Pair на нечётность
bool Pred2(pair<string, int> a)
{
	return !(a.second % 2);
};
int _tmain(int argc, _TCHAR* argv[])
{
//Задание 1. Итераторы
/*
Реверсивные итераторы. Сформируйте set<Point>. Подумайте, что
нужно перегрузить в классе Point. Создайте вектор, элементы которого
являются копиями элементов set, но упорядочены по убыванию
*/
	set<Point> sPoint = { Point(1,1) , Point(3,3), Point(2,2) };
	set<Point>::reverse_iterator r_IT_first = sPoint.rbegin();
	set<Point>::reverse_iterator r_IT_last = sPoint.rend();
	vector<Point> vPoint(r_IT_first, r_IT_last);
	stop
/*
Потоковые итераторы. С помощью ostream_iterator выведите содержимое
vector и set из предыдущего задания на экран.
*/
		ostream_iterator<Point> os(cout, "\n");//Незабыть поюзать книгу
	copy(vPoint.begin(), vPoint.end(), os);
	stop
/*
Итераторы вставки. С помощью возвращаемых функциями:
back_inserter()
front_inserter()
inserter()
итераторов вставки добавьте элементы в любой из созданных контейнеров. Подумайте:
какие из итераторов вставки можно использовать с каждым контейнером.
*/
//vector --------------back_inserter(), inserter()
//list---------------- All
//deque -------------- All

		Point w(Point(90, 90));
	back_insert_iterator<vector<Point>> it = back_inserter(vPoint);
	Point ar[] = { Point(5,5) , Point(6,6) , Point(7,7) };
	copy(ar, ar + 3, back_inserter(vPoint));
	copy(&w, &w + 1, back_inserter(vPoint));//Чисто по фану юзанул
	stop

///////////////////////////////////////////////////////////////////
/*
Задание 2. Обобщенные алгоритмы (заголовочный файл <algorithm>). Предикаты.
алгоритм for_each() - вызов заданной функции для каждого элемента любой последовательности
(массив, vector, list...)
С помощью алгоритма for_each в любой последовательности с элементами любого типа
распечатайте значения элементов
Подсказка : неплохо вызываемую функцию определить как шаблон
*/
	{
		system("cls");
		vector<int> vInt = {9,0,8,1,7,2,6,3,5,4};
		for_each(vInt.begin(),vInt.end(),Print<int>);
		stop
	}
/*
С помощью алгоритма for_each в любой последовательности с элементами типа Point
измените "координаты" на указанное значение (такой предикат тоже стоит реализовать
как шаблон) и выведите результат с помощью предыдущего предиката
*/
	{
		system("cls");
		vector<Point> vPoint2 = { Point(1,1) , Point(2,2) , Point(3,3) , Point(4,4) , Point(5,5) , Point(6,6) };
		for_each(vPoint2.begin(), vPoint2.end(), New_coordinat<Point, 7, 7>);
		for_each(vPoint2.begin(), vPoint2.end(), Print<Point>);
		stop
	}
/*
С помощью алгоритма find() найдите в любой последовательности элементов Point все итераторы на элемент Point с указанным значением.
*/
	{	//Вместо сохранения значений итераторов на найденные элементы. Подсчитываю их количество.
		//Что бы сохранять значения итераторов выполнить п.1 и п.2
		system("cls");
		size_t cnt = 0;
		//Создаём ёмкость для сохранения указателей--------------------------------п.1
		vector<Point> vPoint2 = { Point(1,1) , Point(2,2) , Point(3,3) , Point(4,4) , Point(5,5) , Point(6,6) , Point(3,3) };
		vector<Point>::iterator it = vPoint2.begin();
		while (it != vPoint2.end())
		{
			it = find(it, vPoint2.end(), Point(3, 3));
			if (it != vPoint2.end())
			{
				//Туть сохраняем итераторы!!!!!!_Плодим сиамских близнецов-----------------------------------п.2
				++it;
				++cnt;
			}
		}
		stop
	}
/*
С помощью алгоритма sort() отсортируйте любую последовательность элементов Point.
//По умолчанию алгоритм сортирует последовательность по возрастанию.
Что должно быть определено в классе Point?
	Замечание: обобщенный алгоритм sort не работает со списком, так как
это было бы не эффективно => для списка сортировка реализована методом класса!!!
*/
	{
		system("cls");
		vector<Point> vPoint2 = { Point(1,1) , Point(2,2) , Point(3,3) , Point(4,4) , Point(5,5) , Point(6,6) , Point(3,3) };
		sort(vPoint2.begin(), vPoint2.end());
		for (size_t i = 0; i < vPoint.size(); i++)
		{
			cout << vPoint2[i] << endl;
		}
		stop
	}
/*
С помощью алгоритма find_if() найдите в любой последовательности элементов Point
итератор на элемент Point, удовлетворяющий условию: координаты x и y лежат в промежутке
[-n, +m].
*/
	{
		//--------------------------------------------Подумать как избавиться от шаблонности(возможно нужна просто функция с двумя параметрами)
		vector<Point> vPoint2 = { Point(1,1) , Point(2,2) , Point(3,3) , Point(4,4) , Point(5,5) , Point(6,6) , Point(3,3) };
		vector<Point>::iterator it;
		it = find_if(vPoint2.begin(), vPoint2.end(), coord<0, 2>);
		stop
	}
/*
С помощью алгоритма sort() отсортируйте любую последовательность элементов Rect,
располагая прямоугольники по удалению центра от начала координат.
*/
	{
		system("cls");
		vector<Point> vPoint2 = { Point(9,9) , Point(4,4) , Point(3,3) , Point(1,1) , Point(2,2) , Point(6,6) , Point(5,5), Point(1,1) };
		sort(vPoint2.begin(), vPoint2.end(), sort_coord);
		stop
	}
/*
transform
Напишите функцию, которая с помощью алгоритма transform переводит
содержимое объекта string в нижний регистр.
Подсказка: класс string - это "почти" контейнер, поэтому для него
	определены методы begin() и end()
*/
	{
		system("cls");
		string ABC = { "ABC" };
		string::iterator it = ABC.begin();
		transform(it, ABC.end(), it, transformation_register);
		stop
	}
	/*
	Заполните list объектами string.
	С помощью алгоритма transform сформируте значения "пустого" set, конвертируя строки в нижний регистр
	*/
	{
		system("cls");
		set<string> sChar;

		list<string> lString;
		string ABC[] = { "ABC","DEF" };
		for (size_t i = 0; i < (sizeof(ABC) / sizeof(ABC[0])); i++)
		{
			lString.push_back(ABC[i]);
		}
		stop

			set<string> sString;;
		insert_iterator<set<string>> it = inserter(sString, sString.begin());
		transform(lString.begin(), lString.end(), it, transformation_register2);
		stop
	}
/*
copy_if
Дан вектор с элементами типа string. С помощью copy_if() требуется
вывести сначала строки, начинающиеся с буквы "А" или "а", затем с "Б"...
При этом порядок строк в исходном векторе менять не нужно!
*/
	{
		system("cls");
		vector<string> vString = { "ABC","DEF", "GFH","BCD", "AHJ" };
		c_output_if(vString);
		stop
	}
/*
Дан multimap, содержаций пары: "месяц - количество денй в месяце"
pair<string, int>. С помощью copy_if сформируйте ДВА map-а: первый -
с парами, содержащими четное количество дней, 2-ой - нечетное.
*/
	{
		system("cls");
		multimap<string, int> month
		{
			{"January", 31}, {"February", 28}, {"February", 29}, { "March", 31},
			{"April", 30}, {"May",31}, {"June", 30}, {"July", 31}, {"August",31},
			{"September",30}, {"October", 31}, {"November",30}, {"December",31}
		};
		map<string, int> month_0;
		map<string, int> month_1;
		insert_iterator<map<string, int>> it = inserter(month_0, month_0.begin());
		insert_iterator<map<string, int>> itt = inserter(month_1, month_1.begin());
		copy_if(month.begin(), month.end(), it, Pred);
		copy_if(month.begin(), month.end(), itt, Pred2);
		stop
/*
Распечатайте multimap и map - ы, используя написанный вами ранее шаблон
функции, выводящей элементы ЛЮБОГО контейнера на печать.
Что нужно сделать дополнительно для вывода пары ?
*/
/*
Не стал заморачиваться с выводом. Почти всё перенружено для вывода. Если потребуется вызывайте шаблон "Print"
*/
		//c_output(month);
		cout << "----------------------------------------------------------------------" << endl;
		//c_output(month_0);
		cout << "----------------------------------------------------------------------" << endl;
		//c_output(month_1);
	}
		return 0;
}

