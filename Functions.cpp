#include <iostream>
#include <vector>
#include <map>

using namespace std;

template <typename T>
void PrintCollection(T& collection);

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, std::pair<T1, T2> const& p);


//int main()
//{
//	int arr[5] = {0, 1, 2, 3, 4};
//	map<string, int> maps;
//	maps["US"] = 1;
//	maps["UK"] = 2;
//	
//	PrintCollection(maps);
//}

template <typename T>
void PrintCollection(T& collection)
{
	for(auto const& item : collection){
		std::cout << item << std::endl;
	}
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, std::pair<T1, T2> const& p)
{
   return out << p.first << " " << p.second;
}