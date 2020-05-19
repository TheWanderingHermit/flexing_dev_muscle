def mk_class( x ) :
    class dog :
        def __init__( self, name ) :
            self.name = name
        def print_val( self ) :
            print( x ) 
    return dog

cls = mk_class( 10 )
print( cls )
