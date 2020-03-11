"""
Module to interpret automata txt file and generate the relation between all states
"""
import pandas as pd

def read_automata(automata_file):

    with open(automata_file) as automata:
        lines = automata.readlines()

    automata = []

    for line in lines:
        start = '(START)' in line
        final = '(FINAL)' in line
        if start is False and final is False:
            automata.append(line.strip().split(" "))

    dataframe = pd.DataFrame(automata, columns = ['State', 'Event', 'State'])

    print('\n##### Automata file interpretated #####')

    return dataframe
