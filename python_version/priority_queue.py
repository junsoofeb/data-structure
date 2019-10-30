import heapq

class PriorityQueue(object):
    def __init__(self):
        self._queue = []
        self._index = 0

    def push(self, item, priority):
        heapq.heappush(self._queue, (-priority, self._index, item))
        self._index += 1

    def pop(self):
        return heapq.heappop(self._queue)[-1]

class Item:
    def __init__(self, name):
        self.name = name

    def __repr__(self):
        return f"{self.name}"

pq = PriorityQueue()
pq.push(Item('test1'), 1)
pq.push(Item('test3'), 3)
pq.push(Item('test2'), 2)

while 1:
    try:
        print(pq.pop())
    except IndexError:
        print("pq is empty!")
        break

'''
실행결과

test3
test2
test1
pq is empty!

'''
