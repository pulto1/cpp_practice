#include <iostream>

using namespace std;

template<class K, class V>
class BSTreeNode
{
public:
	BSTreeNode(){}

	BSTreeNode(K key, V value)
		:_key(key)
		,_value(value)
		,left(nullptr)
		,right(nullptr)
	{}

	V _value;
	const K _key;	
	BSTreeNode<K, V>* left;
	BSTreeNode<K, V>* right;
};

template<class K, class V>
class BSTree
{
	typedef BSTreeNode<K, V> Node;
public:
	bool Insert(const K& key, const V& value)
	{
		Node* newnode = new Node(key, value);

		if (_root == nullptr)
		{
			_root = newnode;
			return true;
		}

		Node* prev = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key > key)
			{
				prev = cur;
				cur = cur->left;
			}

			else if (cur->_key < key)
			{
				prev = cur;
				cur = cur->right;
			}

			else
			{
				return false;
			}
		}

		if (prev->_key > key)
		{
			prev->left = newnode;
		}

		if (prev->_key < key)
		{
			prev->right = newnode;
		}

		return true;
	}

	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (key < cur->_key)
			{
				cur = cur->left;
			}

			else if (key > cur->_key)
			{
				cur = cur->right;
			}

			else
			{
				return cur;
			}
		}

		return nullptr;
	}

	bool Erase(const K& key)
	{
		Node* prev = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (key < cur->_key)
			{
				prev = cur;
				cur = cur->left;
			}

			else if (key > cur->_key)
			{
				prev = cur;
				cur = cur->right;
			}

			else
			{
				break;
			}
		}

		if (cur == nullptr)
			return false;

		//cur��Ϊ��
		if (cur->left == nullptr)
		{
			if (cur == _root)
			{
				_root = cur->right;
			}

			else
			{
				if (prev->left == cur)
				{
					prev->left = cur->right;
				}

				if (prev->right == cur)
				{
					prev->right = cur->right;
				}
			}
			
			delete cur;
		}

		//cur��Ϊ��
		else if (cur->right == nullptr)
		{
			if (cur == _root)
			{
				_root = cur->left;
			}

			else
			{
				if (prev->left == cur)
				{
					prev->left = cur->left;
				}

				if (prev->right == cur)
				{
					prev->right = cur->left;
				}
			}

			delete cur;
		}

		//cur���Ҷ���Ϊ��
		//�����������ҽ��
		else
		{
			prev = cur; //prev��������Ϊ�գ���Ϊcur����û��ȥ
			Node* BigLeft = cur->left; //һ����Ϊ��
			while (BigLeft->right)
			{
				prev = BigLeft;
				BigLeft = BigLeft->right;
			}

			//BigLeft��cur��������
			//����cur��BigLeft
			cur->_key = BigLeft->_key;

			//ɾ��BigLift,BigLeft�ұ�Ϊ��
			if (prev->left == cur)
			{
				prev->left = cur->left;
			}

			if (prev->right == cur)
			{
				prev->right = cur->left;
			}

			delete BigLeft;
		}

		return true;
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		//������
		_InOrder(root->left);
		cout << "key: " << root->_key << "  value: " << root->_value << endl;		
		_InOrder(root->right);
	}
	
	void InOrder()
	{
		_InOrder(_root);
	}
private:
	Node* _root = nullptr;
};

void TestBSTree()
{
	BSTree<string, string> dict;
	dict.Insert("insert", "����");
	dict.Insert("erase", "ɾ��");
	dict.Insert("left", "���");
	dict.Insert("string", "�ַ���");

	string str;
	/*while (cin >> str)
	{
		auto ret = dict.Find(str);
		if (ret)
		{
			cout << str << ":" << ret->_value << endl;
		}
		else
		{
			cout << "����ƴд����" << endl;
		}
	}*/

	string strs[] = { "ƻ��", "����", "ƻ��", "ӣ��", "ƻ��", "ӣ��", "ƻ��", "ӣ��", "ƻ��" };
	// ͳ��ˮ�����ֵĴ�
	BSTree<string, int> countTree;
	for (auto str : strs)
	{
		auto ret = countTree.Find(str);
		if (ret == NULL)
		{
			countTree.Insert(str, 1);
		}
		else
		{
			ret->_value++;
		}
	}
	countTree.InOrder();
}

int main()
{
	TestBSTree();
	return 0;
}