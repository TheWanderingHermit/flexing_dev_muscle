#!/usr/local/bin/python3 -tt
__author__     = 'Sidharth Sharma'
__copyright__  = 'Copyright 2020, Sidharth Sharma'
__license__    = 'Beer-Ware License Rev. 42'
__maintainer__ = 'Sidharth Sharma'
__email__      = 'ims.sharma@gmail.com'
__credits__    = ['Sidharth Sharma']
__version__    = '0.1'
__status__     = 'Development'

game_config = [[ 0, 0, 0 ],
               [ 0, 0, 0 ],
               [ 0, 0, 0 ]]

valid_moves = [[ 1, 1, 1 ],
               [ 1, 1, 1 ],
               [ 1, 1, 1 ]]

def get_snapshot() :
    snapshot_row_template = "| {:1d} | {:1d} | {:1d} |"
    for config_row in game_config :
        print( snapshot_row_template.format( config_row[ 0 ], config_row[ 1 ], config_row[ 2 ] ) )
    print("--------")

def make_move( player = 0, row = 0, column = 0 ) :
    try :
        if valid_moves[ row ][ column ] :
            game_config[ row ][ column ] = player
            valid_moves[ row ][ column ] = 0
        else :
            raise Exception( "invalid move index (%d, %d)" % ( row, column ) )
    except Exception as e :
        print( e )

def is_win() :
    rows = cols = len( game_config )
    for config_row in game_config :
        if config_row[ 0 ] != 0 and config_row.count( config_row[ 0 ] ) == len( config_row ) :
            print( "player %d has won the following configuration" % ( config_row[ 0 ] ) )
            get_snapshot()
            return True
    config_col = []
    for config_row_idx in range( rows ) :
        for config_col_idx in range( cols ) :
            config_col.append( game_config[ config_row_idx ][ config_col_idx ] )
        if config_col[ 0 ] != 0 and config_col.count( config_col[ 0 ] ) == len( config_col )  :
            print( "player %d has won the following configuration" % ( config_col[ 0 ] ) )
            get_snapshot()
            return True
        else :
            config_col.clear()
    config_diag = []
    for config_row_col_idx in range( rows ) :
        config_diag.append( game_config[ config_row_col_idx ][ config_row_col_idx ] )
    if config_diag[ 0 ] != 0 and config_diag.count( config_diag[ 0 ] ) == len( config_diag ) :
        print( "player %d has won the following configuration" % ( config_diag[ 0 ] ) )
        get_snapshot()
        return True
    else :
        config_diag.clear()
    for config_col, config_row in enumerate( reversed( range( rows ) ) ) :
        config_diag.append( game_config[ config_row ][ config_col ] )
    if config_diag[ 0 ] != 0 and config_diag.count( config_diag[ 0 ] ) == len( config_diag ) :
        print( "player %d has won the following configuration" % ( config_diag[ 0 ] ) )
        get_snapshot()
        return True
    has_valid_moves = False
    for row_idx in range( rows ) :
        for col_idx in range( cols ) :
            if valid_moves[ row_idx ][ col_idx ] :
                has_valid_moves = True
    if not has_valid_moves :
        print("no winning config possible. game over")
    return False

if __name__ == '__main__' :
    get_snapshot()
    make_move( 1, 0, 0 )
    is_win()
    get_snapshot()
    make_move( 1, 1, 1 )
    is_win()
    get_snapshot()
    make_move( 1, 2, 2 )
    is_win()
    get_snapshot()
