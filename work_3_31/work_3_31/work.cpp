#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Base
{
public:
	virtual void show()
	{
		cout << "Base:....." << endl;
	}

};
class D :public Base
{
public:
	virtual void show()
	{
		cout << "D:........" << endl;
	}
};
int main()
{
	Base* b = new D;
	//b->show();
	Base b1;
	//b1.show();
	D b2;
	//b2.show();
	system("pause");
	return 0;
}

int ADD(int num1, int num2)
{
	while (num2)
	{
		//int a = num1;
		//int b = num2;
		//num1 = a ^ b;
		//num2 = (a&b) << 1;
		int temp = num1 ^ num2;
		num2 = (num1&num2) << 1;
		num1 = temp;
	}
	return num1;
}
void oddInOddEvenInEven(vector<int>& arr, int len) {
	int i = 0;
	int j = 1;
	while (i<len&&j<len)
	{
		if (arr[i] % 2 == 1 && arr[j] % 2 == 0)
		{
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			//swap(arr[i],arr[j]);
			i += 2;
			j += 2;
			continue;
		}
		if (arr[i] % 2 == 0)
			i += 2;
		if (arr[j] % 2 == 1)
			j += 2;
	}
}
    string longestPalindrome(string s) {
        if(s==" ")
        return s;
        string temp(s.rbegin(),s.rend());
        vector<vector<int>> v(s.size(),vector<int>(s.size(),0));
        int MaxLen=0;
        int pos=0;
        for(int i=0;i<s.size();++i)
        {
            for(int j=0;j<s.size();++j)
            {
                if(s[i]==temp[j])
                {
                    if(i==0||j==0)
                    v[i][j]=1;
                    else
                    v[i][j]=v[i-1][j-1]+1;
                }
                if(v[i][j]>MaxLen)
                {
                    int thispos=s.size()-1-j;
                    if(thispos+v[i][j]-1==i)
                    {
                        pos=i-v[i][j]+1;
                        MaxLen=v[i][j];
                    }
                }
            }
        }
        return s.substr(pos,MaxLen);

    }
int getFirstUnFormedNum(vector<int> arr, int len) {
	int min = arr[0];
	int sum = 0;
	for (int i = 0; i<len; i++)
	{
		if (min>arr[i])
			min = arr[i];
		sum += arr[i];
	}
	int i = 0;
	arr.insert(arr.begin(), 0);
	int temp = 0;
	for (i = min + 1; i<sum; i++)
	{
		int j = 0;
		for (j = 0; j<len; j++)
		{
			int k = 0;
			for (k = j + 1; k <= len; k++)
			{
				if (i == arr[j] + arr[k])
				{
					break;
				}
			}
			if (k == len + 1)
				continue;
			if (i == arr[j] + arr[k])
				break;
		}
		if (j == len)
			return i;
	}
		return sum + 1;
}
//int main()
//{
//	int num = 0;
//	while (cin >> num)
//	{
//		vector<int> v;
//		for (int i = 2; i <= (int)sqrt(num); i++)
//		{
//			if (num == 1)
//				break;
//			if (num%i == 0)
//			{
//				while (num%i == 0)
//				{
//					v.push_back(i);
//					num /= i;
//				}
//			}
//			if (num == 1)
//				break;
//		}
//		if (num > 1)
//			v.push_back(num);
//		cout << v[v.size() - 1] << endl;
//
//	}
//
//	return 0;
//}
//int main()
//{
//	http://www.taobao.com
//	vector<int> v = { 3,1,2 ,5,6};
//	cout << getFirstUnFormedNum(v, v.size()) << endl;
//	//string s("cbbd");
//	//cout << longestPalindrome(s) << endl;
//	//vector<int> v{ 1,2,3,4 };
//	//oddInOddEvenInEven(v, v.size());
//	//int num1 = 0;
//	//int num2 = 0;
//	//while (cin >> num1 >> num2)
//	//{
//	//	cout << ADD(num1, num2) << endl;
//	//}
//	system("pause");
//	return 0;
//}