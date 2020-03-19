"""
Module to interpret automata txt file and generate the relation between all states
"""
import pandas as pd
import yaml

class AutomataWriter:

    def __init__(self, file_name):

        self.read_automata(file_name)
        self.states_input_places()
        self.write_state_machine()

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

        # Cleaning automata's blank lines
        for line in body:
            if line.strip() != '':
                automata.append(line.strip())

        # Store lists in the class
        self.automata = automata
        self.heading = heading

    def states_input_places(self, net_info_file = 'petri_net/net_info.yaml'):
        """
        Identifies all states that are related to places that generates inputs in the petri net. These places should be notified in net_info.yaml file.
        """

        with open(net_info_file, 'r') as file:
            data = yaml.safe_load(file)

        self.input_places = data['input_places']

        related_places = []

        # Finding states related to input places
        for place in self.input_places:
            for line in self.automata:
                if place in line:
                    index = self.automata.index(line)
                    related_places.append(self.automata[index - 1])

        self.related_places = related_places

    def write_state_machine(self):
        """
        It creates a file with a case switch sentence that represents a state machine with the automata's logic.
        """

        states = []

        for line in self.automata:
            if 'state' in line:
                states.append(line)

        with open('petri_net/automata.ino', 'w+') as file:
            file.write('Hello!')
