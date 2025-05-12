#include"LeetCodeTest.h"

namespace
{
	//合并两个有序数组
	void fun1_1(vector<int> v)
	{
		for (int i = 0;i < v.size();i++)
		{
			cout << v.at(i) << " ";
		}
		cout << endl;
	}
	class Class1 {
	public:
		void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
		{
			if (m == 0)
			{
				nums1 = nums2;
				return;
			}
			if (n == 0) return;
			int pos = 0;
			int pos1 = 0;//记录比对的nums2的位置
			int pos2 = 0;//记录temp容器的写入位置
			//bool flag = false;
			vector<int> temp(n + m);
			
			for (int i = 0;i < m + n;i++)
			{
				if (i == m)//有nums2剩余元素已大于所有nums1元素
				{
					for (int k = pos1;k < n;k++)
					{
						temp.at(pos2) = nums2.at(k);
						pos2++;
					}
					break;
				}
				int j = pos1;
				if (i < m && j == n)//有nums1剩余，nums2已完成遍历
				{
					for (i;i < m;i++)
					{
						temp.at(pos2) = nums1.at(i);
						pos2++;
					}
					break;
				}
				for (;j < n;j++)
				{
					if (nums1.at(i) > nums2.at(j))
					{
						temp.at(pos2) = nums2.at(j);
						pos1++;
						pos2++;
						i--;
						break;
					}
					else if (nums1.at(i) <= nums2.at(j))
					{
						temp.at(pos2) = nums1.at(i);
						pos2++;
						break;
					}
				}
			}
			nums1 = move(temp);

		}
	};
	void fun1()
	{
		cout << "\n\nTest_fun1" << endl;

		Class1 c1;
		vector<int> num1{ 1,2,3,0,0,0 };
		vector<int> num2{ 2,5,6 };
		c1.merge(num1, 3, num2, 3);
		fun1_1(num1);

		vector<int> num3{ 1 };
		vector<int> num4;
		c1.merge(num3, 1, num4, 0);
		fun1_1(num3);

		vector<int> num5;
		vector<int> num6{ 1 };
		c1.merge(num5, 0, num6, 1);
		fun1_1(num5);

		vector<int> num7{ 2,0 };
		vector<int> num8{ 1 };
		c1.merge(num7, 1, num8, 1);
		fun1_1(num7);
	}
}

void testLeetCode()
{
	//合并两个有序数组
	fun1();
}