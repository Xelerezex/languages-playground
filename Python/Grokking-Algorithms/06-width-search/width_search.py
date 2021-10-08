from collections import deque

graph = {'you': ['alice', 'bob', 'claire'],
         'bob': ['anuj', 'peggy'],
         'alice': ['peggy'],
         'claire': ['thom', 'jonny'],
         'anuj': [],
         'peggy': [],
         'thom': [],
         'jonny': []}


def peson_is_seller(name):
    return name[-1] == 'm'


def width_search(graph, name):
    search_queue = deque()
    search_queue += graph[name]
    searched = []
    while search_queue:
        person = search_queue.popleft()
        if not person in searched:
            if peson_is_seller(person):
                print(f'{person} is a mango seller!')
                return True
        else:
            search_queue += graph[person]
            searched.append(person)
    return False


print(width_search(graph, "thom"))
