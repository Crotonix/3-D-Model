module mobius(radius, width, thickness){
    for(i = [0 : step : end ]){
        hull(){
        x = radius*cos(i/2);
        y = radius*sin(i/2);
        z = -(radius*i/end)/2;
        translate([x,y,z])
        rotate(i/2,v=[1,0,1])
        cube([radius, width, thickness]);
        x1 = radius*cos((i+step)/2);
        y2 = radius*sin((i+step)/2);
        z3 = -(radius*(i+step)/end)/2;
        translate([x1,y2,z3])
        rotate(i/2,v=[1,0,1])
        cube([radius, width, thickness]);
        }
    }
}

step = 8;
depth = 0;
radius = 8;
thickness = 0.5;
width = 0.4;
end =360;
mobius(radius,width,thickness);
translate([0,0,thickness]) rotate([180,0,0]) mobius(radius,width,thickness);

