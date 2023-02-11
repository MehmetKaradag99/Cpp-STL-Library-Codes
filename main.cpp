#include <random>
#include <string>
#include <iostream>
#include <forward_list>
#include <algorithm>
#include <ctime>
#include<iterator>
#include<vector>
#include<list>
#include "nutility.h"
#include <set>
#include<functional>
#include<deque>
#include<cstdlib>
#include<cmath>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<set>
#include<map>
#include<ostream>
#include<array>
#include<stack>
#include<queue>
#include<tuple>
#include<bitset>
#include<functional>
#include<memory>


//[] param icine initializerlist ile dene mesela {"ali","veli"}yi copylesin
//******************      KESINLIKLE VECTORLERDE SINIFLARLA ILGILI BIR CALISMA YAP VE DATE SINIFINI KAVRA            *******************************///
///////////////////////////////////////   string str;  str.substr(1)  ---->>>> 1. elemandan basla hepsini yaz   ///////////////////////////////////////////

////////////////////////////////////////////////		OSTREAM I TAM ANLA OZELLIKLE dline I ////////////////////////////////////////////////


using namespace std;

#if 0

template<typename T, typename U>
auto find_index(T svec, U&& f)
{
	if (auto iter = find_if(svec.begin(), svec.end(), f); iter != svec.end())
		return iter-svec.begin();
}

template<typename T>
void count_specified_name(T vec, const string& name)
{
	vector<string> svec; // bos konteyner old icin back_inserter
	copy_if(vec.begin(), vec.end(), back_inserter(svec), [](const string& name) {
		return name == string{ "mehmet" };
		});
	auto numberOfSpecifiedName=count_if(svec.begin(), svec.end(), [](const string& name) {
		return name == string{ "mehmet" };
		});
	cout << numberOfSpecifiedName;

}


class CL_Teams {
public:
	CL_Teams() = default;
	CL_Teams(string team) : clteam(team)
	{
	}
	friend ostream& operator<<(ostream& os,const CL_Teams& cl)
	{
		return os << cl.clteam;
	}
private:
	string clteam;
};

void CL_TeamsInit()
{
	vector<CL_Teams> champleague;
	CL_Teams rma{ string{"real madrid"} };
	CL_Teams atm{ string{"atletic madrid"} };
	CL_Teams bar{ string{"barcelona"} };
	CL_Teams fb{ string{"fenerbache"} };



	champleague.push_back(rma);
	champleague.push_back(atm);
	champleague.push_back(bar);
	champleague.push_back(fb);

	champleague.emplace_back("Ludogorets");

	print(champleague);

	//generate_n(back_inserter(champleague), 100, []() {
		//return CL_Teams{ string{rname()}};
		//});
}

size_t cnt = 0;

template<typename T>
void longestName(T svec)
{
	static T tempsvec = svec;
	if (auto iter = find_if(svec.begin(), svec.end(), [](const string& s) {
		for (const auto i : tempsvec)
		{
			if ((s.size() > i.size()))
				++cnt;
			else if (s == i)
				++cnt;
		}
		if (cnt == tempsvec.size()) 
		{
			
			return 1;
		}
		else
		{
			cnt = 0;
			return 0;
		}
		}); iter != svec.end())
	{
		cout << *iter;
	}
		
}

void foo(int*, size_t) {}


void eraseIdx(auto& vec, auto idx)
{
	if (vec.empty() || vec.size()<idx)
		throw runtime_error{ "Vector's empty" };
	vec.erase(vec.begin() + idx);
}


static void eraseProcessing(auto& svec, const string& name,auto& sizeOfVector)
{
	while (sizeOfVector)
	{
	if (auto iter = find(svec.begin(), svec.end(), name); iter != svec.end())
		svec.erase(iter);
	--sizeOfVector;
	}
}

void eraseName(auto& svec, const string& name)
{
	auto sizeOfVector = svec.size();
	if (svec.empty())
		throw runtime_error{ "Vector's empty" };
	eraseProcessing(svec, name, sizeOfVector);

}

void copyAnything(const auto& svec1, auto& svec2, const string& copiedName)
{
	copy_if(svec1.begin(), svec1.end(), back_inserter(svec2), [copiedName](const string& Name) {
		return Name == copiedName;
		});
}

struct x {
	int a;
	int b;
};

void foo(const string* cptr)
{
	cout << *cptr;
}


struct Ali {
	friend bool operator <(const Ali& left, const Ali& right)
	{
		return left < right;
	}
	friend bool operator >(const Ali& left, const Ali& right)
	{
		return left > right;
	}
};



class w {
public:
	friend bool operator <(const w& x, const w& y);
	friend bool operator >(const w& x, const w& y);
	friend ostream& operator<<(ostream& os, const w& x);
private:
	int x = 2;
	int y = 3;
};

bool operator <(const w& x, const w& y)
{
	return x.x < y.y;
}
bool operator >(const w& x, const w& y)
{
	return x.x > y.y;
}

ostream& operator<<(ostream& os, const w& x)
{
	return os << x;
}

template<typename T>
T ABS(T x)
{
	return (x >= 0) ? (x) : ((-1) * x);
}

int* foo(int* x)
{

	return x;
}

//typedef int* type;

using typeofbracket = pair<string, string>;



	#define NO  0
	#define YES 1

	auto BracketsTruth(string brackets)
	{
		auto n = brackets.size();
		//acýlýs paranteziile kapanýþ parantezi arasýndaký uyumluluk için olan degýsken
		int flag{ 1 };
		//kapanma parentezi ilk gelirse no return etmek ýcýn
		int reverse_control = 0;
		//eger eleman sayýsý cýft sayý degýlse zaten no return edýlýr
		if (n % 2 != 0)
		{
			return NO;
		}
		//acýlýs ve kapanýs parentezlerýnýn býrbýrýne olan esýtlýgýnýn kontrolu ýcýn olan degýskenler
		int counter1 = 0; int counter2 = 0;
			while (n)
			{
				//acýlýs parantezý sayýsý
				if (brackets.at(brackets.size() - n ) == '[' || brackets.at(brackets.size() - n) == '(' || brackets.at(brackets.size() - n) == '{')
				{
					reverse_control++;
					++counter1;
				}
				//acýlýs parantezý sayýsý
				else
				{
					//kapalý parantez baslangýcta geldý ýse return no 
					if (reverse_control == 0)
					{
						return NO;
					}
					//acýlýs ve kapanýs parantezý arasýndaký uyumluluk kontrolu
					if (abs(brackets.at(n) - brackets.at(n - 1)) > 2 && n!= brackets.size() && flag)
					{					
						return NO;
					}
					flag = 0;
					++counter2;
				}
				n--;

			}
			if (counter1 != counter2)
			{
				return NO;
			}
			return YES;
	}

/*int TruthForBrackets(char* bracket)
{

	int n = strlen(bracket);

	int flag = 1;

	int reverse_control = 0;

	if (n % 2 != 0)
	{
		return NO;
	}

	int counter1 = 0; int counter2 = 0;

	while (n)
	{
		//acýlýs parantezý sayýsý
		if (bracket[(strlen(bracket) - n)] == '[' || bracket[(strlen(bracket) - n)] == '(' || bracket[(strlen(bracket) - n)] == '{')
		{
			reverse_control++;
			++counter1;
		}
		//acýlýs parantezý sayýsý
		else
		{
			//kapalý parantez baslangýcta geldý ýse return no 
			if (reverse_control == 0)
			{
				return NO;
			}
			//acýlýs ve kapanýs parantezý arasýndaký uyumluluk kontrolu
			if (abs(bracket[n] - bracket[n - 1]) > 2 && n != strlen(bracket) && flag)
			{
				return NO;
			}
			flag = 0;
			++counter2;
		}
		n--;

	}
	if (counter1 != counter2)
	{
		return NO;
	}
	return YES;
}*/
//18446744073709551615




long long primes[] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,
109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,
241,251,257,263,269,271,277,281,283	,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409 };

long long maxNO = 0, oldMaxNO = 1;

bool divisor = true;

bool number_of_positif_divisors(int maxNo)
{
	if (maxNo >= 500)
		return false;
	else
		return true;
}

long long number_of_positive_divisor(long long No)
{
	long long t = 1;
	long long j = 2;
	for (long long i = 0; primes[i] <= No/2; i++)
	{
		j = 2;
		maxNO = 1;
		if ((No % primes[i]) == 0)
		{
			maxNO++;
			while (j < 100)
			{
				if ((No % (long long)(pow(primes[i], j)) == 0)) {
					maxNO++; j++;
				}
				else {
					j = 100;
				}
			}
		}
		t *= maxNO;
		if (i == 79)
			break;
	}
	maxNO = t;
	return maxNO;
}






class A {
public:
	A(int a) : x{a}
	{}
private:
	int x{ 32 };
	int y{ 19 };
	friend bool operator<(const A& a1, const A& a2);
	friend struct comp;
};

bool operator<(const A& a1, const A& a2)
{
	return a1.x < a2.y;
}

struct comp {
	bool operator()(const A& x, const A& y)const
	{
		return x.x < y.y;
	}
};
#endif




class date {
public:
	date() = default;
	date(int day, int month, int year) : _day{ day }, _month{ month }, _year{ year }
	{
	}
	friend ostream& operator<<(ostream& os, const date& _date);
	bool operator()();
private:
	int _day, _month, _year;
};

bool date::operator()()
{
    return date::_day == 0;
}

ostream& operator<<(ostream& os, const date& _date)
{
	return os << _date._day << ' ' << _date._month << ' ' << _date._year;
}

template<typename T , unsigned int N>
void foo(array<T, N>& ar)
{
	auto pp = partition(ar.begin(), ar.end(), [](const auto& s1) {
		return s1.contains('a');
		});

	print(ar);

	cout<< distance(ar.begin(), pp)<<"\n";
	
	size_t idx{ 1 };

	for (auto i = pp; i < end(ar);)
	{
		ar.at(distance(begin(ar),i)) = " ";
		advance(i, idx);
	}

	if(idx != 1)
	   ar.at(N-1) = " ";

	print(ar);
}

ostream& operator<<(ostream& os, const array<int, 10>& ar)
{
	for (int i = 0; i < 10; i++)
	{
		os << ar.at(i);
	}

	return os << ar.back();
}

template<typename T, typename U>
pair<T, U> foo(T x, U y)
{
	U a = 21;
	
	throw runtime_error{ "sdasfh" };
	return pair{ x,y };

}


class mystack : public stack<int> {
public:
	void print()const
	{
		auto n = size();
		while (n--)
		{
			cout << *(--c.end());
		}
	}
};

template<typename T , typename U>
void generate_vector(T x, U y)
{
	static int i{};
	vector<U> ivec;
	ivec.insert(ivec.begin(),y);
	if (i < 99) {
		reverse(ivec.begin(), ivec.end());
		print(ivec);
	}
	++i ;
}

template<typename T>
void func(T x)
{
	cout << typeid(x).name();
}

template<typename T=string>
class myvector : public vector<string>
{
public:
	void pop_front(void)
	{
			erase(vector<string>::begin());		
	}
};

enum class speciality {
	age = 0,
	gender = 1,
	name = 2
};

typedef enum {
	age,
	salary,
	identityy,
	height,
	name
}Property;

namespace Garb {
	using nname = string;
	using salary = int;
}

namespace SupportScope {
	using Age = int;
	using Salary = int;
	using Identity = string;

	using person = tuple<Age, Salary, Identity>;
}
namespace fooFuncForTuple {
	SupportScope::person foo() {
		return SupportScope::person{ make_tuple(32,43222,"Ali Beran") };
	}
}

struct nec {
	int a;
	double b;
	int c[20];
};



void TupleFunc(int x, double y, string z)
{
	cout << z;
}

using tpl = tuple<int, double, string>;

struct strct {
	int a = 3;
	int b = 4;
};

using bit16 = bitset<16>;

//struct refwrap {
	//int datbuff[2048];
//};

namespace Special {

	typedef struct {
		int a;
		int b;
		int c;
	} nec;

	nec neco = { 1,2,3 };

	nec foo()
	{
		return { 2,31,5 };
	}
}

namespace specialimportant {

	class myclass {
	public:
		myclass() = default;
		int x{}, y{};
		tuple<int,int,int> operator()()
		{
			return make_tuple(3, 4, 5);
		}
	private:
		friend void foo();
		int z{};
	};
	void foo()
	{
		myclass m;
		//private'da eleman old ýcýn alamaz frendlik ver
		auto[a, b, c] = m;
	}
	template<typename T>
	void foo(T refwrap)
	{
		int y = 31;
		refwrap = y;
	}
	void func(auto x)
	{
		cout<<x[3];
	}

}

