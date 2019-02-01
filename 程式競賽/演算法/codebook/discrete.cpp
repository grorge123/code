#include <bits/stdc++.h>
using namespace std;
vector<int> v;
#define ALL(X) (X).begin() , (X).end()
void add( int x ){
	v.push_back( x );
}
void discrete(){
	sort( v.begin() , v.end() );
	v.resize( unique( v.begin() , v.end() ) - v.begin() );
}
int vl( int x ){
	return lower_bound( v.begin() , v.end() , x ) - v.begin() + 1;
}
int a[ N ];
void init(){
	int n = getint();
	for( int i = 0 ; i < n ; i ++ ){
		a[ i ] = getint();
		add( a[ i ] );
	}
	discrete();
	for( int i = 0 ; i < n ; i ++ )
		a[ i ] = vl( a[ i ] );
}