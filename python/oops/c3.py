class animal( object ) :
    def __init__( self, name, age ) :
        self.name = name
        self.age  = age
    def speak( self ) :
        print( "hi I my name is ", self.name, " and I am ", self.age, " years old" )
    def talk( self ) :
        print( "generic animal talk" )

class cat( animal ) :
    def __init__( self, name, age, color ) :
        super().__init__( name, age ) 
        self.color = color
    def talk( self ) :
        print( "meow" )

kitty = cat( "kitty", 21, "blue" )
kitty.speak()
kitty.talk()