namespace Bindd {
	void func(int a,int b,int c)
	{
		cout << a << b << c;
	}
	class myclass {
	public:
		void operator()(int x, int y)
		{
			cout << x << " " << y;
		}
	};
	void foo(int& x, int& y)
	{
		++x;
		++y;
	}
	namespace Bind {
		class myclass {
		public:
			void foo(int a, int b)
			{
				cout << a << " " << b << "\n";
			}
		};
		class functor {
		public:
			void operator()(int x, int y)const
			{
				cout << x << " " << y << " \n " ;
			}
		};
	}

}

void fn(int& x)
{
	++x;
}

namespace binding = Bindd::Bind;

namespace forRefWrap {
	template<typename T>
	void foo(T x)
	{
		++x;
	}
}

void refwrapfunc(auto x)
{
	++x;
	++x;
}

namespace memfn {
	class nec {
	public:
		nec(int x = 0) : mx{ x } {}
		void print()const
		{
			cout << mx;
		}
		void set(int val)
		{
			mx = val;
		}
	private:
		int mx{};
	};
	class myclass {
	public:
		void foo()
		{

		}
		int func(int)
		{

		}
		double foo(string)
		{

		}

	};
	class neco {
	public:
		void foo(void)
		{
			cout << "memfn::nec::foo\n";
		}
	private:
		friend void func();
		int x{ 3 };
	};
	void func()
	{
		neco nec;
		neco nec1;

		int neco::* pv = &neco::x;

		nec.*pv = 32;

		nec1.*pv = 62;
	}
}

class myclassnec
{
public:
	void baz(int) {}
	int x{ 32 };
	int y{ 12 };
	int z{ 53 };
};

//int(myclass::*fptr[])(int) = {&myclass::foo,&myclass::func....}


//HANGISINI GONDERDI ISE ONUN UZERINDE ISLEM YAPAR YANI KULLANICIYA BIRAKIR
void foo(myclassnec& nec, int myclassnec::* pv)
{
	auto val = nec.*pv;
}

using mfptr = int(memfn::myclass::*)(int);

int sum(int a, int b)
{
	return a + b;
}

class pred {
public:
	bool operator()(string name)
	{
		auto iter = name.find('a');
		return iter != string::npos;

	}
};

class predict {
public:
	void foo()
	{
		cout << "aaaaaa";
	}
};

namespace testForStruct {
	struct mystruct {
		mystruct() { cout << "x"; }
		mystruct(const mystruct& other)
		{
			cout << "y";
		}
	};
	struct yourstruct : private mystruct {
		yourstruct() { cout << "a"; }
		~yourstruct(){}
		//int a = 3;
	};
}

namespace not_fnTest {
	int func(int x)
	{
		return (x % 2 == 0);
	}
}

struct functor {
	int x = 32;
	bool operator()(int x)
	{
		return x%2 == 0;
	}

	operator int()
	{
		return x;
	}
};

bool cube(int x)
{
	return x % 2 == 0;
}

