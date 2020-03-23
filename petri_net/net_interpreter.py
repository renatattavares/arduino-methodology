import yaml

class NetInterpreter:

    def read_net_info_file(self, net_info_file = 'petri_net/net_info.yaml'):

        with open(net_info_file, 'r') as file:
            data = yaml.safe_load(file)

        self.functions_info = data['functions']
        self.places_info = data['places']
        self.colors_info = data['colors']

    def places(self, net_info_file = 'petri_net/net_info.yaml'):
        """
        Identifies all states that are related to places that must receive a switch case sentence. This places must be informed in net_info.yaml file.
        """

        for place in self.places_info:
            indexes = [self.automata.index(line) for line in self.automata if place in line]
            self.switch_places = [self.automata[index-1] for index in indexes]

    def transitions(self, net_info_file = 'petri_net/net_info.yaml'):
        """
        Identifies all states that are related to transitions that represents specific functions in arduino library. This transisions must be informed in net_info.yaml file, considering which function they represent.
        """
        inverted_dict = {}

        for dict in self.functions_info:
            transitions = list(dict.values()).pop()
            function = list(dict.keys()).pop()
            for transition in transitions:
                inverted_dict[transition] = function

        self.functions = inverted_dict


    def colors(self, net_info_file = 'petri_net/net_info.yaml'):
        """
        Atributes a number for each color.
        """

        self.colors_number = {}
        i = 0

        for color in self.colors_info:
            self.colors_number[list(color.values()).pop().pop()] = str(i)
            i += 1
