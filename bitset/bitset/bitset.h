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

		// ��which����λ��1
		void set(size_t which)
		{
			int index = which / 32;
			int num = which % 32;
			_bit[index] |= (1 << num);
		}
			// ��which����λ��0
		void reset(size_t which)
		{
			int index = which / 32;
			int num = which % 32;
			_bit[index] &= ~(1 << num);
		}
		// ���λͼ��which�Ƿ�Ϊ1
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
