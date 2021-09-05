#pragma once
#include <iostream>
#include <vector>

using namespace std;

namespace leo
{
	class bitset
	{
	public:
		bitset(size_t bitCount)
			: _bit((bitCount >> 5) + 1)
			,_bitCount(bitCount)
		{}

		// 将which比特位置1
		void set(size_t which)
		{
			int index = which / 32;
			int num = which % 32;
			_bit[index] |= (1 << num);
		}
			// 将which比特位置0
		void reset(size_t which)
		{
			int index = which / 32;
			int num = which % 32;
			_bit[index] &= ~(1 << num);
		}
		// 检测位图中which是否为1
		bool test(size_t which)
		{
			if (which > _bitCount)
			{
				return false;
			}

			int index = which / 32;
			int num = which % 32;

			return (_bit[index] &= (1 << num));
		}

		size_t size()const { return _bitCount; }

	private:
		vector<int> _bit;
		size_t _bitCount;
	};
}
