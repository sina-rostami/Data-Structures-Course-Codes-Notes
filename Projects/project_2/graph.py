class Graph(object):

    def __init__(self, adjacency_list=dict(), edge_weights=dict()):
        self.adjacency_list = adjacency_list.copy()
        self.edge_weights = edge_weights.copy()

    def add_edge(self, u, v, w):
        self.edge_weights[u, v] = w
        if u not in self.adjacency_list:
            self.adjacency_list[u] = set()
        self.adjacency_list[u].add(v)

    def get_edge_weight(self, u, v):
        return self.edge_weights[u, v]

    def get_adjacent_nodes(self, u):
        return self.adjacency_list.get(u, set())