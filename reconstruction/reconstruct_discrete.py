# Converts a list of discrete distance measurements (from a static distance sensor), of a single rotation of an object, to create a 2D scatter plot.
# The distance is measured at discrete steps of the object rotation.
# Inputs:
# SCAN_FILENAME - file that contains a list of distance measurements in mm
# SCATTER_INTERVAL_MILLIS - interval between each measurement in milliseconds
# FULL_ROTATION_INTERVAL_MILLIS - interval of the full rotation in milliseconds

import plotly.express as px
import math

def readFileIntoList(filename):
    with open(filename) as scan:
        return [int(line.rstrip()) for line in scan]

def calculateDegreeStep(point_count):
    return 360 / point_count;

def polarCoordinatesToCartesian(length, degree):
    return [math.cos(math.radians(degree)) * length, math.sin(math.radians(degree)) * length]

def convertScanDataToCartesianData(scan_data, degree_step):
    coords_x = []
    coords_y = []
    degree = 0

    for entry in scan_data:
        cartesian_coords = polarCoordinatesToCartesian(entry, degree)
        coords_x.append(cartesian_coords[0])
        coords_y.append(cartesian_coords[1])
        degree += degree_step

    return [coords_x, coords_y]

SCAN_FILENAME = "reconstruction//scans//tinderbox_5.txt"

scan_data = readFileIntoList(SCAN_FILENAME)
degree_step = calculateDegreeStep(len(scan_data))
processed_scan = convertScanDataToCartesianData(scan_data, degree_step)

fig = px.scatter(x=processed_scan[1], y=processed_scan[0])
fig.update_layout(
    title=dict(
        text="Tinderbox scan from a top-down view using discrete step scans"
    )
)
fig.show()
