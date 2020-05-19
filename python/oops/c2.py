class dog( object ) :
    def __init__( self, name ) :
        self.name = name
        print( "nice, you made a dog!" )
    def speak( self ) :
        print( "Hi I am ", self.name )

a = dog( "a" )
dog( "b" ).speak()
