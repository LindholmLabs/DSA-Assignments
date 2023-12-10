import os
import matplotlib.pyplot as plt
import numpy as np

# Function to read measurements from a file
def read_measurements(filename):
    measurements = []
    with open(filename, 'r') as file:
        for line in file:
            parts = line.strip().split(',')
            if len(parts) == 3 and int(parts[0]) == 9000:  # Check if the first value is 1000
                measurements.append((int(parts[1]), float(parts[2])))  # Ignore the first value
    return measurements

# Get the current directory and construct the file path
current_dir = os.getcwd()
file_path = os.path.join(current_dir, 'problem1_data_insertionSort.txt')

# Read measurements from file
measurements = read_measurements(file_path)

# Unpacking the measurements
array_sizes, times = zip(*measurements)  # Only two values now

# Convert to numpy arrays for easier handling
array_sizes = np.array(array_sizes)
times = np.array(times)

# Creating the 2D plot
plt.figure(figsize=(16, 12))  # Adjust figure size

# Plotting
plt.scatter(array_sizes, times, c='blue', marker='o')  # Use a single color for simplicity

# Adding labels and title
plt.xlabel('Array Length')
plt.ylabel('Time (seconds)')

plt.subplots_adjust(left=0.1, right=0.9, top=0.9, bottom=0.1)

plt.savefig(os.path.join(current_dir, '2d_plot_filtered.png'), dpi=500)

# Show the plot
plt.show()