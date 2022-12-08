#run locally with folder with appropriate txt files

import networkx as nx
G = nx.read_edgelist("686.txt")

# G.add_edge(1, 2)
# G.add_edge(2, 3)
# G.add_edge(1, 3)
# G.add_edge(1, 9)
# G.add_edge(9, 2)
# G.add_edge(9, 3)
# G.add_edge(9, 4)
bc = nx.betweenness_centrality(G, k = None, normalized = True, weight = None, endpoints = False, seed = None)
#pr = nx.pagerank(G, alpha = 0.85)
bc = {k: v for k, v in sorted(bc.items(), key=lambda item: item[1], reverse = True)}
print (bc.keys())

#for dataset
#713', '828', '818', '719', '705', '805'

#for normal, just print bc to see with bc value too