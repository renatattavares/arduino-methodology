"""
Rewrite definition
"""
from petri_net.net_interpreter import NetInterpreter

class AutomataWriter(NetInterpreter):

    def __init__(self, file_name):

        self.read_automata(file_name)
        self.read_net_info_file()
        self.places()
        self.transitions()
        self.colors()
        self.write_state_machine()

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
                if state in self.switch_places:
                    automata.write('\n\t\t\tswitch(color){')

                    transitions = self.states_trans_dict[state]
                    transitions = transitions.strip('trans').split()

                    for trans in transitions:
                        index = trans.find('/')
                        color_number = self.colors_number[trans[:index]]
                        future_state_number = trans[index+1:]
                        automata.write('\n\t\t\t\tcase(' + color_number + '):')
                        automata.write('\n\t\t\t\t\tstate = ' + future_state_number + ';')
                        automata.write('\n\t\t\t\t\tbreak;')

                    automata.write('\n\t\t\t\t}')
                    automata.write('\n\t\t\tbreak;')



                else:
                    transition = self.states_trans_dict[state].strip('trans')
                    index = transition.find('/')
                    future_state_number = transition[index+1:]
                    function = 'mymachine.' + self.functions[transition[:index].strip(' ')]

                    if function == 'mymachine.GetColor':
                        function = 'color = mymachine.GetColor'
                        automata.write('\n\t\t\t' + function + '();')
                        automata.write('\n\t\t\tmymachine.ShowColor(color);')
                        automata.write('\n\t\t\tSerial.print("\\t Cor detectada:");')
                        automata.write('\n\t\t\tPrintColorTxt(color);')
                        automata.write('\n\t\t\tstate = ' + future_state_number + ';')
                        automata.write('\n\t\t\tbreak;')
                    elif function == 'mymachine.Ignore':
                        automata.write('\n\t\t\tstate = ' + future_state_number + ';')
                        automata.write('\n\t\t\tbreak;')
                    else:
                        automata.write('\n\t\t\t' + function + '();')
                        automata.write('\n\t\t\tstate = ' + future_state_number + ';')
                        automata.write('\n\t\t\tbreak;')

            automata.write('\n\t}')
            automata.write('\n\treturn(state);')
            automata.write('\n}')
