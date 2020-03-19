#include<iostream>
#include<string>
using namespace std;

int lengthOfLongestSubstring(string s) {
	string::iterator it1 = s.begin();

	int len = 0;
	int flag = 0;

	string temp;
	while (it1 != s.end())
	{
		if (temp.empty())
		{
			temp += *it1;
			if (temp.size()>len)
			{
				len = temp.size();
			}
		}
		else
		{
			for (string::iterator it = temp.begin(); it != temp.end(); it++)
			{
				if (*it == *it1)
				{
					if (temp.size()>len)
					{
						len = temp.size();
					}
					temp.erase(temp.begin(), it + 1);
					break;
				}

			}
			temp += *it1;
		}
		it1++;
	}
	if (temp.size() > len)
		len = temp.size();
	return len;

}
int main()
{
	cout << lengthOfLongestSubstring("au") << endl;
	
	system("pause");
	return 0;
}