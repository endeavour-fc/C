#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int jude(const void *a1, const void *a2)
{
	
	return (*(char*)a1 > *(char*)a2);
}

void my_qsort(void* base, size_t num, size_t width, int(*p)(const void *, const void *))
{
	char temp = 0;
	for(int i=0;i<num;i++)
		for (int j = 0; j < num-i-1; j++)
		{
			if (p((char *)base +( j * width), (char *)base + (j + 1)*width)>0)
			{
				for (int k = 0; k < width; k++)
				{
					temp = *((char*)base+k+ j * width);
					*((char*)base +k+ j * width) = *((char*)base + width + k+ j * width);
					*((char*)base + width + k+ j * width) = temp;
				}
			}
		
		}
}


int main()
{
	int arr[] = { 5,34,65,7,9,2,0 };
	char arr2[] = "gdvxvsfafads";
	//int temp = 0;

	//for(int i=0;i<7;i++)
	//	for (int j = 0; j < 7 - i - 1; j++)
	//	{
	//		if (arr[j] > arr[j + 1])
	//		{
	//			temp = arr[j];
	//			arr[j] = arr[j + 1];
	//			arr[j + 1] = temp;
	//		}
	//	}


	my_qsort(arr2, sizeof(arr2) / sizeof(arr2[0])-1, sizeof(char), jude);
	
		printf("%s ", arr2);
	
	system("pause");
	return 0;
}