#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define earth_radius 6378137

int long2tilex(double lon, int z);
int lat2tiley(double lat, int z);
double tilex2long(int x, int z);
double tiley2lat(int y, int z);
double degrees_to_radian(double degrees);
double lat_to_y(double lat);
double lon_to_x(double lon);
double lat_to_pixels(double lat, double map_minlat, double map_maxlat);
double lon_to_pixels(double lon, double map_minlon, double map_maxlon);
int tileLat2pixel(double lat);
int tileLon2pixel(double lon);
