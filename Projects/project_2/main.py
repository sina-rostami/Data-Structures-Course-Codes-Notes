from typing import DefaultDict
from dijkstra import Dijkstra
from graph import Graph


def test_dijkstra():
    graph = Graph()
    nodes = []
    while True:
        str = input()
        if str == "-1":
            break
        first, second, weight = str.split(' ')
        if first not in nodes:
            nodes.append(first)
        if second not in nodes:
            nodes.append(second)
        graph.add_edge(first, second, int(weight))

    dijkstra = Dijkstra(graph, nodes[0])
    dijkstra.do_dijkstra()

    print("weights : ")
    for v in nodes:
        print("%s :  %s" % (v, dijkstra.get_distance(v)))
    mst = []
    for n in nodes:
        path = dijkstra.get_path(n)
        if len(path) == 1:
            continue
        for i in range(len(path) - 1):
            edge = path[i] + " ---- " + path[i + 1]
            if edge not in mst:
                mst.append(edge)
    print("MST : ")
    for edge in mst:
        print (edge)

if __name__ == "__main__":
    test_dijkstra()

