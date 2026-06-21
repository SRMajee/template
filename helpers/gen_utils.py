import random

def gen_int(min_v, max_v):
    return random.randint(min_v, max_v)

def gen_array(n, min_v, max_v):
    return [random.randint(min_v, max_v) for _ in range(n)]

def gen_unique_array(n, min_v, max_v):
    return random.sample(range(min_v, max_v + 1), n)

def gen_permutation(n):
    arr = list(range(1, n + 1))
    random.shuffle(arr)
    return arr

def gen_string(n, chars="abcdefghijklmnopqrstuvwxyz"):
    return "".join(random.choices(chars, k=n))

def gen_binary_string(n):
    return gen_string(n, "01")

def gen_tree(n):
    edges = []
    for i in range(2, n + 1):
        parent = random.randint(1, i - 1)
        edges.append((parent, i))
    
    mapping = list(range(1, n + 1))
    random.shuffle(mapping)
    mapped_edges = []
    for u, v in edges:
        if random.random() > 0.5: mapped_edges.append((mapping[u-1], mapping[v-1]))
        else: mapped_edges.append((mapping[v-1], mapping[u-1]))
    random.shuffle(mapped_edges)
    return mapped_edges

def gen_graph(n, m):
    edges = []
    for _ in range(m):
        edges.append((random.randint(1, n), random.randint(1, n)))
    return edges