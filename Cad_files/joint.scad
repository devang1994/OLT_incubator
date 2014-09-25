// A simple angle joint to hold 2 acryclic sheets to provide the basic structure
// for the incubator



module bracket(height,sheet_width)
{
	difference()
	{
		union()
		{
			cube([40,40,height]);
		}
		union()
		{
			translate([5+sheet_width,5+sheet_width,-1]) cube([40,40,height+10]);
			//gives the basic angle bracket shape
				
			translate([sheet_width+0.5,sheet_width+0.5,3]) cube ([sheet_width+0.5,40,height]);
			translate([sheet_width+0.5,sheet_width+0.5,3]) cube ([40,sheet_width+0.5,height]);
			//removes the slots for the sheet to go into
		}
	}
}

bracket(30,2);
//by changing the sheet width parameter in the module call above this can be adapted to acrylic sheets of different thicknesses