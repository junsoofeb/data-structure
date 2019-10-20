#from queue import Queue

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
        
class Deque(Queue):
    def enqueue_back(self, item):
        self.items.append(item)
    
    def dequeue_front(self):
        value = self.items.pop(0)
        if value is None:
            return value
        else:
            print("Deque is empty!")
            
deque = Deque()

empty_check = deque.isEmpty()
print(f"데크가 비어있는가? >> {empty_check}")

for i in range(5):
    print(f"데크에 {i} enqueue!")
    deque.enqueue(i)

print("현재 데크 >>", deque)

for i in range(3):
    print(f"데크에서 3개 dequeue!")
    deque.dequeue()

print("현재 데크 >>", deque)


'''
실행 결과

데크가 비어있는가? >> True
데크에 0 enqueue!
데크에 1 enqueue!
데크에 2 enqueue!
데크에 3 enqueue!
데크에 4 enqueue!
현재 데크 >> [4, 3, 2, 1, 0]
데크에서 3개 dequeue!
데크에서 3개 dequeue!
데크에서 3개 dequeue!
현재 데크 >> [4, 3]

'''