#!/usr/bin/python

def msm( m ) :
    r = len( m )
    c = len( m[ 0 ] )
    s = [ [ 0 for m in range( c ) ] for n in range( r ) ]
    for i in range( 1, r ) :
        for j in range( 1, c ) :
            if m[ i ][ j ] == 1 :
                s[ i ][ j ] = min( s[ i ][ j - 1 ], s[ i - 1 ][ j ], s[ i - 1 ][ j - 1 ] ) + 1
            else :
                s[ i ][ j ] = 0
    smax = s[ 0 ][ 0 ]
    for a in range( r ) :
        for b in range( c ) :
            if s[ a ][ b ] > smax :
                smax = s[ a ][ b ]
    print( smax )

# Driver Program
m = [[0, 1, 1, 0, 1],
     [1, 1, 0, 1, 0],
     [0, 1, 1, 1, 0],
     [1, 1, 1, 1, 0],
     [1, 1, 1, 1, 1],
     [0, 0, 0, 0, 0]]
 
msm(m)
