#define  _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<string>
#include<vector>
#include<functional>
#include <algorithm>
#include<stack>
#include<assert.h>
using namespace std;

template<class V,class W, bool IsDirect = false>
class Graph
{
private:
	vector<V> _v;
	vector<vector<W>> _edges;
public:
	Graph(V* _array,size_t size):_v(_array,_array+size)
	{
		_edges.resize(size);
		for (int i = 0; i < size; ++i)
		{
			_edges[i].resize(size);
		}
	}
	size_t GetIndexOfV(const V& v)
	{
		for (int i = 0; i < _v.size(); ++i)
		{
			if (v == _v[i])
				return i;
		}
		assert(false);
		return -1;
	}
	size_t GetDevOfV(const V& v)
	{
		size_t count = 0;
		size_t index = GetIndexOfV(v);
		for (int i = 0; i < _v.size(); ++i)
		{
			if (_edges[index][i])
				++count;
		}
		if (IsDirect)
		{
			for (int i = 0; i < _v.size(); ++i)
			{
				if (_edges[i][index])
					++count;
			}
		}
		return count;
	}
	void AddEdge(const V& v1, const V& v2, const W& weight)
	{
		size_t index1 = GetIndexOfV(v1);
		size_t index2 = GetIndexOfV(v2);
		_edges[index1][index2] = weight;
		if (!IsDirect)
			_edges[index2][index1] = weight;
	}	void PrintGraph()
	{
		size_t N = _v.size();
		for (size_t i = 0; i < N; ++i)
			cout << _v[i] << " ";
		cout << endl;
		for (size_t i = 0; i < N; ++i)
		{
			for (size_t j = 0; j < N; ++j)
			{
				printf("%2d ", _edges[i][j]);
			}
			cout << endl;
		}
	}
};

int main()
{
	char s[] = "ABCDE";
	Graph<char,int> g(s,strlen(s));
	g.AddEdge('A', 'D', 10);
	g.AddEdge('A', 'E', 20);
	g.AddEdge('B', 'C', 10);
	g.AddEdge('B', 'D', 20);
	g.AddEdge('B', 'E', 30);
	g.AddEdge('C', 'E', 40);

	g.PrintGraph();

	system("pause");
	return 0;
}