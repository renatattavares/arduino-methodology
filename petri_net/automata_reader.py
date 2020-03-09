"""
Module to interpret automata txt file and generate the relation between all states
"""

def read_automata(automata_file):

    with open(automata_file) as automata:
        lines = automata.readlines()

    print('\n##### Automata file interpretated #####')

    return lines