int main()
{
	using namespace std::placeholders;

	cout << boolalpha;

	function<bool(int)> fn = functor{};

	cout<<fn(32);

	/*cout << boolalpha;

	function<bool(int)> fn = cube;

	cout<<fn(32);*/

	/*vector<int> ivec1;

	generate_n(back_inserter(ivec1), 100, []() {
		return Rand{ 0,99 }();
		});

	print(ivec1);

	vector<int> ivec2;

	copy_if(ivec1.begin(), ivec1.end(), back_inserter(ivec2), not_fn(not_fnTest::func));

	print(ivec2);*/



//	testForStruct::mystruct u;
//	testForStruct::mystruct y = u;

	//testForStruct::yourstruct x;

	//predict x;

	//auto fptr = &predict::foo; // void(predict::*fptr)() = &myclass::foo

	//invoke(fptr, x);
	
	/*pred x;

	auto bv = invoke(x, rname());

	cout << boolalpha;

	cout << bv;*/


	/*int a{32};
	int b{ 55 };

	auto val = invoke(sum, a, b);*/

	/*myclassnec x;
	myclassnec y;
	myclassnec z;

	auto fn = mem_fn(&myclassnec::baz);
	fn(x, 3);

	auto fn1 = &myclassnec::baz; // auto = void(myclass::*fn1)(int) = %myclass::baz;

	(x.*fn1)(3);

	foo(x, &myclassnec::x);
	foo(x, &myclassnec::y);
	foo(x, &myclassnec::z);*/

	/*void(memfn::neco:: * mfp)(void) = &memfn::neco::foo;

	memfn::neco nec;

	(nec.*mfp)();

	memfn::func();*/

	//double(memfn::myclass::* fp)(string) = &memfn::myclass::foo;
	//mfptr mfp = &memfn::myclass::func;

	/*memfn::nec mynec{5};
	
	auto fn = mem_fn(&(memfn::nec::print));

	fn(mynec);

	auto fx = mem_fn(&memfn::nec::set);

	fx(mynec, 20);*/


	/*int x = 32;

	reference_wrapper<int> rw(x);

	refwrapfunc(ref(rw));

	cout << x<<" "<<rw;*/
	
	/*int x{32};

	int y{ 12 };

	reference_wrapper<int> rw{ x };

	rw++; x++;

	cout << rw << " " << x << "\n";

	rw.get() = y;

	rw++; x++; 

	cout << rw << " " << x << "\n";

	cout << y;*/



	/*int x = 14;
	int y = 86;

	reference_wrapper<int> rw(x);

	//x artar
	rw++;

	//rw degisir
	++x;

	cout << rw << " " << x << "\n";

	//x degismez
	rw = y;

	// y = x;
	rw.get() = x;

	cout << rw << " " << y << " " << x << "\n";

	//rw ve x degismez
	++y;

	cout << rw << " " << y << " " << x << "\n";

	//rw ve y deigmsez
	++x;

	cout << rw << " " << y << " " << x << "\n";*/

	//y degisir
	//++rw;

	//cout << rw << " " << y << " " << x << "\n";

	/*int x = 12;

	int y = 42;

	reference_wrapper<int> rw{ x };

	++rw;

	cout << x << "\n";

	rw = y;

	++y;

	++rw;

	cout << x << " " << y << "\n";

	rw = x;

	rw.get() = y;

	rw++;

	y++;

	x++;

	cout << x << " " << y <<  " "<< rw << " " << "\n";*/

	/*int x = 10;

	reference_wrapper<int> rw{ x };

	++rw;

	forRefWrap::foo(ref(rw));

	cout << x << "\n";

	int y{};

	rw.get() = y;

	rw++;

	cout << x << " " << y << "\n";*/

	/*int x = 12;
	int y = 16;

	reference_wrapper<int> rw1{ y };
	reference_wrapper<int> rw2{ x };

	rw1 = rw2;

	rw1++;

	rw2++;

	cout << x << " " << y << "\n";*/

	

	//auto fn = bind(binding::functor{}, 10, _1);
	//fn(3);

	/*binding::myclass m;

	auto fn = bind(&binding::myclass::foo, m, _2, _1);

	fn(12, 34);*/

	/*int y = 32;
	fn(ref(y));

	cout << y<<"\n";
	
	using namespace std::placeholders;

	//bind(Bindd::func, 10, _1, _2)(4, 5); //ONEMLI

	int a = 2;// Rand{ 0,10 }();
	int b = 5;// Rand{ 0,10 }();

	//a  ve  b degismez!!!! degistirmek icin ref ie gönder
	auto fn = bind(Bindd::foo, a, b);
	fn();

	cout << a << " " << b << "\n";

	auto ffn = bind(Bindd::foo, ref(a), ref(b));

	ffn();
	cout << a << " " << b << "\n";*/

	/*Bindd::myclass{}(4, 5);

	cout << "\n";

	auto fn = bind(Bindd::myclass{}, _1, _2);
	fn(3,4);

	cout << "\n";

	auto fnn = bind(Bindd::myclass{}, _1, _1);
	fnn(3);*/

	//auto f = bind(Bindd::func, _1, _2, _3);
	//auto f = bind(Bindd::func, _2, _1, _3);
	//auto f = bind(Bindd::func, _1, _2, _3);
	//auto fu = bind(Bindd::func, 10,23,31); //default arguman gibi
	//auto fuu = bind(Bindd::func, 10, _1, 31); //default arguman gibi func(10,3,31)
	//fuu(3);
	//fu();

	//f(1, 2, 3);



	//int x[32]{};
	//x[3] = 3;
	//specialimportant::func(ref(x));

	//int x = 10;
	//specialimportant::foo(ref(x));
	//cout << x;


	/*specialimportant::myclass m;
	int x; int y; int z;
	tie(x, y, z) = m();
	cout << x << "\n" << y << "\n" << z;*/

	//auto [x, y, z] = Special::foo();
	//cout << x;

	/*refwrap x;

	vector<int> ivec;

	generate_n(back_inserter(ivec), 100, []() {
		return Rand{ 0,100 }();
		});

	count_if(begin(ivec), end(ivec), ref(x));*/
	
	/*int x = 10;

	auto y = ref(x); //cref const reference_wrapper

	++y;

	cout << x;

	int a = 32;

	y.get() = a;*/


	/*int x = 10;
	int y = 56;
	reference_wrapper<int> r = x;

	++r;

	cout << x << "\n";

	//r = y; //sýfýrdan baslýyor yaný artýk x'i etkilemeyi býrakýyor

	r.get() = y; //x'i etkiliyor;

	++r;

	cout << x << "\n";*/

	/*vector<string> myvec;

	generate_n(back_inserter(myvec), 100, []() {
		return rname();
		});

	sort(myvec.begin(), myvec.end());

	print(myvec);


	auto a = lower_bound(myvec.begin(), myvec.end(), "abdullah");

	auto b = upper_bound(myvec.begin(), myvec.end(), "abdullah");

	cout << *a << "\n" << *b;

	cout << "\n" << distance(a, b);*/

	/*set<string> myset;

	for (size_t i{}; i < 100; ++i)
	{
		myset.insert(rname());
	}

	string mystr{ rname() };

	if (auto iter = myset.find(mystr); iter != end(myset))
	{
		myset.erase(iter);

		if (auto [x, success] = myset.insert(mystr); success == true)
		{
			cout << "insertion successful\n";
		}

	}

	auto x =  myset.extract(mystr);

	if (!x.empty())
	{
		x.value() = "berat";
		myset.insert(move(x));
	}

	print(myset);

	auto iteratorx = myset.lower_bound(rname());

	cout<<distance(begin(myset), iteratorx);*/


	

	/*list<string> x;

	list<string> y;

	generate_n(back_inserter(x), 10, []() {
		return string{ rname() };
		});

	generate_n(back_inserter(y), 10, []() {
		return string{ rname() };
		});

	x.splice(x.begin(), y, y.begin(), prev(y.end()));

	print(x);*/

	/*print(x);

	print(y);

	x.sort();

	y.sort();

	const auto f = [](string a, string b) {
		return a.size() > b.size();
	};

	x.merge(y, f);

	print(x);*/

	/*list<int> x{213,21421,212,4};

	auto a = x.unique([](const auto& x,const auto& y) {
		return x % 2 == 0 && y%2==0;
		});
	print(x);*/

	/*string x{"Ali"};

	string y{ "Ali" };

	x.append(y,0,3);*/

	//cout << x;
	/*itset<64> x{2134564421u};

	auto s = x.to_string();

	reverse(s.begin(), s.end());

	cout << s<<"\n";*/


	/*bitset<16> x{54};
	bitset<16> y{ 21};

	cout << x << "\n";

	cout << y << "\n";

	cout << (x ^ y);*/

	//bitset<16> x{ 33 };

	//x.reset();

	//x |= (1 << 5);

	//x = x << 5;

	//cout << x;

	//bitset'de saðdan 0-1-2... diye sýralanýlýr

	/*bitset<8> x; //defaultu zero initialization

	x.set(4);

	cout << x << "\n";

	x.reset();

	cout << x<<"\n";

	x.set(6);

	cout << x << "\n";

	x.reset(6);

	cout << x << "\n";

	x = 232;

	cout << x << "\n";

	x.flip(); //toggle eder

	cout << x<<"\n";

	x.reset();

	x = 232;

	x.flip(3);

	cout << x << "\n";

	x = 34;

	cout << x << "\n";

	cout << ~x<<"\n";

	cout << x.any()<<"\n"; //hic bir var mi
	                 
	cout << x.all()<<"\n"; // hepsi bir mi

	cout << x.count() << "\n"; //kac tane bir var

	cout << x.none() << "\n"; // hepsi sifir mi?

	x = 39;

	cout << x << "\n";

	bitset<8> y;

	for (size_t i{}; i < x.size(); ++i)
	{
		cout << x[i];
		y[i]=x[i];
	}

	cout << "\n";

	cout << y << "\n";

	x.reset();

	x.set(3);

	cout << x << "\n";

	cout << x[3]<<"\n";

	bitset<8> a{ 13 };

	bitset<8> b{ 69 };

	cout << (a == b)<<"\n";*/

	
	//BITSET'DE < YA DA > OLMADIGI ICIN COMP KUR VE ULONG A CEVIREREK KUCUKTEN BUYUGE SIRALA
	/*const auto fcomp = [](const bit16& x, const bit16& y) {
		return x.to_ullong() < y.to_ullong();
	};
	
	set<bit16,decltype(fcomp)> myset;

	for (size_t i{}; i < 100; ++i)
	{
		myset.insert(Rand{ 0,255 }());
	}

	print(myset);

	const auto x = *(next(begin(myset)));

	cout<< x.count();*/

	/*bitset<8> x;

	x.set();

	cout << x<<"\n";

	x = 0;

	x.set(3);

	cout << x << "\n";

	x = 0;

	x.set(5);

	cout << x<< " \n ";*/


	/*bitset<132> x{2132414};

	cout << x<<"\n";

	cout << x.count(); //1'lerin sayisi*/

	//bitset<16> x{ "01000111" };
	//cout << x;

	/*string str{"0101"};
	bitset<16> x{ str,1,2};
	cout << x;*/

	//bitset<16> x(12);
	//cout << x;

	//cout << sizeof(bitset<64>); //4 bayt ve yukarýsýný hesaplar

	//3 bitlik sayi
	/*bitset<3> x;
	cout << x;*/

	/*strct s;
	auto& [q,w] = s;

	cout << q << " " << w << "\n";

	array<int, 5> x{ 0,1,2,3,4 };

	cout << get<3>(x)<<"\n";

	tuple_element_t<0, decltype(x)> a;

	cout << typeid(a).name() << "\n";

	cout << tuple_size_v<decltype(x)>;*/

	//tuple_size_t and tuple_element_t
	/*tpl a;

	auto x = tuple_size_v<tpl>;
	tuple_element_t<1, tpl> y = 3.2;

	cout << x << " " << y;
	*/

	/*tuple<int, double, string> t{1,1.2,"ali"};

	int x;
	double y;
	string z;

	tie(x, y, z) = t;
	++x;

	auto [a, b, c] = t;
	++a;
	cout << a << " " << get<0>(t) << " " << x;;

	apply(TupleFunc, t);*/

	/*int x = 32;
	int y = 3;
	tuple<int, int> t{ y,x };

	tie(x, y) = t;

	++x;

	cout << x << " " << y<<"\n";

	cout << get<0>(t) << " " << x;*/


	/*int ival = 3;
	double dval = 4.2;

	tie(ival, dval) = tuple<int, double>{ 2,4.6 };

	cout << ival << " " << dval;*/

	/*int x = 32;
	double y = 3.3;
	auto t = tie(x, y);
	cout << get<0>(t);*/

	/*tuple<int, long, string> x{1,2,"veli"};
	int a;
	long b; 
	string c;
	auto [q, w, e] = x;
	cout << q << " " << w << " " << " " << e<<"\n";
	tie(a, ignore, c) = x;
	cout << a << " " << c;*/


	/*tuple<int, string> x{make_tuple(3,"ali")};
	int a{};
	string b;
	tie(a, b) = x;
	cout << a << " " << b;*/

	//STRUCTED BINDING ILE STRUCTI DA ALABILIRZ!!!!!!!!!!!!!
	/*auto [x, y, z] = nec{};
	cout << typeid(z).name();*/
	/*const auto& [x, y, z] = fooFuncForTuple::foo();
	cout << x << " " << y << " " << z << "\n";*/

/*	vector<SupportScope::person> tvec;

	generate_n(back_inserter(tvec), 100, []() {
		return make_tuple(Rand{ 20,40 }(), Rand{ 8500,45000 }(), (rname() + " " + rfname()));
			});

	for (size_t i = 0; i < tvec.size(); ++i)
	{
		cout << get<age>(*(next(tvec.begin(),i))) << " "  << get<salary>(*(next(tvec.begin(), i))) << " " << get<identityy>(*(next(tvec.begin(), i)))<< "\n";
	}

	sort(begin(tvec), end(tvec), [](const auto& t1, const auto& t2) {
		return (get<age>(t1) > get<age>(t2)) || (get<age>(t1) == get<age>(t2) && get<salary>(t1) > get<salary>(t2));
		});

	cout << "---------------------------------------------------------------------------------------------------------------------------------------------------\n";

	//for (size_t i = 0; i < tvec.size(); ++i)
	//{
		//cout << get<age>(*(next(tvec.begin(), i))) << " " << get<salary>(*(next(tvec.begin(), i))) << " " << get<identityy>(*(next(tvec.begin(), i))) << "\n";
	//}


	for (const auto& [Age, Sal, Ident] : tvec)
	{
		cout << Age << " " << Sal << " " << " " << Ident<<"\n";
	}
*/
	//tuple<nname, salary> tx{ make_tuple("mehmet",1987) };
	//cout << get<0>(tx) << " " << get<1>(tx);
	//using enum speciality;
	/*tuple<int, double, string> tx{23,1.75,"mehmet"};
	
	cout<<get<age>(tx)<<" ";
	cout << get<height>(tx) << " ";
	cout << get<name>(tx) << " ";*/

	/*tuple<int, int, string> x{1,2,"Ali"};
	get<2>(x) = "mehmet";
	cout<<get<2>(x).size();*/
	//tuple<int,double,string> x = make_tuple(1, 2.5, "Ali");
	//auto x = make_tuple(1, 2.5, "Ali");

	/*vector<int> ivec;
	generate_n(back_inserter(ivec), 100, []() {
		return Rand{ 0,100 }();
		});
	const auto fcomp = [](const int& s1, const int& s2) {
		return s1 > s2;
	};
	print(ivec);
	priority_queue<int, vector<int>, decltype(fcomp)> vq{ ivec.begin(),ivec.end() };

	using TempMove = priority_queue<int, vector<int>, decltype(fcomp)>;

	for (size_t i{}; i < ivec.size(); ++i)
	{
		cout << vq.top()<<" ";
		vq.pop();
		(void)getchar();
		TempMove temp{ vq };
		for (size_t i{}; i < temp.size(); ++i)
		{
			cout << temp.top()<<" ";
			temp.pop();
		}
		
		//for (size_t i{} ; i < vq.size() ; ++i)
			//cout << vq. <<" ";
		cout << "\n";

	}*/

	//ONEMLI
	/*myvector<string> svec;
	generate_n(back_inserter(svec), 100, []() {
		return rname();
		});
	print(svec);
	//svec.pop_front();
	//print(svec);
	queue<string, myvector<string>> vq{ svec };

	for (size_t i{}; i < svec.size(); ++i)
	{
		cout << vq.front() << " ";
		vq.pop();
	}*/

	/*list<int> ilist{1,2,3};
	cout << *ilist.begin();

	ilist.pop_front();

	cout << *ilist.begin();*/


	/*vector<string> svec{string{rname()},string{rname()}, string{rname()}, string{rname()}, string{rname()}, string{rname()}, string{rname()}, string{rname()}};

	print(svec);

	stack<string, vector<string>> mystack{ svec };

	for (size_t i{}; i < svec.size(); ++i)
	{
		cout << mystack.top()<<" ";
		mystack.pop();
		mystack.emplace(rname());
	}
	cout << "\n";
	for (size_t i{}; i < svec.size(); ++i)
	{
		cout << mystack.top() << " ";
		mystack.pop();
	}*/


	//POZITIF LAMDA IDIOM
	//func(+[](int) {return true; });

	/*const auto fcomp = [](const string& s1, const string& s2) {
		return s1.size() > s2.size();
		};
	vector<string> svec;

	generate_n(back_inserter(svec), 100, []() {
		return rname();
		});

	print(svec);

	priority_queue<string, vector<string>, decltype(fcomp)> sq{ svec.begin(),svec.end() };

	for (size_t i{}; i < 100; ++i)
	{
		cout << sq.top() << " ";
		sq.pop();
	}*/





	// STACK LIFO QUEUE FIFI
	/*list<int> ivec;
	generate_n(back_inserter(ivec), 100, []() {
		return Rand{ 0,100 }();
		});

	print(ivec);

	queue<int, list<int>> iq{ ivec };

	for (int i{}; i < 100; i++)
	{
		cout << iq.front()<<" ";
		iq.pop();
		
	}*/


	/*for (size_t i{}; i < 100; ++i) {
		generate_vector(100, Rand{ 0,100 }());
	}*/

	/*list<int> ilist;
	generate_n(back_inserter(ilist), 100, []() {
		return Rand{ 0,100 }();
		});

	print(ilist);

	stack<int, list<int>> mystack{ ilist };

	for (size_t i{}; i < mystack.size(); ++i)
	{
		cout << mystack.top() << " ";
		mystack.pop();
	}*/





	//stack son eklenen son cýkar
	/*vector<int> ivec;
	generate_n(back_inserter(ivec), 100, []() {
		return Rand{ 0,100 }();
		});
	print(ivec);
	stack<int,deque<int>> istack;
	for (int i = 0; i < 100; i++)
	{
		istack.push(*(next(ivec.begin(), i)));
	}
	for (int i = 0; i < 100; i++)
	{
		cout<<istack.top()<<" ";
	}*/

	/*vector<int> ivec{3,4};
	vector<int> ivec1{ 4,6 };
	ivec.swap(ivec1);
	print(ivec);
	print(ivec1);


	const auto fcomp = [](const int& n1, const int& n2) {
		return n1 < n2;
	};

	set<int, decltype(fcomp)> iset;
	
	for (size_t i{}; i < 100; ++i) {
		iset.insert(Rand{ 0,100 }());
	}

	//stack LIFO

	vector<string> svec;

	generate_n(back_inserter(svec), 100, []() {
		return rname();
		});

	print(svec);

	stack<string, vector<string>> mystack{ svec };

	for (int i = 0; i < 100; i++)
	{
		cout << mystack.top() << " ";
		mystack.pop();
	}*/

	
	//pair x = foo(3.3, 21);


	//map<array<int, 10>, string> amap;  // legal cunku array lerin < , > operatorlerý overload edýlmýs ve array<int,10> icin ostream ý overload ettým ve boylece ar dedigi anda 1231414 gýbý sayý cýktýsýný alabýlecek 

	/*array<int, 4> a1{6,0,0,0};
	array<int, 4> a2{ 5,2,1,6 };

	auto x =  a1 < a2;  // x->bool

	cout << x;*/

	/*array<string, 10> ar1;

	for (int i{}; i < 10; ++i)
	{
		ar1.at(i) = rname();
	}

	print(ar1);
	
	sort(ar1.begin(), ar1.end(), [](const auto& s1, const auto& s2) {
		return s1 > s2;
		});

	print(ar1);

	foo(ar1);*/

	/*array<int, 10> ar;

	ar.fill(0);

	for (int i = 0; i < 10; i++)
	{
		ar.at(i) = Rand{ 0,10 }();
	}

	cout << ar<<"\n";

	cout << ar.data();*/

	//array<int,10> ar2 = foo(ar)
	
	/*const auto fcomparator = [](const auto& str1, const auto& str2)
	{
		return str1.length() > str2.length() || str1.length() == str2.length() && str1 > str2;
	};

	map<string, date,decltype(fcomparator)> smap;

	cout << date{4,3,5}();

	for (int i = 0; i < 10; ++i)
	{
		smap.insert(make_pair(rname(), date{ Rand{1,31}(),Rand{1,13}(),Rand{1990,2022}() }));
	}

	print(smap);*/

	//key'e göre kucukten buyuge sýralar!!1
	/*map<string, int> smap;
	for (size_t i{}; i < 100; i++)
	{
		smap.insert(make_pair(rname(), Rand{ 0,100 }()));
	}
	print(smap);
	for (const auto& [name, idx] : smap)
	{
		if(idx%2==0)
           cout << (name + " " + rfname()) << "\n" ;
	}
	if (auto iter = smap.find("mustafa"); iter != smap.end())
	{
		cout << iter->second<<"\n";
	}*/

	/*const auto comparator = [](const int& n1, const  int& n2) {
		return n1 < n2;// n1 % 2 == 0 && n2 % 2 != 0 || n1 % 2 == n2 % 2 && n1 < n2; //n1<n2;
	};

	map<int, string,decltype(comparator)> imap;

	for (int i{}; i < 100; ++i) {
		imap.insert(make_pair(Rand{0,100}(), rname()));
	}

	if (auto iter = imap.find(35); iter != imap.end())
	{
		auto temp = iter->second;
		imap.erase(iter);
		imap.insert(make_pair(35, "mehmet"));
	}

	auto handle = imap.extract(0);

	if (!handle.empty())
	{
		//handle.key() = 124;
		handle.mapped() = "asddfdssfd";
		imap.insert(move(handle));
	}

	print(imap);*/

	/*const auto f = [](const auto& s1, const auto& s2) {
		return s1.length() > s2.length() || s1.length() == s2.length() && s1 > s2;
	};

	map<string, int, decltype(f)> smap;

	for (size_t i{}; i < 100; ++i) {
		smap.insert(make_pair(rname(), Rand{ 0,100 }()));
	}

	print(smap);

	smap[string{ "mehmet" }] = 100;

	print(smap);*/

	/*vector<string> svec;

	generate_n(back_inserter(svec), 100, []() {
		return rname();
		});

	map<string, int> smap;

	for (size_t i{}; i < 100; ++i) {
		smap.insert(make_pair(rname(), Rand{ 0,10 }()));
	}

	print(svec);

	cout << "--------------------------------------------------------------------------------------\n";

	print(smap);

	size_t i{};

	for (const auto& str : svec)
	{
		++smap[str];
	}

	print(smap);*/

	/*map<string, int> smap;

	for (size_t i{}; i < 100; ++i) {
		smap.insert(make_pair(rname(), Rand{ 0,10 }()));
	}

	print(smap);

	auto[iter,success] = smap.insert(make_pair("mehmet", 10));

	if (success == true)
	{
		smap[string{ "MEHMET" }] = 10;
	}

	print(smap);

	string str = smap.begin()->first;

	str = str + " Ali";

	cout << str;*/


	/*vector<string> svec;
	generate_n(back_inserter(svec), 1000, []() {
		return rname();
		});
	const auto fcomp = [](const string& s1, const string& s2) {
		return s1.length() > s2.length();
	};
	//sort(svec.begin(), svec.end());
	auto iter = lower_bound(svec.begin(), svec.end(), string{ "ali" }, fcomp);
	svec.insert(iter, 10,string{ "wwwwwqwqqqqqqqqqq" });
	print(svec);*/

	

	
	/*const auto fcomp = [](const string& s1, const string& s2) {
		return s1 > s2;
	};
	set<string,decltype(fcomp)> s1; set<string, decltype(fcomp)> s2;
	for (unsigned int i{}; i < 10; i++)
		s1.insert(rname());
	for (unsigned int i{}; i < 10; i++)
		s2.insert(rname());
	print(s1);
	print(s2);
	s1.merge(s2);
	print(s1);
	string name{ "Ali" };
	s1.insert(name);*/

	//bool x = isprime(1751757233);
	//cout << x;
	
	/// <summary>
	/// VECTOR LOWER BOUND
	/// </summary>
	/// <returns></returns>
	/*vector<string> svec;
	generate_n(back_inserter(svec), 1000, []() {
		return rname();
		});
	sort(svec.begin(), svec.end());
	auto iter = lower_bound(begin(svec), end(svec), "mehmet");
	svec.insert(iter, 10, "asdasfdasfsaf");
		print(svec);*/


	/// 33333333333333333333333333   lower_bound(3) bu 3 ayýlarýnýn basý olarak ýterator upper da soonu olur.
	/// 
	/// </summary>
	/// <returns></returns>
	/*multiset<int> myset;
	for (unsigned int i{}; i < 100; i++)
		myset.insert(Rand{0,10}());
	auto iter_lower = myset.lower_bound(3);
	auto iter_upper = myset.upper_bound(3);
	print(myset);
	cout << distance(myset.begin(), iter_lower)<<"\n";
	cout << distance(myset.begin(), iter_upper) << "\n";

	auto [ilow, iup] = myset.equal_range(3);

	cout << distance(ilow,iup);*/


	///SET EXTRACT ILE ALI ISMI VAR ISE ALI ISMI SETTEN SILINIR VE HANDLE A ATILIR VE HANDLE ARTIK DOLU OLUR
	/*set<string> myset;

	for (unsigned int i{}; i < 100; i++)
		myset.insert(rname());

	auto handle = myset.extract("ali");

	//cout << myset.size()<<"\n";

	if (!handle.empty())
	{
		handle.value() = "wwwww";
		myset.insert(move(handle));
	}
	else
	{
		cout << "Ali ismi bulunamadi\n";
	}

	print(myset);*/

/*	set<string> myset;

	string x = "abdullah";
	string y = "ali";

	for (unsigned int i{}; i < 100; i++)
		myset.insert(rname());

	if (auto iter = myset.find(x); iter != myset.end())
	{
		myset.erase(iter);
		auto[iterator,success]=myset.insert(y);
		if (success)
		{
			cout << "islem basarili";
			//nothing to do
		}
		else
		{
			cout << distance(begin(myset), iterator);
		}
	}
	else
	{
		cout << "isim bulunamadý";
	}*/

	/*set<string> myset;
	for (unsigned int i{}; i < 100; i++)
		myset.insert(rname());
	myset.erase("abdullah");
	if (auto n = erase_if(myset, [](const auto& s) {return s.contains('x'); }); n)
	{
		cout << "sad";
	}*/

	/*vector<string> svec;
	generate_n(back_inserter(svec), 1000, []() {
		return rname();
		});
	const auto f = [](const string& s1, const string& s2)
	{
		return s1 > s2;
	};
	set<string, decltype(f)> myset{ svec.begin(),svec.end() };

	print(myset);

	myset.insert({ "ali","veli","kavlak" });

	print(myset);*/

	/*set<string> myset;
	for (unsigned int i{}; i < 100; i++)
		myset.insert(rname());
	if (auto [iterator, success] = myset.insert("mehmet"); success == true)
	{
		cout << distance(myset.begin(), iterator)<<"\n";
	}
	else
	{
		cout << distance(myset.begin(), iterator)<<"\n";
	}
	print(myset);*/

	//set<A, comp> s;

	/*set<string> myset;
	
	for (unsigned int i{}; i < 100; i++)
		myset.insert(rname());
	print(myset);
	auto x = myset.size();
	myset.insert("abdullah");
	print(myset);
	if (x == myset.size())
		cout << "eklenmedi";
	else
		cout << "eklendi";*/



		/*const auto f = [](const string s1, const string s2) {
		return s1.length() > s2.length();
	};

	set<string, decltype(f)> s;

	for (unsigned int i{}; i < 1000; i++)
		s.insert(rname());

	print(s);*/

	//set<int> x;
	//for (int i{}; i < 100; i++)
		//x.insert(Rand{0,100}());
	//auto a = x.size();
	//cout << a << "\n\n\n";
	//print(x);

	/*forward_list s{"Ali","Veli","Musa","Vedat","Mehmet","Cumali","Zeynep","Serra","Ceyda","Ferda"};

	s.insert_after(next(s.before_begin(), 3), "Veli");

	//s.erase_after(s.begin(), s.end());

	print(s);*/

	/// <summary>
	/// LIST.SPLICE INSERT GIBI YANI L1.BEGINE L2 NIN , L2.BEGIN+3 UNU EKLICEN
	/// </summary>
	/// <returns></returns>
	/*list<string> l1; list<string> l2;
	generate_n(back_inserter(l1), 10, [] {
		return rname();
		});
	generate_n(back_inserter(l2), 10, [] {
		return rname();
		});

	l1.splice(l1.begin(), l2, next(l2.begin(), 3));

	print(l1);*/


	/// <summary>
	/// LIST MERGE 2 KONTEYNERI BIRLESTIRIR 2.SI BOSALIR SIZE 0 OLUR 1. SI ILE BIRLESIR ÝLÝST1.MERGE(COLLABLE)
	/// </summary>
	/// <returns></returns>
	/*list<string> ilist1;
	list<string> ilist2;
	generate_n(back_inserter(ilist1), 10, []() {
		return rname();
		});
	generate_n(back_inserter(ilist2), 10, []() {
		return rname();
		});
	auto f = [](string s1,string s2) {
		return s1 > s2;
	};
	ilist1.sort(); ilist2.sort();
	ilist1.merge(ilist2);
	//ilist1.sort([](const auto s1, const auto s2) {
		//return s1.length() > s2.length();
		//});
	print(ilist1);*/

	/// <summary>
	///		lýst icin remove ýf uye fonk
	/// </summary>
	/// <returns></returns>
	/*list<int> ilist;
	generate_n(back_inserter(ilist), 100, []() {
		return Rand{ 0,100 }();
		});

	auto silinen_oge_sayisi = ilist.remove_if([](const auto x) {return x % 2 == 0; });

	print(ilist);

	auto x = erase(ilist, 3);

	//cout << x;
	*/

	///// LIST SORT UYE FONK PARAMETRE OLARAK COLLABLE ALIR
	////  LIST UNIQUE ILE AYNI OLANLARI SILERSIN ORNEK MEVCUT COLLABLE DIREKT PARANTEZ ICINE KONABILIR 
	/*
	list<string> slist;

	generate_n(back_inserter(slist), 100, []() {
		return rname();
		});

	const auto f = [](const string s1, const string s2) {
		return (s1.length() > s2.length()) || ((s1.length() == s2.length()) && (s1 > s2));
	};

	slist.sort(f);

	//print(slist);

	slist.unique([](const auto s1, const auto s2) {return s1.length() == s2.length(); });

	print(slist);

	*/

	/*deque<int> dvec;
	generate_n(back_inserter(dvec), 100, []() {
		return Rand{0,100}();
		});

	print(dvec);

	auto& iter = *(dvec.begin() + 4);

	dvec.push_front(3);

	cout << iter;

	print(dvec);*/

	/*list<int> dvec;
generate_n(back_inserter(dvec), 100, []() {
	return Rand{0,100}();
	});
print(dvec);
auto iter = next(dvec.begin());  // burada ne tutuyor isem tutmaya devam ediyorum!!!
dvec.insert(next(dvec.begin()), 4);
print(dvec);
cout << *iter;*/























	/*long long result = 0, sum = 3, sum1 = 0, a = 0;
	double x = 2;
	set<long long,greater<>> myset{0,1,3};
	while (divisor) {	
		sum1 = sum * x;
	    a = number_of_positive_divisor(sum1);
		if (a > oldMaxNO) {
			myset.insert(sum1);
			result = *myset.begin();
		}
		sum++; x+=0.5;
		oldMaxNO = a;
		divisor = number_of_positif_divisors(a);
	}
	cout << result;*/


	/*vector<int> x;
generate_n(back_inserter(x), 100, []() {
	return Rand{ 0,100 }();
	});
sort(x.begin(), x.end(), [](int a, int b)
	{
		maxNO = 0; minNO = 0;
		if (a > b)
		{
			for (int i = 2; i <= (a / 2); ++i)
			{
				if (a % i == 0) maxNO++;
				if (b % i == 0) minNO++;
			}
		}
		else
		{
			for (int i = 2; i <= (b / 2); ++i)
			{
				if (a % i == 0) maxNO++;
				if (b % i == 0) minNO++;
			}
			
		}
		return maxNO > minNO || (maxNO == minNO && a>b);
	});
print(x);*/








	//stringleri belli bir düzende almak için
	/*vector<string> brackets;

	string input{};

	cout << "input : ";

	getline(cin, input);

	//eleman sayýsý
	auto n = stoi(input);

	if ( n < 1000)
	{
		auto n = stoi(input);

		input.clear();

		while (n--)
		{
			//elemanlarý vector'e gecýrýyor
			getline(cin, input);
			brackets.insert(end(brackets), input);
		}
	}
	while (n)
	{
		if (BracketsTruth(*(brackets.end() - n)))
			cout << "YES\n";
		else
			cout <<"NO\n";
			n--;
	}*/

	/*int buffer[1000] = {0};
	
	char* bracket;

	int n_eleman;

	printf("input: ");

	(void)scanf("%d", &n_eleman);

	if (n_eleman < 1000)
	{
		int n = n_eleman;
		while (n--)
		{
			(void)scanf("%s", bracket);
			buffer[n_eleman - n] = TruthForBrackets(bracket);
		}
	}*/















	/*forward_list x{"eray","musa","samet"};
	auto iter = next(x.begin());
	x.insert_after(iter, "necati");
	print(x);*/
	/*vector<int> ivec{1,2,2,2,4,5,6,7,8,8,9,10,11,12,14,15,15,15};
	unique(ivec.begin(), ivec.end(), [](const auto& s1, const auto& s2) {
		return s1 % 2 == s2 % 2;
		});
	print(ivec);*/
	//vector<int> x{1,2,3,4,5};
	//list<int> y;
	//y.assign(x.begin(), x.end()); print(y);
	/*int x = 33;
	int* a = foo(&x);

	cout << *a;*/
	/////////////////legal
	/*int x = 3;
	int a[1] = { x };*/
	//////////////////

	/*string x = "Ali";
	string y(x, 1, 1);
	cout << y;*/

	/*vector<bool> x{true,false,false,true};

	cout << boolalpha;

	cout << x[1];*/

	/////legal
	//sizeof 12.3;
	//////////

	/*vector<int> x;
	generate_n(back_inserter(x), 100, []() {
		return Rand{ 0,100 }();
		});

	auto [min_iter, max_iter] = minmax_element(begin(x), end(x));

	cout << *min_iter<<"\n";
	cout << *max_iter;*/


	/*vector<int> x;
	generate_n(back_inserter(x), 100, []() {
		return Rand{ 0,100 }();
		});

	auto a = max_element(begin(x), end(x));
	auto b = min_element(begin(x), end(x));

	cout << *a<<"\n";
	cout << *b;*/

	/*vector<int> x;
	generate_n(back_inserter(x), 100, []() {return Rand{ 0,100 }(); });
	make_heap(x.begin(), x.end());
	print(x);*/
	 


	////////////////////////////////////////////////////  IS _ PARTITIONED(begin,end,lamda) -> lamda ile diyom ki yaptýgým ýþlemý saglayan gercekten basa alýndý mý 

	/*vector<int> x{0,2,4,6,8,3,5,7,9};

	cout << boolalpha;

	cout << is_partitioned(begin(x), end(x), [](const int& x) {
		return x % 2 == 0;
		});*/

	///////////////////////// PARTITION_POINT = PARTITION

	/*vector<int> ivec{3,7,9,1,6,4,2};

	auto iter = partition_point(ivec.begin(), ivec.end(), [](const auto& x) {
		return x % 2 != 0;
		});
	cout << iter-ivec.begin();*/
	             

	                                      /////AUTO X = IS_SORTED_UNTIL(BEGIN(X),END(X),GREATER{})   X->ITERATOR 
	/*vector<int> ivec{0,1,2,3,4,5,6,7,1};
	cout << boolalpha;
	auto x = is_sorted_until(begin(ivec), end(ivec));
	cout << *x;*/

	/*vector<int> ivec;
	generate_n(back_inserter(ivec), 100, []() {
		return Rand{ 0,100 }();
		});

	sort(begin(ivec), end(ivec));

	cout << boolalpha;

	cout << is_sorted(begin(ivec), end(ivec));*/



	                                 //MAKE_HEAP, PUSH_HEAP, POP_HEAP

	/*vector<int> ivec;
	generate_n(back_inserter(ivec), 100, []() {
		return Rand{ 0,100 }();
		});
	make_heap(ivec.begin(), ivec.end());

	ivec.push_back(43);

	push_heap(ivec.begin(), ivec.end());

	pop_heap(ivec.begin(), ivec.end());

	ivec.pop_back();*/



	                                     /// <summary>
	                                    /// PARTITION COPY
	                                   /// </summary>
	                                  /// <returns></returns>
	/*
	vector<string> v1;
	vector<string> v2;
	vector<string> v3;

	generate_n(back_inserter(v1), 100, []() {
		return rname();
		});



	auto [a, b] = partition_copy(v1.begin(), v1.end(), back_inserter(v2), back_inserter(v3), [](const string& str) {
		return str.contains('a');
		});
	//print(v1); print(v2); print(v3);



	auto pp = partition(v1.begin(), v1.end(), [](const string& x) {
		return x.contains('e');
		});
	print(v1);
	cout << *pp;
	*/

	/*vector<person> x;
	generate_n(back_inserter(x), 100, []() {
		return pair{ Rand{0,100}(),rname() };
		});
	sort(x.begin(), x.end(), [](const person& p1, const person& p2) {
		return p1.first > p2.first || p1.first == p2.first && p1.second.size() > p2.second.size();
		});
	print(x);*/

	                    //PARTIAL_SORT
	/*vector<person> x;
	generate_n(back_inserter(x), 100, []() {
		return pair<int, string>{Rand{ 0,100 }(), rname() };
		});
	partial_sort(x.begin(), x.begin() + 20, x.end(), [](const person& p1, const person& p2) {
		return p1.first > p2.first;
		});
	print(x);*/


	/*vector<person> x;
	generate_n(back_inserter(x), 100, []() {
		return person{ Rand{0,100}(), rname() };
		});
	sort(x.begin(), x.end(), [](const person& p1, const person& p2) {
		return p1.first < p2.first;
		});
	vector<person> y;
	copy(x.begin(), x.begin() + 20, back_inserter(y));
	print(y);
	print(x);*/



	                   //PARTITION

	/*vector<int> x;
	generate_n(back_inserter(x), 100, [] {
		return Rand{ 0,100 }();
		});
	auto pp = partition(x.begin(), x.end(), [](const auto& x) {
		return x % 10 == 0;
		});
	print(x);
	cout << *pp;*/

	



	/*x X = {
		.a = 3,
	    .b = 4
	};*/
	/*vector<int> x;
	generate_n(back_inserter(x), 100, []() {return Rand{ -100,100 }(); });
	sort(x.begin(), x.end(), [](int& a, int& b) {return ABS(a) < ABS(b); });
	print(x);*/

	/*vector<int> x;
	generate_n(back_inserter(x), 100, []() {return Rand{ 0,100 }(); });
	sort(x.begin(), x.end(), [](int& a, int& b) {
		return (a % 2 == 0 && b % 2 != 0 ) || (a % 2 == b % 2 && a < b);
		});
	print(x);*/

	/*vector<int> x;
	vector<int> y;
	vector<int> z;
	generate_n(back_inserter(x), 100, []() {return Rand{ 0,100 }(); });
	generate_n(back_inserter(y), 100, []() {return Rand{ 0,100 }(); });
	print(x); print(y);
	transform(x.begin(), x.end(),y.begin(), back_inserter(z), [](int& x, int& y) {
		return plus<int>{}(x,y);
		});
	print(z);*/


	//vector<string> x;
	//generate_n(back_inserter(x), 100, []() {
		//return rname() /* +*/ /*' ' + rfname()*/;
		//});
	//sort(x.begin(), x.end(), [](const string& s1, const string& s2) {
		//return s1.length() < s2.length() || s1.length() == s2.length() && s1 < s2;
		//});
	//print(x);


	/*w w1;111
	w w2;

	cout << (w1 > w2);
	cout << "\n\n\n\n";*/

	/* {
		vector<int> x;
		generate_n(back_inserter(x), 100, []() {
			return Rand{ 0,10 }();
			});
		replace_if(x.begin(), x.end(), [](int& x) {return x % 2 == 0; }, 9999);
		print(x);
	}*/

	/* {
		vector<int> x;
		vector<int> y;
		generate_n(back_inserter(x), 100, []() {return Rand{0,10}(); });
		replace_copy_if(x.begin(), x.end(), back_inserter(y), [](int& x) {return (x % 2 == 0); }, 999999);
		print(y);
	}*/


	/*vector<int> ivec;
    generate_n(back_inserter(ivec), 100, [] {
	return Rand{ 0,100 }();
	});

	make_heap(ivec.begin(), ivec.end());

	for (size_t i = 0; i < 10; ++i)
		ivec.push_back(Rand{ 0,100 }());

	cout << is_heap(ivec.begin(), ivec.end())<<"\n\n";

	make_heap(ivec.begin(), ivec.end());

	cout << boolalpha;

	cout << is_heap(ivec.begin(),ivec.end());*/




	/*vector<int> ivec;
	generate_n(back_inserter(ivec), 100, [] {
		return Rand{ 0,100 }();
		});

	make_heap(ivec.begin(), ivec.end());

	while (!ivec.empty())
	{
		cout << boolalpha;
		pop_heap(ivec.begin(), ivec.end());
		ivec.pop_back();
		cout << is_heap(ivec.begin(), ivec.end())<<"\n\n";
	}*/





	/*vector<int> ivec;
    generate_n(back_inserter(ivec), 100, [] {
	return Rand{ 0,100 }();
	});

	partial_sort(ivec.begin(), ivec.begin() + 20, ivec.end());

	auto iter = is_sorted_until(ivec.begin(), ivec.end());
	
	cout << distance(ivec.begin(), iter);*/



	/*vector<int> ivec;
    generate_n(back_inserter(ivec), 100, [] {
    return Rand{ 0,100 }();
    });


	auto pp = partition(ivec.begin(), ivec.end(), [](auto& x) {
		return x % 2 == 0;
		});

	print(ivec);

		auto x = count_if(ivec.begin(), ivec.end(), [](auto& n) {
			return n % 2 == 0;
		});

	cout <<x<<"\n"<< distance(pp, ivec.end()) << "\n" << *pp;*/


	/*vector<int> ivec;

	generate_n(back_inserter(ivec), 100, [] {
		return Rand{ 0,100 }();
		});
	
	auto x = max_element(ivec.begin(), ivec.end());
	auto y = min_element(ivec.begin(), ivec.end());
	auto [a, b] = minmax_element(ivec.begin(), ivec.end());

	cout << *x << "\n" << *a << "\n" <<* y << "\n" << *b;*/


	/*vector<int> ivec;

	generate_n(back_inserter(ivec), 100, [] {
		return Rand{ 0,100 }();
		});

	print(ivec);

	for_each(ivec.begin(), ivec.end(), [](int x) {return x; });

	print(ivec);*/

	/*vector<bool> bvec{true,false};
	bool b = bvec[0];
	cout << b;*/






	/*vector<int> ivec;
	generate_n(back_inserter(ivec), 100, [] {
		return Rand{ 0,100 }();
		});

	partial_sort(ivec.begin(),ivec.begin()+20,ivec.end(), less<int>{});

	print(ivec);*/




	/*vector<int> ivec;
    generate_n(back_inserter(ivec), 100, [] {
	return Rand{ 0,100 }();
	});

	print(ivec);

	auto pp = partition(ivec.begin(), ivec.end(), [](auto& x)
		{
			return x % 2 == 0;
		});

	cout << *pp<<"\n\n";

	cout << distance (pp,ivec.end())<<"\n\n";

	print(ivec);*/


	/*vector<int> ivec;

	generate_n(back_inserter(ivec), 100, [] {
		return Rand{ 0,100 }();
		});

	vector<int> destvec;
	vector<int> destvec2;

	auto pp = partition_copy(ivec.begin(), ivec.end(),back_inserter(destvec2), back_inserter(destvec), [](auto& x) {
		   return x % 2 == 0;
		});
	print(destvec);
	print(destvec2);*/



 


	

	/*vector<int> ivec;
	generate_n(back_inserter(ivec), 1000, [] {
		return Rand{ 0,10 }();
		});

	ivec.insert(ivec.begin(), { 1,1,3,3,4,4,2,2 });

	ivec.erase(unique(ivec.begin(), ivec.end()),ivec.end());

	print(ivec);*/

	/*vector<int> ivec{63,74,82,66,39,35,34,75,76,83,81,75};
    //generate_n(back_inserter(ivec), 1000, []() {
	//return Rand{ 0,100 }();
	//});

	ivec.erase(unique(ivec.begin(), ivec.end(), [](auto& x, auto& y) {return x%2 ==0 && y%2==0; }), ivec.end());

	for (auto i : ivec)
		std::cout << i << "\n";

	print(ivec);

	(void)getchar();*/

	/*vector<int> ivec;
	generate_n(back_inserter(ivec), 1000, [] {
		return Rand{ 0,10 }();
		});
	
	vector<int> destvec;

   remove_copy_if(ivec.begin(), ivec.end(), back_inserter(destvec), [](auto& ival) {return ival % 2 == 0; });

	print(destvec);

	cout << ivec.size() << "\n" << destvec.size() << "\n";*/


	/*vector<int> ivec;
	vector<int> destvec;
    generate_n(back_inserter(ivec), 1000, [] {
return Rand{ 0,10 }();
});

	reverse_copy(ivec.begin(), ivec.end(), back_inserter(destvec));

	print(destvec);

	print(ivec);*/



	/*vector<int> ivec;
	vector<int> destvec;
	generate_n(back_inserter(ivec), 1000, [] {
		return Rand{ 0,10 }();
		});

	replace_copy_if(ivec.begin(), ivec.end(), back_inserter(destvec), [](auto& ival) {return ival % 2 == 0; }, -1);

	print(destvec);*/



	/*using con = pair<int, string>;

	vector<con> pvec;

	generate_n(back_inserter(pvec), 100, [] {
		return con{ Rand{0,100}(),rname() };
		});

	sort(pvec.begin(), pvec.end(), [](con& x, con& y) {
		return x.first > y.first || (x.first == y.first && x.second > y.second);
		});

	print(pvec);*/



	/*using con = pair<string, string>;

	vector<con> pvec;

	generate_n(back_inserter(pvec), 100, [] {
		return con{ rname(),rfname() };
		});

	sort(pvec.begin(), pvec.end(), [](auto& x, auto& y) {
		return x.first > y.first || x.first == y.first && x.second > y.second;
		});

	print(pvec);*/




	/*vector<int> ivec1;
	vector<int> ivec2;

	generate_n(back_inserter(ivec1), 100, [] {
		return Rand{ 0,10 }();
		});

	generate_n(back_inserter(ivec2), 100, [] {
		return Rand{ 0,10 }();
		});

	print(ivec1);

	print(ivec2);

	vector<int> destvec;

	transform(ivec1.begin(), ivec1.end(), ivec2.begin(), back_inserter(destvec), bit_or<int>{});

	print(destvec);*/



	/*vector<int> ivec{1,1,1,1,1,1,0,3,4,5,1,4,5,6,7,2};
	unique(ivec.begin(), ivec.end());
	print(ivec);*/
	



	/*vector<string> svec;
	rfill(svec, 100, rname);

	vector<string> destvec(100);

	rfill(destvec, 1, rname);

	svec.insert(svec.begin(), destvec.begin(),destvec.end());

	print(svec);*/




	/*vector<string> svec;
	vector<string> destvec{ "Ali" };

	svec.assign({ "Veli","kirkdokuzelli" });

	print(svec);

	svec.assign(destvec.begin(), destvec.end());

	print(svec);*/


	/*vector<string> svec;

	generate_n(back_inserter(svec), 1000, [] {
		return rname();
		});

	if (auto iter = find(svec.begin(), svec.end(), "mehmet"); iter != svec.end())
	{
		svec.erase(iter);

		print(svec);
		cout << svec.size()<<"\n";

		auto x = erase(svec, "mehmet");
		cout << svec.size() << "\n"<<x<<"\n";
	}*/


	/*vector<string> svec;

	generate_n(back_inserter(svec), 1000, [] {
		return rname();
		});

	svec.erase(next(svec.begin()), prev(svec.end() - 1));

	print(svec);*/


    


	///// SILME VE KOPYALAMA SILINEN  YA DA KOPYALANAN SON OGEDEN SONRAKI OGENIN ITERATORUNU DONDURUR ///////////////


	/*vector<string>svec;

	generate_n(inserter(svec, svec.begin()), 1000, [] {
		return rname();
		});
	int Len{5};
	auto removedIter = remove_if(svec.begin(), svec.end(), [&Len](auto& name) {
		return name.size() > Len;
		});

	print(svec);

	svec.erase(removedIter, svec.end());

	sort(svec.begin(), svec.end(), [](auto& name1, auto& name2) {
		return name1 > name2 || (name1 == name2) && name1.size() > name2.size();
		});

	cout << svec.size() << "\n\n\n\n\n";

	print(svec);*/




	/*vector<string>svec;
	generate_n(back_inserter(svec), 100, []()
		{
			return rname();
		});

	auto n = erase_if(svec, [](const string& name) {
		return name.size() > 4;
		});

	print(svec);

	cout << n << "\n";*/





	//////////////////////////////////////////////////////    IS HEAP UNTIL   --->>>> RETURN DEGERÝ --->>>   HEAP LIGI BOZAN ÝTERATOR          /////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////            MAX ELEMENT - MIN ELEMENT    ///////////////////////////////////////////////////


	/*vector<int> ivec;
	generate_n(back_inserter(ivec), 100, [] {
		return Rand{ 0,100 }();
		});
	cout << "Sayi gir: \n";
	int x;
	while (!(cin >> x));
	auto number = count_if(ivec.begin(), ivec.end(), [x](auto& ival) {
		return x == ival;
		});
	vector<int> destvec;
	copy_if(ivec.begin(), ivec.end(), back_inserter(destvec), [number](auto& ival) {
		return number % 2 == ival % 2;
		});
	for (auto i : destvec)
		cout << i<<"\n";*/

/*vector<int> x(10);
vector<int> y = { 1,2,3,4,5 };
copy(y.begin(), y.end(), back_inserter(x));
auto a = y.end();
advance(a, -3);
cout << *a;
for (auto iter : x) {
	cout << iter;
}*/

/*string x("Ali");
string y(x, 1, 1);
cout << y;*/


	/*vector<int> ivec;
	generate_n(back_inserter(ivec), 100, [] {
		return Rand{ 0,100 }();
		});
	cout << "Sayi gir: \n";
	int x;
	while (!(cin >> x));

	print(ivec);

	if (auto iter = find_if(ivec.begin(), ivec.end(), [x](auto& ival)    // find_if_not ile de bulmadýgý zaman dondurrur
		{
			return x == ival;
		}); iter != ivec.end())
	{
		cout << *iter;//	cout << distance(ivec.begin(), iter);
	}*/



	/*vector ivec{1,2,3,4,5,6,7,8,2,3,4};
	if (auto riter = find(ivec.rbegin(), ivec.rend(), 2); riter != ivec.rend())
	{
		ivec.erase(riter.base() - 1);
	}
	print(ivec);*/

	/*vector ivec{1,2,3,4,5};
	auto iter = ivec.begin();
	advance(iter, 2);
	cout << *iter;*/


	/*vector<int> ivec{1,2,3,4,14,213};
	{
		auto permanentSize = ivec.size();
		for (int i{}; i < permanentSize; ++i)
		{
			ivec.pop_back();
		}
	}

	print(ivec);
	if (ivec.empty())
		cout << "Empty";*/


	//vector<int> ivec{ 1,2,3,4,14,213 };
	//cout << *next(ivec.begin(), 3);


	//vector svec{ "Ali","Veli" };
	//ector destvec{ "Mehmet","Kara" };

	//iter_swap(svec.begin(), prev(destvec.end()));

	//print(svec);




	/*vector<string> svec1;
	vector<string> svec2;
	vector<string> destvec(10);

	generate_n(back_inserter(svec1), 10, [] {
		return rname();
		});
	print(svec1);
	generate_n(back_inserter(svec2), 10, [] {
		return rname();
		});
	print(svec2);
	transform(svec1.begin(), svec1.end(), svec2.begin(), inserter(destvec,destvec.begin()), [](string& sval1, string& sval2) {
		 sval1.append("Can")  + sval2.append("Nur");
		 return sval1 + " "+ sval2;
		});

	print(destvec);*/






	
	/*vector<int> ivec;
	generate_n(back_inserter(ivec), 100, []()
		{
			return Rand{ 0,100 }();
		});
	print(ivec);
	auto max = max_element(ivec.begin(), ivec.end());
	cout << *max<<"\n";
	cout << distance(ivec.begin(), max);   ////////////  kacýncý sýrada maxý buldu*/


	///ÖRNEK =  max_element(ivec.begin(), ivec.end())->year;      



	////////////////////////////////////////                       MÝNMAX_ELEMENT                       /////////////////////////////////////////////////////

		/*vector<int> ivec;
	generate_n(back_inserter(ivec), 100, []()
		{
			return Rand{ 0,100 }();
		});
	print(ivec);

	auto [iter_min, iter_max] = minmax_element(ivec.begin(), ivec.end());
	cout << *iter_min << "\n";
	cout << *iter_max << "\n";*/


	////////////////////////////////////////////////        FOR_EACH                       /////////////////////////////////////////////

		/*vector<int> ivec;
	generate_n(back_inserter(ivec), 100, []()
		{
			return Rand{ 0,100 }();
		});
	print(ivec);

	for_each(ivec.begin(), ivec.end(), [](auto& x) {
		//cout << x<<"\n";
		if (x % 2 == 0)
			cout << x << "\n";
		});*/


	///////////////////////////////////////////////             VECTOR<BOOL>              /////////////////////////////////////////////////
	
	/*cout << boolalpha;
	vector<bool> bvec{ true,false,false,false,true };
	bool x = bvec[3];
	cout << x;*/
	





	////////////////////  MAKE HEAP ////////////////////////

	/*vector<int> ivec;
	generate_n(inserter(ivec, ivec.begin()), 15, []
		{
			return rand() % 100;
		});
	print(ivec);
	make_heap(ivec.begin(), ivec.end(), greater<int>{});
	print(ivec);*/

	/////////////////////////////           PUSH HEAP                   ///////////////////////////////////////////   ----->>>>> enteresan bir biçimde calýsmýyor greater yapýnca ama diger türlü calýsýyor

	/*vector<int> ivec;
	cout << boolalpha;
	generate_n(inserter(ivec, ivec.begin()), 15, []
		{
			return rand() % 50;
		});
	print(ivec);
	make_heap(ivec.begin(), ivec.end());
	ivec.push_back(13);	
	push_heap(ivec.begin(), ivec.end());
	cout << is_heap(ivec.begin(), ivec.end());*/


	/// <summary>
	/// ///////////////////////////////////////////////  POP HEAP ////////////////////////////////////   ----->>>> heap deki en buyugu silinmesini saglar(buyukten kucuge sayarsýn býldýgýn)
	/// </summary>
	/// <returns></returns>

	/*vector<int>ivec;
	generate_n(inserter(ivec, ivec.begin()), 15, []
		{
			return Rand{0,100}();
		});
	make_heap(ivec.begin(), ivec.end());
	while (!ivec.empty())
	{
		pop_heap(ivec.begin(), ivec.end());
		cout << *(prev(ivec.end()))<<"\n";
		ivec.pop_back();

	}*/


	/////////////////////////////////////////////////////////     SORT HEAP   ////////////////////////////////////////////////////////////////
	
		/*vector<int>ivec;
		cout << boolalpha;
	    generate_n(inserter(ivec, ivec.begin()), 15, []
		{
			return Rand{0,100}();
		});
		make_heap(ivec.begin(), ivec.end());
		print(ivec);
		sort_heap(ivec.begin(), ivec.end());
		print(ivec);
		cout << is_sorted(ivec.begin(), ivec.end());*/



	//////////////////////////////////////////     IS_SORTED_UNTIL      ////////////////////////////////////////////

	/*vector<int> ivec{1,3,5,7,11,12,14,18,22,2};
	cout << boolalpha;
	//generate_n(back_inserter(ivec), 100, [] {
		//return Rand{ 0,100 }();
		//});

	auto iter = is_sorted_until(ivec.begin(), ivec.end());
	cout << distance(ivec.begin(), iter);*/



	/////////////////////////////////////////       IS_PARTITIONED           /////////////////////////////

	/*vector<int> ivec{1,3,5,7,11,12,14,18,22,2};
	cout << boolalpha;
	//generate_n(back_inserter(ivec), 100, [] {
		//return Rand{ 0,100 }();
		//});

	cout << is_partitioned(ivec.begin(), ivec.end(), [](auto& x)
		{
			return x % 2 != 0;
		});*/

	/*	vector<int> ivec{1,3,5,7,11,12,14,18,22,2};
		cout << boolalpha;
		//generate_n(back_inserter(ivec), 100, [] {
			//return Rand{ 0,100 }();
			//}
		auto pp = partition(ivec.begin(), ivec.end(), [](auto& x) {
			return x % 2 == 0;
			});
		cout << *pp<<"\n";
		auto x = distance(ivec.begin(), pp);
		cout << x;*/
















	////////////////////////   struct ali'yi ctor olarak aldýgý sayýya gore sýrala ama operator olacak tabi      /////////////////////////

	////////////////////////////////////////////////////////////////////////////      PARTIAL SORT    ////////////////////////////////





/*	using x = pair<int, string>;
	vector<x> pvec;
	generate_n(back_inserter(pvec), 100, []()
		{
			return pair{ rand() % 100 + 1,rname() };
		});

	stable_sort(pvec.begin(), pvec.end(), [](const x& id1, const x& id2)
		{
			return id1.first < id2.first;
		});
	print(pvec);
	stable_sort(pvec.begin(), pvec.end(), [](const x& id1, const x& id2)
		{
			return id1.second < id2.second;
		});
	print(pvec);
	*/




	//////////////////////////////////////////       nth_element                    ////////////////

	/*vector<int> ivec;
	rfill(ivec, 10, Rand{ 0,100 });
	print(ivec);
	nth_element(ivec.begin(), ivec.begin() + ivec.size() / 2, ivec.end());
	print(ivec);*/






	////////////////////////////////////            PARTITION        ///////////////////////////


	/*vector<int> ivec;
	rfill(ivec, 100, Rand{ 0,100 });
	print(ivec);
	auto x = partition(ivec.begin(), ivec.end(), [](auto& r)
		{
			return r % 2 == 0;
		});
	if (x != ivec.end())
		cout << "partition point var yani hepsi cift\n";
	print(ivec);
	cout<<distance(x, ivec.end()); // tek sayisi*/



	/*vector<string> svec;
	rfill(svec, 100, rname);
	print(svec);
	auto pp = partition(svec.begin(), svec.end(), [](auto& name)
		{
			return name.find('a') != string::npos;
		});
	print(svec);
	cout << *pp<<"\n";// bundan itibaren hic a yok 
	cout<<distance(pp, svec.end())<<"\n"; // 'a' olmayan sayýsý*/

	/*vector<string> svec;
	vector<string> ok;
	vector<string> not_ok;

	rfill(svec, 100, rname);

	partition_copy(svec.begin(), svec.end(), back_inserter(ok), back_inserter(not_ok), [](const string& s) {   // a iceriyorsa ok'a icermiyor ise not_ok ' a kopyala.
		return s.contains('a');
		});
	print(svec);
	print(ok);
	print(not_ok);*/











	///////////////////////////////////       partial_sort  and ostream_iterator        //////////////////////////////////////////



	/*vector<string> svec;
	vector<string> svec2;
	generate_n(back_inserter(svec), 1000, []() {
		return rname();
		});
	partial_sort(svec.begin(), svec.begin() + 20, svec.end());
	copy(svec.begin(), svec.begin() + 100, ostream_iterator<string>{std::cout, "\n"});*/












	/*using person = pair<int, string>;

	vector<person> svec;

	generate_n(back_inserter(svec), 100, []() {
		return pair<int, string>{rand()%100 + 1, rname()}; }
		);

	sort(svec.begin(), svec.end(), [](const person& p1,const person& p2)
		{
			return p1.first > p2.first || (p1.first == p2.first && p1.second > p2.second);
		});
	for (const auto& p : svec)
		cout << p.first << " " << p.second<<"\n";*/








	/*using person = pair<int, string>;

	vector<person> svec;

	generate_n(back_inserter(svec), 100, []() {
		return pair<int, string>{rand() % 100 + 1, rname()}; }
	);

	partial_sort(svec.begin(), svec.begin()+20, svec.end(),[](const person& p1, const person& p2)
		{
			return p1.first > p2.first || (p1.first == p2.first && p1.second > p2.second);
		});
	for (const auto& p : svec)
		cout << p.first << " " << p.second << "\n";*/





	/*vector<int> ivec1;
	vector<int> ivec2;
	generate_n(back_inserter(ivec1), 10, Rand{ 0,10 });
	generate_n(back_inserter(ivec2), 10, Rand{ 0,10 });
	vector<int> ivec3;

	//transform(ivec1.begin(), ivec1.end(), ivec2.begin(), back_inserter(ivec3), plus<int>{});
	//print(ivec1);
	//print(ivec2);
	//print(ivec3);
	cout << "*************************************************************************\n";
	transform(ivec1.begin(), ivec1.end(), ivec2.begin(), back_inserter(ivec3), bit_and<int>{});  //logical_and
	print(ivec1);
	print(ivec2);
	print(ivec3);
	cout << "*************************************************************************\n";*/









	/*vector<int> ivec;
	generate_n(back_inserter(ivec), 1000, Rand{ -100,100 });

	sort(ivec.begin(), ivec.end(), [](const int& x, const int& y)
		{
			return abs(x) < abs(y);
		});
	print(ivec);*/



	//////////////////////////////////   SORT ILE TEK CIFT    /////////////////////////

		/*static vector<int> ivec{1,2,4,6,8,0};
	//generate_n(back_inserter(ivec), 10, Rand{ 0,100 });
	print(ivec);
	sort(ivec.begin(), ivec.end(), [](const int& x, const int& y)
		{
			return ((x % 2 == 0 && y % 2 != 0))  || ((x % 2) == (y % 2) && x < y);

			//print(ivec);
		});
	print(ivec);*/





	/*vector<string> svec;
	rfill(svec, 10, rname);
	sort(svec.begin(), svec.end(), greater<string>{});
	print(svec);*/


	/*vector<string> svec;
	rfill(svec, 100, rname);
	sort(svec.begin(), svec.end(), [](const string& x, const string& y)
		{
			return x.size() > y.size() || x.size()==y.size() && x>y;
		});
	print(svec);*/






	

	 


	////////////////////////////	REMOVE_COPY     //////////////////////////////
/*srand(time(NULL));

	vector<int> ivec;  // size degismiyor ve ayrýca 2ler sona gidiiyor
	vector<int> dvec;
	generate_n(inserter(ivec, ivec.begin()), 10, []() {
		return rand() % 10 + 1;
		});

	print(ivec);

	auto iter = remove_copy(ivec.begin(), ivec.end(), back_inserter(dvec), 2);
	//cout << ivec.size();

	print(dvec);

	print(ivec);*/


	/////////////////////////////////////////   REMOVE_COPY_IF    //////////////////////////////////

	/*vector<int> ivec1;
	generate_n(back_inserter(ivec1), 1000, []() {
		return rand() % 1000 + 1;
		});
	vector<int> ivec2;
	remove_copy_if(ivec1.begin(), ivec1.end(), back_inserter(ivec2), [](const int& ival)
		{
			return ival % 2 == 0 || ival % 3 == 0;
		});
	print(ivec2);*/




	///////////////////////////////////        REVERSE_COPY     /////////////////////
		/*vector<int> ivec1;
	generate_n(back_inserter(ivec1), 1000, []() {
		return rand() % 100 + 1;
		});
	vector<int> ivec2;
	reverse_copy(ivec1.begin(), ivec1.end(), back_inserter(ivec2));
	print(ivec1); print(ivec2);*/


	/////////////////////////////////////    REPLACE_IF       ////////////////////////


			/*vector<int> ivec1;
	generate_n(back_inserter(ivec1), 1000, []() {
		return rand() % 100 + 1;
		});
	replace_if(ivec1.begin(), ivec1.end(), [](const int& ival)
		{
			return ival % 2 == 0;
		}, -1);
	print(ivec1);*/





	/*vector<int> ivec1;
	vector<int> ivec2;
generate_n(back_inserter(ivec1), 1000, []() {
	return rand() % 100 + 1;
	});
replace_copy_if(ivec1.begin(), ivec1.end(),back_inserter(ivec2), [](const int& ival)
	{
		return ival % 2 == 0;
	}, -3);
print(ivec2);*/







	




	/*vector<int> ivec;
	generate_n(inserter(ivec, ivec.begin()), 1000, []() {
		return rand() % 100 + 1;
		});
	auto iter = remove_if(ivec.begin(), ivec.end(), [](int& ival)
		{
			return ival > 9;
		});
	auto dist =  distance(iter, ivec.end());
	cout << dist << "\n";
	ivec.erase(iter, ivec.end());
	print(ivec);*/

	///////////////////////    ERASE_IF     ///////////////////////////////

	/*vector<int> ivec;
	generate_n(back_inserter(ivec), 100000, []() {
		return rand() % 100 + 1;
		});
	auto n = erase_if(ivec, [](int& ival)
		{
			return ival > 9;
		});
	cout << n<<"\n";
	print(ivec);*/



	/////////////////////////         UNIQUE-> AYNILARI BASA ATAR ---->>> 10203403222 - 10234 002223 GÝBÝ   AYRIM NOKTASININ BASINI DONDURUR ITERATROR OLARAK     ////////////////
	//vector<int> ivec;
	//generate_n(back_inserter(ivec), 100, []() {
		//return rand() % 100 + 1;
		//});
	//rfill(ivec, 100, Rand{ 0,100 });
	//print(ivec);
	//ivec.erase(unique(ivec.begin(), ivec.end()), ivec.end());
	//print(ivec);


	/*vector<int> ivec;
	rfill(ivec, 100, Rand{ 0,100 });
	print(ivec);

	ivec.erase(unique(ivec.begin(), ivec.end(), [](int a, int b)
		{
			return a % 2 == b % 2;
		}), ivec.end());
	print(ivec);*/

	/*vector<string> svec;
	rfill(svec, 100, rname);

	print(svec);

		svec.erase(unique(svec.begin(), svec.end(), [](string& s1, string& s2)
			{
				return s1 > s2;
			}), svec.end());

	print(svec);*/



	////////*********************************       REMOVE           ****************************************////////////
	/*vector ivec{1,21,21,41,4,41,4,1,43,21,31,4,213,21,14,55,4,213,12,1};
	auto iter = remove(ivec.begin(), ivec.end(), 4);
	print(ivec.begin(),iter);
	auto number = distance(iter,ivec.end());
	cout << number;

	ivec.erase(iter,ivec.end());
	print(ivec);*/

	/*vector<string> svec;
	generate_n(back_inserter(svec), 100, []()
		{
			return rname();
		});
	svec.at(3).assign("Ali");
	vector<string> svec1{ svec.begin(),svec.end() };
	(* (svec.begin())).append("can");
	cout << svec[0];*/
	//foo(&( * svec.begin()));

	//vector<string> svec{ "AliBeran","MehmetBeran","AylaBeran" };
	/*auto Size = svec.size();
	while (Size--)
	{
		if (auto iter = find_if(svec.begin(), svec.end(), [](const string& name)
			{
				return name.find("Beran") != string::npos;
			}); iter != svec.end())
		{
			auto idx = (*iter).find("Beran");
			(*iter).erase(idx);
			cout << *iter;
			cout << " ";
		}
			
	}*/

	/*vector svec1{"ali","berat","karadag"};
	vector svec2{ "mehmet","okan","karadag" };

	iter_swap(next(begin(svec1), 1), prev(end(svec2), 2));

	print(svec1); print(svec2);*/





	/*vector<string> svec;
	generate_n(back_inserter(svec), 100, []()
		{
			return rname();
		});

	if (auto iter = find_if(svec.begin(), svec.end(), [](const string& name)
		{
			if (name.size() > 5)
				return 1;
			else
				return 0;
		}); iter != svec.end())
	{
		cout << *iter;
	}*/


	/*vector<int> ivec;
	generate_n(back_inserter(ivec), 10, []()
		{
			return rand()%10;
		});

	print(ivec);

	if (auto riter = find_if(ivec.rbegin(), ivec.rend(), [](const int& val)
		{
			return val == 2;
		}); riter != ivec.rend())
	{
		ivec.erase(riter.base() - 1); /////////////   KRITIK KRITIK KRITIK KRITIK KRITIK KRITIK KRITIK     ////////////////////////
		print(ivec);
	}*/



	/*vector ivec1{1,2,3,4,141,213,41,30};
	vector<int> ivec2(20);


	copy(ivec1.begin(), ivec1.end(), inserter(ivec2, next(ivec2.begin(), 4)));

	print(ivec2);*/


	/*vector ivec{1,2,3,4,5,6};
	auto iter = ivec.begin();
	cout << *next(iter, 3);
	advance(iter, 2);
	cout << *iter;*/

	/*vector ivec{1,21,31,41,41,34,1,414,23,52,421,341,5,214,1};
	auto iter1 = next(ivec.begin(), 3);
	auto iter2 = prev(ivec.end(), 3);
		cout<<distance(iter1,iter2);*/


	/*vector<string> svec{"Eray","Ali","Veli","Mehmet","Berat"};
	auto iter = svec.erase(svec.begin(), prev(svec.end())); ///SON SILINEN OGEDEN SONRAKI DEGERI GOSTERIR!!!!!!!!!
	cout << *iter;*/


	/*vector<string> svec1; vector<string> svec2;
	generate_n(back_inserter(svec), 100, []()
		{
			return rname();
		});
	copyAnything(svec1, svec2, string{ "ali" });
	print(svec2);*/


	/*vector<string> svec;
	generate_n(back_inserter(svec), 10000, []()
		{
			return rname();
		});
	auto x=count_if(svec.begin(), svec.end(), [](const string& name)
		{
			return name == "mehmet";
		});

	cout << x;*/

	//vector<string> svec1;
	//vector<string> svec2;

	/*generate_n(back_inserter(svec1), 10000, []()
		{
			return rname();
		});

	generate_n(back_inserter(svec2), 10000, []()
		{
			return rfname();
		});

	vector<string> svec3;

	transform(svec1.begin(), svec1.end(), svec2.begin(), back_inserter(svec3), [](const string& name, const string& surname) {
		return name + ' ' + surname;
		});
	print(svec3);*/



	//CL_TeamsInit();

	/*vector<string> svec;
	svec.assign(10, { "ali","veli" });
	svec.insert(svec.begin(), { "ads","asd" });*/

	/*vector<string> svec{"ali"};
	print(svec);
	svec.emplace(svec.begin(), 10, 'A');
	print(svec);*/

	/*vector<int> ivec;
	int idx{};
	rfill(ivec, 100, Rand{ 0,10 });
	print(ivec);
	cout << "What's idx= ";
		cin >> idx;
	eraseIdx(ivec, idx);
	print(ivec);*/


	/*vector<string> svec;
	rfill(svec, 100, rname);
	svec.insert(svec.begin(), { "ali","ali","ali" });

	print(svec);

	eraseName(svec,string{"ali"});

	print(svec);*/

	//////////////////////////GLOBAL ERASE///////////////////
	/*vector<string> svec;
	generate_n(back_inserter(svec), 100, [] {return rname(); });

	auto nuOfErasedItem = erase(svec, "mehmet");

	cout << nuOfErasedItem;*/




	//vector<string> svec{ "Ali","Veli" };
	//svec.push_back(string{ "kirkdokuzelli" });
	//print(svec);

	/*vector<string> svec;
	generate_n(inserter(svec,svec.begin()), 100, [] {return rname(); });
	print(svec);

	auto iter = svec.insert(next(svec.begin(),12), string{ "Ali" });
	cout << *iter;

	svec.insert(svec.begin(), { "sad","asdf","weewdsa" });
	print(svec);*/

	/*list<string> ilist{"assaad","sdafd"};
	vector<string> svec{ ilist.begin(),ilist.end()};
	svec.insert(svec.begin(), ilist.begin(), ilist.end());
	print(svec);*/


	/*vector<string> svec;
	rfill(svec, 100, rname);

	vector<string> destvec;

	destvec.insert(destvec.begin(), svec.begin(), svec.end());
	destvec.insert(destvec.end(), 100, string{ "aptalistan" });
	print(destvec);*/




	//vector<string> svec{ "Mehmet","Ali","Veli","Kavlak" };
	//svec.front().erase(2, 3);
	//cout << *begin(svec);
	


	//vector ivec{ 1,2,3,4,5,6,7,8 };
	//foo(&ivec.front(), ivec.size());

	/*vector<string> svec;
	rfill(svec, 100, rname);

	print(svec);
	

	longestName(svec);*/



	//vector<string> svec{ "ali","mehmet" };
	//svec[0] += "can";
	//svec[1] += " Ali";

	//print(svec);





	//for (const auto& d : champleague)
		//cout << d;
	//cout << ostream_iterator<CL_Teams>{cout,"\n"};

	//auto iter =  champleague.begin();
	//cout << *iter;

	//print(champleague);

	///////////////////////////////next/////prev/////////////////////
	/*list ilist{1,2,3,4,5,6,7,8,9};
	auto iter = ilist.begin(); 
	//advance(iter, 3);  // advance direkt konumu degistiriyor next konum donduruyor
    auto x =next(iter, 3);
	auto y = prev(ilist.end(), 6);
	x == y ? cout << "yes\n" : cout << "no\n";
	cout << *iter;*/

	/*vector<string> svec;
	rfill(svec, 100, rname);

	print(svec);

	svec.erase(next(svec.begin(), 3), prev(svec.end(), 6));

	print(svec);*/


	/*list ilist{1,2,3,4,5,6,7,8,9};
	//vector<int> ivec{ ilist.begin(),ilist.end() };
	vector<int> x(10, 7);
	print(x);*/


	/*vector<string> svec;
	rfill(svec, 100, rname);

	list<string> slist;
	slist.assign(svec.begin(), svec.end());
	print(slist);*/


	

	/////////iter_swap/////////////////////////////
	/*vector svecA{"Ali","Bera","Hasan"};
	vector svecM{ "Ufuk","dogukan","selim" };

	iter_swap(next(svecA.begin()), svecM.begin());
	//iter_swap(svecA.begin(),prev(svecM.end()));

	print(svecA); print(svecM);*/


	////////////transform/////////////
	/*vector<int> ivec;
	rfill(ivec, 100, Rand(0, 10));

	print(ivec);

	vector<int> destvec;

	transform(ivec.begin(), ivec.end(), inserter(destvec, destvec.begin()), [](int x) {
		return x % 2 == 0 ? x + 1 : x - 1;
		});

		print(destvec);*/


	///////////////generate_n/////////////////
	/*vector<string> ivec;
	generate_n(back_inserter(ivec), 100, []() {
		return rname();
		});
	print(ivec);*/









	//////////////////advance////////////////////////////
	/*using container = vector<string>;
	container con{ "ali","veli","kirkdokuz","elli","mehmet","tapur","navio","rftek"};
	auto iter = con.end();
	advance(iter, -2),
	cout << *iter;*/

	///////////////distance/////////////////////////////
	/*vector ivec{1,3,5,7,9,11,13,15,17};
	auto Distance = distance(ivec.begin(), ivec.end());
	cout << Distance<<"\n";
	auto x = Distance / 3;
	cout << x;*/



	//vector ivec{ 13,1,4213,4,231,411,1241,123,123,21 };
	//print(ivec.rbegin(), ivec.rend());


	/*vector<string> svec;
	rfill(svec, 10, rname);
	svec.push_back(string{ "mehmet" });
	print(svec);
	const auto f = [](const string& x) {
		return x.find("mehmet") != string::npos; };
	auto index = find_index(svec,f);
	cout << index;*/

	/*vector svec{"ali","veli","kirkdokuz","elli","salih","nur"};
	if (auto iter = find_if(svec.rbegin(), svec.rend(), [](const string& x) {return x.find('a') != string::npos; }); iter != svec.rend())
	{
		cout << *iter << "\n";
		auto riterBase = iter.base();
		cout << *riterBase << "\n";
	}*/


	///////************** 2'lerden sonuncusunu sil********************/////
	/*vector ivec{1,2,4,6,2,1,5,3,6,2,2,1,3,5,2,4,6,4};
	if (auto iter = find(ivec.rbegin(), ivec.rend(), 2); iter != ivec.rend())
	{
		auto riter = iter - ivec.rbegin();
		//cout << *(iter.base()-1);
		ivec.erase(iter.base()-1);   ///////    riter yerine riter.base()-1 kullan
		print(ivec);
	}*/


	/*vector svec{"mehmet","ali","veli","mehmet","mehmet","mehmet"};
	
	count_specified_name(svec, string{ "mehmet" });*/

	/*vector ivec{1,2,3,43,5,5 ,6,43,123,1,3,5};
	vector<int> iset;

	copy(ivec.begin(), ivec.end(), inserter(iset, iset.begin()));

	print(iset);*/


	/*vector<int> ivec1;
	vector<int> ivec2;
	rfill(ivec1, 10, Rand{ 0,10 });
	print(ivec1); cout << "\n\n\n";

	copy(ivec1.begin(), ivec1.end(), inserter(ivec2, ivec2.begin()));
	copy(ivec1.begin(), ivec1.end(), inserter(ivec2, ivec2.begin() + 3)); //ivec1 in hepsini ivec2'nin 4. indexine kopyala bir diger deyisle insert et
	print(ivec2);*/


	/*list ilist{1,2,3,4,5,6};
	for (auto iter = ilist.begin(); iter != ilist.end(); ++iter)
	{
		cout << *iter;
		//++ list icin yasal list.begin deki + operatoru yasal degil
	}*/


	//vector ivec{ 1,2,3 };
	//auto iter = ivec.begin();
	//iter += 2;
	//cout << *iter;





	/*vector<string> svec;
	rfill(svec, 20, []() {return rname() + ' ' + rfname(); });
	vector<string> copeidVal(100);
	auto iter = copy_if(svec.begin(), svec.end(), copeidVal.begin(), [](const string& x) {return  x.find('a') == string::npos; });
	print(copeidVal.begin(),iter);*/


	/*vector<string> svec;
    rfill(svec, 200, []() {return rname() + ' ' + rfname(); });
    vector<string> copeidVal(200);
	//string str;
	//getline(cin, str);
    auto iter = copy_if(svec.begin(), svec.end(), copeidVal.begin(), [](const string& x) {return  x.find("emre") != string::npos; });
    print(copeidVal.begin(),iter);*/  // copeidval --- begin begin+1 begin+2 .... end(iter oluyor) .... iter=copyalanan son itratorun býr sonraký konumu


	/*vector<string> ivec;
	rfill(ivec, 100, []() {return rname() + ' ' + rfname(); });
	print(ivec);

	auto x = count_if(ivec.begin(), ivec.end(),[](const string& s) {return s.find("mehmet") != string::npos; });
	cout << x;*/

	/*vector<string> svec;
	rfill(svec, 500, []() {return rname() + ' ' + rfname(); });
	vector<string> destvec(500);
	static string str; // local degiskeni kivircik parantez icinde kullandigimiz icin static;
	cin >> str;
	auto iter = copy_if(svec.begin(), svec.end(),destvec.begin(), [](const string& x) {return x.find(str) != string::npos; });
	print(destvec.begin(),iter);
	auto x = count_if(destvec.begin(), destvec.end(), [](const string& str) {return str.size() > 14; });
	cout << x;*/




	/*vector<string> svec1;
	vector<string> svec2;
	vector<string> svec3;
	rfill(svec1, 500,rname);

	copy_if(svec1.begin(), svec1.end(), back_inserter(svec2), [](const string& str) {
		return str.find("ali") != string::npos;
		});

	print(svec2);

	const char suffix[] = " Can";

	transform(svec2.begin(), svec2.end(), back_inserter(svec3), [suffix](const string& str)
		{
			return str + suffix;
		});
	print(svec3);*/


	/*vector<string> svec1;
	vector<int> svec2;

	rfill(svec1, 200, rname);


	transform(svec1.begin(), svec1.end(), back_inserter(svec2), [](const string& x)
		{
				return x.size();
		});

	print(svec2);*/


	/*vector<string> svec1;
	vector<int> ivec1{1,2,3,4,5,6,7,8,9,10};
	//vector<string> ivec1;

	rfill(svec1, 10, rname);

	vector<string> svec2(10);

	transform(svec1.begin(), svec1.end(), ivec1.begin(), svec2.begin(), [](const string& x, const int& y) {

		return x + ' ' + to_string(y) + ". oldu \n";

		});

	print(svec2);*/


	/*vector<string> svec;
	rfill(svec, 10, rname);
	svec.push_back(string{ "mehmet" });
	print(svec);
	if (auto iter = find(svec.begin(), svec.end(), "mehmet"); iter != svec.end())
	{
		cout << *iter<<"\n";
		cout << "index= " << (iter - svec.begin())+1;
	}*/


	//find_if_not -------->>>>> ayni mantik sadece bulamadiysa gönderiyor!!!


	/*vector<int> ivec;
	rfill(ivec, 1000, Rand(0, 1000));
	print(ivec);
	if (auto iter = find_if(ivec.begin(), ivec.end(), [](int x) { return x % 2 == 0; }); iter != ivec.end())
	{
		cout << *iter<<"\n";
		cout << iter - ivec.begin();
	}*/







//////////////////////////////////////////////////////////////           DEQUE KONTEYNIR ////////////////////////////////////////////


/*deque<bool> bd{true,false,true,true};

auto x = *next(bd.begin());
	
{
	auto iter = bd.begin();
	advance(iter, 2);
	auto x = iter;
	cout << *x<<"\n";
}
cout << boolalpha;

cout << x;*/




/*deque di{0,1,2,3,4,5,6,7,8,9};

auto& r =*(di.begin() + 3);

di.push_front(-1);

cout << r<<"\n";*/

//print(di);

/*deque di{0,1,2,3,4,5,6,7,8,9};

di.insert(next(di.begin(), 3), 4);

auto& r = di[3];   //------>>>>>bu sekilde yapinca UB oldu ************************************* (cunku ortadan ekleme yapinca hem iterator hem de referans invalidate olur******************************

cout << di[3];       //----------->>>>> bu sekýlde erisilir

//cout << di[4];*/



/*list ilist{1,2,3,4,5,6};

auto iter = next(ilist.begin(), 3);

ilist.insert(ilist.begin(), 4);

cout << *iter;*/




/*// INSERT ORTADAN YAPILINCA ITERATOR IBAVLDIATE OLDU//   */

	/*deque<int> id{1,2,3,4};
	deque<int> id1;

	//auto& r = id[0];

	id.insert(id.begin()+2, 2);

	auto iter = id.begin() + 3;

	//id.push_front(2);


	//cout << r<<"\n";

	//cout << id[0];

	cout << *iter;*/











}