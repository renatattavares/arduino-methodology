"""
Module to interpret automata txt file and generate the relation between all states
"""
import pandas as pd

class AutomataWriter:

    def __init__(self, file_name):

        self.read_automata(file_name)

    def read_automata(self, file_name):
        """
        Interprets the file containing the informations of automata. Creates a list containg the lines that composes the heading and the body of file provided.
        """

        with open(file_name) as automata:
            file_lines = automata.readlines()

        automata = []
        heading = []
        space = False

        # Identify heading
        for line in file_lines:
            heading.append(line.strip())
            if line == '\n' and space == False:
                space = True
                line = None
            if line == '\n' and space == True:
                break

        # Identify automata
        lenght_heading = len(heading)
        body = file_lines[lenght_heading:]

        for line in body:
            automata.append(line.strip())

        # Store lists in the class
        self.automata = automata
        self.heading = heading

    def states_input_places(self, net_info_file = 'net_info.yaml'):
        """
        Identifies all states that are related to places that generates inputs in the petri net. These places should be notified in net_info.yaml file.
        """

        with open(net_info_file, 'r') as file:
            data = yaml.safe_load(file)

        input_places = data['input_places']

        for line in self.automata:
            if p2 in line:
                pass

    
