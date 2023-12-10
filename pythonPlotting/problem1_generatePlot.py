import os
import matplotlib.pyplot as plt
import numpy as np
from scipy.optimize import curve_fit

# Function to read measurements from a file
def read_measurements(filename):
    measurements = []
    with open(filename, 'r') as file:
        for line in file:
            parts = line.strip().split(',')
            if len(parts) == 3 and int(parts[0]) == 1000:  # Check if the first value is 1000
                measurements.append((int(parts[1]), float(parts[2])))  # Ignore the first value
    return measurements

# Function for exponential model
def exponential_model(x, a, b, c):
    return a * np.exp(b * x) + c

# Get the current directory and construct the file path
current_dir = os.getcwd()
file_path = os.path.join(current_dir, 'problem1_data_insertionSort.txt')

# Read measurements from file
measurements = read_measurements(file_path)

# Unpacking the measurements
array_sizes, times = zip(*measurements)

# Convert to numpy arrays for easier handling
array_sizes = np.array(array_sizes)
times = np.array(times)

# Fit the exponential model to the data
params, covariance = curve_fit(exponential_model, array_sizes, times)

# Create the 2D plot
plt.figure(figsize=(16, 12))

# Plotting the original data
plt.scatter(array_sizes, times, c='blue', marker='o', label='Original Data')

# Plotting the regression curve
array_sizes_fit = np.linspace(min(array_sizes), max(array_sizes), 400)
times_fit = exponential_model(array_sizes_fit, *params)
plt.plot(array_sizes_fit, times_fit, color='red', label='Fitted Curve')

# Adding labels, title, and legend
plt.xlabel('Array Length')
plt.ylabel('Time (seconds)')
plt.title('Array Length vs Time with Exponential Regression')
plt.legend()

plt.subplots_adjust(left=0.1, right=0.9, top=0.9, bottom=0.1)
plt.savefig(os.path.join(current_dir, '2d_plot_with_regression.png'), dpi=500)

# Show the plot
plt.show()