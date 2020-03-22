import yaml

class NetInterpreter:

    def states_input_places(self, net_info_file = 'petri_net/net_info.yaml'):
        """
        Identifies all states that are related to places and transitions informed in net_info.yaml file.
        """

        with open(net_info_file, 'r') as file:
            data = yaml.safe_load(file)

        self.input_places = data['input_places']
        self.functions_correlations = data['functions_correlations']

        self.related_states = []
