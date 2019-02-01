struct BIT
{
	int sz , dat[ MAXN ];
	void init( int _sz)
	{sz = _sz;fill(dat,dat+sz+1,0);}
	void upd( int id , int x )
	{ for( int i = id ; i <= sz ; i += i&-i ) dat[ i ] += x; }
	int qry( int id )
	{
		int res = 0;
		for( int i = id ; i > 0 ; i -= i&-i ) res += dat[ i ];
		return res;
	}
} bit;