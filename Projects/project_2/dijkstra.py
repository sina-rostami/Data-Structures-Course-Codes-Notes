import math


class Dijkstra(object):

    def __init__(self, graph, src):
        self.dist = dict()
        self.prev = dict()
        self.graph = graph
        self.src = src

    def do_dijkstra(self):
        visited = set()

        self.dist[self.src] = 0
        self.prev[self.src] = self.src

        queue = set()
        queue.add(self.src)
        while queue:
            u = min(queue, key=self.dist.get)
            for v in self.graph.get_adjacent_nodes(u):
                if v in visited:
                    continue
                alt = self.get_distance(u) + self.graph.get_edge_weight(u, v)
                if alt < self.get_distance(v):
                    self.dist[v] = alt
                    self.prev[v] = u
                    queue.add(v)
            queue.remove(u)
            visited.add(u)

    def get_distance(self, u):
        """ Return the length of shortest path from src to u. """
        return self.dist.get(u, math.inf)

    def get_path(self, v):
        """ Return the shortest path from src to v. """
        path = [v]
        while self.prev[v] != v:
            v = self.prev[v]
            path.append(v)
        return path[::-1]
