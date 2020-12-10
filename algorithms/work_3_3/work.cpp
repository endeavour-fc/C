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
	}
	void PrintGraph()
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


template<class W>
struct LinkEdge
{
	LinkEdge<W>* _pNext;
	W _weight; // 节点的权值
	size_t _src; // 起点的下标(后面使用)
	size_t _dst; // 终点的下标
	LinkEdge(size_t src, size_t dst, const W& weight)
		: _src(src)
		, _dst(dst)
		, _weight(weight)
		, _pNext(NULL)
	{}
};

template<class V, class W, bool IsDirect = false>
class Graph
{
	typedef LinkEdge<W> LinkEdge;
	typedef Graph<V, W, IsDirect> Self;
public:
	Graph(const V* array, size_t size)
		: _v(array, array + size)
	{
		_linkEdges.resize(size);
	}
	void AddEdge(const V& v1, const V& v2, const W& weight)
	{
		size_t src = GetIndexOfV(v1);
		size_t dst = GetIndexOfV(v2);
		_AddEdge(src, dst, weight);
		if (!IsDirect)
			_AddEdge(dst, src, weight);
	}
	size_t GetIndexOfV(const V& v)
	{
		for (size_t i = 0; i < _v.size(); ++i)
		{
			if (v == _v[i])
				return i;
		}
		assert(false);
		return -1;
	}
	void PrintGraph()
	{
		for (size_t index = 0; index < _v.size(); ++index)
		{
			cout << "v[" << _v[index] << "]--->";
			LinkEdge* pCur = _linkEdges[index];
			while (pCur)
			{
				cout << "v[" << _v[pCur->_dst] << "]--->";
				pCur = pCur->_pNext;
			}
			cout << "NULL" << endl;
		}
	}
	int GetVDev(const V& v)
	{
		size_t index = GetIndexOfV(v);
		LinkEdge* pCur = _linkEdges[index];
		size_t count = 0;
		while (pCur)
		{
			count++;
			pCur = pCur->_pNext;
		}
		if (IsDirect)
		{
			int dst = index;
			for (size_t src = 0; src < _v.size(); ++src)
			{
				if (src == dst)
				continue;
				else
				{
					LinkEdge* pCur = _linkEdges[src];
					while (pCur)
					{
						if (pCur->_dst == dst)
							count++;
						pCur = pCur->_pNext;
					}
				}
			}
		}
		return count;
	}
private:
	void _AddEdge(size_t src, size_t dst, const W& weight)
	{
		LinkEdge* pCur = _linkEdges[src];
		while (pCur)
		{
			if (pCur->_dst == dst)
				return;
			pCur = pCur->_pNext;
		}
		LinkEdge* pNewNode = new LinkEdge(src, dst, weight);
		pNewNode->_pNext = _linkEdges[src];
		_linkEdges[src] = pNewNode;
	}
private:
	vector<V> _v;
	vector<LinkEdge*> _linkEdges;
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