import os
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np

# Function to read measurements from a file
def read_measurements(filename):
    measurements = []
    with open(filename, 'r') as file:
        for line in file:
            parts = line.strip().split(',')
            if len(parts) == 3:
                measurements.append((int(parts[0]), int(parts[1]), float(parts[2])))
    return measurements

# Get the current directory and construct the file path
current_dir = os.getcwd()
file_path = os.path.join(current_dir, 'problem1_data_insertionSort.txt')

# Read measurements from file
measurements = read_measurements(file_path)

# Unpacking the measurements
max_values, array_sizes, times = zip(*measurements)

# Convert to numpy arrays for easier handling
max_values = np.array(max_values)
array_sizes = np.array(array_sizes)
times = np.array(times)

# Creating the 3D plot
fig = plt.figure(figsize=(16, 12))  # Increase the figure size (width, height) in inches
ax = fig.add_subplot(111, projection='3d')

# Plotting
scatter = ax.scatter(max_values, array_sizes, times, c=times, cmap='viridis', marker='o')

# Adding labels and title
ax.set_xlabel('Max Integer Value')
ax.set_ylabel('Array Length')
ax.set_zlabel('Time (seconds)')

# Adding a color bar
color_bar = fig.colorbar(scatter, ax=ax, extend='both')
color_bar.set_label('Sorting Time (seconds)')

plt.subplots_adjust(left=0.1, right=0.9, top=0.9, bottom=0.1)

plt.savefig(os.path.join(current_dir, '3d_plot.png'), dpi=500)

# Show the plot
plt.show()