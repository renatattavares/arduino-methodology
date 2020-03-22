"""
Rewrite definition
"""
from petri_net.net_interpreter import NetInterpreter

class AutomataWriter(NetInterpreter):

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

        self.heading = []
        space = False

        # Identify heading
        for line in file_lines:
            self.heading.append(line.strip())
            if line == '\n' and space == False:
                space = True
                line = None
            if line == '\n' and space == True:
                break

        # Identify file body
        lenght_heading = len(self.heading)
        body = file_lines[lenght_heading:]

        # Defining automata cleaning its blank lines
        self.automata = [line for line in body if line.strip() != '']

    def write_state_machine(self):
        """
        It creates a file with a case switch sentence that represents a state machine with the automata's logic.
        """
        # Identify all states and transitions of automata
        self.states_trans_dict = {}

        for line in self.automata:
            if 'state' in line:
                index = self.automata.index(line)
                self.states_trans_dict[line] = self.automata[index+2]

        # Read heading in heading.ino file
        with open('petri_net/heading.ino', 'r') as heading:
            heading_lines = heading.readlines()

        # Write content in automata.ino file
        with open('petri_net/automata.ino', 'w') as automata:

            automata.writelines(heading_lines) # Write heading
            automata.write('\nint Automata (int state){')
            automata.write('\n\tswitch(state){')

            for state in self.states_trans_dict.keys():
                state_number = ''.join([letter for letter in state if letter.isdigit()]) # Get state number in string data type

                automata.write('\n\t\tcase(' + state_number + '):') # Write case sentence
                if state in self.related_states:
                    automata.write('\n\t\t\tcolor = get_color();')
                    automata.write('\n\t\t\tswitch(color){')

                    transitions = self.states_trans_dict[state]
                    transitions = transitions.strip('trans').split()
                    i = 1

                    for trans in transitions:
                        trans_number = str(i)
                        index = trans.find('/')
                        state_number = trans[index+1:]
                        automata.write('\n\t\t\t\tcase(' + trans_number + '):')
                        automata.write('\n\t\t\t\t\tstate = ' + state_number + ';')
                        i += 1

                    automata.write('\n\t\t\t\t}')

                else:
                    transition = self.states_trans_dict[state].strip('trans')
                    index = transition.find('/')
                    state_number = transition[index+1:]
                    automata.write('\n\t\t\tstate = ' + state_number + ';')

                automata.write('\n\t\t\tbreak;')

            automata.write('\n\t}')
            automata.write('\n\treturn(state);')
            automata.write('\n}')
