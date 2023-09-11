#define _CRT_SECURE_NO_WARNINGS//第一行

//strstr模拟实现
#include<stdio.h>
#include<assert.h>
char* my_strstr(const char* str1, const char* str2)
{
	assert(str1 && str2);
	const char* s1 = str1;
	const char* s2 = str2;
	const char* p = str1;
	while (*p)
	{
		s1 = p;
		s2 = str2;
		while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (*s1 == '\0')
			return p;
		p++;
	}
	return NULL;
}
int main()
{
	char arr1[] = "zwh@bbbbcdfg";
	char arr2[] = "bcdfg";
	char* ret = my_strstr(arr1, arr2);
	if (ret == NULL)
	{
		printf("找不到子字符串");
	}
	else
	{
		printf("%s\n", ret);
	}
	return 0;
}


//memcpy模拟实现
#include<stdio.h>
#include<assert.h>
void* my_memcpy(void* dest, const void* src, size_t num)
{
	assert(dest && src);
	void* ret = dest;
	while (num--)
	{
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}
	return ret;
}
int main()
{
	int arr1[] = {1,2,3,4,5,6,7,8};
	int arr2[20] = { 0 };
	my_memcpy(arr2, arr1, 32);
	int i = 0;
	for (i = 0; i < sizeof(arr2) / sizeof(arr2[0]); i++)
		printf("%d ", arr2[i]);
	return 0;
}
