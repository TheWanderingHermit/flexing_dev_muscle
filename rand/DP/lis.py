#!/usr/bin/python

def lis( a ) :
    n = len( a )
    s = [ 1 ] * n
    for i in range( 1, n ) :
        for j in range( 0, i ) :
            if a[ i ] > a[ j ] and s[ i ] < s[ j ] + 1 :
                s[ i ] = s[ j ] + 1
    print( s )
    print( max( s ) )

a = [ 10, 22, 9, 33, 21, 50, 41, 60 ]
lis( a )
