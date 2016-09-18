#include <iostream.h>

Pointer findTab(Pointer p, string sym, Attribute attr)
{
	if(!p)
	{
		this->makeItem(p, sym, attr);
	}
	else if(sym == this->sym)
	{
		return p;
	}
	else if(sym < this->sym)
	{
		return findTab(p->left, sym, attr);
	}
	else return findTab(p->right, sym, attr);
}
