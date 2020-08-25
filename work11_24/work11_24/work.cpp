#include<iostream> 
#include<string> 
#include<vector>
using namespace std;
#define x        ((x>> 1) & 0x55555555) | ((x << 1) & 0xaaaaaaaa);x = ((x >> 2) & 0x33333333) | ((x << 2) & 0xcccccccc);x = ((x >> 4) & 0x0f0f0f0f) | ((x << 4) & 0xf0f0f0f0);x = ((x >> 8) & 0x00ff00ff) | ((x << 8) & 0xff00ff00);x = ((x >> 16) & 0x0000ffff) | ((x << 16) & 0xffff0000);
class MyData 
{     public:
       int  GetData()
       {
           return this->data;
       }
        void SetData(int num)        {
           this->data=num;
        }
        MyData()
        {
            this->data=0;
        }
       MyData(int num)
        {
          this->data=num;
        }
        ~MyData()
        {
  
       }
     private:
        int data;
 };
 
class CGoods
 {
     public:
         void RegisterGoods(string name,int count, float price)
        {
            this->name=name;
            this->count=count;
            this->price=price;
        }

         void SetName(string name) 
			{  
			 this->name=name;
          }
         void SetCount(int count)
        {
             this->count=count;
         }
         void SetPrice(float price)
         {
            this->price=price;
         }
         string GetName()
         {
             return this->name;
         }
         int GetCount()
         {
            return this->count;
         }
         float GetPrice()
         {
                       return this->price;
         }
         float GetTotal_price()
         {
             return this->count*this->price;
        }
     private:
         string name;
         int count;
        float price;
         float total_price;
  
 };
 //int main()
 //{
 //  //  MyData d1,d2;
 //  CGoods g1,g2;
 //  g1.RegisterGoods("abc",15,12.4);
 // cout<< g1.GetName()<<endl;
 // cout<< g1.GetCount()<<endl;
 // cout<< g1.GetPrice()<<endl;
 // cout << g1.GetPrice() << endl;
 // g1.SetName("bcd");
 // cout << g1.GetName() << endl;
 //    return 0;
 //}
int min(int a, int b)
{
	return a > b ? b : a;
}
int minSubArrayLen(int s, vector<int>& nums) {
	for (int i = 1; i<nums.size(); ++i)
		nums[i] += nums[i - 1];
	int ret = INT_MAX;
	nums.insert(nums.begin(), 0);
	for (int i = 1; i<nums.size(); ++i)
	{
		for (int j = 0; j<i; ++j)
		{
			if (nums[i] - nums[j] >= s)
			{
				ret = min(ret, i - j);
			}
		}
	}
	return ret == INT_MAX ? 0 : ret;
}

//int main()
//{
//	vector<int> v{ 1,2,3,4,5};
//	cout<<minSubArrayLen(11, v)<<endl;
//
//	system("pause");
//	return 0;
//}
void stringtonum(string str)
{
	vector<string> v;
	int begin = 0;
	int end = 0;
	while (begin < str.size())
	{
		end = str.find(' ',begin);
		v.push_back(str.substr(begin, end - begin));
		if (end == -1)
			break;
		begin = end + 1;
	}

	for (auto& e : v)
	{
		cout << e << endl;
	}
}
//int main()
//{
//
//	stringtonum("12 13 15 27 18 30");
//
//	system("pause");
//	return 0;
//}
bool isequal(vector<int>& v)
{
	for (int i = 1; i<v.size(); ++i)
	{
		if (v[i] != v[i - 1])
			return false;
	}
	return true;
}
int getmax(vector<int>& v)
{
	int max = 0;
	int ret = 0;
	for (int i = 0; i<v.size(); ++i)
	{
		if (v[i]>max)
		{
			max = v[i];
			ret = i;
		}
	}
	return ret;
}
void addone(vector<int>& v, int flag)
{
	for (int i = 0; i<v.size(); ++i)
	{
		if (i != flag)
		{
			++v[i];
		}
	}
}

int main()
{
	int n = 0;
	while (cin >> n)
	{
		vector<int> v(n, 0);
		for (int i = 0; i<n; ++i)
			cin >> v[i];
		int num = 0;
		while (!isequal(v))
		{
			int flag = getmax(v);
			addone(v, flag);
			++num;
		}
		cout << num << endl;
	}

	return 0;
}