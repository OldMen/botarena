


bot = function( _id )
{
	var id = _id;
	this.tick = function()
	{
		print( "tick" + id );
	}
}

var o1 = new bot( 10 );
var o2 = new bot( 20 );

BotScheduler.appendBot( "bot1", o1.tick )
BotScheduler.appendBot( "bot2", o2.tick )

