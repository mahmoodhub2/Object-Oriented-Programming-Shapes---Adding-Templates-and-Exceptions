/* this include file contains a number of template functions */

template <class X> X combineShape(X& a, X& b)
{
	X	c;

	c = a + b;

	return c;
}

template <class X> X ComeApart(X& a, X& b)
{
	X	c;

	c = a - b;

	return c;
}

template <class X, class Y, class Z> Z combineDiffrentShape(X& a, Y& b)
{
	Z	c;

	c = a + b;

	return c;
}

template <class X, class Y, class Z> Z ComeApart(X& a, Y& b)
{
	Z	c;

	c = a - b;

	return c;
}
