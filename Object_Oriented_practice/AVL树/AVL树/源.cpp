#include <iostream>
#include <stack>
using namespace std;


template<typename Type>
class AVLTree;
template<typename Type>
class AVLNode
{
	friend class AVLTree<Type>;
public:
	AVLNode(Type& x, AVLNode<Type>* LeftChild = nullptr, AVLNode<Type>* RightChild = nullptr)
		: data(x), LeftChild(nullptr), RightChild(nullptr), bf(0)
	{

	}

private:
	Type data;
	AVLNode<Type>* LeftChild;
	AVLNode<Type>* RightChild;
	int bf;  //平衡因子
}; 

template<typename Type>
class AVLTree
{
public:
	AVLTree() : root(nullptr)
	{}
public:
	void Order()const;
	bool Insert(Type& x);
protected:
	void Order(AVLNode<Type>* root)const
	{
		if (root != nullptr)
		{
			Order(root->LeftChild);
			cout << root->data << " ";
			Order(root->RightChild);
		}
	}
	bool Insert(AVLNode<Type>* &t, Type &x);
private:
	AVLNode<Type>* root;
};




template<typename Type>
void AVLTree<Type>::Order()const
{
	Order(root);
}

template<typename Type>
bool AVLTree<Type>::Insert(Type& x)
{
	return Insert(root, x);
}

template<typename Type>
bool AVLTree<Type>::Insert(AVLNode<Type>*& t, Type& key)
{
	stack<AVLNode<Type>*> st;  //用于记录AVL的创建路径
	AVLNode<Type>* p = root;
	AVLNode<Type>* pr = nullptr;
	//找到要插入的位置
	while (p != nullptr)
	{
		pr = p;
		st.push(pr);
		if (key < p->data)
			p = p->LeftChild;
		else if (key > p->data)
			p = p->RightChild;
		else
			return false;
	}
	p = new AVLNode<Type>(key);
	if (pr == nullptr)
	{
		root = p;
		return true;
	}
	//连接结点
	if (key < pr->data)
		pr->LeftChild = p;
	else
		pr->RightChild = p;
	 
	//平衡调整平衡因子并调整树结构
	while (!st.empty())
	{
		pr = st.top();
		st.pop();

		if (pr->LeftChild == p)
			pr->bf--;
		else
			pr->bf++;

		if (pr->bf == 0)
			break;
		if (pr->bf == 1 || pr->bf == -1)
			p = pr;
		else
		{
			if (pr->bf > 0)
			{
				if (p->bf > 0)    //    \ 
				{
					//cout<<"RotateL"<<endl;
					RotateL(pr);
				}
				else             //      >
				{
					cout << "RotateRL" << endl;
					//RotateRL(pr);
				}
			}
			else
			{
				if (p->bf < 0)    //      /
				{
					//cout<<"RotateR"<<endl;
					RotateR(pr);
				}
				else             //     <
				{
					//cout<<"RotateLR"<<endl;
					RotateLR(pr);
				}
			}
			break;
		}
	}



	}






	return true;
}

int main()
{
	int ar[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	int n = sizeof(ar) / sizeof(int);
	AVLTree<int> avl;
	for (int i = 0; i < n; ++i)
	{
		avl.Insert(ar[i]);
	}
	avl.Order();
	return 0;
}