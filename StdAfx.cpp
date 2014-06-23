// stdafx.cpp : source file that includes just the standard includes
//	GoodsManageSystem.pch will be the pre-compiled header
//	stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

BOOL bDesc = 0;
int nColToSort=0;
int nLastColToSort=0;

bool IsNumber( LPCTSTR pszText )
{
	if (lstrlen( pszText )==0||lstrlen( pszText )>9)
		return false;
	for( int i = 0; i < lstrlen( pszText ); i++ )
		if( !_istdigit( pszText[ i ] ) )
			return false;
		
		return true;
}


int NumberCompare( LPCTSTR pszNumber1, LPCTSTR pszNumber2 )
{
	const int iNumber1 = atoi( pszNumber1 );
	const int iNumber2 = atoi( pszNumber2 );
	
	if( iNumber1 < iNumber2 )
		return -1;
	
	if( iNumber1 > iNumber2 )
		return 1;
	
	return 0;
}



