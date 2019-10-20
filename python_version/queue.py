class Queue(object):
    def __init__(self):
        self.items = []
        
    def isEmpty(self):
        return not bool(self.items)
    
    def enqueue(self, item):
        self.items.insert(0, item)
        
    def dequeue(self):
        value = self.items.pop()
        if value is not None:
            return value
        else:
            print("Queue is empty!")
            
    def size(self):
        return len(self.items)
    
    def peek(self):
        if self.items:
            return self.items[-1]
        else:
            print("Queue is Empty!")
            
    # representation
    def __repr__(self): 
        return repr(self.items)
        # repr() 문자열 형태로 반환

queue = Queue()

empty_check = queue.isEmpty()
print(f"큐 비어있는가? >> {empty_check}")

for i in range(5):
    print(f"큐에 {i} enqueue!")
    queue.enqueue(i)

print("현재 큐 >>", queue)

for i in range(3):
    print(f"큐에서 3개 pop!")
    queue.dequeue()

print("현재 큐 >>", queue)

'''
실행결과

큐 비어있는가? >> True
큐에 0 enqueue!
큐에 1 enqueue!
큐에 2 enqueue!
큐에 3 enqueue!
큐에 4 enqueue!
현재 큐 >> [4, 3, 2, 1, 0]
큐에서 3개 pop!
큐에서 3개 pop!
큐에서 3개 pop!
현재 큐 >> [4, 3]

'''
