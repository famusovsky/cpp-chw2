# АиСД-2, 2023, КДЗ-2
# Степанов А, БПИ212

import os
import sys
import pandas as pd
import matplotlib.pyplot as plt


def generate_graphs_from_csv(csv_path):
    csv_dir = os.path.dirname(os.path.realpath(__file__))
    os.chdir(csv_dir)
    data = pd.read_csv(csv_path, sep=';', header=None)

    string_sizes = list(range(100, 3001, 100))
    algorithm_data = list(data[data.columns[0]])
    algorithm_results = {}

    for i, name in enumerate(algorithm_data):
        parts = name.split(' - ')
        algorithm_name = parts[0]
        measurement_type = parts[1]
        measurements = list(data.iloc[i])[1:]
        if algorithm_name not in algorithm_results:
            algorithm_results[algorithm_name] = {}
        algorithm_results[algorithm_name][measurement_type] = measurements

    for algorithm_name, measurement_data in algorithm_results.items():
        plt.figure()
        for measurement_type, measurements in measurement_data.items():
            if len(string_sizes) > 10:
                x_ticks = range(0, len(string_sizes), 3)
                x_tick_labels = [string_sizes[i] for i in x_ticks]
                plt.plot(measurements, label=measurement_type)
                plt.xticks(x_ticks, x_tick_labels)
            else:
                plt.plot(string_sizes, measurements, label=measurement_type)

        file_name = csv_path.split('/')[-1]
        plt.title(
            f'{algorithm_name} Effectiveness by String Size ({file_name})')
        plt.xlabel('String Size')
        plt.ylabel('Measurement Result')

        plt.legend()
        results_dir = os.path.join("data/results", algorithm_name)
        os.makedirs(results_dir, exist_ok=True)
        plot_file_name = os.path.join(
            results_dir, f'{algorithm_name}_{file_name}.png')
        plt.savefig(plot_file_name)

    plt.show()


folders_pathes = list

if len(sys.argv) <= 1:
    folders_pathes = list(input(
        "Input path to the folder, which contains .csv files to make graphs from: "))
else:
    folders_pathes = sys.argv[1:]

for folder_path in folders_pathes:
    for file_name in os.listdir(folder_path):
        if file_name.endswith('.csv'):
            csv_path = os.path.join(folder_path, file_name)
            generate_graphs_from_csv(csv_path)
