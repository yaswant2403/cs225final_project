#run locally with folder with appropriate txt files

import networkx as nx

G_small_graph = nx.Graph()
G_small_graph.add_edge(1, 2)
G_small_graph.add_edge(2, 3)
G_small_graph.add_edge(1, 3)
G_small_graph.add_edge(1, 9)
G_small_graph.add_edge(9, 2)
G_small_graph.add_edge(9, 3)
G_small_graph.add_edge(9, 4)

bc_small = nx.betweenness_centrality(G_small_graph, k = None, normalized = True, weight = None, endpoints = False)
print(bc_small)

G_dataset = nx.read_edgelist("../data/686.edges")
bc_dataset = nx.betweenness_centrality(G, k = None, normalized = True, weight = None, endpoints = False)
sorted_bc_dataset = {k: v for k, v in sorted(bc.items(), key=lambda item: item[1], reverse = True)}
print(sorted_bc_dataset.keys())
# Top 6 Users According to BC
#713', '828', '818', '719', '705', '805'